#include "Adjency_list.h"

#include <iostream>
#include <random>
#include <time.h>
#include <algorithm>
#include <limits>

using std::cout;
using std::vector;
using std::fstream;

Adjency_list::Adjency_list()
{}

Adjency_list::Adjency_list(Matrix_adj &matrix)  // kowersja z macierzy sasiedztwa
{
    vector < vector < int > > temp_matrix = matrix.get_matrix();    // kopiuje macierz

    for(int row = 0; row < (int)temp_matrix.size(); row++)  //  tworze tyle vektorow ile jest wierzcholkow
        list.push_back(vector < int >());

    for(int row = 0; row < (int)temp_matrix.size(); row++)  // ide po kazdym wierzcholku
        for(int col = 0; col < (int)temp_matrix[row].size(); col++) // i po polaczeniach tego wierzcholka z kazym innym
            if(temp_matrix[col][row] == 1)     // 1 oznacza ze polaczenie istnieje
                list[row].push_back(col);   // wiec dodajeje do listy
}

Adjency_list::Adjency_list(Matrix_inc &matrix)  // kowersja z macierzy incydencji
{
    vector < vector < int > > temp_matrix = matrix.get_matrix();    // kopiuje macierz

    for(int row = 0; row < (int)temp_matrix.size(); row++)  // tworze tyle vectorow ile jest wierzcholkow (liczba rzedow macierzy - liczba wektorow w niej)
        list.push_back(vector < int >());

    for(int col = 0; col < (int)temp_matrix[0].size(); col++)   // sprawdzam kazda kolumne(krawedz) i szukam polaczonych nia wierzcholkow
    {
        vector <int> vertices; // tworze pomocnicza tablice na szukane wierzcholki

        for(int row = 0; row < (int)temp_matrix.size(); row++)
        {
            if(temp_matrix[row][col] == 1)  // jezeli 1 to dana krawedz laczy dany wierzcholek
                vertices.push_back(row);    // dodaje go do tablicy
            if(vertices.size() == 2)    // jezeli znalazlem juz 2 wierzcholki ktore laczy krawedz wychodze z petli
                break;
        }

        list[vertices[0]].push_back(vertices[1]);   //  dodaje do obu wierzcholkow ze sasiaduja ze soba
        list[vertices[1]].push_back(vertices[0]);

        vertices.clear();   // czyszcze pomocnicza tablice przed nastepnym obiegiem
    }
}

void Adjency_list::read_list(fstream &file)
{
    list.clear();
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

void Adjency_list::generate(int n, int l)   // tworzy liste sasiedztwa na podstawie paramatrow n - liczba wierzcholkow, l -liczba krawedzi
{
    list.clear();   // gdyby lista juz istniala czyscimy ja
    if(l > (n*(n-1))/2)     // liczba krawedzi nie morze byc wieksza od tej wartosci
        l = (n*(n-1))/2;    // jesli jest zmniejszamy ja do wartosci maksymalnej

    for(int i = 0; i < n; ++i)
        list.push_back(vector < int >());


    std::srand(time(NULL));
    for(int i = 0; i < l;)
    {
        int first_vertice = std::rand() % n;    // losujemy pierwsza krawedz
        int second_vertice;
        do
            second_vertice = std::rand() % n;
        while(second_vertice == first_vertice); // losujemy druga krawedz tak zeby nie byla pierwsza

        if(std::find(list[first_vertice].begin(), list[first_vertice].end(), second_vertice) == list[first_vertice].end())
        {                                                                   // jezeli taka krawedz jeszcze nie istnieje dodajemy ja
            list[first_vertice].push_back(second_vertice);
            list[second_vertice].push_back(first_vertice);
            ++i;    // indeks zwiekszamy dopiero po dodaniu krawedzi zeby zadnej nie opuscic
        }
    }
}

void Adjency_list::generate(int n, float probability)
{
    list.clear();   // gdyby lista juz istniala czyscimy ja
    if(probability > 1)     // sprowadzamy prawdopodobienstwo do przedzialu <0; 1>
        probability = 1;
    else if(probability < 0)
        probability = 0;

    for(int i = 0; i < n; ++i)
        list.push_back(vector < int >());

    std::srand(time(NULL));
    {
        for(int i = 0; i < n; ++i)
            for(int j = i+1; j < n; j++)    // dla kazdej krawedzi losujemy czy krawedzie o numerach wyzszych od niej sa z nia polaczone
            {
                float sample = static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX);
                if(sample < probability)
                {
                    list[i].push_back(j);
                    list[j].push_back(i);
                }
            }
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
    cout << "\n";
}

void Adjency_list::save_to_file_adj_list()
{
    fstream file;
    file.open("adj_list.txt", std::ios::out);
    file << "L";

    for(int col = 0; col < (int)list.size(); col++)
    {
        file << "\n";
        file << col << ": ";
        for(int row = 0; row < (int)list[col].size(); row++)
        {
            file << " " << list[col][row];
        }
    }
}

vector < vector < int > > Adjency_list::get_list() const
{
    return list;
}
