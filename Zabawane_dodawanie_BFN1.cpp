//
//        Zadanie
//        Zadaniem jest stwierdzić, czy dana liczba jest palindromem
//        (tzn. czy czyta się ją tak samo od lewej do prawej strony, jak od prawej do lewej).
//        Jeżeli nie, powinno się dodać do siebie wartość liczby czytanej od lewej do prawej
//        oraz wartość liczby czytanej od prawej do lewej, sprawdzić, czy suma jest palindromem, i jeżeli nie
//        -- kontynuować proces, aż otrzyma palindromu.
//
//        Wejście
//        Pierwsza linia wejścia zawiera liczbę t (t <= 80),
//        określającą ile liczb znajduje się na wejściu.
//        Każda z następnych t linii zawiera dokładnie jedną liczbę naturalną n (1 <= n <= 80),
//        dla której należy wykonać obliczenia.
//
//        Wyjście
//        Dla kolejnych liczb podanych na wejściu wypisz po jednej linijce zawierającej dwie liczby całkowite oddzielone spacją.
//        Pierwsza oznacza palindrom otrzymany przez algorytm, druga -- liczbę dodawań wykonanych, by go otrzymać.

#include <iostream>
#include <cmath>

using std::cout;
using std::cin;

int inverse(int);

int main()
{
    unsigned short t{};
    int i{};
    if ( cin >> t && (t <= 80) )
    {
        unsigned short n{};
        int temp[t];
        int tempinverse[t];
        int cnt = 0;
        int counter[t];
        for ( ; i < t; i++)
        {
            if ( cin >> n && (n <= 80 && n > 0) )
            {
                temp[i] = n;
                tempinverse[i] = inverse(n);

                while (!(temp[i] == tempinverse[i]))
                {
                    temp[i] += tempinverse[i];
                    tempinverse[i] = inverse(temp[i]);
                    cnt++;
                }
                counter[i] = cnt;
                cnt = 0;
            }

            else
                return 0;
        }

        for (int i = 0; i < t; i++)
        {
            std::cout << temp[i] << " " << counter[i] << std::endl;
        };
    }

    return 0;
}

// funkcja odwracajaca liczbe
int inverse(int x)
{
    int counter;
    int temp = x;

    // najpierw zlicza ilosc cyfr w liczbie
    for (counter = 0; temp > 0 ;counter++)
    {
        temp /= 10; // odrzuca w petli cyfre jednosci i inkrementuje licznik
    }

    for (; counter > 0 ;counter--)
    {
        temp += (x%10) * pow(10, counter-1);
        x = x/10;
    }

    return temp;
}
