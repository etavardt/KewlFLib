#pragma once

#include <glm/glm.hpp>
namespace Kewl
{
	namespace OpenGL
	{

		struct Vertex
		{
			glm::vec3 position;
			glm::vec4 color;
			glm::vec2 texCoords;
			float texID;
			float mvpID;
		};
	} // namespace OpenGL
} // namespace Kewl