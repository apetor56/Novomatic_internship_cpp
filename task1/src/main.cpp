#include <Triangle.hpp>
#include <Window.hpp>
#include <memory>
#include <thread>

int main() {
    try {
        Window window("Task 1", 1080, 720);
        glm::vec2 p1[] = {{100, 100}, {300, 300}, {300, 100}};
        glm::vec2 p2[] = {{600, 400}, {550, 670}, {750, 700}};

        Triangle t1(p1[0], p1[1], p1[2]);
        Triangle t2(p2[0], p2[1], p2[2]);

        t1.setColor({0.0, 1.0, 0.0});
        t2.setColor({0.0, 0.0, 1.0});

        glm::vec2 trans1{0.0f, 0.0f};
        glm::vec2 trans2{0.0f, 0.0f};
        
        while(!window.shouldClose()) {
            window.clearBuffer();
            window.renderSettings(trans1, trans2);

            if(Triangle::isColliding(t1, t2)) {
                trans1 = {0.0f, 0.0f};
                trans2 = {0.0f, 0.0f};
            }

            t1.draw();
            t1.translate(trans1);
            t2.draw();
            t2.translate(trans2);
            
            window.swapBuffers();
            window.pollEvents();
            window.processInput();
        }
    }
    catch(std::exception& e) {
        std::cout << e.what() << '\n';
    }
}