#version 460 core

// Basically look at buffer index [0] for (stride amount) of (type)
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aColor;

uniform vec3 uniOffset;

out vec3 vertexColor; // output aColor from vertex attribute
out vec4 pos;

void main(){
    gl_Position = vec4(aPos+uniOffset, 1.0);
    pos = gl_Position;
    //vertexColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
    vertexColor = aColor;
}
