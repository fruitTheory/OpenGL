#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>

// Init glad by loading functions relevant to current context(glfw)
void handle_glad_init(){
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cerr << "Failed to initialize GLAD" << std::endl;
    }
}