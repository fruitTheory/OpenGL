#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "file_utility.hpp"
#include <iostream>

// For pname use GL_COMPILE_STATUS or GL_LINK_STATUS 
int debug_shader_program(GLuint program, int pname){
    int success;
    char infoLog[512];
    switch(pname){
        case GL_LINK_STATUS:{
            glGetProgramiv(program, GL_LINK_STATUS, &success);
            if(success == GL_FALSE){
                glGetProgramInfoLog(program, 512, NULL, infoLog);
                std::cout << "ERROR::SHADER::LINKING_FAILED\n" << infoLog << std::endl;
                return EXIT_FAILURE;
            } break;
        }
        case GL_COMPILE_STATUS:{
            glGetShaderiv(program, GL_COMPILE_STATUS, &success);
            if(success == GL_FALSE){
                glGetShaderInfoLog(program, 512, NULL, infoLog);
                std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
                return EXIT_FAILURE;
            } break;
        }
        default:
            break;
    }
    return EXIT_SUCCESS;
}

GLuint create_vertex_shader(std::string filepath){

    std::string vert_filepath = filepath;
    std::string v_file_data;

    // Load and print shader file
    v_file_data = load_file(vert_filepath);
    const GLchar *vert_file_data = v_file_data.c_str();
    // std::cout << v_file_data << std::endl;

    GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    if(vertex_shader == 0){ std::cerr << "Error creating shader object" << std::endl;}
    glShaderSource(vertex_shader, 1, &vert_file_data, NULL);
    glCompileShader(vertex_shader);
    debug_shader_program(vertex_shader, GL_COMPILE_STATUS);

    return vertex_shader;
}

GLuint create_frag_shader(std::string filepath){

    std::string frag_filepath = filepath;
    std::string f_file_data;

    // Load and print shader file
    f_file_data = load_file(frag_filepath);
    const GLchar *frag_file_data = f_file_data.c_str();
    // std::cout << f_file_data << std::endl;

    GLuint frag_shader = glCreateShader(GL_FRAGMENT_SHADER);
    if(frag_shader == 0){ std::cerr << "Error creating shader object" << std::endl;}
    glShaderSource(frag_shader, 1, &frag_file_data, NULL);
    glCompileShader(frag_shader);
    debug_shader_program(frag_shader, GL_COMPILE_STATUS);

    return frag_shader;
}

// Returns a program that has the shader inputs attached and linked together
GLuint create_shader_program(GLint v_shader, GLint f_shader){

    GLuint shader_program = glCreateProgram();
    glAttachShader(shader_program, v_shader);
    glAttachShader(shader_program, f_shader);
    glLinkProgram(shader_program);
    debug_shader_program(shader_program, GL_LINK_STATUS);

    return shader_program;
}
