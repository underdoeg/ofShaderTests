#version 150

uniform mat4 modelViewProjectionMatrix;
uniform mat4 modelViewMatrix;
uniform mat3 normalMatrix;
uniform vec3 lightPos;
uniform vec3 lightColor;
uniform int doFlat;

in vec4 position;
in vec3 normalSmooth;
flat in vec3 normalFlat;

out vec4 colorOut;

void main() {
	
	vec3 nn = normalize(normalMatrix * normalSmooth);
	if(doFlat == 1){
		nn = normalize(normalMatrix * normalFlat);
	}
	
	vec3 eyePos = vec3(modelViewMatrix * position);
	vec3 s = normalize(lightPos - eyePos);

	vec3 lightIntensity = lightColor * max( dot( s, nn ), 0.0 );

	colorOut = vec4(lightIntensity, 1.0);
	//colorOut = vec4(normalOut, 1.);
}
