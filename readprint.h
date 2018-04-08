#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>


void read_list(std::fstream &file, std::vector < std::vector < int > > &list);
void print_list(std::vector < std::vector < int > > &list);
void read_matrix(std::fstream &file, std::vector < std::vector < int > > &matrix);
void print_matrix_adj(std::vector < std::vector < int > > &matrix);
void print_matrix_inc(std::vector < std::vector < int > > &matrix);
