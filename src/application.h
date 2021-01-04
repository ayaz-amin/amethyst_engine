#pragma once

#define GLFW_INCLUDE_VULKAN
#include "GLFW/glfw3.h"

#include <iostream>
#include <string>

namespace Amethyst {
    class App {
        public:
            App(int _width, int _height, std::string _title);
            ~App();
            void Run();
        
        private:
            int width;
            int height;
            std::string window_title;

            GLFWwindow* window;

            void initWindow();
            void renderLoop();
            void cleanUp();

        protected:
            virtual void Start();
            virtual void Update(float delta_time);
    };
}
