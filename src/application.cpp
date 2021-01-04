#include "application.h"

namespace Amethyst {
    App::App(int _width, int _height, std::string _title) : width{_width}, height{_height}, window_title{_title} {}

    App::~App() {cleanUp();}

    void App::Run() {
        Start();
        initWindow();
        renderLoop();
    }

    void App::initWindow() {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
        window = glfwCreateWindow(width, height, window_title.c_str(), nullptr, nullptr);
    }

    void App::renderLoop() {
        while(!glfwWindowShouldClose(window)) {
            glfwPollEvents();
            Update(0.1);
        }
    }

    void App::cleanUp() {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void App::Start() {}
    void App::Update(float delta_time) {}
}