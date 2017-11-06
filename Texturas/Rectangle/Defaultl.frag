#version 400

in vec3 InterpolatedColor;
in vec3 InterpolatedNormal;
in vec3 PixelPosition;
in vec2 InterpolatedTexCoord;

out vec4 FragColor;

uniform sampler2D DiffuseTexture;
uniform mat4 mvpMatrix;
uniform mat3 nMatrix;
uniform vec3 lightPosition;
uniform vec3 lightColor;
uniform vec3 CameraPosition;

void main()
{
vec3 L = normalize(lightPosition - PixelPosition);
vec3 R = reflect(-L,InterpolatedNormal);
vec3 V = normalize(CameraPosition - PixelPosition);
float comp = max(dot(V,R),0.0f);

vec3 ambient = 0.1f * lightColor;

vec3 diffuse = dot(InterpolatedNormal,L) * lightColor;

vec3 specular = pow(comp,32.0f) * lightColor;

vec3 phong = (ambient + diffuse + specular) * InterpolatedColor;
FragColor = texture2D(DiffuseTexture,InterpolatedTexCoord);
FragColor = vec4(phong, 1.0f);
//FragColor = vec4(InterpolatedColor, 1.0f);

}






