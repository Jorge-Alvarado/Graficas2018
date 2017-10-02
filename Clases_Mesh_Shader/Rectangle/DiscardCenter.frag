#version 330

in vec3 InterpolatedColor;

//Resolucion de la ventana en pixeles
uniform vec2 Resolution;


out vec4 FragColor;

void main(){

	
	//vec2 resolution = vec2(600.0f,600.0f);
	//Es la posicion del pixel en la ventana en un rango de [(0,0),(1,1)]
	vec2 p = gl_FragCoord.xy / Resolution;
	//Calculando un vector que val del pixel al centro de la ventana
	vec2 q = p - vec2(0.5f,0.5f);
	//Si el vector q tiene una medida menor a 0.25, descartamos el pixel
	if(length(q) < 0.25f)
		discard;


	FragColor = vec4(InterpolatedColor, 1.0f);
}