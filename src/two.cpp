#include <algorithm>
#include <cstdlib>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>
#include "../include/two.h"

unsigned long long dtwoqone(std::string &iFile) {
    unsigned long long result{0};
    std::stringstream sfile(iFile);
    std::vector<std::string> tokens{};
    std::string word{};

    while (std::getline(sfile, word, ',')){
        tokens.push_back(word);
    }

    for (auto range : tokens) {
        int index = range.find('-');
        long first = strtol(range.substr(0, index).c_str(), nullptr, 10);
        long second = strtol(range.substr(index+1).c_str(), nullptr, 10);

        for (long i = first; i <= second; i++){
            std::string temp = std::to_string(i);
            if (temp.size() % 2 != 0) continue;
            long numone = strtol(temp.substr(0, (temp.size()/2)).c_str(), nullptr, 10);
            long numtwo= strtol(temp.substr(temp.size()/2).c_str(), nullptr, 10);
            if (numone == numtwo) {
                result += i;
            }
        }
    }


    return result;
}

unsigned long long dtwoqtwo(std::string &iFile) {
    unsigned long long result{0};
    std::stringstream sfile(iFile);
    std::vector<std::string> tokens{};
    std::string word{};

    while (std::getline(sfile, word, ',')){
        tokens.push_back(word);
    }

    for (auto range : tokens) {
        int index = range.find('-');
        long first = strtol(range.substr(0, index).c_str(), nullptr, 10);
        long second = strtol(range.substr(index+1).c_str(), nullptr, 10);

        for (long i = first; i <= second; i++){
            std::string temp = std::to_string(i);
            check_all_combinations(temp, result);
        }
    }

    return result;
}

void check_all_combinations(std::string iString, unsigned long long &result){
    std::vector<long> temp{};
    for (size_t i = 1; i <= iString.size()/2; i++){
        for (size_t j = 0; j < iString.size(); j+=i) {
            temp.push_back(strtol(iString.substr(j, i).c_str(), nullptr, 10));
            }
        std::vector<long>::iterator it = std::unique(temp.begin(), temp.end());
        temp.resize(std::distance(temp.begin(), it));
        if (temp.size() == 1) {
            result += strtol(iString.c_str(), nullptr, 10);
            return;
        }
        temp.clear();
    }
}
