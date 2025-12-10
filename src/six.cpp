#include "../include/six.h"
#include <algorithm>
#include <cstdlib>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

unsigned long long dsixqone(std::string &iFile){
    unsigned long long result{};
     
    std::stringstream sfile(iFile);
    std::vector<std::string> tokens{};
    std::string word{};

    while (std::getline(sfile, word, '\n')){
        tokens.push_back(word);
    }

    std::vector<std::vector<int>> problems;
    std::vector<std::string> operations;
    for (auto token : tokens) {
        std::stringstream temp{token};
        std::vector<int> temp_vec{};
        while (std::getline(temp, word, ' ')){
            if (word.empty()) continue;
            if (word == "*" || word == "+") operations.push_back(word);
            else temp_vec.push_back(static_cast<int>(strtol(word.c_str(), nullptr, 10)));
        }
        problems.push_back(temp_vec);
    }

    for (size_t i = 0; i < operations.size(); i++) {
        unsigned long long temp_result{};
        switch (operations[i][0]) {
            case '+':
                temp_result = 0;
                for (size_t j = 0; j < problems.size()-1; j++) {
                    temp_result += problems[j][i];
                }
                result += temp_result;
                break;
            case '*':
                temp_result = 1;
                for (size_t j = 0; j < problems.size()-1; j++) {
                    temp_result *=  problems[j][i];
                }
                result += temp_result;
                break;
            default:
                break;
        }
    }

    return result;
}

unsigned long long dsixqtwo(std::string &iFile){
    unsigned long long result{};
     
    std::stringstream sfile(iFile);
    std::vector<std::string> tokens{};
    std::string word{};

    while (std::getline(sfile, word, '\n')){
        tokens.push_back(word);
    }

    std::vector<std::vector<int>> problems;

    std::vector<std::string> operations;
    for (auto token : tokens) {
        std::stringstream temp{token};
        std::vector<int> temp_vec{};
        while (std::getline(temp, word, ' ')){
            if (word.empty()) continue;
            if (word == "*" || word == "+") operations.push_back(word);
            else temp_vec.push_back(static_cast<int>(strtol(word.c_str(), nullptr, 10)));
        }
        problems.push_back(temp_vec);
    }

    for (size_t i = 0; i < operations.size(); i++) {
        unsigned long long temp_result{};
        size_t largest{0};
        switch (operations[i][0]) {
            case '+':
                largest=0;
                temp_result = 0;
                for (size_t j = 0; j < problems.size()-1; j++) {
                    if (std::to_string(problems[j][i]).size() > largest) largest = std::to_string(problems[j][i]).size();
                }

                for (size_t k = 1; k <= largest; k++){
                    std::string temp{""};
                    for (size_t j = 0; j < problems.size()-1; j++) {
                        if (std::to_string(problems[j][i]).size() >= k) {
                            temp += std::to_string(problems[j][i]).rbegin()[k-1];
                        }
                    }
                    std::cout << "adding " << temp << " to " << temp_result << std::endl;
                    temp_result += strtoull(temp.c_str(), nullptr, 10);
                }
                result += temp_result;
                break;
            case '*':
                largest=0;
                temp_result = 1;
                for (size_t j = 0; j < problems.size()-1; j++) {
                    if (std::to_string(problems[j][i]).size() > largest) largest = std::to_string(problems[j][i]).size();
                }

                for (size_t k = 1; k <= largest; k++){
                    std::string temp{""};
                    for (size_t j = 0; j < problems.size()-1; j++) {
                        if (std::to_string(problems[j][i]).size() >= k) {
                            temp += std::to_string(problems[j][i]).rbegin()[k-1];
                        }
                    }
                    std::cout << "multi " << temp << " to " << temp_result << std::endl;
                    temp_result *= strtoull(temp.c_str(), nullptr, 10);
                }
                result += temp_result;
                break;
            default:
                break;
        }
    }

    return result;
}
