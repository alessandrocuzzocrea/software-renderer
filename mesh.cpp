#include <iostream>
#include <fstream>
#include <SDL.h>
#include <glm/glm.hpp>
#include <vector>
#include "mesh.h"

Mesh::Mesh() {}

Mesh::~Mesh() {}

void Mesh::addVert(float x, float y, float z) {
	
	vertices.push_back(glm::vec3(x, y, z));
}

void Mesh::addFace(int a, int b, int c) {
	
	faces.push_back(Face(a, b, c));
}

glm::vec3 Mesh::getVertCoord(int id) {

	return vertices[id];

}