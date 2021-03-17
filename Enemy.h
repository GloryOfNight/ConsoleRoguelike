#pragma once
class Enemy
{
public:
	Enemy(const int x, const int y, const int delay, const int speed)
		: _x{x}
		, _y{y}
		, _delay{delay}
		, _speed{speed}
	{
	}

	void setPositionX(const int x)
	{
		_x = x;
	}

	void setPositionY(const int y)
	{
		_y = y;
	}

	void getPosition(int& x, int& y) const
	{
		x = _x;
		y = _y;
	}

	int getDelay() const
	{
		return _delay;
	}

	int getDelayCounter() const
	{
		return _delayCounter;
	}

	int getSpeed() const
	{
		return _speed;
	}

	void tick()
	{
		_delayCounter++;
	}

private:
	int _x;
	int _y;

	// delay between player moves
	const int _delay;
	int _delayCounter = 0;

	// how much tiles enemy moves
	const int _speed;
};
