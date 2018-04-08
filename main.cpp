#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>
#include "readprint.h"

using std::fstream;
using std::vector;
using std::cout;

//void read_list(fstream &file, vector < vector < int > > &list);
//void print_list(vector < vector < int > > &list);
//void read_matrix(fstream &file, vector < vector < int > > &matrix);
//void print_matrix_adj(vector < vector < int > > &matrix);
//void print_matrix_inc(vector < vector < int > > &matrix);

int main(void)
{
    fstream file;

    file.open("graph1.txt", std::ios::in);

    char flag;
    file >> flag;

    vector < vector < int > > list;

    switch(flag)
    {
    case 'L':
        read_list(file, list);
        print_list(list);
        break;
    case 'S':
        read_matrix(file, list);
        print_matrix_adj(list);
        break;
    case 'I':
        read_matrix(file, list);
        print_matrix_inc(list);
        break;
    default:
        cout << "cos nie dziala :(";
    }

    file.close();
}


//void read_list(fstream &file, vector < vector < int > > &list)
//{
//    char find_endline;
//    int temp, n = 0;
//
//    file.get();
//
//    while(!file.eof())
//    {
//        list.push_back(vector < int >());
//        file.ignore(2);
//
//        find_endline = file.get();
//        while(find_endline == ' ')
//        {
//            file >> temp;
//            list[n].push_back(temp);
//            find_endline = file.get();
//        }
//
//        n++;
//    }
//}
//
//void print_list(vector < vector < int > > &list)
//{
//    for(int col = 0; col < list.size(); col++)
//    {
//        cout << col << ": ";
//        for(int row = 0; row < (int)list[col].size(); row++)
//        {
//            cout << list[col][row] << " ";
//        }
//        cout << "\n";
//    }
//}
//
//void read_matrix(fstream &file, vector < vector < int > > &matrix)
//{
//    char find_endline;
//    int temp, n = 0;
//
//    file.get();
//    file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//
//    while(!file.eof())
//    {
//        matrix.push_back(vector < int >());
//        file.ignore(2);
//
//        find_endline = file.get();
//        while(find_endline == '\t')
//        {
//            file >> temp;
//            matrix[n].push_back(temp);
//            find_endline = file.get();
//        }
//
//        n++;
//    }
//}
//
//void print_matrix_adj(vector < vector < int > > &matrix)
//{
//    cout << "   ";
//    for(int col = 0; col < matrix.size(); col++)
//        cout << col << " ";
//    for(int col = 0; col < matrix.size(); col++)
//    {
//        cout << "\n";
//        cout << col << ": ";
//        for(int row = 0; row < (int)matrix[col].size(); row++)
//        {
//            cout << matrix[col][row] << " ";
//        }
//    }
//}
//
//void print_matrix_inc(vector < vector < int > > &matrix)
//{
//    cout << "  \t";
//    for(int col = 0; col < matrix[0].size(); col++)
//        cout << "L" << col << "\t";
//    for(int col = 0; col < matrix.size(); col++)
//    {
//        cout << "\n";
//        cout << col << ":\t";
//        for(int row = 0; row < (int)matrix[col].size(); row++)
//        {
//            cout << matrix[col][row] << "\t";
//        }
//    }
//}
