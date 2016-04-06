#ifndef MESH_H
#define MESH_H

//#include <iostream>
//#include <fstream>
//#include <SDL.h>
#include <glm/glm.hpp>
#include <vector>

struct Face {
	int vertA;
	int vertB;
	int vertC;

	Face(int a, int b, int c) {	
		vertA = a;
		vertB = b;
		vertC = c;
	}
};

class Mesh {

public:
	Mesh();
	~Mesh();

	void addVert(float x, float y, float z);
	void addFace(int a, int b, int c);
	glm::vec3 getVertCoord(int id);

	glm::vec3 position;
	glm::vec3 rotation;
	std::vector<glm::vec3> vertices;
	std::vector<Face> faces;

private:

};

#endif /* MESH_H */