#pragma once

#include <glm/glm.hpp>
#include <gengine/Vertex.h>

struct Cell;

/// Plain old data
/// No reason not to use a struct
struct Ball {
	Ball(float radius, float mass, const glm::vec2& position,
		 const glm::vec2& velocity, unsigned int textureID,
		 const gengine::ColorRGBA8 color);
	
	float radius;
	float mass;
	glm::vec2 velocity;
	glm::vec2 position;
	unsigned int textureID = 0;
	gengine::ColorRGBA8 color;
	Cell* ownerCell = nullptr;
	int cellVectorIndex = -1;
};

