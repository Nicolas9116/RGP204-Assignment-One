#include "StageManager.hpp"
#include "Stage.hpp"
#include <iostream>

// Include other stage subclasses...

StageManager::StageManager(const int& groundLevel)
	: lastStage(0), m_groundLevel(groundLevel)
{

}


void StageManager::Draw(sf::RenderWindow& window, float frame_Time)
{
	for (auto& stage : m_stages) {
		stage->Draw(window, frame_Time);
	}
}

void StageManager::Update(Player& player) 
{
	// Scroll existing stages
	//std::cout << "It is iteration : " << iteration << std::endl;

	if (!m_stages.empty())
	{
		m_currentStage = m_stages[0];
		//std::cout << "Current stage: " << m_currentStage->GetStageType() << std::endl;
	}

	for (auto& stage : m_stages)
	{
		stage->Update(player);
		stage->IsOffScreen();
	}

	// Remove off-screen stages
	m_stages.erase(std::remove_if(m_stages.begin(), m_stages.end(), [](const std::shared_ptr<Stage>& stage)
		{
			return stage->GetIsOffScreen();
		}), m_stages.end());

	if (m_stages.size() < 3)
	{
		LoadStage(m_groundLevel);
	}

	//for (auto& stage : m_stages)
	//{
	//	std::cout << "Stage Type : " << stage->GetStageType() << std::endl;
	//	std::cout << "Stage position: " << stage->GetSprite().getPosition().x << std::endl;
	//	std::cout << "Stage is off screen: " << stage->GetIsOffScreen() << std::endl;
	//}

	//std::cout << "There are " << m_stages.size() << " stages in the vector" << std::endl;
	iteration++;
}

void StageManager::LoadStage(int& groundLevel)
{
	int randomStage = GenerateRandomStage(totalNumberOfStages, lastStage);


	std::shared_ptr<Stage> stage;
	switch (randomStage) {
	case 1:
		stage = std::make_shared<BlueStage>(m_groundLevel);
		lastStage = 1;
		break;
	case 2:
		stage = std::make_shared<RedStage>(m_groundLevel);
		lastStage = 2;
		break;
	default:
		// Handle invalid stage number...
		break;
	}
	if (stage != nullptr) {
		m_stages.push_back(stage); // Use std::move to transfer ownership
	}
	m_stages.back()->LoadToBack();
	m_stages.back()->DelayedSetupCall();
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

std::shared_ptr<Stage>& StageManager::InitialStageSetup()
{
	int xOffSet = 0;

	LoadStage(m_groundLevel);
	LoadStage(m_groundLevel);
	LoadStage(m_groundLevel);

	for (auto& stage : m_stages)
	{
		stage->GetSprite().setPosition(xOffSet, 0);
		xOffSet = xOffSet + 1920;
	}

	for (auto& stage : m_stages)
	{
		stage->DelayedSetupCall();

	}
	//std::cout << "Initial stage setup done, there are " << m_stages.size() << "stages in the vector" << std::endl;

	//for (auto& stage : m_stages)
	//{
		//std::cout << "Stage type: " << stage->GetStageType() << std::endl;
		//std::cout << "Stage position: " << stage->GetSprite().getPosition().x << std::endl;
	//}
	
	return m_stages[0];

}
