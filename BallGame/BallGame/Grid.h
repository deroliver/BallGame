#pragma once

#include <vector>

#include "Ball.h"


struct Cell {
	std::vector<Ball*> balls;
};

class Grid {
	friend class BallController;
public:
	Grid(int width, int height, int cellSize);
	~Grid();

	// Calculated the cell to add the ball to
	void addBall(Ball* ball);
	// Adds the ball to the specified cell
	void addBall(Ball* ball, Cell* cell);
	// Gets cell based on cell coordinates
	Cell* getCell(int x, int y);
	// Gets cell based on window coordinates
	Cell* getCell(const glm::vec2& pos);
	// Removes the specified ball from its cell
	void removeBallFromCell(Ball* ball);

private:
	std::vector<Cell> m_cells;
	int m_cellSize;
	int m_width;
	int m_height;
	int m_numYCells;
	int m_numXCells;
};

