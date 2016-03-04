#pragma once

#include <vector>
#include <memory>

#include <gengine/SpriteBatch.h>
#include <gengine/GLSLProgram.h>

#include "Ball.h"

class BallRenderer {
public:
	virtual void renderBall(gengine::SpriteBatch& spriteBatch, 
							const std::vector<Ball>& ball, 
							const glm::mat4& projectionMatrix);

protected:
	std::unique_ptr<gengine::GLSLProgram> m_program = nullptr;
};

class MomentumBallRenderer : public BallRenderer {
public:
	virtual void renderBall(gengine::SpriteBatch& spriteBatch,
		const std::vector<Ball>& ball,
		const glm::mat4& projectionMatrix) override;

};

class VelocityBallRenderer : public BallRenderer {
public:
	VelocityBallRenderer(int screenWidth, int screenHeight);
	virtual void renderBall(gengine::SpriteBatch& spriteBatch,
		const std::vector<Ball>& ball,
		const glm::mat4& projectionMatrix) override;

private:
	int m_screenWidth;
	int m_screenHeight;
};

class PulsingBallRenderer : public BallRenderer {
public:
	PulsingBallRenderer(int screenWidth, int screenHeight);
	virtual void renderBall(gengine::SpriteBatch& spriteBatch,
		const std::vector<Ball>& ball,
		const glm::mat4& projectionMatrix) override;

private:
	int m_screenWidth;
	int m_screenHeight;
	float m_time;
};

