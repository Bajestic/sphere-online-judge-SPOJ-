//      Napisz program, który:
//
//      wczyta ze standardowego wejścia: podstawę a oraz wykładnik b,
//      wyznaczy ostatnią cyfrę liczby ab,
//      wypisze wynik na standardowe wyjście.
//
//      Wejście
//      W pierwszej linii wejścia znajduje się jedna liczba całkowia D (1≤D≤10), oznaczjąca liczbę przypadków
//      do rozważenia. Opis każdego przypadku podany jest w jednym wierszu, zawierającym dwie liczby naturalne
//      a i b oddzielone pojedynczym odstępem (spacją), takie, że (1 ≤ a,b ≤ 1 000 000 000).
//
//      Wyjście
//      Dla każdego przypadku z wejścia Twój program powinien wypisać (w osobnej linii
//      dla każdego przypadku z wejścia) cyfrę jedności liczby ab zapisanej dziesiętnie.

#include <iostream>

static const unsigned int limit = 1000000000;
static const unsigned short tab[4][10] =
{
    {0,1,4,9,6,5,6,9,4,1},
    {0,1,8,7,4,5,6,3,2,9},
    {0,1,6,1,6,5,6,1,6,1},
    {0,1,2,3,4,5,6,7,8,9},
};

int main()
{
    using std::cin;
    using std::cout;
    std::ios_base::sync_with_stdio(0);

    unsigned short ile_przypadkow;
    cin >> ile_przypadkow;
    if ((ile_przypadkow<=10)&&(ile_przypadkow>=1))
    {
        short wyniki[ile_przypadkow] {};

        for(short i=0; i<ile_przypadkow; i++)
        {
            int a{}, b{};
            cin >> a >> b;
            if ((a<=limit)&&(a>=1)&&(b<=limit)&&(b>=1))
            a = a%10;
            b = (b-2)%4;

            switch(b)
            {
                case  1: wyniki[i] = a;
                default: wyniki[i] = tab[b][a];
            }
        }

        for(short j=0;j<ile_przypadkow;j++)
            {
            cout << wyniki[j] << '\n';
            }
    }
    else;

    return 0;
}
