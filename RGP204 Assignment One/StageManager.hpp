#pragma once
#include <vector>
#include <memory>
#include "Stage.hpp"

class StageManager
{
public:
	StageManager();

	void Update();
	void Draw(sf::RenderWindow& window);
	int GenerateRandomStage(int totalNumberOfStages, int lastStage);
	void InitialStageSetup();
	void LoadStage();
private:
	int lastStage;
	int totalNumberOfStages = 2;
	int m_currentStage;
	std::vector<std::unique_ptr<Stage>> m_stages;
};

