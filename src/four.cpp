#include <stdlib.h>
#include <sstream>
#include <vector>
#include <iostream>

#include "../include/four.h"

int dfourqone(std::string &iFile){
    int result{0};

    std::stringstream sfile(iFile);
    std::vector<std::string> tokens{};
    std::string word{};

    while (std::getline(sfile, word, '\n')){
        tokens.push_back(word);
    }

    int counter{0};
    for (int i = 0; i < tokens.size(); i++){
        for (int j = 0; j < tokens[i].size(); j++){
            if (tokens[i][j] == '@'){
                int left{j-1}, right{j+1}, top{i-1}, bot{i+1};
                if (left >= 0 && tokens[i][left] == '@') counter++;
                if (right < tokens[i].size() && tokens[i][right] == '@') counter++;
                if (top >= 0 && tokens[top][j] == '@') counter++;
                if (bot < tokens.size() && tokens[bot][j] == '@') counter++;
                if (top >= 0 && left >= 0 && tokens[top][left] == '@') counter++;
                if (top >= 0 && right < tokens[i].size() && tokens[top][right] == '@') counter++;
                if (bot < tokens.size() && left >= 0 && tokens[bot][left] == '@') counter++;
                if (bot < tokens.size() && right < tokens[i].size() && tokens[bot][right] == '@') counter++;
                if (counter < 4) result++;
            }
            counter = 0;
        }
    }

    return result;
}

int dfourqtwo(std::string &iFile) {
    int result{0};

    std::stringstream sfile(iFile);
    std::vector<std::string> tokens{};
    std::string word{};

    while (std::getline(sfile, word, '\n')){
        tokens.push_back(word);
    }

    int counter{0};
    bool something_changed{true};
    while (something_changed) {
        something_changed = false; 
        for (int i = 0; i < tokens.size(); i++){
            for (int j = 0; j < tokens[i].size(); j++){
                if (tokens[i][j] == '@'){
                    int left{j-1}, right{j+1}, top{i-1}, bot{i+1};
                    if (left >= 0 && tokens[i][left] == '@') counter++;
                    if (right < tokens[i].size() && tokens[i][right] == '@') counter++;
                    if (top >= 0 && tokens[top][j] == '@') counter++;
                    if (bot < tokens.size() && tokens[bot][j] == '@') counter++;
                    if (top >= 0 && left >= 0 && tokens[top][left] == '@') counter++;
                    if (top >= 0 && right < tokens[i].size() && tokens[top][right] == '@') counter++;
                    if (bot < tokens.size() && left >= 0 && tokens[bot][left] == '@') counter++;
                    if (bot < tokens.size() && right < tokens[i].size() && tokens[bot][right] == '@') counter++;
                    if (counter < 4) {
                        result++;
                        tokens[i][j] = '.';
                        something_changed = true;
                    }
                }
                counter = 0;
            }
        }
    }

    return result;
}
