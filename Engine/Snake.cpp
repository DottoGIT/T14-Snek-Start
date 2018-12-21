#include "Snake.h"
#include <assert.h>

Snake::Snake(const Location& in_loc)
{
	segments[0].InitHead(in_loc);
}

void Snake::MoveBy(Location & delta_loc)
{
	for (int i = SegsNow - 1; i > 0; i--)
		segments[i].Follow(segments[i - 1]);
	segments[0].MoveBy(delta_loc);
}

void Snake::Grow(Color& segc)
{

	segments[SegsNow].InitBodyC(segc);
	SegsNow++;
}

void Snake::Draw(Board & brd) 
{
	for (int i = 0; i < SegsNow; ++i)
		segments[i].Draw(brd);
}

bool Snake::IsSegOnSeg()
{
	for (int i = 1; i < SegsNow; i++)
	{
		if(Next == segments[i].GetLocation())
		return true;
	}
	return false;
}

bool Snake::HasEaten(Location& obj_loc)
{
	if (segments[0].GetLocation() == obj_loc)
	{
		return true;	
	}
	return false;
}

bool Snake::IsInTale(const Location & obj_loc) const
{
	for(int i=0; i<SegsNow;i++)
	if (segments[i].GetLocation() == obj_loc)
	{
		return true;
	}
	return false;
}

Location Snake::NextHeadLoc(Location & delta_loc)
{
	Location l(segments[0].GetLocation());
	l.Add(delta_loc);
	return Next=l;
}

void Snake::Segment::InitHead(const Location & in_loc)
{
	loc = in_loc;
	c = HeadColor;
}

void Snake::Segment::InitBodyC(Color& segc)
{
	c = segc;
}


void Snake::Segment::MoveBy(Location & delta_loc)
{
	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);
	loc.Add(delta_loc);
}

void Snake::Segment::Follow(const Segment & next)
{
	loc = next.loc;
}



void Snake::Segment::Draw(Board & brd)
{
	brd.DrawCell(loc, c);
}

const Location& Snake::Segment::GetLocation() const
{
	return loc;
}



