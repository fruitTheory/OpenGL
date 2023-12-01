#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>

// For type use GL_COMPILE_STATUS or GL_LINK_STATUS 
void debug_shader_program(GLuint program, int type){

    int success;
    char infoLog[512];
    switch(type){
        case GL_LINK_STATUS:{
            glGetProgramiv(program, GL_LINK_STATUS, &success);
            if (!success){
                glGetProgramInfoLog(program, 512, NULL, infoLog);
                std::cout << "ERROR::SHADER::LINKING_FAILED\n" << infoLog << std::endl;
            } break;
        }
        case GL_COMPILE_STATUS:{
            glGetShaderiv(program, GL_COMPILE_STATUS, &success);
            if (!success){
                glGetShaderInfoLog(program, 512, NULL, infoLog);
                std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
            } break;
        }
        default:
            break;
    }
}