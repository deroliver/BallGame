#pragma once

#include <vector>

#include "Ball.h"

enum class GravityDirection { NONE, LEFT, RIGHT, UP, DOWN };

class Grid;

class BallController {
public:

	/// Updates all the balls
	void updateBalls(std::vector<Ball>& balls, Grid* grid, float deltaTime, int maxX, int maxY);

	void onMouseDown(std::vector<Ball>& balls, float mouseX, float mouseY);

	void onMouseUp(std::vector<Ball>& balls);
	void onMouseMove(std::vector<Ball>& balls, float mouseX, float mouseY);
	void setGravityDirection(GravityDirection direction) { m_gravityDirection = direction; }

private:
	/// Updates collision
	void updateCollision(Grid* grid);
	/// Checks collision between a ball and a vector of balls, at a specific index
	void checkCollision(Ball* ball, std::vector<Ball*>& ballsToCheck, int startindIndex);
	/// Checks is two balls collide
	void checkCollision(Ball& B1, Ball& B2);

	/// Checks is the mouse is over a ball
	bool isMouseOnBall(Ball& B, float mouseX, float mouseY);
	glm::vec2 getGravityAccel();

	int m_grabbedBall = -1;
	glm::vec2 m_prevPos = glm::vec2(0.0f);
	glm::vec2 m_grabOffSet = glm::vec2(0.0f);

	GravityDirection m_gravityDirection = GravityDirection::NONE;
};

