
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#ifndef STRUCTS_H
#define STRUCTS_H

class Matrix
{
private:
    class Matrices{
        public: 
            int matrix_index;
            int rows;
            int cols;
            std::vector<std::vector<double>> data;
    };
    std::unordered_map <int, Matrices> claster;


public:
    
   /**
    * @brief Construct a new Matrix object
    * 
    * @param rows 
    * @param cols 
    */
    Matrix();

    /**
     * @brief Function that create matrice and fill it with data from vectorx
     * 
     * @param _rows 
     * @param _cols 
     * @param values 
     */
    void fillingMatrix(int _rows, int _cols, std::vector<double> values);

    void saving(int, Matrices);

    /**
     * @brief Function that print matrix in terminal
     * 
     */
    void printMatrix();

    void printMatrix(int w);

    /**
     * @brief Function that add two matrices
     * 
     * @param index_1 
     * @param index_2 
     */
    void addMatrix(int index_1, int index_2);

    /**
     * @brief Function that substract two matrices
     * 
     * @param index_1 
     * @param index_2 
     */
    void subMatrix(int index_1, int index_2);

    /**
     * @brief Function that multipy two matrices
     * 
     * @param index_1 
     * @param index_2 
     */
    void multMatrix(int index_1, int index_2);

    /**
     * @brief Function that calculate dot product two matrices
     * 
     * @param index_1 
     * @param index_2 
     */
    std::vector<std::vector <double>> dotProduct(int index_1, int index_2);

    /**
     * @brief Function that calculate scalar multiplication
     * 
     * @param index_1 
     * @param scalar 
     */
    void multMatrixByScalar(int index_1, double scalar);

    std::vector<std::vector<double>> multMatrixByScalar2(std::vector<std::vector<double>> matrix, double scalar);

    /**
     * @brief Function that calculate transpose matrix
     * 
     * @param index_1 
     */
    void transposeMatrix(int index_1);

    std::vector<std::vector<double>> transposeMatrix(std::vector<std::vector<double>> matrix);

    /**
     * @brief Function that calculate inverse matrix
     * 
     * @param index_1 
     */
    void inverseMatrix(int index_1);

    /**
     * @brief Function that calculate determinant matrix 2x2
     * 
     * @param matrix 
     * @return double 
     */
    double determinantMatrix2by2(std::vector<std::vector<double>> matrix);

    double determinantMatrix(std::vector<std::vector<double>> matrix);

    /**
     * @brief Function that calculate determinant matrix
     * 
     * @param index_1 
     */
    void determinantMatrix(int index_1);

    /**
     * @brief Function that calculate cofactor matrix
     * 
     * @param matrix 
     * @return std::vector<std::vector<double>> 
     */
    std::vector<std::vector<double>> inverseMatrix(std::vector<std::vector<double>> matrix);

    /**
     * @brief Function that save matrix in file
     * 
     * @param fileName 
     */
    void saveMatrix(std::string fileName);
    
    /**
     * @brief Functrion that clear matrix
     * 
     */
    void clearMatrix();

    /**
     * @brief Function that delete matrix
     * 
     * @param index 
     */
    void deleteMatrix(int index);





};




#endif