#shader vertex
#version 330 core

layout (location = 0) in vec3 FragmentPos;
layout (location = 1) in vec3 NormalVector;
layout (location = 2) in vec2 TexCoordinates;

out vec2 TexPos;
out vec3 FragPos;
out vec3 Normals;

uniform mat3 NormalMatrix;
uniform mat4 Model;
uniform mat4 View;
uniform mat4 Perspective;

void main()
{
    TexPos = TexCoordinates;
    FragPos = vec3(Model * vec4(FragmentPos, 1.0f));
    Normals = NormalVector;

    gl_Position = Perspective * View * Model * vec4(FragmentPos, 1.0f);
}

#shader fragment
#version 330 core

vec3 CalculateDirectionalLightOutput(vec3 UV_Normal, vec3 DiffuseTexture, vec3 SpecularTexture, vec3 UV_ViewPos);

struct MaterialStats
{
    sampler2D DiffuseTex;
    sampler2D SpecularTex;

    float Shininess;
};

struct DirectionalLightStats
{
    vec3 Direction;

    vec3 Ambient;
    vec3 Diffuse;
    vec3 Specular;
};

in vec2 TexPos;
in vec3 FragPos;
in vec3 Normals;

out vec4 FragmentColor;

uniform vec3 CamPos;
uniform DirectionalLightStats DirectionalLight;
uniform MaterialStats Material;

void main()
{
    vec4 DiffuseTexture = vec4(texture(Material.DiffuseTex, TexPos));
    vec4 SpecularTexture = vec4(texture(Material.SpecularTex, TexPos));
    vec3 UV_Normal = normalize(Normals);
    vec3 UV_ViewPosition = normalize(CamPos - FragPos);

    vec3 Output = CalculateDirectionalLightOutput(UV_Normal, vec3(DiffuseTexture), vec3(SpecularTexture), UV_ViewPosition);
    FragmentColor = vec4(Output, DiffuseTexture.a);
}


vec3 CalculateDirectionalLightOutput(vec3 UV_Normal, vec3 DiffuseTexture, vec3 SpecularTexture, vec3 UV_ViewPos)
{
    vec3 UV_LightDirection = normalize(DirectionalLight.Direction);
    vec3 ReflectDirection = reflect(-UV_LightDirection, UV_Normal);

    vec3 AmbientLighting = 0.2f * DirectionalLight.Ambient;
    float DiffuseStrength = max(dot(UV_Normal, UV_LightDirection), 0.0f);
    vec3 DiffuseLighting = DiffuseStrength * DirectionalLight.Diffuse * DiffuseTexture;
    float SpecularStrength = pow(max(dot(ReflectDirection, UV_ViewPos), 0.0f), 32);
    vec3 SpecularLighting = SpecularStrength * DirectionalLight.Specular * SpecularTexture;

    return (AmbientLighting + DiffuseLighting);
} 