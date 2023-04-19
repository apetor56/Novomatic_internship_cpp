#version 430

layout(location = 0) in vec2 iPosition;
layout(location = 1) in vec3 iColor;

out vec3 oColor;
uniform mat4 transform = mat4(1.0, 0.0, 0.0, 0.0,
                              0.0, 1.0, 0.0, 0.0,
                              0.0, 0.0, 1.0, 0.0,
                              0.0, 0.0, 0.0, 1.0);

void main() {
    gl_Position = transform * vec4(iPosition.x, iPosition.y, 0.0, 1.0);
    oColor = iColor;
}