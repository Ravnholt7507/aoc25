#include <algorithm>
#include <cstdlib>
#include <stdlib.h>
#include <tuple>
#include <vector>
#include <sstream>

#include "../include/five.h"


int dfiveqone(std::string &iFile){
    int result{0};

    std::stringstream sfile(iFile);
    std::vector<std::tuple<unsigned long long, unsigned long long>> ranges{};
    std::vector<unsigned long long> ids{};
    std::string word{};
    
    bool swap{false};
    while (std::getline(sfile, word, '\n')){
        if (word.empty()){
            swap = true;
            continue;
        }
        if (!swap){
            unsigned long long first{strtoull(word.substr(0, word.find('-')).c_str(), nullptr, 10)};
            unsigned long long second{strtoull(word.substr(word.find('-')+1).c_str(), nullptr, 10)};
            ranges.push_back(std::tuple<unsigned long long, unsigned long long>(first, second));
        } else {
            ids.push_back(strtoull(word.c_str(), nullptr, 10));
        }
    }

    for (auto id : ids){
        for (auto range : ranges){
            if (id >= get<0>(range) && id <= get<1>(range)){
                result++;
                break;
            } 
        }
    }

    return result;
}

unsigned long long dfiveqtwo(std::string &iFile){
    std::stringstream sfile(iFile);
    std::vector<std::tuple<unsigned long long, unsigned long long>> ranges{};
    std::vector<unsigned long long> ids{};
    std::string word{};
    
    bool swap{false};
    while (std::getline(sfile, word, '\n')){
        if (word.empty()){
            swap = true;
            continue;
        }
        if (!swap){
            unsigned long long first{strtoull(word.substr(0, word.find('-')).c_str(), nullptr, 10)};
            unsigned long long second{strtoull(word.substr(word.find('-')+1).c_str(), nullptr, 10)};
            if (first > second) std::swap(first, second);
            ranges.emplace_back(first, second);
        } else {
            ids.push_back(strtoull(word.c_str(), nullptr, 10));
        }
    }

    if (ranges.empty()) return 0;

    std::sort(ranges.begin(), ranges.end(),
        [](const auto &a, const auto &b){
            if (std::get<0>(a) != std::get<0>(b)) return std::get<0>(a) < std::get<0>(b);
            return std::get<1>(a) < std::get<1>(b);
        });

    std::vector<std::pair<unsigned long long, unsigned long long>> merged;
    unsigned long long curL = std::get<0>(ranges[0]);
    unsigned long long curR = std::get<1>(ranges[0]);

    for (size_t i = 1; i < ranges.size(); ++i){
        unsigned long long L = std::get<0>(ranges[i]);
        unsigned long long R = std::get<1>(ranges[i]);
        if (L <= curR + 1) {
            if (R > curR) curR = R;
        } else {
            merged.emplace_back(curL, curR);
            curL = L; curR = R;
        }
    }
    merged.emplace_back(curL, curR);

    unsigned long long total{0};
    for (const auto &p : merged){
        total += (p.second - p.first + 1);
    }
    return total;
}
