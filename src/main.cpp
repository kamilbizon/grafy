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

    file.open("graph1.txt", std::ios::in); // odczytuje graf z pliku, format zapisu grafu podany

    char flag;
    file >> flag;   // wczytuje pierwsza litere, ktora oznacza sposob prezentacji grafu

    switch(flag)
    {
    case 'L': // lista sasiedztwa
        {
            Adjency_list list_adj;
            list_adj.read_list(file);   //wczytuje liste z pliku
            list_adj.print_list();
            Matrix_adj matrix_adj(list_adj);    // tworze macierz sasiedztwa na podstawie listy
            matrix_adj.print_matrix_adj();
            Matrix_inc matrix_inc(list_adj);    // tworze macierz incydencji na podstawie listy
            matrix_inc.print_matrix_inc();
            break;
        }
    case 'A': // macierz sadsiedztwa
        {
            Matrix_adj matrix_adj;
            matrix_adj.read_matrix(file);
            matrix_adj.print_matrix_adj();
            Adjency_list list_adj(matrix_adj);
            list_adj.print_list();
            Matrix_inc matrix_inc(list_adj);    // tlumaczac macierz sasiedztwa/incydencji zawsze posrednicze przez liste
            matrix_inc.print_matrix_inc();
            break;
        }
    case 'I': // macierz incydencji
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
