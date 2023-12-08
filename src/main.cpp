#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include "utility.hpp"
#include "file_utility.hpp"
#include "shader_utility.hpp"
#include "shader_create.hpp"
#include "config.hpp"
#include "window.hpp"


int main(){

    // Initialize glfw and create a window
    handle_glfw_init();
    GLFWwindow* window;
    window = create_window(SCRN_WIDTH, SCRN_HEIGHT, WINDOW_NAME, NULL, NULL);
    glfwMakeContextCurrent(window); // Context - pass data/info to

    // Initalize glad
    handle_glad_init();

    print_tool_versions();

    // Shader filepaths
    std::string vert_filepath = "shader/temp.vert";
    std::string frag_filepath = "shader/temp.frag";

    // Create and debug shader programs
    GLint v_shader = create_vertex_shader(vert_filepath);
    GLint f_shader = create_frag_shader(frag_filepath);
    GLint linked_shader = create_shader_program(v_shader, f_shader);
    glDeleteShader(v_shader); glDeleteShader(f_shader);

    // Buffers - VBO stores verticies in gpu memory 
    GLuint VAO, VBO, EBO;

    // Generate and store IDs, bind to current context and set state of object  
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    // VAO object (bind)
    glBindVertexArray(VAO);

    // VBO object
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);

    // EBO object
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), &indices, GL_STATIC_DRAW);

    // How should gl interpret vertex data
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, (sizeof(float)*3), nullptr);
    glEnableVertexAttribArray(0);

    // Unbind objects
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    // Render loop
    while(!glfwWindowShouldClose(window)){
        // shader program to use
        glUseProgram(linked_shader);

        // bg color 
        glClearColor(0.2f, .25, .4, 1.);
        glClear(GL_COLOR_BUFFER_BIT);

        // change state of how polygons are rasterized
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        
        // rebind objects
        glBindVertexArray(VAO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

        // drawing
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0); // does nothing
        glDrawArrays(GL_TRIANGLES, 0, 6); // draws rectangle

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    exit:
    glDeleteVertexArrays(1, &VAO); glDeleteBuffers(1, &VBO);
    glfwTerminate();
    return 0;

}