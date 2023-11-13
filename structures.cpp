#include "structures.h"
#include <iostream>
#include <string> 
#include <vector>
#include <math.h>
#include <unordered_map>
#include <sstream>
#include <fstream>

Matrix::Matrix(){};

void Matrix::fillingMatrix(int _cols, int _rows, std::vector<double> values)
{
    
    if (claster.empty())
    {
        Matrices matrice;
        matrice.matrix_index = 0;
        matrice.cols = _cols;
        matrice.rows = _rows;
        int v = 0;
        for (int i =0 ; i < _rows; i++)
        {
            matrice.data.push_back(std::vector<double>());
            for (int j = 0 ; j < _cols; j++)
            {

                matrice.data[i].push_back(values[v]);
                v++;
            }
        }
        claster.insert({matrice.matrix_index, matrice});
        return ;
    }
    Matrices matrice;
    matrice.matrix_index = claster.size();
    matrice.cols = _cols;
    matrice.rows = _rows;
    int v = 0;
    for (int i =0 ; i < _rows; i++)
    {
        matrice.data.push_back(std::vector<double>());
        for (int j = 0 ; j < _cols; j++)
        {
            matrice.data[i].push_back(values[v]);
            v++;
        }
    }
    claster.insert({matrice.matrix_index, matrice});
    return ;
}

// void Matrix::saving(int index, Matrices)
// {   
//     auto mat = Matrices;
//     std::string command,commandIn;
//     std::cout<<"Would you like to save matrix? \n Y/N"<<std::endl;
//     std::cin>>commandIn;
//     for (int i=0; i < commandIn.size() ; i++)
//         {
//             command+= tolower(commandIn[i]);
//         }
//     int x = 0;
//     while (x != 1)
//     {
//         if( command == "y" || command == "yes")
//         {
//             claster.insert({index, Matrices});
//             x=1;
//         }
//         else if (command == "n" || command == "no")
//         {
//             x=1;
//         }
//         else
//         {
//             std::cout<<"Wrong command"<<std::endl;
//             std::cout<<"Would you like to save matrix? \n Y/N"<<std::endl;
//         }
//     }
// }

void Matrix::printMatrix()
{
    if(claster.empty())
    {
        std::cout<< "ERROR \n THERE IS NO MATRIX TO PRINT " << std::endl;
        return ;
    }
    for (int i = 0; i < claster.size(); i++)
    {
        std::cout << "Matrix number " << i << std::endl;
        for (int j = 0; j < claster[i].rows; j++)
        {
            for (int k = 0; k < claster[i].cols; k++)
            {
                std::cout << claster[i].data[j][k] << "     ";
            }
            std::cout << std::endl;
        }
    
    }
    return;
}

void Matrix::printMatrix(int w)
{
    if(claster.empty())
    {
        std::cout<< "ERROR \n THERE IS NO MATRIX TO PRINT " << std::endl;
        return ;
    }
        for (int j = 0; j < claster[w].rows; j++)
        {
            for (int k = 0; k < claster[w].cols; k++)
            {
                std::cout << claster[w].data[j][k] << "     ";
            }
            std::cout << std::endl;
        }
    
    return;
}

void Matrix::addMatrix(int index_1, int index_2)
{
    if (claster.empty())
    {
        std::cout << "ERROR \n THERE IS NO MATRIX TO ADD " << std::endl;
        return;
    }
    if (claster[index_1].rows != claster[index_2].rows || claster[index_1].cols != claster[index_2].cols)
    {
        std::cout << "ERROR \n MATRICES HAVE DIFFERENT DIMENSIONS " << std::endl;
        return;
    }
    Matrices matrice;
    printMatrix(index_1);
    std::string command,commandIn;
    std::cout << "      +       "<<std::endl;
    printMatrix(index_2);
    std::cout << "      =       "<<std::endl;
    matrice.matrix_index = claster.size();
    matrice.cols = claster[index_1].cols;
    matrice.rows = claster[index_1].rows;
    for (int i = 0; i < claster[index_1].rows; i++)
    {            
        matrice.data.push_back(std::vector<double>());
        for (int j = 0; j < claster[index_1].cols; j++)
        {
            matrice.data[i].push_back(claster[index_1].data[i][j] + claster[index_2].data[i][j]);
            std::cout<< claster[index_1].data[i][j] + claster[index_2].data[i][j] << "     ";
        }
        std::cout<<std::endl;
    }
    std::cout<<"Would you like to save matrix? \n Y/N"<<std::endl;
    std::cin>>commandIn;
    for (int i=0; i < commandIn.size() ; i++)
        {
            command+= tolower(commandIn[i]);
        }
    int x = 0;
    while (x != 1)
    {
        if( command == "y" || command == "yes")
        {
            claster.insert({matrice.matrix_index, matrice});
            x=1;
        }
        else if (command == "n" || command == "no")
        {
            x=1;
        }
        else
        {
            std::cout<<"Wrong command"<<std::endl;
            std::cout<<"Would you like to save matrix? \n Y/N"<<std::endl;
        }
    }
    return;    
}

