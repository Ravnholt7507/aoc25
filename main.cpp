#include <iostream>

#include "include/helpers.h"
#include "include/one.h"
#include "include/two.h"
#include "include/three.h"
#include "include/four.h"
#include "include/five.h"
#include "include/six.h"

int main(){
    std::string input{};
    file_parser(input, "inputs/test_input.txt");

    //std::cout << "Day one puzzle one: " << doneqone(input) << std::endl; 
    //std::cout << "Day one puzzle two: " << doneqtwo(input) << std::endl; 
    //std::cout << "Day two puzzle one: " << dtwoqone(input) << std::endl; 
    //std::cout << "Day two puzzle two: " << dtwoqtwo(input) << std::endl; 
    //std::cout << "Day three puzzle one: " << dthreeqone(input) << std::endl; 
    //std::cout << "Day three puzzle two: " << dthreeqtwo(input) << std::endl; 
    //std::cout << "Day four puzzle one: " << dfourqone(input) << std::endl; 
    //std::cout << "Day four puzzle two: " << dfourqtwo(input) << std::endl; 
    //std::cout << "Day five puzzle one: " << dfiveqone(input) << std::endl; 
    //std::cout << "Day five puzzle two: " << dfiveqtwo(input) << std::endl; 
    std::cout << "Day six puzzle one: " << dsixqone(input) << std::endl; 
    std::cout << "Day six puzzle two: " << dsixqtwo(input) << std::endl; 
}
