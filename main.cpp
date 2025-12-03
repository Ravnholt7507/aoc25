#include <iostream>
#include <ostream>

#include "include/helpers.h"
#include "include/one.h"
#include "include/two.h"

int main(){
    std::string input{};
    file_parser(input, "inputs/day_two_puzzle_one.txt");

    //std::cout << "Day one puzzle one: " << doneqone(input) << std::endl; 
    //std::cout << "Day one puzzle two: " << doneqtwo(input) << std::endl; 
    std::cout << "Day one puzzle two: " << dtwoqone(input) << std::endl; 
    std::cout << "Day one puzzle two: " << dtwoqtwo(input) << std::endl; 
}
