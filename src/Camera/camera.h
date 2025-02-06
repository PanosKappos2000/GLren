#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Window/window.h"

#define CAMERA_BASE_SPEED			1.f
#define CAMERA_BASE_SENSITIVITY		0.1f

enum class CameraMovement : uint8_t
{
	Forward = 0,
	Backward = 1,
	Right = 2,
	Left = 3,

	None = 4
};

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

	static Camera* s_pCamera;

public:

	CameraMovement movement = CameraMovement::None;

public:
	Camera(float speed = CAMERA_BASE_SPEED, float sensitivity = CAMERA_BASE_SENSITIVITY);
	~Camera();

	inline const glm::vec3& GetPosition() const { return m_pos; }
	inline const glm::vec3& GetDirection() const { return m_dir; }
	inline const glm::vec3& GetUpVector() const { return m_up; }

	inline const glm::mat4& GetLookAt() const { return m_lookAt; }

	inline const glm::mat4& GetPerspective() const { return m_perspective; }
	inline void UpdatePerspective() {
		m_perspective = glm::perspective(glm::radians(65.0f),
		float(GetWindowWidth()) / float(GetWindowHeight()), 0.1f, 100.0f);
	}

	void MoveForward(float deltatime);
	void MoveBackward(float deltatime);
	void MoveRight(float deltatime);
	void MoveLeft(float deltatime);
	void Rotate(float xPos, float yPos);

	inline static Camera* GetCamera() {return s_pCamera;}

	void Update();
};