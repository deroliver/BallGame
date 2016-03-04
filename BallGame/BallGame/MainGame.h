#pragma once

#include <gengine/Camera2D.h>
#include <gengine/SpriteBatch.h>
#include <gengine/InputManager.h>
#include <gengine/Window.h>
#include <gengine/GLSLProgram.h>
#include <gengine/Timing.h>
#include <gengine/SpriteFont.h>
#include <memory>

#include "BallController.h"
#include "BallRenderer.h"
#include "Grid.h"

enum class GameState { RUNNING, EXIT };

const int CELL_SIZE = 12;

class MainGame {

public:
	~MainGame();
	void run();

private:
	void init();
	void initRenderers();
	void initBalls();
	void update(float deltaTime);
	void draw();
	void drawHUD();
	void processInput();

	int m_screenWidth = 0;
	int m_screenHeight = 0;

	std::vector<Ball> m_balls; ///< All the balls on the screen
	std::unique_ptr<Grid> m_grid; ///< Grid for spatial partitioning for collision

	int m_currentBallRenderer = 0;
	std::vector<BallRenderer*> m_ballRenderers; ///< Vector of ball renderers

	BallController m_ballController; ///< Controls the balls

	gengine::Window m_window; ///< The main window
	gengine::SpriteBatch m_spriteBatch; ///< Renders the balls
	std::unique_ptr<gengine::SpriteFont> m_spriteFont; /// < Font rendering
	gengine::Camera2D m_camera; ///< Renders the scene
	gengine::InputManager m_inputManager; ///< Manages the input for the game
	gengine::GLSLProgram m_textureProgram; ///< Shader for the textures

	gengine::FpsLimiter m_fpsLimiter; ///< Used for controlling the FPS
	float m_fps = 0.0f;

	GameState m_gameState = GameState::RUNNING; /// < The current state of the game
};

