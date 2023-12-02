#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include "utility.hpp"
#include "io_utility.hpp"
#include "shader_utility.hpp"
#include "shader.hpp"
#include "config.hpp"


int main(){

    GLFWwindow* window;

    // Init glfw
    if(!glfwInit()){std::cerr << "Failed to initialize GLFW" << std::endl; return -1;};

    // Create window
    window = glfwCreateWindow(SCRN_WIDTH, SCRN_HEIGHT, "My Window", NULL, NULL);
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

    // Create and debug shader programs
    GLint v_shader = create_vertex_shader(vert_filepath);
    GLint f_shader = create_frag_shader(frag_filepath);
    GLint linked_shader = create_shader_program(v_shader, f_shader);
    debug_shader_program(v_shader, GL_COMPILE_STATUS);
    debug_shader_program(f_shader, GL_COMPILE_STATUS);
    debug_shader_program(linked_shader, GL_LINK_STATUS);

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
