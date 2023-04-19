#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include "Buffer.hpp"
#include "VertexArray.hpp"
#include "Shader.hpp"
#include <vector>
#include <windows.h>

// static const char *vertexPath = "./task1/shaders/vertex.glsl";
// static const char *fragmentPath = "./task1/shaders/fragment.glsl";

static std::string shaderPath(std::string shader) {
    char buffer[256];
	GetModuleFileNameA(NULL, buffer, 256);
	std::string::size_type pos = std::string(buffer).find_last_of("\\/");
	return std::string(buffer).substr(0, pos - 3) + "shaders\\" + shader;
}

struct Graphics {
    Graphics() :
        vertexShader(GL_VERTEX_SHADER, shaderPath("vertex.glsl").c_str()),
        fragmentShader(GL_FRAGMENT_SHADER, shaderPath("fragment.glsl").c_str()),
        program(Shader::createProgramShader(vertexShader, fragmentShader))
    {}

    Buffer<GL_ARRAY_BUFFER, float> vbo;
    Buffer<GL_ELEMENT_ARRAY_BUFFER, unsigned int> ebo;
    VertexArray vao;
    Shader vertexShader;
    Shader fragmentShader;
    unsigned int program;
    std::vector<float> vertices;
    std::vector<unsigned int> indices;
};

#endif // GRAPHICS_HPP