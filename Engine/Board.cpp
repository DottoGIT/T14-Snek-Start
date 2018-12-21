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
	for (int lx = demension; lx < (width*demension); ++lx)
		for (int h = 0; h < 4; h++)
		gfx.PutPixel(lx, demension+h, bColor);
	
    for (int lx = demension; lx < (width*demension); ++lx)
		for (int h = 0; h < 4; h++)
		gfx.PutPixel(lx, demension*height+h, bColor);
	
	for (int ly = demension; ly < (height*demension); ++ly)
		for (int h = 0; h < 4; h++)
		gfx.PutPixel(demension+h, ly, bColor);
	
	for (int ly = demension; ly < (height*demension); ++ly)
		for (int h = 0; h < 4; h++)
		gfx.PutPixel(demension*width+h, ly, bColor); 
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
