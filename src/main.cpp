#include "debug_utility.hpp"
#include "glad_utility.hpp"
#include "file_utility.hpp"
#include "shader.hpp"
#include "config.hpp"
#include "data.hpp"
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

    #ifdef IMGUI_TRUE
    // Initalize imgui
    handgle_imgui_init(window);
    #endif

    // Shader filepaths
    std::string vert_filepath = "shader/temp.vert";
    std::string frag_filepath = "shader/temp.frag";

    // Create and debug shader programs
    GLint v_shader = create_vertex_shader(vert_filepath);
    GLint f_shader = create_frag_shader(frag_filepath);
    GLint shader_program = create_shader_program(v_shader, f_shader);
    glDeleteShader(v_shader); glDeleteShader(f_shader);

    // Buffers - VBO stores verticies in gpu memory 
    GLuint VAOs[2], VBOs[2];
    GLuint VAO, VBO, EBO;

    // Generate and store IDs, bind to current context and set state of object  
    // glGenVertexArrays(1, &VAO);
    // glGenBuffers(1, &VBO);
    // glGenBuffers(1, &EBO);

    // Quiz
    // Generate multiple buffers
    glGenVertexArrays(2, VAOs);
    glGenBuffers(2, VBOs);

    glBindVertexArray(VAOs[0]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(firstTriangle), &firstTriangle, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, (sizeof(float)*3), nullptr);
    glEnableVertexAttribArray(0);

    glBindVertexArray(VAOs[1]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(secondTriangle), &secondTriangle, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, (sizeof(float)*3), nullptr);
    glEnableVertexAttribArray(0);
    // End

    // // VAO object (bind)
    // glBindVertexArray(VAO);

    // // VBO object
    // glBindBuffer(GL_ARRAY_BUFFER, VBO);
    // glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);

    // // EBO object
    // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    // glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), &indices, GL_STATIC_DRAW);

    // // How should gl interpret vertex data, type, stride, etc
    // glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, (sizeof(float)*3), nullptr);
    // glEnableVertexAttribArray(0);

    // Unbind objects
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    // Render loop
    while(!glfwWindowShouldClose(window)){

        key_close_window(window);

        // Clear background with color 
        glClearColor(0.2f, .25, .4, 1.);
        glClear(GL_COLOR_BUFFER_BIT);

        // Activate shader
        glUseProgram(shader_program);

        // Set how polygons are rasterized
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        
        // Triangle 1
        glBindVertexArray(VAOs[0]);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // Triangle 2
        glBindVertexArray(VAOs[1]);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // Time varies color via uniform variable
        time_vary_color(shader_program);

        //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        #ifdef IMGUI_TRUE
        // Imgui
        imgui_create_frame();
        imgui_render_frame();
        #endif

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    exit:
    glDeleteVertexArrays(1, &VAO); glDeleteBuffers(1, &VBO); glDeleteBuffers(1, &EBO);
    glDeleteVertexArrays(2, VAOs); glDeleteBuffers(2, VBOs);
    glfwTerminate();
    return 0;

}