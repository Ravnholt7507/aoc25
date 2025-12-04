#include <cstdlib>
#include <vector>
#include <cstring>
#include <sstream>
#include <string>

#include "../include/three.h"

constexpr int largest{9};
constexpr int smallest{1};

int dthreeqone(std::string &iFile){
    int result{0};
    int idx{};
    char first_num{};
    char second_num{};

    std::stringstream sfile(iFile);
    std::vector<std::string> tokens{};
    std::string word{};

    while (std::getline(sfile, word, '\n')){
        tokens.push_back(word);
    }


    for (auto line : tokens){
        for (int i = largest; i >= smallest; --i){
            char digit = static_cast<char>('0' + i);
            size_t pos = line.find(digit);
            if (pos != std::string::npos && pos != line.size() - 1){
                idx = static_cast<int>(pos);
                first_num = line[idx];
                break;
            }
        }

        for (int i = largest; i >= smallest; --i){
            char digit = static_cast<char>('0' + i);
            size_t pos = line.find(digit, idx+1); 
            if (pos != std::string::npos){
                second_num = line[static_cast<int>(pos)];
                break;
            }
        }

        int first_val = first_num - '0';
        int second_val = second_num - '0';
        int combined = first_val * 10 + second_val;
        result += combined;
    }
    return result;
}

unsigned long long dthreeqtwo(std::string &iFile){
    unsigned long long result{0};

    std::stringstream sfile(iFile);
    std::vector<std::string> tokens{};
    std::string word{};

    while (std::getline(sfile, word, '\n')){
        tokens.push_back(word);
    }

    for (auto line : tokens){
        std::string number{};
        int idx{0};
        while (number.size() < 12) {
            for (int i = largest; i >= smallest; --i){
                char digit = static_cast<char>('0' + i);
                size_t pos = line.find(digit, idx);
                if (pos != std::string::npos && pos <= line.size() - (12-number.size())){
                    number += line[pos];
                    idx = static_cast<int>(pos+1);
                    break;
                }
            }
        }
        idx = 0;
        result += strtoull(number.c_str(), nullptr, 10);
    }

    return result;
}