void Matrix::subMatrix(int index_1, int index_2)
{

    if (claster.empty())
    {
        std::cout << "ERROR \n THERE IS NO MATRIX TO ADD " << std::endl;
        return;
    }
    if (claster[index_1].rows != claster[index_2].rows || claster[index_1].cols != claster[index_2].cols)
    {
        std::cout << "ERROR \n MATRICES HAVE DIFFERENT DIMENSIONS " << std::endl;
        return;
    }
    printMatrix(index_1);
    std::cout << "      -       "<<std::endl;
    printMatrix(index_2);
    std::cout << "      =       "<<std::endl;
    Matrices matrice;
    matrice.matrix_index = claster.size();
    matrice.cols = claster[index_1].cols;
    matrice.rows = claster[index_1].rows;
    for (int i = 0; i < claster[index_1].rows; i++)
    {            
        matrice.data.push_back(std::vector<double>());
        for (int j = 0; j < claster[index_1].cols; j++)
        {
        matrice.data[i].push_back(claster[index_1].data[i][j] - claster[index_2].data[i][j]);
        std::cout<< claster[index_1].data[i][j] - claster[index_2].data[i][j] << "     ";
        }
        std::cout<<std::endl;
    }
    std::string commandIn,command;
    std::cout<<"Would you like to save matrix? \n Y/N"<<std::endl;
    std::cin>>commandIn;
    for (int i=0; i < commandIn.size() ; i++)
        {
            command+= tolower(commandIn[i]);
        }
    int x = 0;
    while (x != 1)
    {
        if( command == "y" || command == "yes")
        {
            claster.insert({matrice.matrix_index, matrice});
            x=1;
        }
        else if (command == "n" || command == "no")
        {
            x=1;
        }
        else
        {
            std::cout<<"Wrong command"<<std::endl;
            std::cout<<"Would you like to save matrix? \n Y/N"<<std::endl;
        }
    }
    return;   
}

void Matrix::multMatrix(int index_1, int index_2)
{
    std::string commandIn,command;
    if (claster.empty())
    {
        std::cout << "ERROR \n THERE IS NO MATRIX TO MULTIPLY " << std::endl;
        return;
    }
    if (claster[index_1].cols != claster[index_2].rows)
    {
        std::cout << "ERROR \n MATRICES HAVE DIFFERENT DIMENSIONS " << std::endl;
        return;
    }    
    Matrices matrice;
    matrice.matrix_index = claster.size();        
    matrice.cols = claster[index_1].cols;
    matrice.rows = claster[index_2].rows;
    std::vector<std::vector<double>> a = dotProduct(index_1,index_2);
    for (int i = 0; i < claster[index_1].rows; i++)
    {
        matrice.data.push_back(std::vector<double>());
        for (int j = 0; j < claster[index_1].cols; j++)
        {
            matrice.data[i].push_back(a[i][j]);
            std::cout<< a[i][j] << "     ";
        }
        std::cout<<std::endl;
    }
    std::cout<<"Would you like to save matrix? \n Y/N"<<std::endl;
    std::cin>>commandIn;
    for (int i=0; i < commandIn.size() ; i++)
        {
            command+= tolower(commandIn[i]);
        }
    int x = 0;
    while (x != 1)
    {
        if( command == "y" || command == "yes")
        {
            claster.insert({matrice.matrix_index, matrice});
            x=1;
        }
        else if (command == "n" || command == "no")
        {
            x=1;
        }
        else
        {
            std::cout<<"Wrong command"<<std::endl;
            std::cout<<"Would you like to save matrix? \n Y/N"<<std::endl;
        }
    }
    return;    
}

