#version 150

uniform mat4 modelViewProjectionMatrix;
uniform mat4 modelViewMatrix;
uniform mat3 normalMatrix;
uniform vec3 lightPos;
uniform vec3 lightColor;

flat out vec3 lightIntensityFlat;
out vec3 lightIntensitySmooth;

in vec4 position;
in vec3 normal;

void main(void) {
	//mat3 normalMat = transpose(inverse(mat3(modelViewMatrix)));

	vec3 nn = normalize(normalMatrix * normal);
	vec3 eyePos = vec3(modelViewMatrix * position);
	vec3 s = normalize(lightPos - eyePos);

	// The diffuse shading equation
	lightIntensityFlat = lightColor * max( dot( s, nn ), 0.0 );
	lightIntensitySmooth = lightIntensityFlat;

	// Convert position to clip coordinates and pass along
	gl_Position = modelViewProjectionMatrix * position;
}
