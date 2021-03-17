#include "GameSystem.h"

#include <conio.h>

GameSystem::GameSystem(const std::string& levelPath)
	: _level(levelPath)
	, _player()
{
}

void GameSystem::start()
{
	bool isDone{false};

	_level.init(_player, _enemies);

	while (!isDone)
	{
		const char input = _getch();
		switch (input)
		{
		case 'w':
		case 'W':
			_level.tryMovePlayer(_player, -1, 0);
			break;
		case 's':
		case 'S':
			_level.tryMovePlayer(_player, 1, 0);
			break;
		case 'a':
		case 'A':
			_level.tryMovePlayer(_player, 0, -1);
			break;
		case 'd':
		case 'D':
			_level.tryMovePlayer(_player, 0, 1);
			break;
		default:
			isDone = true;
			break;
		}

		for (Enemy& enemy : _enemies)
		{
			enemy.tick();
			_level.tryMoveEnemy(enemy, _player);
		}

		system("CLS");
		_level.print();
	}
}
