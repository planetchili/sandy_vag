#pragma once

class Tile
{
public:
	bool IsOccupied() const
	{
		return occupied;
	}
	void SetOccupied()
	{
		occupied = true;
	}
	void ClearOccupied()
	{
		occupied = false;
	}
private:
	bool occupied = false;
};