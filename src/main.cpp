#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include "Adjency_list.h"
#include "Matrix_adj.h"
#include "Matrix_inc.h"

using std::fstream;
using std::vector;
using std::cout;
using std::cin;

int main(void)
{
    fstream file;

    cout << "Jesli chcesz odczytac graf z pliku wpisz O, jesli wygenereowac graf wpisz W\n";
    char mode;
    cin >> mode;

    switch(mode)
    {
    case 'O':
        {
            cout << "Podaj nazwe pliku, z kotrego odczytujesz graf: ";
            std::string file_name;
            cin >> file_name;

            file.open(file_name, std::ios::in); // odczytuje graf z pliku, format zapisu grafu podany
            if(file.is_open())
            {
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
                    cout << "cos nie dziala :(\n";
                }

                cout << std::endl;
                file.close();
            }
            break;
        }
    case 'W':
        {
            cout << "Jesli wygenereowac graf na podstawie ilosci krawedzi wpisz K, jesli chcesz podac prawdopodobienstwo wpisz P\n";
            cin >> mode;

            switch(mode)
            {
            case 'K':
            {
                cout << "Podaj liczbe wierzcholkow: ";
                int number_of_vertices;
                cin >> number_of_vertices;
                cout << "Podaj liczbe krawedzi: ";
                int number_of_edges;
                cin >> number_of_edges;

                Adjency_list list_a;
                list_a.generate(number_of_vertices, number_of_edges);
                list_a.print_list();
                list_a.save_to_file_adj_list();
                Matrix_inc mat_i(list_a);
                mat_i.print_matrix_inc();
                mat_i.save_to_file_matrix_inc();
                Matrix_adj mat_a(list_a);
                mat_a.print_matrix_adj();
                mat_a.save_to_file_matrix_adj();

                break;
            }
            case 'P':
            {
                cout << "Podaj liczbe wierzcholkow: ";
                int number_of_vertices;
                cin >> number_of_vertices;
                cout << "Podaj prawdopodobienstwo: ";
                float probability;
                cin >> probability;

                Adjency_list list_a;
                list_a.generate(number_of_vertices, probability);
                list_a.print_list();
                list_a.save_to_file_adj_list();
                Matrix_inc mat_i(list_a);
                mat_i.print_matrix_inc();
                mat_i.save_to_file_matrix_inc();
                Matrix_adj mat_a(list_a);
                mat_a.print_matrix_adj();
                mat_a.save_to_file_matrix_adj();

                break;
            }
            default:
                cout << "Cos zrobiles zle, sproboj jeszcze raz";
                exit (EXIT_FAILURE);
            }
            break;
        }
    default:
        cout << "Cos zrobiles zle, sproboj jeszcze raz";
        exit (EXIT_FAILURE);
    }
}
