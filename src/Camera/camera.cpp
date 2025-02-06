#include "camera.h"
#include "Window/window.h"

Camera* Camera::s_pCamera;

Camera::Camera(float speed, float sensitivity)
	:m_speed(speed), m_sensitivity(sensitivity), m_lookAt(1.0f), 
	m_pos(0.0f, 0.0f, 5.0f), m_dir(0.0f, 0.0f, -1.0f), m_up(0.0f, 1.0f, 0.0f),
	m_previousXpos(0.0f), m_previousYpos(0.0f), m_yaw(0.0f), m_pitch(0.0f)
{
	m_lookAt = glm::lookAt(m_pos, m_pos + m_dir, m_up);
	m_perspective = glm::perspective(glm::radians(80.0f),
	float(GetWindowWidth()) / float(GetWindowHeight()), 0.1f, 100.0f);

	s_pCamera = this;
}

Camera::~Camera()
{

}

void Camera::MoveForward(float deltatime)
{
	m_pos += m_dir * m_speed * deltatime;
	m_lookAt = glm::lookAt(m_pos, m_pos + m_dir, m_up);
}

void Camera::MoveBackward(float deltatime)
{
	m_pos -= m_dir * m_speed * deltatime;
	m_lookAt = glm::lookAt(m_pos, m_pos + m_dir, m_up);
}

void Camera::MoveRight(float deltatime)
{
	m_pos += glm::normalize(glm::cross(m_dir, m_up)) * m_speed * deltatime;
	m_lookAt = glm::lookAt(m_pos, m_pos + m_dir, m_up);
}

void Camera::MoveLeft(float deltatime)
{
	m_pos -= glm::normalize(glm::cross(m_dir, m_up)) * m_speed * deltatime;
	m_lookAt = glm::lookAt(m_pos, m_pos + m_dir, m_up);
}

void Camera::Rotate(float xPos, float yPos)
{
	xPos *= m_sensitivity;
	yPos *= m_sensitivity;

	if (xPos > 100.f || xPos < -100.f)
		xPos = 0.f;
	
	if (yPos > 100.f || yPos < -100.f)
		yPos = 0.f;

	if (m_pitch + yPos > 89.0f)
		m_pitch = 89.0f;
	else if (m_pitch + yPos < -89.0f)
		m_pitch = -89.0f;
	else
		m_pitch -= yPos;

	m_yaw += xPos;

	glm::vec3 direction;
	direction.x = cos(glm::radians(m_pitch)) * cos(glm::radians(m_yaw));
	direction.y = sin(glm::radians(m_pitch));
	direction.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
	m_dir = direction;
	m_lookAt = glm::lookAt(m_pos, m_pos + m_dir, m_up);
}

void Camera::Update()
{
	switch (movement)
	{
		case CameraMovement::Forward:
		{
			MoveForward(GetDeltaTime());
			break;
		}

		case CameraMovement::Backward:
		{
			MoveBackward(GetDeltaTime());
			break;
		}

		case CameraMovement::Right:
		{
			MoveRight(GetDeltaTime());
			break;
		}

		case CameraMovement::Left:
		{
			MoveLeft(GetDeltaTime());
			break;
		}

		case CameraMovement::None:
		{
			break;
		}
	}
}