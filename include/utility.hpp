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

// Print versions of tools related openGL 
void print_tool_versions(){
    // Output OpenGL version
    const GLubyte* version = glGetString(GL_VERSION);
    std::cout << "OpenGL version: " << version << std::endl;

    // Output glfw and glad versions
    int maj, min, rev;
    glfwGetVersion(&maj, &min, &rev);
    printf("GLFW version: %i.%i.%i\n", maj, min, rev);
    printf("GLAD version: %i.%i\n", GLVersion.major, GLVersion.minor);
}