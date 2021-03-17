#include "Level.h"

#include "Enemy.h"

#include <fstream>
#include <iostream>

Level::Level(const std::string& levelPath)
	: _levelData{}
{
	std::ifstream file;
	file.open(levelPath);

	if (file.fail())
	{
		std::cout << "ERROR: failed to load file: " << levelPath << std::endl;
		return;
	}

	std::string row;
	while (std::getline(file, row))
	{
		_levelData.push_back(row);
	}

	file.close();
}

void Level::print()
{
	const size_t size{_levelData.size()};
	for (int i = 0; i < size; ++i)
	{
		std::cout << _levelData[i] << std::endl;
	}
}

void Level::init(Player& player, std::vector<Enemy>& enemies)
{
	const size_t size{_levelData.size()};
	for (int i = 0; i < size; ++i)
	{
		const size_t str_size{_levelData[i].size()};
		for (int k = 0; k < str_size; ++k)
		{
			const char tile{_levelData[i][k]};

			switch (tile)
			{
			case '@':
				player.setPosition(i, k);
				break;
			case 'E':
				enemies.push_back(Enemy(i, k, 2, 1));
				break;
			default:
				break;
			}
		}
	}
}

void Level::tryMovePlayer(Player& player, int directionX, int directionY)
{
	int playerPosX;
	int playerPosY;
	player.getPosition(playerPosX, playerPosY);

	const int targetX = playerPosX + directionX;
	const int targetY = playerPosY + directionY;

	const char moveTile = _levelData[targetX][targetY];
	switch (moveTile)
	{
	case '.':
		_levelData[targetX][targetY] = '@';
		_levelData[playerPosX][playerPosY] = '.';
		player.setPosition(targetX, targetY);
		break;
	}
}

void Level::tryMoveEnemy(Enemy& enemy, const Player& player)
{
	const int enemyDelayCounter = enemy.getDelayCounter();
	if (enemyDelayCounter % enemy.getDelay() != 0)
	{
		return;
	}

	int playerPosX;
	int playerPosY;
	player.getPosition(playerPosX, playerPosY);

	int enemyPosX;
	int enemyPosY;
	enemy.getPosition(enemyPosX, enemyPosY);

	if (playerPosX > enemyPosX)
	{
		enemy.setPositionX(enemyPosX + 1);
	}
	else
	{
		enemy.setPositionX(enemyPosX - 1);
	}

	if (playerPosY > enemyPosY)
	{
		enemy.setPositionY(enemyPosY + 1);
	}
	else
	{
		enemy.setPositionY(enemyPosY - 1);
	}

	_levelData[enemyPosX][enemyPosY] = '.';
	enemy.getPosition(enemyPosX, enemyPosY);
	_levelData[enemyPosX][enemyPosY] = 'E';
}
