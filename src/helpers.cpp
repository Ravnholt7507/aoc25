#include <fstream>

#include "../include/helpers.h"

void file_parser(std::string &oFile, std::string filename){
    std::ifstream t(filename);
    std::stringstream buffer;
    buffer << t.rdbuf();
    oFile = buffer.str();
}
