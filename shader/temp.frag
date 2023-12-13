#version 460 core

out vec4 FragColor;

in vec3 vertexColor;
in vec4 pos;

uniform vec4 uniColor;

void main(){
    //FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
    //FragColor = uniColor;
    //FragColor = vec4(vertexColor, 1.0);
    FragColor = pos;
}