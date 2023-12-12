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
    
    GLFWwindow* window;
    window = glfwCreateWindow(width, height, title, monitor, share);
    if(!window){
        std::cerr << "Window didn't initialize" << std::endl; 
        return nullptr;
    }
    return window;
}

// Escape key will close glfw window
void key_close_window(GLFWwindow *window){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// Keeps framebuffer relative to window stretch size
// Used in combination with glfwSetFramebufferSizeCallback(window, framebuffer_size_callback)
void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}