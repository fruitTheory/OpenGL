#version 460 core

// obj position attrib now stored in index 0 of buffer
layout(location = 0) in vec3 aPos;

void main(){
    gl_Position = vec4(aPos, 1.0);
}
