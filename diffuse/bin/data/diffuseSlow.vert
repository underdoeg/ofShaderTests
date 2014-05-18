#version 150

uniform mat4 modelViewProjectionMatrix;
uniform mat4 modelViewMatrix;

out vec4 position;
out vec3 normalSmooth;
flat out vec3 normalFlat;

in vec4 positionIn;
in vec3 normal;

void main(void) {
	
	//eyePos = vec3(modelViewMatrix * positionIn);
	
	position = positionIn;
	normalSmooth = normal;
	normalFlat = normal;
	
	// Convert position to clip coordinates and pass along
	gl_Position = modelViewProjectionMatrix * position;
}
