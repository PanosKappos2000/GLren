#pragma once

#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Texture
{
private:
	unsigned int m_tag;
public:
	Texture(const char* textureFilepath);

	inline unsigned int GetTag() const { return m_tag; }
};

unsigned int TextureFromFile(const std::string& filepath);


class TextureHolder
{

};