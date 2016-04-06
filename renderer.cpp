#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>
#include "renderer.h"

Renderer::Renderer(SDL_Window* window, int width, int height) {

	sdlRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	this->width = width;
	this->height = height;
}

Renderer::~Renderer() {}

void Renderer::clear() {

	SDL_SetRenderDrawColor(this->sdlRenderer, 1, 1, 1, 255);
	SDL_RenderClear(this->sdlRenderer);
}

void Renderer::present() {

	SDL_RenderPresent(sdlRenderer);
}

glm::vec2 Renderer::project(glm::vec3 vert, glm::mat4 transformMat) {

	glm::vec4 pointClipped = transformMat * glm::vec4(vert, 1.0f);

	glm::vec3 pointNormalized = glm::vec3(pointClipped.x / pointClipped.w, pointClipped.y / pointClipped.w, pointClipped.z / pointClipped.w);

	int x = pointNormalized.x * this->width + this->width / 2;
	int y = -pointNormalized.y * this->height + this->height / 2;
	float z = pointNormalized.z;

	return glm::vec2(x, y);
}

void Renderer::render(Camera * camera, Mesh * mesh) {

	glm::mat4 viewMat = glm::lookAtLH(camera->Position, camera->Target, glm::vec3(0, 1, 0));
	glm::mat4 projMat = glm::perspectiveFovLH(glm::radians(45.0f), (float)this->width, (float)this->height, 0.01f, 10.0f);

	glm::mat4 rotMat = glm::yawPitchRoll(mesh->rotation.y, mesh->rotation.x, mesh->rotation.z);

	glm::mat4 modelMat = rotMat;
	glm::mat4 modelViewProjMat = projMat * viewMat *  modelMat;
	
	SDL_SetRenderDrawColor(sdlRenderer, 255, 255, 255, 255);

	for (size_t indexFaces = 0; indexFaces < mesh->faces.size(); indexFaces++) {

			Face currFace = mesh->faces[indexFaces];

			glm::vec3 vert1 = mesh->getVertCoord(currFace.vertA);
			glm::vec3 vert2 = mesh->getVertCoord(currFace.vertB);
			glm::vec3 vert3 = mesh->getVertCoord(currFace.vertC);

			glm::vec2 point1 = this->project(vert1, modelViewProjMat);
			glm::vec2 point2 = this->project(vert2, modelViewProjMat);
			glm::vec2 point3 = this->project(vert3, modelViewProjMat);

			SDL_RenderDrawLine(this->sdlRenderer, point1.x, point1.y, point2.x, point2.y);
			SDL_RenderDrawLine(this->sdlRenderer, point2.x, point2.y, point3.x, point3.y);
			SDL_RenderDrawLine(this->sdlRenderer, point3.x, point3.y, point1.x, point1.y);
	}	

}