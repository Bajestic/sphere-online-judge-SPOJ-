//
//        Zadanie
//        Twoim zadaniem jest dla zadanego wyrazu, podanie skróconej wersji tego wyrazu.
//
//        Wejście
//        W pierwszej linijce wejścia znajduje się liczba naturalna C, 1 ≤ C ≤ 50, oznaczająca
//        ilość zestawów danych. W kolejnych C wierszach wejścia znajdują się zestawy danych.
//        Każdy zestaw składa się z niepustego wyrazu złożonego z samych dużych liter alfabetu amerykańskiego.
//        Długość wyrazu nie przekracza 200 znaków.
//
//        Wyjście
//        Dla każdego zestawu danych, dla zadanego wyrazu, na wyjściu powinna znaleźć się jego skrócona wersja.

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

std::pair<std::string, std::vector<int> > make_words(const std::string & s);
void display(std::pair<std::string, std::vector<int> > & s);

int main()
{
    unsigned short test;

    if (std::cin >> test && (test > 0 && test <= 50))
    {
        std::vector<std::string> words(test);
        std::vector<std::pair<std::string,std::vector<int> > >result;
        typedef std::vector<std::pair<std::string,std::vector<int> > > TypeIter;

        for (int i = 0; i < test ;i++) {
            std::cin >> words[i];
        };
        std::back_insert_iterator< TypeIter > iter(result);
        std::transform(words.begin(), words.end(), iter, make_words);
        std::for_each(result.begin(),result.end(), display);
    }

    return 0;
}

std::pair<std::string, std::vector<int> > make_words(const std::string & s)
{
    std::pair<std::string, std::vector<int> > temp;
    int SIZE = s.size();
    int counter = 1;
    temp.first = s[0];
    for (auto it = s.begin(); it != s.end(); it++)
    {
        if (*it == *(it + 1)) {
            counter++;
        }
        else
        {
            temp.first += *(it + 1);
            temp.second.push_back(counter);
            counter = 1;
        }
    };

    temp.first.pop_back();

    return temp;
}

void display(std::pair<std::string, std::vector<int> > & s)
{
    int SIZE = s.first.size();
    for (int i = 0; i < SIZE; i++)
        if (s.second[i] < 3)
            for (int j = 0; j < s.second[i]; j++)
                std::cout << s.first[i];

        else
            std::cout << s.first[i] << s.second[i];

    std::cout << std::endl;
}

