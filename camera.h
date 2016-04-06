#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>

class Camera
{
public:
	Camera();
	~Camera();

	glm::vec3 Position;
	glm::vec3 Target;

private:

};

#endif /* CAMERA_H */