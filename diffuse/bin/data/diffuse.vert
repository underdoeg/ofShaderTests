#version 150

uniform mat4 modelViewProjectionMatrix;
uniform mat4 modelViewMatrix;

flat out vec3 NFlat;
out vec3 NSmooth;
out vec3 v;

in vec4 position;
in vec3 normal;

void main(void) {
	vec4 vt = modelViewMatrix * position;
	v = vec3(vt[0], vt[1], vt[2]);
	NFlat = normal;
	NSmooth = normal;
	gl_Position = modelViewProjectionMatrix * position;
}
