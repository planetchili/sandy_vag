#pragma once

#include <cassert>
#include <memory>
#include <vector>
#include "Graphics.h"
#include "Tile.h"
#include "Contents.h"

class Field
{
public:
	Field();
	Tile& GetTile( int x,int y )
	{
		assert( x >= 0 && y >= 0 && x < width && y < height );
		return tiles[y * width + x];
	}
	template<class T>
	void SpawnContents( int x,int y )
	{
		Tile& t = GetTile( x,y );
		if( !t.IsOccupied() )
		{
			contents.push_back( std::make_unique<T>( x,y ) );
			t.SetOccupied();
		}
	}
	template<class T>
	void SpawnCircle( int x,int y,int radius )
	{
		const int start_x = std::max( 0,x - radius );
		const int start_y = std::max( 0,y - radius );
		const int end_x = std::min( width - 1,x + radius );
		const int end_y = std::min( height - 1,y + radius );
		const int rSqr = radius * radius;
		for( int yLoop = start_y; yLoop < end_y; yLoop++ )
		{
			for( int xLoop = start_x; xLoop < end_x; xLoop++ )
			{
				const int xOff = xLoop - x;
				const int yOff = yLoop - y;
				if( xOff * xOff + yOff * yOff <= rSqr )
				{
					SpawnContents<T>( xLoop,yLoop );
				}
			}
		}
	}
	template<class T>
	void SpawnRectangle( int x,int y,int rect_width,int rect_height )
	{
		const int halfWidth = rect_width / 2;
		const int halfHeight = rect_height / 2;
		const int start_x = std::max( 0,x - halfWidth );
		const int start_y = std::max( 0,y - halfHeight );
		const int end_x = std::min( width - 1,x + halfWidth );
		const int end_y = std::min( height - 1,y + halfHeight );
		for( int y = start_y; y < end_y; y++ )
		{
			for( int x = start_x; x < end_x; x++ )
			{
				SpawnContents<T>( x,y );
			}
		}
	}
	void Update()
	{
		for( auto& c : contents )
		{
			c->Update( *this );
		}
	}
	void Draw( Graphics& gfx )
	{
		for( auto& c : contents )
		{
			c->Draw( gfx );
		}
	}
private:
	int width = 800;
	int height = 600;
	std::unique_ptr<Tile[]> tiles;
	std::vector<std::unique_ptr<Contents>> contents;
};