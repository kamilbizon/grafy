#include "Adjency_list.h"

#include <iostream>

using std::cout;
using std::vector;
using std::fstream;

Adjency_list::Adjency_list()
{}

Adjency_list::Adjency_list(Matrix_adj &matrix)
{
    vector < vector < int > > temp_matrix = matrix.get_matrix();

    for(int row = 0; row < (int)temp_matrix.size(); row++)
        list.push_back(vector < int >());

    for(int row = 0; row < (int)temp_matrix.size(); row++)
        for(int col = 0; col < (int)temp_matrix[row].size(); col++)
            if(temp_matrix[col][row] == 1)
                list[row].push_back(col);
}

Adjency_list::Adjency_list(Matrix_inc &matrix)
{
    vector < vector < int > > temp_matrix = matrix.get_matrix();

    for(int row = 0; row < (int)temp_matrix.size(); row++)
        list.push_back(vector < int >());

    for(int col = 0; col < (int)temp_matrix[0].size(); col++)
    {
        vector <int> vertices;

        for(int row = 0; row < (int)temp_matrix.size(); row++)
            if(temp_matrix[row][col] == 1)
                vertices.push_back(row);

        list[vertices[0]].push_back(vertices[1]);
        list[vertices[1]].push_back(vertices[0]);

        vertices.clear();
    }
}

void Adjency_list::read_list(fstream &file)
{
    char find_endline;
    int temp, n = 0;

    file.get();

    while(!file.eof())
    {
        list.push_back(vector < int >());
        file.ignore(2);

        find_endline = file.get();
        while(find_endline == ' ')
        {
            file >> temp;
            list[n].push_back(temp);
            find_endline = file.get();
        }

        n++;
    }
}

void Adjency_list::print_list(void)
{
    for(int col = 0; col < (int)list.size(); col++)
    {
        cout << col << ": ";
        for(int row = 0; row < (int)list[col].size(); row++)
        {
            cout << list[col][row] << " ";
        }
        cout << "\n";
    }
}

vector < vector < int > > Adjency_list::get_list() const
{
    return list;
}
