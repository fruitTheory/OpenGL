#pragma once

#include <iostream>
#include <fstream>


// Returns string of char from specificed file
std::string load_file(std::string& file_path){

    std::ifstream fs;
    fs.open(file_path, std::iostream::in);
    char c;
    std::string s;
    while((c = fs.get()) != EOF){ 
        s.push_back(c); 
    } return s;
}

void print_file_data_C(unsigned char* file_data){
    int x = 0;
    while(file_data[x] != '\0'){
        printf("%c", file_data[x]);
        x++;
    } puts("");
}

// Returns characters from specified file
unsigned char* load_file_C(const char* file_path){

    // C style (extra)
    FILE* file = fopen(file_path, "r");
    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    // std::cout << "file size: " << file_size << std::endl; // 103

    unsigned char *buffer = nullptr;
    buffer = (unsigned char*)malloc(file_size);
    size_t fsize = fread(buffer, sizeof(unsigned char), file_size, file);
    // std::cout << "file size: " << fsize << std::endl; // 96
    buffer[fsize] = '\0';
    fclose(file);

    return buffer;
}