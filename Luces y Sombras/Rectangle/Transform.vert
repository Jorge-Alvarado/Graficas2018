#version 400

in vec3 VertexPosition;
in vec3 VertexColor;
in vec3 VertexNormal;

out vec3 InterpolatedColor;
out vec3 InterpolatedNormal;
out vec3 PixelPosition;

uniform mat4 mvpMatrix;
uniform mat3 nMatrix;
uniform mat4 ModelMatrix;
void main()
{
InterpolatedColor = VertexColor;
//InterpolatedNormal = vec3(nMatrix * vec4(VertexNormal,1.0f));

InterpolatedNormal = nMatrix * VertexNormal;

PixelPosition = vec3(ModelMatrix * vec4(VertexPosition,1.0f));

gl_Position = mvpMatrix * vec4(VertexPosition, 1.0f);
}


