#include "Object.h"



void Object::InitBlock(std::mt19937 & rng, const Board & brd, const Snake & snake)
{
	Respawn(rng, brd, snake);
}


void Object::Respawn(std::mt19937 & rng,const Board & brd,const Snake & snake)
{
	std::uniform_int_distribution<int> xDist(2, brd.GetWidth() - 2);
	std::uniform_int_distribution<int> yDist(2, brd.GetHeight() - 2);
  
	Location newLoc;
	do
	{
		newLoc.x = xDist(rng);
		newLoc.y = yDist(rng);
	} while (snake.IsInTale(newLoc) == true);

	loc = newLoc;
}

void Object::Draw(Board& brd)
{
	brd.DrawCell(loc,c);
}

void Object::DrawBlock(Board & brd)
{
	c = Colors::Gray;
	brd.DrawCell(loc, c);
}



Location& Object::GetLoaction() 
{
	return loc;
}

