#shader vertex
#version 330 core

layout (location = 0) in vec3 FragmentPos;
layout (location = 1) in vec3 NormalVec;
layout (location = 2) in vec2 TexCoordinates;

out vec2 TexPos;
out vec3 Normal;

uniform mat4 Model;
uniform mat4 View;
uniform mat4 Perspective;

void main()
{
    Normal = NormalVec;
    TexPos = TexCoordinates;

    gl_Position = Perspective * View * Model * vec4(FragmentPos, 1.0f);
}

#shader fragment
#version 330 core

struct MaterialStats
{
    sampler2D DiffuseTex[12];
    sampler2D SpecularTex[12];
    sampler2D NormalTex[12];
    sampler2D HeightTex[12];

    int DiffuseTexNum;
    int SpecularTexNum;
    int NormalTexNum;
    int HeightTexNum;
};

in vec2 TexPos;

out vec4 FragmentColor;

uniform MaterialStats Material;

void main()
{
    vec3 tex = vec3(0.0f, 0.0f, 0.0f);
    for(int i = 0; i < Material.DiffuseTexNum; ++i)
    {
        tex += vec3(texture(Material.DiffuseTex[i], TexPos));
    }
    for(int i = 0; i < Material.SpecularTexNum; ++i)
    {
        //tex += vec3(texture(Material.SpecularTex[i], TexPos));
    }
    for(int i = 0; i < Material.NormalTexNum; ++i)
    {
        //tex += vec3(texture(Material.NormalTex[i], TexPos));
    }
    for(int i = 0; i < Material.HeightTexNum; ++i)
    {
        //tex += vec3(texture(Material.HeightTex[i], TexPos));
    }
    FragmentColor = texture(Material.DiffuseTex[0], TexPos);
}