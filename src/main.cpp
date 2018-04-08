#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Adjency_list.h"
#include "Matrix_adj.h"
#include "Matrix_inc.h"

using std::fstream;
using std::vector;
using std::cout;

int main(void)
{
    fstream file;

    file.open("graph1.txt", std::ios::in);

    char flag;
    file >> flag;

    switch(flag)
    {
    case 'L':
        {
            Adjency_list list_adj;
            list_adj.read_list(file);
            list_adj.print_list();
            Matrix_adj matrix_adj(list_adj);
            matrix_adj.print_matrix_adj();
            Matrix_inc matrix_inc(list_adj);
            matrix_inc.print_matrix_inc();

            break;
        }
    case 'S':
        {
            Matrix_adj matrix_adj;
            matrix_adj.read_matrix(file);
            matrix_adj.print_matrix_adj();
            Adjency_list list_adj(matrix_adj);
            list_adj.print_list();
            Matrix_inc matrix_inc(list_adj);
            matrix_inc.print_matrix_inc();
            break;
        }
    case 'I':
        {
            Matrix_inc matrix_inc;
            matrix_inc.read_matrix(file);
            matrix_inc.print_matrix_inc();
            Adjency_list list_adj(matrix_inc);
            list_adj.print_list();
            Matrix_adj matrix_adj(list_adj);
            matrix_adj.print_matrix_adj();

            break;
        }
    default:
        cout << "cos nie dziala :(";
    }

    file.close();
}
