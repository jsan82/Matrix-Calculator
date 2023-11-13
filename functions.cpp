#include <iostream>
#include <string>
#include "functions.h"
#include <sstream>
#include <fstream> 
#include "structures.h"



std::unordered_map<int, std::vector<std::string> > readFile(std::string &inputFile)
{
    int x;
    int y = 0;
    std::vector<std::string> words;
    std::unordered_map<int, std::vector<std::string> > holder; 
    std::ifstream file(inputFile);
    std::string line, word1, word2;
    while (getline(file,line))
    {  
        words.clear();
        std::stringstream line1(line);
        x = 0;
        while(line1>>word1)
        {
            word2.clear();
                for(int i = 0; i < word1.size();i++)
                {
                    if(word1[i] != '%')
                    {   
                        
                            if(word1[i]==';')
                            {
                                words.push_back(word2);
                                word2.clear();
                                continue;
                            }
                            if (word1[i]== ',')
                                word2 += '.';
                            else    
                                word2 += word1[i];
                        
                    }
                    else if (word1[i] == '%')
                    {
                        x++;
                    }
                }
                if(!word2.empty())
                {
                    words.push_back(word2);
                }

        }
        if(!words.empty())
        {
            holder.insert(std::make_pair(y, words));
            y++;
        }

        }    
    return holder;
}

void interactiveConsole()
{
    Matrix matrix;
    system("clear");
    bool running = true;
    while (running)
    {
        std::string command1, command;

        std::cout << "Enter command: ";
        std::cin >> command1;
        for (int i=0; i < command1.size() ; i++)
        {
            command+= tolower(command1[i]);
        }
        if (command == "exit")
        {
            running = false;
        }
        if (command == "help")
        {
            system("clear");
            std::cout<< "_______________________________________________________"<<std::endl;
            std::cout << "Commands: " << std::endl;
            std::cout << "exit - exit the program" << std::endl;
            std::cout << "help - print this help message" << std::endl;
            std::cout << "load - load a file whit matrix" << std::endl;
            std::cout << "create - create a matrix" << std::endl;
            std::cout << "save - save a file whit matrix" << std::endl;
            std::cout << "print - print matrix" << std::endl;
            std::cout << "add - add two matrix" << std::endl;
            std::cout << "sub - subtract two matrix" << std::endl;
            std::cout << "mul - multiply two matrix by scalar" << std::endl;
            std::cout << "file - information about how to preapare correctfile " << std::endl;
            std::cout << "clear - delete all matrices"<<std::endl;
            std::cout << "transpose - transpose matrix"<<std::endl;
            std::cout << "det - calculate determinant of matrix"<<std::endl;
            std::cout << "inv - calculate inverse of matrix"<<std::endl;
            // std::cout << "del - delete matrix"<<std::endl;
            std::cout<< "_______________________________________________________"<<std::endl;

        }
        if (command == "load")
        {
            std::string filename;
            std::cout << "Enter filename: ";
            std::cin >> filename;
            
            std::unordered_map<int, std::vector<std::string> > holder = readFile(filename);
            std::cout << "Loading file '" << filename << "'..." << std::endl;
            
            if (holder.empty())
            {
                std::cout << "Error: file '" << filename << "' not found." << std::endl;
            }
            else
            {
                std::cout << "File '" << filename << "' loaded." << std::endl;
            }
            for (auto it = holder.begin(); it != holder.end(); it++)
            {
                std::string row, col;
                int x = 0;
                std::vector<double> numbers;
                for (int i = 0; i < it->second[0].size(); i++)
                {   
                    if (it->second[0][i] == 'x'|| it->second[0][i] == 'X')
                    {
                        x++;
                        continue;
                    }
                    if (x == 0)
                    {
                        row += it->second[0][i];
                    }
                    if (x == 1)
                    {
                        col += it->second[0][i];
                    }
                }
                for (int i = 1; i < it->second.size(); i++)
                {
                    numbers.push_back(std::stod(it->second[i]));
                }
                matrix.fillingMatrix( stoi(row), stoi(col), numbers );
                numbers.clear();
            }
        }
        if (command == "print")
        {
            system("clear");
            matrix.printMatrix();
        }    
        if (command == "add")
        {
            int x,y;
            std::cout<<"Insert numbers of matrices witch would you like add"<<std::endl;
            std::cout<<"Matrix 1: ";
            std::cin>> x;
            std::cout<<"Matrix 2: ";
            std::cin>> y;
            matrix.addMatrix(x,y);
            
        }
        if (command == "sub")
        {
            int x,y;
            std::cout<<"Insert indexes of matrices witch would you like substract"<<std::endl;
            std::cout<<"Matrix 1: ";
            std::cin>> x;
            std::cout<<"Matrix 2: ";
            std::cin>> y;
            matrix.addMatrix(x,y);
        }
        if(command == "mul")
        {
            int x,y;
            std::cout<<"Insert indexes of matrices witch would you like multiply"<<std::endl;
            std::cout<<"Matrix 1: ";
            std::cin>> x;
            std::cout<<"Matrix 2: ";
            std::cin>> y;
            matrix.multMatrix(x,y);
        }
        if(command == "file")
        {
            system("clear");
            std::cout<< "_______________________________________________________"<<std::endl;
            std::cout << "File should be in the following format: " << std::endl;
            std::cout << "xXyY%a11;a12;a13;a21;a22;a23;a31;a32;a33" << std::endl;
            std::cout << "xXyY - matrix size" << std::endl;
            std::cout << "a11;a12;a13;a21;a22;a23;a31;a32;a33 - matrix elements" << std::endl;
            std::cout << "x - number of rows" << std::endl;
            std::cout << "y - number of columns" << std::endl;
            std::cout<< "_______________________________________________________"<<std::endl;
        }
        if(command == "save")
        {
            std::string filename;
            std::cout << "Enter filename: ";
            std::cin >> filename;
            std::cout << "Saving file '" << filename << "'..." << std::endl;
            std::ofstream file;
            matrix.saveMatrix(filename);
            std::cout << "File '" << filename << "' saved." << std::endl;
        }
        if(command == "clear")
        {
            matrix.clearMatrix();
            std::cout<<"Matrix cleared"<<std::endl;
        }
        if(command == "transpose")
        {
            int x;
            std::cout<<"Insert index of matrix witch would you like transpose"<<std::endl;
            std::cout<<"Matrix: ";
            std::cin>> x;
            matrix.transposeMatrix(x);
        }
        if(command == "det")
        {
            int x;
            std::cout<<"Insert index of matrix witch would you like calculate determinant"<<std::endl;
            std::cout<<"Matrix: ";
            std::cin>> x;
            matrix.determinantMatrix(x);
        }
        if(command == "inv")
        {
            int x;
            std::cout<<"Insert index of matrix witch would you like calculate inverse"<<std::endl;
            std::cout<<"Matrix: ";
            std::cin>> x;
            matrix.inverseMatrix(x);
        }
        if(command == "create")
        {
            int x,y;
            std::cout<<"Insert size of matrix with would you like create"<<std::endl;
            std::cout<<"Rows: ";
            std::cin>> x;
            std::cout<<"Columns: ";
            std::cin>> y;
            std::vector<double> numbers;
            for (int i = 0; i < x; i++)
            {
                for (int j = 0; j < y; j++)
                {
                    double number;
                    std::cout<<"Insert number: ";
                    std::cin>> number;
                    numbers.push_back(number);
                }
            }
                matrix.fillingMatrix(x,y,numbers);
                numbers.clear();
                std::cout<<"Matrix created"<<std::endl;
        }
        
        
    }
}  
