#shader vertex
#version 330
layout (location = 0) in vec3 GraphicCoordinates;
uniform mat4 model;
uniform mat4 view;
uniform mat4 perspective;
void main()
{
    gl_Position = perspective * view * model * vec4(GraphicCoordinates, 1.0f);
}
#shader fragment
#version 330
out vec4 FragmentColor;
uniform vec3 LightColor;
void main()
{
    FragmentColor = vec4(LightColor, 1.0f);
}