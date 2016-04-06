#ifndef RENDERER_H
#define RENDERER_H

#include <SDL.h>
#include <glm/glm.hpp>
#include "camera.h"
#include "mesh.h"

class Renderer
{
public:
	Renderer(SDL_Window* window, int width, int height);
	~Renderer();

	void clear();
	void present();
	glm::vec2 project(glm::vec3 vert, glm::mat4 transformMat);
	void render(Camera* camera, Mesh* mesh);

	SDL_Renderer* sdlRenderer;
	int width;
	int height;

private:

};

#endif /* RENDERER_H */