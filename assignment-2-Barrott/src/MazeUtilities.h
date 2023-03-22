#include "Stack.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>


#ifndef ASSIGNMENT_2_MAZEUTILITIES_H
#define ASSIGNMENT_2_MAZEUTILITIES_H




void run_maze(std::string input_path, std::string output_path);

void direct_path(std::vector<std::string> &map, Stack &stack);

void clear_maze(std::vector<std::string> &map);

void save_vector_to_file(std::vector<std::string> &map, std::string output_file);

bool valid_move(int x_pos, int y_pos,int gridsize, std::vector<std::string> map);

std::vector<std::string> open_file_to_vector(std::string input_file);

std::ostream& operator<<(std::ostream& output ,std::vector<std::string>& v);

#endif //ASSIGNMENT_2_MAZEUTILITIES_H#endif //ASSIGNMENT_2_MAZEUTILITIES_H