std::vector<std::vector<double>> Matrix::dotProduct(int index_1, int index_2) {
    double dot; 
    std::vector<std::vector<double>> result;
    for (int i = 0; i < claster[index_1].rows; i++)
    {
        result.push_back(std::vector<double>());
        for (int j = 0; j < claster[index_2].cols; j++)
        {
            dot = 0;
            for (int k = 0; k < claster[index_1].cols; k++)
            {
                dot += claster[index_1].data[i][k] * claster[index_2].data[k][j];
            }
            result[i].push_back(dot);
        }
    }
    return result;
}

void Matrix::multMatrixByScalar(int index_1, double scalar)
{
    if (claster.empty())
    {
        std::cout << "ERROR \n THERE IS NO MATRIX TO MULTIPLY " << std::endl;
        return;
    }
    Matrices matrice;
    matrice.matrix_index = claster.size();
    matrice.cols = claster[index_1].cols;
    matrice.rows = claster[index_1].rows;
    for (int i = 0; i < claster[index_1].rows; i++)
    {
        matrice.data.push_back(std::vector<double>());
        for (int j = 0; j < claster[index_1].cols; j++)
        {
            matrice.data[i].push_back(claster[index_1].data[i][j] * scalar);
        }
    }
    claster.insert({matrice.matrix_index, matrice});
    return;
}

std::vector<std::vector<double>> Matrix::multMatrixByScalar2(std::vector<std::vector<double>> matrix, double scalar)
{
    std::vector<std::vector<double>> result;
    for (int i = 0; i < matrix.size(); i++)
    {
        result.push_back(std::vector<double>());
        for (int j = 0; j < matrix[i].size(); j++)
        {
            result[i].push_back(matrix[i][j] * scalar);
        }
    }
    return result;
}

void Matrix::transposeMatrix(int index_1)
{
    if (claster.empty())
    {
        std::cout << "ERROR \n THERE IS NO MATRIX TO TRANSPOSE " << std::endl;
        return;
    }
    Matrices matrice;
    matrice.matrix_index = claster.size();
    matrice.cols = claster[index_1].rows;
    matrice.rows = claster[index_1].cols;
    for (int i = 0; i < claster[index_1].cols; i++)
    {
        matrice.data.push_back(std::vector<double>());
        for (int j = 0; j < claster[index_1].rows; j++)
        {
            matrice.data[i].push_back(claster[index_1].data[j][i]);
        }
    }
    claster.insert({matrice.matrix_index, matrice});
    return;
}

std::vector<std::vector<double>> Matrix::transposeMatrix(std::vector<std::vector<double>> matrix)
{
    std::vector<std::vector<double>> result;
    for (int i = 0; i < matrix[0].size(); i++)
    {
        result.push_back(std::vector<double>());
        for (int j = 0; j < matrix.size(); j++)
        {
            result[i].push_back(matrix[j][i]);
        }
    }
    return result;
}

void Matrix::determinantMatrix(int index_1)
{
    if (claster.empty())
    {
        std::cout << "ERROR \n THERE IS NO MATRIX TO CALCULATE DETERMINANT " << std::endl;
        return;
    }
    if (claster[index_1].rows != claster[index_1].cols)
    {
        std::cout << "ERROR \n MATRIX IS NOT SQUARE " << std::endl;
        return;
    }
    double determinant = determinantMatrix(claster[index_1].data);
    std::cout << "DETERMINANT OF MATRIX " << index_1 << " IS " << determinant << std::endl;
    return;
}

