#pragma once

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#define IMGUI_TRUE

void handgle_imgui_init(GLFWwindow *window){
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 460");
    //ImGuiIO& io = ImGui::GetIO(); (void)io;
}

void imgui_write(const char *title, const char *description){
    ImGui::Begin(title);                          
    ImGui::Text(description);
    ImGui::End();
}

void imgui_create_frame(){
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    const char *title = "Frame Title";
    const char *description = "Heres a text description.";
    imgui_write(title, description);
}

void imgui_render_frame(){
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}