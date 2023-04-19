#version 430

in vec3 oColor;
out vec4 color;

void main() {
    color = vec4(oColor.x, oColor.y, oColor.z, 1.0);
}