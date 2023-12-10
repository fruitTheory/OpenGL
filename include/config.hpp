#pragma once

#include <stdint.h>

int SCRN_WIDTH = 1000;
int SCRN_HEIGHT = 800;
const char *WINDOW_NAME = "OpenGL Window";

// float vertices[] = {
//      0.5f,  0.5f, 0.0f,  // top right
//      0.5f, -0.5f, 0.0f,  // bottom right
//     -0.5f, -0.5f, 0.0f,  // bottom left
//     -0.5f,  0.5f, 0.0f   // top left 
// };

unsigned int indices[] = {  // note that we start from 0!
    0, 1, 3,   // first triangle
    1, 2, 3    // second triangle
};

float vertices[] = {
    // first triangle
     0.5f,  0.5f, 0.0f,  // top right
     0.5f, -0.5f, 0.0f,  // bottom right
    -0.5f,  0.5f, 0.0f,  // top left 
    // second triangle
     0.5f, -0.5f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f,  // bottom left
    -0.5f,  0.5f, 0.0f   // top left
}; 