double Matrix::determinantMatrix(std::vector<std::vector<double>> matrix)
{
    if (matrix.size() ==2)
    {
        return determinantMatrix2by2(matrix);
    }

    double determinant = 0;
    for (int i = 0; i < matrix.size(); i++)
    {
        std::vector<std::vector<double>> minor;
        for (int j = 1; j < matrix.size(); j++)
        {
            minor.push_back(std::vector<double>());
            for (int k = 0; k < matrix.size(); k++)
            {
                if (k != i)
                {
                    minor[j - 1].push_back(matrix[j][k]);
                }
            }
        }
        determinant += pow(-1, i) * matrix[0][i] * determinantMatrix(minor);
    }
    return determinant; 
}

double Matrix::determinantMatrix2by2(std::vector<std::vector<double>> matrix)
{
    double determinant = 0;
    determinant = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    return determinant;
}

void Matrix::inverseMatrix(int index_1)
{
    if (claster.empty())
    {
        std::cout << "ERROR \n THERE IS NO MATRIX TO CALCULATE INVERSE " << std::endl;
        return;
    }
    if (claster[index_1].rows != claster[index_1].cols)
    {
        std::cout << "ERROR \n MATRIX IS NOT SQUARE " << std::endl;
        return;
    }
    double determinant = determinantMatrix(claster[index_1].data);
    if (determinant == 0)
    {
        std::cout << "ERROR \n MATRIX IS NOT INVERTIBLE " << std::endl;
        return;
    }
    std::vector<std::vector<double>> inverse = inverseMatrix(claster[index_1].data);
    Matrices matrice;
    matrice.matrix_index = claster.size();
    matrice.cols = claster[index_1].cols;
    matrice.rows = claster[index_1].rows;
    for (int i = 0; i < claster[index_1].rows; i++)
    {
        matrice.data.push_back(std::vector<double>());
        for (int j = 0; j < claster[index_1].cols; j++)
        {
            matrice.data[i].push_back(inverse[i][j]);
        }
    }
    claster.insert({matrice.matrix_index, matrice});
    return;
}

std::vector<std::vector<double>> Matrix::inverseMatrix(std::vector<std::vector<double>> matrix)
{
    std::vector<std::vector<double>> inverse;
    double determinant = determinantMatrix(matrix);
    for (int i = 0; i < matrix.size(); i++)
    {
        inverse.push_back(std::vector<double>());
        for (int j = 0; j < matrix.size(); j++)
        {
            std::vector<std::vector<double>> minor;
            for (int k = 0; k < matrix.size(); k++)
            {
                if (k != i)
                {
                    minor.push_back(std::vector<double>());
                    for (int l = 0; l < matrix.size(); l++)
                    {
                        if (l != j)
                        {
                            minor[minor.size() - 1].push_back(matrix[k][l]);
                        }
                    }
                }
            }
            inverse[i].push_back(pow(-1, i + j) * determinantMatrix(minor));
        }
    }
    inverse = multMatrixByScalar2(inverse, 1 / determinant);
    inverse = transposeMatrix(inverse);
    return inverse;
}

void Matrix::saveMatrix(std::string fileName)
{
    if (claster.empty())
    {
        std::cout << "ERROR \n THERE IS NO MATRIX TO SAVE " << std::endl;
        return;
    }
    std::ofstream file;
    file.open(fileName);
    if (file.is_open())
    {
        for (int i = 0; i < claster.size(); i++)
        {
            
            file << claster[i].rows << "x" << claster[i].cols<<";";
            for (int j = 0; j < claster[i].rows; j++)
            {
                for (int k = 0; k < claster[i].cols; k++)
                {
                    file << claster[i].data[j][k] << ";";
                }
            }
            file << std::endl;
        }
    }
    else
    {
        std::cout << "ERROR \n CANNOT OPEN FILE " << std::endl;
        return;
    }
    file.close();
    return;
    
}

void Matrix::clearMatrix()
{
    claster.clear();
    return;
}

void Matrix::deleteMatrix(int index_1)
{
    if (claster.empty())
    {
        std::cout << "ERROR \n THERE IS NO MATRIX TO DELETE " << std::endl;
        return;
    }
    if(claster.find(index_1) == claster.end())
    {
        std::cout << "ERROR \n THERE IS NO MATRIX WITH THIS INDEX " << std::endl;
        return;
    }
    claster.erase(index_1);
    return;
}
