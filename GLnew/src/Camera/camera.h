#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#define CAMERA_BASE_SPEED			10.0f
#define CAMERA_BASE_SENSITIVITY		0.1f

class Camera
{
private:
	glm::vec3 m_pos;
	glm::vec3 m_dir;
	glm::vec3 m_up;

	glm::mat4 m_lookAt;
	glm::mat4 m_perspective;

	float m_speed;
	float m_sensitivity;

	float m_previousXpos;
	float m_previousYpos;
	float m_yaw;
	float m_pitch;
public:
	Camera(float speed = CAMERA_BASE_SPEED, float sensitivity = CAMERA_BASE_SENSITIVITY);
	~Camera();

	inline const glm::vec3& GetPosition() const { return m_pos; }
	inline const glm::vec3& GetDirection() const { return m_dir; }
	inline const glm::vec3& GetUpVector() const { return m_up; }

	inline const glm::mat4& GetLookAt() const { return m_lookAt; }
	inline const glm::mat4& GetPerspective() const { return m_perspective; }

	void MoveForward(float deltatime);
	void MoveBackward(float deltatime);
	void MoveRight(float deltatime);
	void MoveLeft(float deltatime);
	void Rotate(float xPos, float yPos);
};