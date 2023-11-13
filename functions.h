#include <string> 
#include <vector>
#include <unordered_map>
#ifndef FUNCTS_H
#define FUNCTS_H



/**
 * @brief Run the interactive console
 * 
 * @return 
 */
void interactiveConsole();

/**
 * @brief reading lines from file and putting them in map
 * 
 * @param map 
 * @return int 
 */
std::unordered_map<int, std::vector<std::string> > readFile(std::string &inputFile);



#endif