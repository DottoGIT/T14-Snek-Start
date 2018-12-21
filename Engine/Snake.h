#pragma once
#include "Board.h"
#include "Location.h"

class Snake
{
private:
		class Segment
	{
	public:
		void InitHead(const Location& in_loc);
		void InitBodyC(Color& segc);
		void MoveBy(Location& delta_loc);
		void Follow(const Segment& next);
        void Draw(Board& brd);
		const Location& GetLocation()const ;
	private:
		Location loc;
		Color c;
		
	};
public:
	Snake(const Location& in_loc);
	void MoveBy(Location& delta_loc);
	void Grow(Color& segc);
	void Draw(Board& brd);
	bool IsSegOnSeg();
	bool HasEaten(Location& obj_loc);
	bool IsInTale(const Location& obj_loc)const ;
	Location NextHeadLoc(Location& delta_loc);
	Location Next;


private:
	static constexpr Color HeadColor = Colors::Yellow;
	static constexpr int MaxSegs = 10000;
	Segment segments[MaxSegs];
	int SegsNow = 1;

};
