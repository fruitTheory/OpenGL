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
    const GLchar *vert_file_data = v_file_data.c_str();
    // std::cout << v_file_data << std::endl;

    GLint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vert_file_data, NULL);
    glCompileShader(vertex_shader);
    debug_shader_program(vertex_shader, GL_COMPILE_STATUS);

    return vertex_shader;
}

GLuint create_frag_shader(std::string filepath){

    std::string frag_filepath = filepath;
    std::string f_file_data;

    // Load and print shader file
    load_file(frag_filepath);
    f_file_data = load_file(frag_filepath);
    const GLchar *frag_file_data = f_file_data.c_str();
    // std::cout << f_file_data << std::endl;

    GLint frag_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(frag_shader, 1, &frag_file_data, NULL);
    glCompileShader(frag_shader);
    debug_shader_program(frag_shader, GL_COMPILE_STATUS);

    return frag_shader;
}

// take id of a vert and frag shader
GLuint create_shader_program(GLint v_shader, GLint f_shader){

    GLuint shader_program = glCreateProgram();
    glAttachShader(shader_program, v_shader);
    glAttachShader(shader_program, f_shader);
    glLinkProgram(shader_program);
    debug_shader_program(shader_program, GL_LINK_STATUS);

    return shader_program;
}