#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <GLFW/glfw3.h>
#include "Exception.hpp"
#include "glm/vec2.hpp"

class Window {
private:
    struct resolution {
        int x;
        int y;
    };

public:
    friend class Triangle;

    explicit Window(const char *name, int width, int height);

    Window(const Window& other) = delete;

    ~Window();

    void processInput();

    int shouldClose() noexcept;

    void swapBuffers();

    void pollEvents();

    void clearBuffer();

    void renderSettings(glm::vec2& t1, glm::vec2& t2);

    const char *getName() const noexcept;

    resolution getResolution() const noexcept;

    operator GLFWwindow*() const;

private:
    const char *_name;
    int _width;
    int _height;
    GLFWwindow *windowHandle;

    static struct CursorPos {
        double x;
        double y;
    } mouse;

    static void framebuffer_size_callback(GLFWwindow *window, int width, int height);

    static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

    static void APIENTRY glDebugOutput(GLenum source, GLenum type, unsigned int id, GLenum severity, 
                            GLsizei length, const char *message, const void *userParam);

};

class WindowException : public Exception {
public:
    using Exception::Exception;

    const char *getType() const override;

    const char *what() const noexcept override;
};

#endif // WINDOW_HPP