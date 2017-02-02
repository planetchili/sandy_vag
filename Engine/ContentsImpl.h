#pragma once

#include "Colors.h"
#include "Graphics.h"
#include "Field.h"
#include "Contents.h"
#include <random>

class Sand : public Contents
{
public:
	Sand( int x,int y )
		:
		Contents( x,y,Colors::Yellow )
	{}
	virtual void Update( Field& f ) override
	{
		{
			Tile& downTile = f.GetTile( x,y + 1 );
			if( !downTile.IsOccupied() )
			{
				downTile.SetOccupied();
				f.GetTile( x,y ).ClearOccupied();
				y += 1;
				return;
			}
		}

		if( bd( rng ) )
		{
			Tile& downLeftTile = f.GetTile( x - 1,y + 1 );
			if( !downLeftTile.IsOccupied() )
			{
				downLeftTile.SetOccupied();
				f.GetTile( x,y ).ClearOccupied();
				x -= 1;
				y += 1;
			}
		}
		else
		{
			Tile& downRightTile = f.GetTile( x + 1,y + 1 );
			if( !downRightTile.IsOccupied() )
			{
				downRightTile.SetOccupied();
				f.GetTile( x,y ).ClearOccupied();
				x += 1;
				y += 1;
			}
		}
		return;
	}
private:
	static std::minstd_rand rng;
	static std::bernoulli_distribution bd;
};

class Rock : public Contents
{
public:
	Rock( int x,int y )
		:
		Contents( x,y,Colors::Gray )
	{}
	virtual void Update( Field& f ) override {}
};