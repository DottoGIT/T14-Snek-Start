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
#include "SpriteCodex.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	brd(gfx),
	snek({ 5,5 }),
	rng(std::random_device()()),
	cDist(50, 150)
	

{
	 point.InitBlock(rng, brd, snek);
     point.Respawn(rng, brd, snek);
	 
	 for (int i = 0; i < 1000; i++)
	 {
		 blocks[i].InitBlock(rng, brd, snek);
	 }

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
	
	if (GameOver == false)
	{
		///Movement///
		{
			if ((wnd.kbd.KeyIsPressed(VK_UP) && delta_loc.y != 1 && wnd.kbd.KeyIsPressed(VK_DOWN)==false && wnd.kbd.KeyIsPressed(VK_RIGHT)==false && wnd.kbd.KeyIsPressed(VK_LEFT)==false))
			{
				delta_loc = { 0,-1 };
				CanMove = false;
			}
			if (wnd.kbd.KeyIsPressed(VK_DOWN) && delta_loc.y != -1 && wnd.kbd.KeyIsPressed(VK_UP) == false && wnd.kbd.KeyIsPressed(VK_RIGHT) == false && wnd.kbd.KeyIsPressed(VK_LEFT) == false)
			{
				delta_loc = { 0,1 };
				CanMove = false;

			}
			if (wnd.kbd.KeyIsPressed(VK_RIGHT) && delta_loc.x != -1 && wnd.kbd.KeyIsPressed(VK_DOWN) == false && wnd.kbd.KeyIsPressed(VK_UP) == false && wnd.kbd.KeyIsPressed(VK_LEFT) == false)
			{
				delta_loc = { 1,0 };
				CanMove = false;
			}
			if (wnd.kbd.KeyIsPressed(VK_LEFT) && delta_loc.x != 1 && wnd.kbd.KeyIsPressed(VK_DOWN) == false && wnd.kbd.KeyIsPressed(VK_RIGHT) == false && wnd.kbd.KeyIsPressed(VK_UP) == false)
			{
				delta_loc = { -1,0 };
				CanMove = false;
			}
			if (wnd.kbd.KeyIsPressed(VK_SHIFT))
			{
				FpsPass = 2;
			}
			else FpsPass = 5;

		}
		
	FpsCounter++;
		if (FpsCounter >= FpsPass)
		{
			
			if (brd.IsSnekIn(snek.NextHeadLoc(delta_loc)) == false || snek.IsSegOnSeg() || HaveEatenBlock)
			{
				GameOver = true;
			}

			for (int i = 0; i < BlockNow; i++)
				{
					if (snek.NextHeadLoc(delta_loc) == blocks[i].GetLoaction())
						HaveEatenBlock = true;
				}

			if (BRTc == BlockRezTime)
				{
					BlockNow++;
                    BRTc = 0;
				}

			if (GPPc < GrowPerPoint)
			{
				Color c(0, cDist(rng), 0);
				snek.Grow(c);
			}

			if (snek.HasEaten(point.GetLoaction()))
			{
			    
			    point.Respawn(rng, brd, snek);	
				GPPc = 0;
			}

			if (GameOver == false)
			{
					snek.MoveBy(delta_loc);
			}

			

			CanMove = true;
			BRTc++;
			FpsCounter = 0;
			GPPc++;
		}
		

	}
}

void Game::ComposeFrame()
{ 
  
	point.Draw(brd);
	for (int i = 0; i < BlockNow; i++)
	{
		blocks[i].DrawBlock(brd);
	}
	snek.Draw(brd);
	brd.DrawBorders();
  
  if (GameOver)
   SpriteCodex::DrawGameOver(350,250,gfx);
} 



