/**
 * @file main.cpp
 * @author Jakub Sanecki
 * @brief 
 * @version 0.5
 * @date 2023-06-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include <iostream>
#include <vector>
#include "functions.h"
#include "structures.h"

int main(int argc, char *argv[])
{
    system("clear");
    std::string inputFile;
    int i;
    //int deArgs = decodeArgs(argc, argv, inputFile);
    
    std::cout<< "Welcome to the program!"<<std::endl;
    std::cout<< "If you don't know how to use this program enter 'help' to get some info."<<std::endl;
    std::cout<< "Press ENTER key to continue..."<<std::endl;
    std::cin.get();
    Matrix matrix;
    interactiveConsole();
    



    return 0;
}
