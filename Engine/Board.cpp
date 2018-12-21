#include "Board.h"


Board::Board(Graphics & gfx)
	:
	gfx(gfx)
{}

void Board::DrawCell(Location & loc,Color c)
{

  gfx.DrawRectDim(loc.x*demension, loc.y*demension, demension-2, demension-2,c);

}

void Board::DrawBorders()
{
	///TOP
	for (int lx = demension; lx < (width*demension+2); ++lx)
		for (int h = 0; h < 4; h++)
		gfx.PutPixel(lx-3, demension-h-1, bColor);
	
	///BOTTOM
    for (int lx = demension; lx < (width*demension+3); ++lx)
		for (int h = 0; h < 4; h++)
		gfx.PutPixel(lx, demension*height+h, bColor);
	
	///LEFT
	for (int ly = demension-4; ly < (height*demension); ++ly)
		for (int h = 0; h < 4; h++)
		gfx.PutPixel(demension-h, ly+4, bColor);
	
	///RIGHT
	for (int ly = demension; ly < (height*demension+4); ++ly)
		for (int h = 0; h < 4; h++)
		gfx.PutPixel(demension*width+h-1, ly-4, bColor); 
}

bool Board::IsSnekIn(Location & loc)
{
	return loc.x>0 && loc.x < width && loc.y >0 && loc.y < height ;
}



int Board::GetHeight() const
{
	return height;
}

int Board::GetWidth() const
{
	return width;
}
