#include <iostream>
#include "application.h"

using namespace Amethyst;

class SampleApp : public App {

    using App::App;

    void Start() override {
        std::cout << "Start" << std::endl;
    }

    void Update(float delta_time) override {
        std::cout << "Update" << std::endl;
    }
};

int main() {
    SampleApp app{800, 600, "Sample App"};
    app.Run();
    return 0;
}