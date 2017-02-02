#pragma once

#include "Colors.h"
#include "Graphics.h"

class Contents
{
public:
	Contents( int x,int y,Color color )
		:
		x( x ),
		y( y ),
		color( color )
	{}
	void Draw( Graphics& gfx ) const
	{
		gfx.PutPixel( x,y,color );
	}
	virtual void Update( class Field& f ) = 0;
protected:
	Color color;
	int x;
	int y;
};