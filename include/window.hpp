#pragma once

#include "GLFW/glfw3.h"
#include <iostream>

// Handle glfw init and/or failure
void handle_glfw_init(){
    if(!glfwInit()){
        std::cerr << "Failed to initialize GLFW" << std::endl;
        glfwTerminate();
    }
}

// Returns a GLFW window object - handles failure
GLFWwindow* create_window(int width, int height, const char *title, GLFWmonitor *monitor, GLFWwindow *share){
    // Create window
    GLFWwindow* window;
    window = glfwCreateWindow(width, height, title, monitor, share);
    if(!window){
        std::cerr << "Window didn't initialize" << std::endl; 
        return nullptr;
    }
    return window;
}