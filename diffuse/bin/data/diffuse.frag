#version 150

uniform vec3 lightPos;
uniform vec3 lightColor;
uniform int doFlat;

flat in vec3 NFlat;
in vec3 NSmooth;
in vec3 v;

out vec4 colorOut;

void main() {
	vec3 L = normalize(lightPos - v);
	vec3 N = NSmooth;

	if(doFlat == 1)
		N = NFlat;

	vec3 Idiff = lightColor * max(dot(N,L), 0.0);
	Idiff = clamp(Idiff, 0.0, 1.0);
	colorOut = vec4(Idiff[0], Idiff[1], Idiff[2], 1.0);
}
