#version 150

uniform int doFlat;

flat in vec3 lightIntensityFlat;
in vec3 lightIntensitySmooth;

out vec4 colorOut;

void main() {

	if(doFlat == 1)
		colorOut = vec4(lightIntensityFlat, 1.0);
	else
		colorOut = vec4(lightIntensitySmooth, 1.0);
}
