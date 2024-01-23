Blok 1 [Podstawy programowania - wskaźniki]:
1) Pobierz od użytkownika cztery wartości całkowitoliczbowe x1, y1, x2, y2. 
Następnie oblicz odległość pomiędzy dwoma punktami, które znajdują kolejno na współrzędnych (x1,y1), (x2,y2). 
Do obliczenia odległości pomiędzy punktami wykorzystaj poniższy wzór na odległość euklidesową: d = √(x2-x1)² + (2 - 1)²
Obliczoną odległość wyświetl w notacji naukowej.
2) Utwórz tablicę dwuwymiarową o T rozmiarach x1 x y1. 
Każdą kolumnę tablicy wypełnij jednym z następujących znaków (dla każdej kolumny losujemy osobno): *, &, $, #, @, !. Wyświetl zawartość tablicy.
3) Wykorzystując wskaźniki utwórz widok parzystych wierszy tablicy T. Wyświetl ten widok wykorzystując wskaźniki.

#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;
int main() {
    setlocale(LC_ALL, "");
    srand(time(0));

    constexpr size_t SIZE_X = 100,
        SIZE_Y = 100,
        SIZE_rng = 6;

    char typeIn;
    int x1, x2, y1, y2;
    double d;

    char T[SIZE_X][SIZE_Y] = {},
        rng[SIZE_rng] = { '', '&', '$', '#', '@', '!' };

    char ptr, * ptrEND;

    cout << "Podaj x1: "; cin >> x1;
    cout << "Podaj x2: "; cin >> x2;
    cout << "Podaj y1: "; cin >> y1;
    cout << "Podaj y2: "; cin >> y2;

    d = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));

    //cout << d;
    cout << "d = " << scientific << d << endl;

    if (x1 > 0 && y1 > 0) {

        for (size_t i = 0; i < y1; i++) {
            typeIn = rng[rand() % SIZE_rng];
            for (size_t j = 0; j < x1; j++) {
                T[j][i] = typeIn;
            }
        }

        cout << "Tablica:" << endl;
        for (size_t i = 0; i < x1; i++) {
            for (size_t j = 0; j < y1; j++) {
                cout << T[i][j] << '\t';
            }
            cout << endl;
        }

        cout << "Parzyste wiersze:" << endl;
        for (size_t i = 0; i < x1; i++) {
            if ((i + 1) % 2 == 0) {        // wiersze liczone od 1
                ptr = &T[i][0];
                ptrEND = &T[i][y1 - 1];

                cout << "w. " << i + 1 << '\t';
                while (ptr != ptrEND + 1) {
                    cout << *ptr << '\t';
                    ptr++;
                }
                cout << endl;
            }
        }
    }
    else
        cout << "błędne dane rozmiaru tablicy" << endl;

}