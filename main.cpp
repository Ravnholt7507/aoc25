#include <iostream>
#include <ostream>

#include "include/helpers.h"
#include "include/one.h"

int main(){
    std::string input{};
    file_parser(input, "inputs/day_one_puzzle_one.txt");

    std::cout << "Day one puzzle one: " << doneqone(input) << std::endl; 
    std::cout << "Day one puzzle two: " << doneqtwo(input) << std::endl; 
}
