#pragma once
#include <vector>
#include <memory>
#include "Stage.hpp"
#include <iostream>

class Player;
class Gametextures;

class StageManager
{
public:
	StageManager(const int& groundLevel);

	void Update(Player& player);
	void Draw(sf::RenderWindow& window, float frame_Time);
	int GenerateRandomStage(int totalNumberOfStages, int lastStage);
	std::shared_ptr<Stage>& InitialStageSetup();
	void LoadStage(int& groundLevel);
	std::shared_ptr<Stage>& GetCurrentStage() { return m_currentStage; std::cout << this << std::endl; }
private:
	int iteration = 0;
	int lastStage;
	int totalNumberOfStages = 2;
	std::shared_ptr<Stage> m_currentStage;
	int m_groundLevel;
	std::vector<std::shared_ptr<Stage>> m_stages;
};

