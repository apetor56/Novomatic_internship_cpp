#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "AttributeLayout.hpp"

class Shape {
public:
    Shape() :
        m_color(glm::vec3(1.0f, 0.5f, 0.0f)) {}
    
    virtual void draw() const = 0;

    virtual ~Shape() {}

    virtual void translate(glm::vec2 move) = 0;

    virtual void setColor(glm::vec3 color) const = 0;

protected:
    glm::vec3 m_color;
};

#endif // SHAPE_HPP