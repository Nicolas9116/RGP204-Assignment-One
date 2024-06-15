#pragma once
#include <vector>
#include <memory>
#include "Stage.hpp"

class Player;

class StageManager
{
public:
	StageManager(const int& groundLevel);

	void Update(Player& player);
	void Draw(sf::RenderWindow& window);
	int GenerateRandomStage(int totalNumberOfStages, int lastStage);
	void InitialStageSetup();
	void LoadStage(int& groundLevel);
	std::shared_ptr<Stage> GetCurrentStage() { return m_currentStage; }
private:
	int lastStage;
	int totalNumberOfStages = 2;
	std::shared_ptr<Stage> m_currentStage;
	int m_groundLevel;
	std::vector<std::shared_ptr<Stage>> m_stages;
};

