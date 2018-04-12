#ifndef MATRIX_INC_H
#define MATRIX_INC_H

#include <fstream>
#include <vector>
#include "Adjency_list.h"

class Adjency_list;

class Matrix_inc
{
public:
    Matrix_inc();
    Matrix_inc(Adjency_list &list);
    void read_matrix(std::fstream &file);
    void print_matrix_inc();
    void save_to_file_matrix_inc();
    std::vector < std::vector < int > > get_matrix() const;


private:
    std::vector < std::vector < int > > matrix; // macierz przechowuje w wektorze wektorow intow
};

#endif // MATRIX_INC_H
