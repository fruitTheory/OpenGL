#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>


const uint16_t SCR_WIDTH = 800;
const uint16_t SCR_HEIGHT = 600;

int main(){

    GLFWwindow* window;

    // Init glfw
    if(!glfwInit()){std::cerr << "Failed to initialize GLFW" << std::endl; return -1;};

    // Create window
    window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "My Window", NULL, NULL);
    if(!window){std::cerr << "Window didn't initialize" << std::endl; glfwTerminate(); return -1;}

    // Context - pass data/info to
    glfwMakeContextCurrent(window);

    // Init glad
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Output OpenGL version
    const GLubyte* version = glGetString(GL_VERSION);
    std::cout << "OpenGL version: " << version << std::endl;

    while(!glfwWindowShouldClose(window)){
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    exit:
    glfwTerminate();
    return 0;

}


/*
    std::string vertexShaderSource = LoadShaderSource("temp.vert");
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    const GLchar* source = (const GLchar*)vertexShaderSource.c_str();
    glShaderSource(vertexShader, 1, &source, 0);
    glCompileShader(vertexShader);

*/