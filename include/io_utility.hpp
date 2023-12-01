#include <iostream>
#include <fstream>


// Returns string of char from specificed file
std::string load_shader(std::string& shader_file){

    std::ifstream fs;
    fs.open(shader_file, std::iostream::in);
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
unsigned char* load_shader_C(const char* shader_file){

    // C style (extra)
    FILE* file = fopen(shader_file, "r");
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

    // load c style - extra
    // unsigned char* load = load_shader_C("shader/temp.frag");
    // print_file_data_C(load);
}