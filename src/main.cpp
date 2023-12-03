#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include "utility.hpp"
#include "io_utility.hpp"
#include "shader_utility.hpp"
#include "shader.hpp"
#include "config.hpp"
#include "window_utility.hpp"


int main(){

    // Initialize glfw and create a window
    handle_glfw_init();
    GLFWwindow* window;
    window = create_window(SCRN_WIDTH, SCRN_HEIGHT, "My Window", NULL, NULL);
    glfwMakeContextCurrent(window); // Context - pass data/info to

    // Initalize glad
    handle_glad_init();

    // Utility
    print_tool_versions();

    // Shader filepaths
    std::string vert_filepath = "shader/temp.vert";
    std::string frag_filepath = "shader/temp.frag";

    // Create and debug shader programs
    GLint v_shader = create_vertex_shader(vert_filepath);
    GLint f_shader = create_frag_shader(frag_filepath);
    GLint linked_shader = create_shader_program(v_shader, f_shader);
    glDeleteShader(v_shader); glDeleteShader(f_shader);


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