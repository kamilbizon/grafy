#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>

using std::fstream;
using std::vector;
using std::cout;

void read_list(fstream &file, int &n, vector < vector < int > > &list);
void read_matrix(fstream &file, int &n, vector < vector < int > > &list);

int main(void)
{
    fstream file;

    file.open("graph.txt", std::ios::in);

    char flag;
    file >> flag;
    file.get();

    vector < vector < int > > list;

    int n = 0;


    switch(flag)
    {
    case 'L':
        read_list(file, n, list);
        break;
    case 'S':
        break;
    case 'I':
        break;
    }

    for(int col = 0; col < n; col++)
    {
        cout << col << ": ";
        for(int row = 0; row < (int)list[col].size(); row++)
        {
            cout << list[col][row] << " ";
        }
        cout << "\n";
    }

    file.close();
}


void read_list(fstream &file, int &n, vector < vector < int > > &list)
{
    char find_endline;
    int temp;

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
    n--;
}

void read_matrix(fstream &file, int &n, vector < vector < int > > &list)
{
    char find_endline;
    int temp;

    file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

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
    n--;
}
