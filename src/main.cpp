#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "utility.hpp"
#include "io_utility.hpp"
#include "shader_utility.hpp"
#include <iostream>


const uint16_t SCR_WIDTH = 800;
const uint16_t SCR_HEIGHT = 600;

float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
};


GLuint create_vertex_shader(std::string filepath);
GLuint create_frag_shader(std::string filepath);
GLuint create_shader_program(GLint v_shader, GLint f_shader);

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

    std::string vert_filepath = "shader/temp.vert";
    std::string frag_filepath = "shader/temp.frag";

    GLint v_shader = create_vertex_shader(vert_filepath);
    GLint f_shader = create_frag_shader(frag_filepath);
    GLint link_shader = create_shader_program(v_shader, f_shader);

    debug_shader_program(v_shader, GL_COMPILE_STATUS);
    debug_shader_program(f_shader, GL_COMPILE_STATUS);
    debug_shader_program(link_shader, GL_LINK_STATUS);


    // Render loop
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

GLuint create_vertex_shader(std::string filepath){

    std::string vert_filepath = filepath;
    std::string v_file_data;

    // Load and print shader file
    load_shader(vert_filepath);
    v_file_data = load_shader(vert_filepath);
    const GLchar* v_shader = v_file_data.c_str();
    std::cout << v_file_data << std::endl;

    GLint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &v_shader, NULL);
    glCompileShader(vertexShader);
    debug_shader_program(vertexShader, GL_COMPILE_STATUS);

    return vertexShader;
}

GLuint create_frag_shader(std::string filepath){

    std::string frag_filepath = filepath;
    std::string f_file_data;

    // Load and print shader file
    load_shader(frag_filepath);
    f_file_data = load_shader(frag_filepath);
    const GLchar* f_shader = f_file_data.c_str();
    std::cout << f_file_data << std::endl;

    GLint fragShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragShader, 1, &f_shader, NULL);
    glCompileShader(fragShader);
    debug_shader_program(fragShader, GL_COMPILE_STATUS);

    return fragShader;
}

GLuint create_shader_program(GLint v_shader, GLint f_shader){

    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, v_shader);
    glAttachShader(shaderProgram, f_shader);
    glLinkProgram(shaderProgram);
    glUseProgram(shaderProgram);
    debug_shader_program(shaderProgram, GL_LINK_STATUS);

    return shaderProgram;
}


/* Previous raw setup */
    // std::string v_file_data;
    // std::string f_file_data;

    // // Load and print shader file
    // load_shader(vert_filepath);
    // v_file_data = load_shader(vert_filepath);
    // const GLchar* v_shader = v_file_data.c_str();
    // std::cout << v_file_data << std::endl;

    // // Load and print shader file
    // load_shader(frag_filepath);
    // f_file_data = load_shader(frag_filepath);
    // const GLchar* f_shader = f_file_data.c_str();
    // std::cout << f_file_data << std::endl;

    // // set later
    // glad_glViewport;

    // GLint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    // glShaderSource(vertexShader, 1, &v_shader, NULL);
    // glCompileShader(vertexShader);
    // debug_shader_program(vertexShader, GL_COMPILE_STATUS);

    // GLint fragShader = glCreateShader(GL_FRAGMENT_SHADER);
    // glShaderSource(fragShader, 1, &f_shader, NULL);
    // glCompileShader(fragShader);
    // debug_shader_program(fragShader, GL_COMPILE_STATUS);

    // GLuint shaderProgram = glCreateProgram();
    // glAttachShader(shaderProgram, vertexShader);
    // glAttachShader(shaderProgram, fragShader);
    // glLinkProgram(shaderProgram);
    // glUseProgram(shaderProgram);
    // debug_shader_program(shaderProgram, GL_LINK_STATUS);