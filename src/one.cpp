#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>

#include "../include/one.h"

int doneqone(std::string &iFile) {
    int result{0};
    int intermid{50};
    std::stringstream sfile(iFile);
    std::vector<std::string> tokens{};
    std::string word{};

    while (std::getline(sfile, word, '\n')){
        tokens.push_back(word);
    }

    for(std::string i : tokens) {
        long temp{strtol(i.substr(1, i.size()).c_str(), nullptr, 10)};
        if (i[0] == 'R') {
            intermid += temp;
            while(intermid >= 100) {
                intermid -= 100;
            }
        } else {
            intermid -= temp;
            while(intermid < 0) {
                intermid += 100;
            }
        }
        if (intermid == 0) {
            result++;
        }
    }

    return result;
}

int doneqtwo(std::string &iFile){
    int result{0};
    int intermid{50};
    std::stringstream sfile(iFile);
    std::vector<std::string> tokens{};
    std::string word{};

    while (std::getline(sfile, word, '\n')){
        tokens.push_back(word);
    }

    for(std::string i : tokens) {
        long temp{strtol(i.substr(1, i.size()).c_str(), nullptr, 10)};
        if (i[0] == 'R') {
            intermid += temp;
            while(intermid >= 100) {
                intermid -= 100;
                if (intermid != 0) {
                    result++;
                }
            }
        } else {
            intermid -= temp;
            while(intermid < 0) {
                if (intermid + temp != 0) {
                    result++;
                }
                intermid += 100;
            }
        }
        if (intermid == 0) {
            result++;
        }
    }

    return result;
}
