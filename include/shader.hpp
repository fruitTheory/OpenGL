#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include "shader_utility.hpp"
#include "io_utility.hpp"

GLuint create_vertex_shader(std::string filepath){

    std::string vert_filepath = filepath;
    std::string v_file_data;

    // Load and print shader file
    load_file(vert_filepath);
    v_file_data = load_file(vert_filepath);
    const GLchar* v_shader = v_file_data.c_str();
    // std::cout << v_file_data << std::endl;

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
    load_file(frag_filepath);
    f_file_data = load_file(frag_filepath);
    const GLchar* f_shader = f_file_data.c_str();
    // std::cout << f_file_data << std::endl;

    GLint fragShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragShader, 1, &f_shader, NULL);
    glCompileShader(fragShader);
    debug_shader_program(fragShader, GL_COMPILE_STATUS);

    return fragShader;
}

// take id of a vert and frag shader
GLuint create_shader_program(GLint v_shader, GLint f_shader){

    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, v_shader);
    glAttachShader(shaderProgram, f_shader);
    glLinkProgram(shaderProgram);
    glUseProgram(shaderProgram);
    debug_shader_program(shaderProgram, GL_LINK_STATUS);

    return shaderProgram;
}