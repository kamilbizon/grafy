#ifndef MATRIX_ADJ_H
#define MATRIX_ADJ_H

#include <fstream>
#include <vector>
#include "Adjency_list.h"

class Adjency_list;

class Matrix_adj
{
public:
    Matrix_adj();
    Matrix_adj(Adjency_list &list);
    void read_matrix(std::fstream &file);
    void print_matrix_adj();
    std::vector < std::vector < int > > get_matrix() const;

private:
    std::vector < std::vector < int > > matrix; // macierz przechowuje w wektorze wektorow intow
};

#endif // MATRIX_ADJ_H
