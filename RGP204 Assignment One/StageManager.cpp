#include "StageManager.hpp"
#include "Stage.hpp"
#include <iostream>

// Include other stage subclasses...

StageManager::StageManager()
	: lastStage(0)
{
	InitialStageSetup();
}


void StageManager::Draw(sf::RenderWindow& window)
{
	for (auto& stage : m_stages) {
		stage->Draw(window);	
	}
}

void StageManager::Update()
{
	for (auto& stage : m_stages) {
		stage->Update();
	}
}

void StageManager::LoadStage()
{
	int randomStage = GenerateRandomStage(totalNumberOfStages, lastStage);


	std::unique_ptr<Stage> stage; // Changed to std::unique_ptr
	switch (randomStage) {
	case 1:
		stage = std::make_unique<BlueStage>(); // Use std::make_unique
		lastStage = 1;
		break;
	case 2:
		stage = std::make_unique<RedStage>(); // Use std::make_unique
		lastStage = 2;
		break;
	default:
		// Handle invalid stage number...
		break;
	}
	if (stage != nullptr) {
		m_stages.push_back(std::move(stage)); // Use std::move to transfer ownership
	}
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

	LoadStage();
	LoadStage();
	LoadStage();

	for (auto& stage : m_stages)
	{
		stage->GetSprite().setPosition(960 + xOffSet, 540);
		xOffSet = xOffSet + 1920;
		std::cout << xOffSet << std::endl;
		std::cout << stage->GetSprite().getPosition().x << std::endl;
	}
}
