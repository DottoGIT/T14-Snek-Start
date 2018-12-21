#pragma once
#include "Board.h"
#include "Snake.h"
#include <random>


class Object
{
public:
	void InitBlock(std::mt19937& rng, const Board& brd, const Snake& snake);
	void Respawn(std::mt19937& rng,const Board& brd,const Snake& snake);
	void Draw(Board& brd); 
	void DrawBlock(Board& brd);
	Location& GetLoaction();


private:
  Location loc;
  Color c = Colors::Red;
	


};
