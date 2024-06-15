#include "StageManager.hpp"
#include "Stage.hpp"
#include <iostream>

// Include other stage subclasses...

StageManager::StageManager(const int& groundLevel)
	: lastStage(0), m_groundLevel(groundLevel)
{
	InitialStageSetup();
}


void StageManager::Draw(sf::RenderWindow& window)
{
	for (auto& stage : m_stages) {
		stage->Draw(window);
	}
}

void StageManager::Update(Player& player)
{
	if (!m_stages.empty())
	{
		m_currentStage = m_stages[0];
		std::cout << "Current stage: " << m_currentStage->GetStageType() << std::endl;	
	}


	if (!m_stages.empty() && m_stages.front()->GetIsOffScreen()) {
		// Remove the first stage
		m_stages.erase(m_stages.begin());
		std::cout << "stage erased" << std::endl;
		// Load a new stage at the end
		LoadStage(m_groundLevel);

		// Adjust the position of the new stage
		auto& newStage = m_stages.back();
		newStage->GetSprite().setPosition(960 + (m_stages.size() - 1) * 1920, 540);
	}
	for (auto& stage : m_stages)
	{
		stage->IsOffScreen();
		stage->Update(player);
	}
}

void StageManager::LoadStage(int& groundLevel)
{
	int randomStage = GenerateRandomStage(totalNumberOfStages, lastStage);


	std::shared_ptr<Stage> stage; // Changed to std::unique_ptr
	switch (randomStage) {
	case 1:
		stage = std::make_shared<BlueStage>(); // Use std::make_unique
		lastStage = 1;
		break;
	case 2:
		stage = std::make_shared<RedStage>(m_groundLevel); // Use std::make_unique
		lastStage = 2;
		break;
	default:
		// Handle invalid stage number...
		break;
	}
	if (stage != nullptr) {
		m_stages.push_back(std::move(stage)); // Use std::move to transfer ownership
	}
	m_stages.back()->LoadToBack(); // Does this even work?
}


int StageManager::GenerateRandomStage(int totalNumberOfStages, int lastStage)
{
	if (totalNumberOfStages == 1)
	{
		return 1;
	}

	int randomStage = std::rand() % totalNumberOfStages + 1;
	if (randomStage == lastStage)
	{
		return GenerateRandomStage(totalNumberOfStages, lastStage);
	}

	return randomStage;
}

void StageManager::InitialStageSetup()
{
	int xOffSet = 0;

	LoadStage(m_groundLevel);
	LoadStage(m_groundLevel);
	LoadStage(m_groundLevel);

	for (auto& stage : m_stages)
	{
		stage->GetSprite().setPosition(960 + xOffSet, 540);
		xOffSet = xOffSet + 1920;
	}
}
