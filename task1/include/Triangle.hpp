#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "Shape.hpp"
#include "Graphics.hpp"
#include <array>

class Triangle : public Shape {
public:
    explicit Triangle(glm::vec2& v1, glm::vec2& v2, glm::vec2& v3);

    void draw() const override;

    void translate(glm::vec2 move) override;

    void setColor(glm::vec3 color) const override;

    void show() {
        std::cout << "[(" << m_position[0].x << ", " << m_position[0].y << "),"
                  << "[(" << m_position[1].x << ", " << m_position[1].y << "),"
                  << "[(" << m_position[2].x << ", " << m_position[2].y << ")]\n";
    }

    std::array<glm::vec3, 3> getPosition() const;

    static bool isColliding(const Triangle& t1, const Triangle& t2);

private:
    Graphics m_graphics;
    std::array<glm::vec2, 3> m_position;
    std::array<glm::vec2, 3> m_beginPos;

    static bool isPointInside(const Triangle& t1, const Triangle& t2);
};

#endif // TRIANGLE_HPP