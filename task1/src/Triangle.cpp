#include "Triangle.hpp"
#include "AttributeLayout.hpp"
#include <cmath>

Triangle::Triangle(glm::vec2& v1, glm::vec2& v2, glm::vec2& v3) {
    static glm::mat4 proj = glm::ortho(0.0f, 1080.0f, 0.0f, 720.0f, 0.1f, 100.0f);
    m_position = {v1, v2, v3};
    m_beginPos = {v1, v2, v3};

    glm::vec4 vec1 = proj * glm::vec4(v1.x, v1.y, 0.0f, 1.0f);
    glm::vec4 vec2 = proj * glm::vec4(v2.x, v2.y, 0.0f, 1.0f);
    glm::vec4 vec3 = proj * glm::vec4(v3.x, v3.y, 0.0f, 1.0f);

    m_graphics.vertices = { vec1.x, vec1.y, m_color.x, m_color.y, m_color.z,
                            vec2.x, vec2.y, m_color.x, m_color.y, m_color.z,
                            vec3.x, vec3.y, m_color.x, m_color.y, m_color.z };

    m_graphics.indices = {0, 1, 2};

    m_graphics.vao.bind();

    m_graphics.vbo.bind();
    m_graphics.vbo.setData(m_graphics.vertices.data(), m_graphics.vertices.size() * sizeof(float));

    m_graphics.ebo.bind();
    m_graphics.ebo.setData(m_graphics.indices.data(), m_graphics.indices.size() * sizeof(unsigned int));

    static AttributeLayout<float> layout(POSITION | COLOR);
    layout.setAttribSize(Position, 2);
    layout.setAttribSize(Color, 3);
    Shader::vertexAttrib(Position, layout);
    Shader::vertexAttrib(Color, layout);
}

void Triangle::draw() const {
    m_graphics.vao.bind();
    Shader::useProgram(m_graphics.program);
    glDrawElements(GL_TRIANGLES, m_graphics.indices.size(), GL_UNSIGNED_INT, (void*)0);
};

void Triangle::setColor(glm::vec3 color) const {
    m_graphics.vao.bind();
    Shader::useProgram(m_graphics.program);
    float newColor[] = {color.x, color.y, color.z};

    glBufferSubData(GL_ARRAY_BUFFER, 2 * sizeof(float), 3 * sizeof(float), (void*)newColor);
    glBufferSubData(GL_ARRAY_BUFFER, 7 * sizeof(float), 3 * sizeof(float), (void*)newColor);
    glBufferSubData(GL_ARRAY_BUFFER, 12 * sizeof(float), 3 * sizeof(float), (void*)newColor);
}

void Triangle::translate(glm::vec2 move) { 
    for(int i = 0; i < 3; i++) {
        m_position[i] = m_beginPos.at(i) + move;
    }
    
    glm::mat4 trans = glm::mat4(1.0f);
    glm::vec4 normMove = glm::vec4(move.x / 540.0f, move.y / 360.0f, 0.0f, 1.0f);

    trans = glm::translate(trans, glm::vec3(normMove.x, normMove.y, 0.0f));
    
    unsigned int transformLoc = glGetUniformLocation(m_graphics.program, "transform");
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));
};

std::array<glm::vec3, 3> Triangle::getPosition() const {
    std::array<glm::vec3, 3> pos3D {
        glm::vec3{m_position[0].x, m_position[0].y, 0.0},
        glm::vec3{m_position[1].x, m_position[1].y, 0.0},
        glm::vec3{m_position[2].x, m_position[2].y, 0.0},
    };

    return pos3D;
}

bool Triangle::isColliding(const Triangle& t1, const Triangle& t2) {
    return isPointInside(t1, t2) || isPointInside(t2, t1);
}

bool Triangle::isPointInside(const Triangle& t1, const Triangle& t2) {
    auto position_t1 = t1.getPosition();
    auto position_t2 = t2.getPosition();

    glm::vec3 AB = position_t1.at(1) - position_t1.at(0);
    glm::vec3 BC = position_t1.at(2) - position_t1.at(1);
    glm::vec3 CA = position_t1.at(0) - position_t1.at(2);

    glm::vec3 point_t2;
    glm::vec3 crossProd_1;
    glm::vec3 crossProd_2;
    glm::vec3 crossProd_3;

    for(int i = 0; i < 3; i++) {
        point_t2 = position_t2.at(i);
        crossProd_1 = glm::cross(point_t2 - position_t1.at(0), AB);
        crossProd_2 = glm::cross(point_t2 - position_t1.at(1), BC);
        crossProd_3 = glm::cross(point_t2 - position_t1.at(2), CA);

        if(crossProd_1.z >= 0.0f && crossProd_2.z >= 0.0f && crossProd_3.z >= 0.0f) {           
            return true;
        }
    }

    t1.setColor({0.0, 1.0, 0.0});
    t2.setColor({0.0, 0.0, 1.0});

    return false;
}