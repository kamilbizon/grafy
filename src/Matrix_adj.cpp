#include "Matrix_adj.h"

#include <iostream>
#include <limits>

using std::cout;
using std::vector;
using std::fstream;

Matrix_adj::Matrix_adj()
{}

Matrix_adj::Matrix_adj(Adjency_list &list)  // konwersja z listy sasiedztwa
{
    vector < vector < int > > temp_list = list.get_list();  // pobieram tablice przedstawiajace liste

    for(int row = 0; row < (int)temp_list.size(); row++)   // tworze macierz nxn (n - liczba wierzcholkow)
    {
        matrix.push_back(vector < int >()); // n - vectorow
        for(int col = 0; col < (int)temp_list.size(); col++)
            matrix[row].push_back(0);   // n - intow w kazdym wektorze, ustawiam na zero
    }


    for(int row = 0; row < (int)temp_list.size(); row++)
        for(int col = 0; col < (int)temp_list[row].size(); col++)
        {
            matrix[row][temp_list[row][col]] = 1;   // sprawdzam sasiadow dla kazdego wierzcholka i ustawiam go w macierzy
        }
}

void Matrix_adj::read_matrix(fstream &file)
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
        while(find_endline == ' ')
        {
            file >> temp;
            matrix[n].push_back(temp);
            find_endline = file.get();
        }

        n++;
    }
}

void Matrix_adj::print_matrix_adj()
{
    cout << "   ";
    for(int col = 0; col < (int)matrix.size(); col++)
        cout << col << " ";
    for(int col = 0; col < (int)matrix.size(); col++)
    {
        cout << "\n";
        cout << col << ": ";
        for(int row = 0; row < (int)matrix[col].size(); row++)
        {
            cout << matrix[col][row] << " ";
        }
    }
    cout << std::endl << std::endl;
}

void Matrix_adj::save_to_file_matrix_adj()
{
    fstream file;
    file.open("matrix_adj.txt", std::ios::out);
    file << "A\n";
    file << "   ";
    for(int col = 0; col < (int)matrix[0].size(); col++)
        file << col << " ";
    for(int col = 0; col < (int)matrix.size(); col++)
    {
        file << "\n";
        file << col << ": ";
        for(int row = 0; row < (int)matrix[col].size(); row++)
        {
            file << matrix[col][row];
            if(row < (int)matrix[col].size() - 1)
                file << " ";
        }
    }
}

vector < vector < int > > Matrix_adj::get_matrix() const
{
    return matrix;
}
