#pragma once
#include "Graphics.h"
#include "Location.h"

class Board
{
public:
	Board(Graphics& gfx);
	void DrawCell(Location& loc, Color c);
	void DrawBorders();
	bool IsSnekIn(Location& loc);
	int GetHeight() const;
	int GetWidth() const;
private:
	Graphics& gfx;
	static constexpr int demension = 12;
	static constexpr int height = 48;
	static constexpr int width = 65;
	Color bColor = Colors::Magenta;

};