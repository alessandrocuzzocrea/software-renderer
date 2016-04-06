#include <iostream>
#include <fstream>
#include <SDL.h>
#include <glm/glm.hpp>
#include <vector>
#include "mesh.h"
#include "camera.h"
#include "renderer.h"

int main(int argc, char *argv[]){

	int w = 320;
	int h = 240;

	SDL_Window* window = NULL;
	window = SDL_CreateWindow
	(
		"SoftwareRenderer", 
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		w,
		h,
		SDL_WINDOW_SHOWN
	);
	
	Renderer* r = new Renderer(window, w, h);

	Mesh* mesh = new Mesh();
	
	mesh->addVert(-1, 1, 1);	//vert0
	mesh->addVert(1, 1, 1);		//vert1
	mesh->addVert(-1, -1, 1);	//vert2
	mesh->addVert(1, -1, 1);	//vert3
	mesh->addVert(-1, 1, -1);	//vert4
	mesh->addVert(1, 1, -1);	//vert5
	mesh->addVert(1, -1, -1);	//vert6
	mesh->addVert(-1, -1, -1);	//vert7
		
	mesh->addFace(0, 1, 2);		//face0
	mesh->addFace(1, 2, 3);		//face1
	mesh->addFace(1, 3, 6);		//face2
	mesh->addFace(1, 5, 6);		//face3
	mesh->addFace(0, 1, 4);		//face4
	mesh->addFace(1, 4, 5);		//face5
	
	mesh->addFace(2, 3, 7);		//face6
	mesh->addFace(3, 6, 7);		//face7
	mesh->addFace(0, 2, 7);		//face8
	mesh->addFace(0, 4, 7);		//face9
	mesh->addFace(4, 5, 6);		//face10
	mesh->addFace(4, 6, 7);		//face11


	Camera* camera = new Camera();
	camera->Position = glm::vec3(0, 0, 10);
	camera->Target   = glm::vec3(0, 0, 0);

	SDL_Event event;

	bool quit = false;

	const int FPS = 60;
	Uint32 start;

	while (!quit)
	{
		start = SDL_GetTicks();
		const Uint8 *state = SDL_GetKeyboardState(NULL);

		while (SDL_PollEvent(&event))
		{

			if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
			{
				quit = true;
			}			
		}		

		mesh->rotation.x += 0.02f;
		mesh->rotation.y += 0.01f;

		r->clear();
		r->render(camera, mesh);

		r->present();

		if (1000 / FPS > SDL_GetTicks() - start) {
			SDL_Delay(1000 / FPS - (SDL_GetTicks() - start));
		}
	}

	delete camera;
	delete mesh;
	delete r;
	SDL_DestroyWindow(window);
	SDL_Quit();
	
   return 0;
}
