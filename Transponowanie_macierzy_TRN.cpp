//
//        Zadanie
//        Transponuj podana macierz
//
//        Wejście
//        W pierwszym wierszu znajdują się dwie liczby m n (1<=m,n<=200)
//        oznaczające odpowiednio liczbę wierszy oraz liczbę kolumn.
//        Następnie następuje m wierszy, w każdym n liczb.
//
//        Wyjście
//        Na wyjściu powinna znaleźć się macierz transponowana do zadanej

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(void)
{
    unsigned short w, k{};

    if(cin >> w >> k)
        if((w >= 1 && w <= 200)&&(k >= 1 && k <= 200))
        {
          int transtab[k][w]{};
          short temp{};

            for(int i = 0; i < w; i++)
            {
                for(int j = 0; j < k; j++)
                {
                    if(cin >> temp)
                    transtab[j][i] = temp;

                    else return 0;
                }
                cin.clear();
                cin.ignore(10000, '\n');
            }

            for(int i = 0; i < k; i++)
            {
                cout << endl;
                for(int j=0; j < w; j++)
                    cout << transtab[i][j] << " ";
            }
        }
    else

    return 0;
}
