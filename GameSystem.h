#pragma once
#include "Level.h"
#include "Player.h"
#include "Enemy.h"

#include <string>
#include <vector>

class GameSystem
{
public:
	GameSystem(const std::string& levelPath);

	void start();

private:
	Level _level;

	Player _player;

	std::vector<Enemy> _enemies;
};