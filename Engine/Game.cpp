/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "ContentsImpl.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
	field.SpawnCircle<Sand>( 200,100,100 );
	field.SpawnRectangle<Rock>( 175,210,50,5 );
	field.SpawnRectangle<Rock>( 225,250,50,5 );
	field.SpawnRectangle<Rock>( 175,300,50,5 );
	field.SpawnRectangle<Rock>( 225,350,50,5 );

	field.SpawnCircle<Sand>( 400,100,60 );
	field.SpawnCircle<Rock>( 400,200,40 );
	field.SpawnRectangle<Rock>( 350,300,80,10 );
	field.SpawnRectangle<Rock>( 450,300,80,10 );
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	field.Update();
	field.Update();
	field.Update();
}

void Game::ComposeFrame()
{
	field.Draw( gfx );
}
