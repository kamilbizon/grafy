#include "Matrix_inc.h"

#include <iostream>
#include <limits>
#include <algorithm>

using std::cout;
using std::vector;
using std::fstream;

Matrix_inc::Matrix_inc()
{}

Matrix_inc::Matrix_inc(Adjency_list &list) // konwersja z listy sasiedztwa
{
    vector < vector < int > > temp_list = list.get_list();  // pobieram tablice przedstawiajace liste

    int number_of_edges = 0;

    for(int row = 0; row < (int)temp_list.size(); row++)
        number_of_edges += temp_list[row].size();   // licze wszystkich sasiadow kazdego wierzcholka

    number_of_edges /= 2;   //  dzielac wartosc przez dwa mam liczbe krawedzi

    for(int row = 0; row < (int)temp_list.size(); row++)    // tworze macierz nxm (n - liczba wierzcholkow, m - liczba krawedzi)
    {
        matrix.push_back(vector < int >());     // tworze n - wektorow

        for(int col = 0; col < number_of_edges; col++)
            matrix[row].push_back(0);   // w kazdym wektorze tworze m intow, ustawiam je na 0
    }

    int edge = 0;   // dla kazdej krawedzi bede ustawial 2 wierzcholki ktorw laczy

    for(int row = 0; row < (int)temp_list.size(); row++)    // kazdy rzad to jeden wierzcholek
    {
        for(int col = 0; col < (int)temp_list[row].size(); col++)
        {
            matrix[row][edge] = 1;  // ustawiam pierwszy wierzcholek dla krawedzi
            int second_vertice = temp_list[row][col];
            matrix[second_vertice][edge] = 1;   // ustawiam drugi wierzcholek
            temp_list[second_vertice].erase(std::find(temp_list[second_vertice].begin(), temp_list[second_vertice].end(), row));    // usuwam pierwszy wierzcholek przy drugim wierzcholku na liscie, zeby go nie powtorzyc
            edge++; // przechodze do nastepnej krawedzi
        }
    }
}

void Matrix_inc::read_matrix(fstream &file)
{
    char find_endline;
    int temp, n = 0;

    file.get();
    file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    while(!file.eof())
    {
        matrix.push_back(vector < int >());
        file.ignore(2);

        find_endline = file.get();
        while(find_endline == '\t')
        {
            file >> temp;
            matrix[n].push_back(temp);
            find_endline = file.get();
        }

        n++;
    }
}

void Matrix_inc::print_matrix_inc()
{
    cout << "  \t";
    for(int col = 0; col < (int)matrix[0].size(); col++)
        cout << "L" << col << "\t";
    for(int col = 0; col < (int)matrix.size(); col++)
    {
        cout << "\n";
        cout << col << ":\t";
        for(int row = 0; row < (int)matrix[col].size(); row++)
        {
            cout << matrix[col][row] << "\t";
        }
    }
    cout << std::endl << std::endl;
}

void Matrix_inc::save_to_file_matrix_inc()
{
    fstream file;
    file.open("matrix_inc.txt", std::ios::out);
    file << "I\n";
    file << "  \t";
    for(int col = 0; col < (int)matrix[0].size(); col++)
        file << "L" << col << "\t";
    for(int col = 0; col < (int)matrix.size(); col++)
    {
        file << "\n";
        file << col << ":\t";
        for(int row = 0; row < (int)matrix[col].size(); row++)
        {
            file << matrix[col][row];
            if(row < (int)matrix[col].size() - 1)
                file << "\t";
        }
    }
}


vector < vector < int > > Matrix_inc::get_matrix() const
{
    return matrix;
}
