#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include <fstream>
#include "utility.hpp"


const uint16_t SCR_WIDTH = 800;
const uint16_t SCR_HEIGHT = 600;

float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
}; 

unsigned char* load_shader_C(const char* shader_file);

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

    print_tool_versions();
    glad_glViewport; // set later

    // c style boi
    unsigned char* load = load_shader_C("shader/temp.frag");
    int x = 0;
    while(load[x] != '\0'){
        printf("%c", load[x]);
        x++;
    } puts("");

    while(!glfwWindowShouldClose(window)){
        glClearColor(0.2f, .25, .4, 1.);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    exit:
    glfwTerminate();
    return 0;

}

unsigned char* load_shader_C(const char* shader_file){

    // C style (extra)
    FILE* file = fopen(shader_file, "r");
    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    std::cout << "file size: " << file_size << std::endl; // 103

    unsigned char *buffer = nullptr;
    buffer = (unsigned char*)malloc(file_size);
    size_t fsize = fread(buffer, sizeof(unsigned char), file_size, file);
    std::cout << "file size: " << fsize << std::endl; // 96
    buffer[fsize] = '\0';
    fclose(file);

    return buffer;
}

std::string load_shader(std::string& shader_file){
    
    std::ifstream cs(shader_file);
    std::string c;
    
    return c;

}
