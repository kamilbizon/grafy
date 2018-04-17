#ifndef ADJENCY_LIST_H
#define ADJENCY_LIST_H

#include <fstream>
#include <vector>
#include "Matrix_adj.h"
#include "Matrix_inc.h"

class Matrix_adj;
class Matrix_inc;

class Adjency_list
{
public:
    Adjency_list();
    Adjency_list(Matrix_adj &matrix);
    Adjency_list(Matrix_inc &matrix);
    void read_list(std::fstream &file);
    void generate(int n, int l);
    void generate(int n, float probability);
    void print_list();
    void save_to_file_adj_list();
    std::vector < std::vector < int > > get_list() const;

private:
    std::vector < std::vector < int > > list;   // liste przechowuje w wektorze wektorow intow
};

#endif // ADJENCY_LIST_H
