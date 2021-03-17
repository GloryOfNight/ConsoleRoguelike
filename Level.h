#pragma once
#include "Player.h"

#include <iostream>
#include <string>
#include <vector>

class Enemy;

class Level
{
public:
	Level() // default
	{
		std::cout << "Level default constructor" << std::endl;
	}

	Level(const std::string& levelPath);

	void print();

	void init(Player& player, std::vector<Enemy>& enemies);

	void tryMovePlayer(Player& player, int directionX, int directionY);

	void tryMoveEnemy(Enemy& enemy, const Player& player);

private:
	std::vector<std::string> _levelData;
};
