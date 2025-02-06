#shader vertex
#version 330 core
layout (location = 0) in vec3 FragmentPos;
layout (location = 1) in vec3 NormalVector;
layout (location = 2) in vec2 TexturePos;
out vec2 TexPos;
out vec3 FragPosition;
out vec3 NormalVec;
uniform mat3 NormalMatrix;
uniform mat4 Model;
uniform mat4 View;
uniform mat4 Perspective;
uniform mat3 Scale;
void main()
{
    //vec3 FP = Scale * FragmentPos;
    gl_Position = Perspective * View * Model * vec4(FragmentPos, 1.0f);
    FragPosition = vec3(Model * vec4(FragmentPos, 1.0f));
    NormalVec = NormalMatrix * NormalVector;
    TexPos = TexturePos;
}
#shader fragment 
#version 330 core
vec3 CalculateDirectionalLightOutput(vec3 Normal, vec3 ViewDirection, vec3 DiffuseMap, vec3 SpecularMap);
vec3 CalculatePointLightOutput(vec3 Normal, vec3 ViewDirection, vec3 DiffuseMap, vec3 SpecularMap, int tag);
vec3 CalculateSpotlightOutput(vec3 Normal, vec3 ViewDirection, vec3 DiffuseMap, vec3 SpecularMap);
struct DirectionalLightStats
{
    vec3 Direction;
    vec3 Ambient;
    vec3 Diffuse;
    vec3 Specular;
};
struct PointLightStats
{
    vec3 Position;
    vec3 Ambient;
    vec3 Diffuse;
    vec3 Specular;
    float Constant;
    float Linear;
    float Quadratic;
};
struct SpotlightStats
{
    vec3 Direction;
    vec3 Position;
    vec3 Color;
    vec3 Ambient;
    vec3 Diffuse;
    vec3 Specular;
    float Constant;
    float Linear;
    float Quadratic;
    float InnerCutoff;
    float OuterCutoff;
};
struct MaterialStats
{
    float Ambient;
    sampler2D Diffuse;
    sampler2D Specular;
    float Shininess;
};
in vec2 TexPos;
in vec3 FragPosition;
in vec3 NormalVec;
out vec4 FinalColor;
int FirstPointLight = 0;
uniform int PointLightNum;
uniform vec3 ViewPosition;
uniform SpotlightStats Spotlight;
uniform PointLightStats PointLight[10];
uniform DirectionalLightStats DirectionalLight;
uniform MaterialStats Material;
void main()
{
    vec3 NormalUnitVec = normalize(NormalVec);
    vec3 ViewDirection = normalize(ViewPosition - FragPosition);
    vec3 DiffuseMap = vec3(texture(Material.Diffuse, TexPos));
    vec3 SpecularMap = vec3(texture(Material.Specular, TexPos));
    vec3 Output = CalculateDirectionalLightOutput(NormalUnitVec, ViewDirection, DiffuseMap, SpecularMap);
    /*for(int i = 0; i < PointLightNum; ++i)
    {
        Output += CalculatePointLightOutput(NormalUnitVec, ViewDirection, DiffuseMap, SpecularMap, i);
    }*/
    Output += CalculateSpotlightOutput(NormalUnitVec, ViewDirection, DiffuseMap, SpecularMap);
    FinalColor = vec4(Output, 1.0f);
    float gamma = 2.2f;
    FinalColor.rgb = pow(FinalColor.rgb, vec3(1.0f/gamma));
}

vec3 CalculateDirectionalLightOutput(vec3 Normal, vec3 ViewDirection, vec3 DiffuseMap, vec3 SpecularMap)
{
    vec3 LightDirection = normalize(-DirectionalLight.Direction);
    vec3 ReflectDirection = normalize(ViewDirection + LightDirection);

    vec3 AmbientLighting = Material.Ambient * DiffuseMap * DirectionalLight.Ambient;
    float DiffuseStrength = max(dot(LightDirection, Normal), 0.0f);
    vec3 DiffuseLighting = DiffuseStrength * DiffuseMap * DirectionalLight.Diffuse;
    float SpecularStrength = pow(max(dot(Normal, ReflectDirection), 0.0f), Material.Shininess);
    vec3 SpecularLighting = SpecularStrength * SpecularMap * DirectionalLight.Specular;
    return (AmbientLighting + DiffuseLighting + SpecularLighting);
}

vec3 CalculatePointLightOutput(vec3 Normal, vec3 ViewDirection, vec3 DiffuseMap, vec3 SpecularMap, int tag)
{
    vec3 LightDirection = normalize(PointLight[tag].Position - FragPosition);
    vec3 ReflectDirection = normalize(ViewDirection + LightDirection);
    float LightDistance = length(PointLight[tag].Position - FragPosition);
    //float Attenuation = 1.0f / (PointLight[tag].Constant + PointLight[tag].Linear * LightDistance + PointLight[tag].Quadratic * (LightDistance * LightDistance));
    float Attenuation = 1.0f / LightDistance;

    vec3 AmbientLighting = Material.Ambient * DiffuseMap * PointLight[tag].Ambient;
    AmbientLighting *= Attenuation;
    float DiffuseStrength = max(dot(LightDirection, Normal), 0.0f);
    vec3 DiffuseLighting = DiffuseStrength * DiffuseMap * PointLight[tag].Diffuse;
    DiffuseLighting *= Attenuation;
    float SpecularStrength = pow(max(dot(Normal, ReflectDirection), 0.0f), Material.Shininess);
    vec3 SpecularLighting = SpecularStrength * SpecularMap * PointLight[tag].Specular;
    SpecularLighting *= Attenuation;
    return (AmbientLighting + DiffuseLighting + SpecularLighting);
}

vec3 CalculateSpotlightOutput(vec3 Normal, vec3 ViewDirection, vec3 DiffuseMap, vec3 SpecularMap)
{
    vec3 LightDirection = normalize(Spotlight.Position - FragPosition);
    vec3 ReflectDirection = normalize(ViewDirection + LightDirection);
    float LightDistance = length(Spotlight.Position - FragPosition);
    //float Attenuation = 1.0f / (Spotlight.Constant + Spotlight.Linear * LightDistance + Spotlight.Quadratic * (LightDistance * LightDistance));
    float Attenuation = 1.0f / LightDistance;
    float Theta = dot(LightDirection, normalize(-Spotlight.Direction));
    float Epsilon = Spotlight.InnerCutoff - Spotlight.OuterCutoff;
    float Intensity = clamp((Theta - Spotlight.OuterCutoff) / Epsilon, 0.0f, 1.0f);

    vec3 AmbientLighting =  Material.Ambient * DiffuseMap * Spotlight.Ambient;
    AmbientLighting *= Attenuation;
    float DiffuseStrength = max(dot(LightDirection, Normal), 0.0f);
    vec3 DiffuseLighting = DiffuseStrength * DiffuseMap * Spotlight.Diffuse;
    DiffuseLighting *= Attenuation;
    DiffuseLighting *= Intensity;
    float SpecularStrength = pow(max(dot(Normal, ReflectDirection), 0.0f), Material.Shininess);
    vec3 SpecularLighting = SpecularStrength * SpecularMap * Spotlight.Specular;
    SpecularLighting *= Attenuation;
    SpecularLighting *= Intensity;
    return (AmbientLighting + DiffuseLighting + SpecularLighting);
}