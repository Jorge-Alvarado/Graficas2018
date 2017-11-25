#version 400
in vec3 VertexPosition;
uniform mat4 mvpMatrix;

void main(){
	gl_Position=mvpMatrix * vec4(VertexPosition, 1.0f);
}