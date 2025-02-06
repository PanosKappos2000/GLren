#include "Shader.h"

//Static variable declarations
Shader* Shader::s_rotatingCubeShader;
Shader* Shader::s_lightCubeShader;
Shader* Shader::s_meshShader;
Shader* Shader::s_vegetationShader;

Shader::Shader(std::string& shaderFilepath)
{
	std::ifstream file(shaderFilepath);
	std::string line;
	std::string shaderSource[2];
	ShaderType type;
	while (getline(file, line))
	{
		if (line.find("#shader") != std::string::npos)
		{
			if (line.find("vertex") != std::string::npos)
				type = ShaderType::ST_Vertex;
			else if (line.find("fragment") != std::string::npos)
				type = ShaderType::ST_Fragment;
		}
		else
		{
			shaderSource[static_cast<int>(type)] += line;
			shaderSource[static_cast<int>(type)] += '\n';
		}
	}

	const char* vertexShaderSource = (shaderSource[static_cast<int>(ShaderType::ST_Vertex)]).c_str();
	unsigned int vertexShaderTag = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShaderTag, 1, &vertexShaderSource, nullptr);
	glCompileShader(vertexShaderTag);
	
	int success;
	glGetShaderiv(vertexShaderTag, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		char infoLog[512];
		glGetShaderInfoLog(vertexShaderTag, 512, nullptr, infoLog);
		std::cout << "OPENGL::SHADER::VERTEX::COMPILATION_FAILED: " << infoLog << '\n';
		__debugbreak();
	}

	const char* fragmentShaderSource = (shaderSource[static_cast<int>(ShaderType::ST_Fragment)]).c_str();
	unsigned int fragmentShaderTag = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShaderTag, 1, &fragmentShaderSource, nullptr);
	glCompileShader(fragmentShaderTag);

	glGetShaderiv(fragmentShaderTag, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		char infoLog[512];
		glGetShaderInfoLog(fragmentShaderTag, 512, nullptr, infoLog);
		std::cout << "OPENGL::SHADER::FRAGMENT::COMPILATION_FAILED: " << infoLog << '\n';
		__debugbreak();
	}

	m_tag = glCreateProgram();
	glAttachShader(m_tag, vertexShaderTag);
	glAttachShader(m_tag, fragmentShaderTag);
	glLinkProgram(m_tag);

	glGetProgramiv(m_tag, GL_LINK_STATUS, &success);
	if (!success)
	{
		char infoLog[512];
		glGetProgramInfoLog(m_tag, 512, nullptr, infoLog);
		std::cout << "OPENGL::SHADER::PROGRAM::LINKER_FAILED: " << infoLog << '\n';
		__debugbreak();
	}

	glDeleteProgram(vertexShaderTag);
	glDeleteProgram(fragmentShaderTag);
}

Shader::~Shader()
{
	glDeleteShader(m_tag);
}

void Shader::Init()
{
	CreateRotatingCubeShader();
	CreateLightCubeShader();
	CreateMeshShader();
	CreateVegetationShader();
}

void Shader::DeInit()
{
	delete s_rotatingCubeShader;
	delete s_lightCubeShader;
	delete s_meshShader;
	delete s_vegetationShader;
}

void Shader::CreateRotatingCubeShader()
{
	if (!s_rotatingCubeShader)
	{
		std::string cubeFilepath(ROTATING_CUBE_SHADER_FILEPATH);
		s_rotatingCubeShader = new Shader(cubeFilepath);
	}
}

void Shader::CreateLightCubeShader()
{
	if (!s_lightCubeShader)
	{
		std::string cubeFilepath(LIGHT_CUBE_SHADER_FILEPATH);
		s_lightCubeShader = new Shader(cubeFilepath);
	}
}

void Shader::CreateMeshShader()
{
	if (!s_meshShader)
	{
		std::string filepath(MESH_SHADER_FILEPATH);
		s_meshShader = new Shader(filepath);
	}
}

void Shader::CreateVegetationShader()
{
	if (!s_vegetationShader)
	{
		std::string filepath(VEGETATION_SHADER_FILEPATH);
		s_vegetationShader = new Shader(filepath);
	}
}