PODSTAWY PROGRAMOWANIA KOMPUTERÓW
Termin OA (sekcja 1)
Czas trwania 120 minut.
Blok 1 [Podstawy programowania - wskaźniki]:
1) Napisz program, który pobierze od użytkownika dwie liczby całkowite (typ dwubajtowy) a i b. Liczba a powinna być ujemna
i nieparzysta, a liczba b dodatnia i parzysta. Program powinien wymusić na użytkowniku podanie poprawnych wartości
powtarzanie pobierania do maksymalnie 3 nieudanych prób. Wymuszanie powinno się odbyć oddzielnie dla każdej z liczb.
Jeśli po limicie prób użytkownik nie poda prawidłowych wartości program powinien arbitralnie ustawić wartości a i b na
dowolne spełniające zadane kryterium.
2) Program powinien wypełnić tablicę T (typ dwubajtowy) o wymiarach 5 x 6 całkowitymi liczbami parzystymi z przedziału [2a, b]. 
wypełnianie powinno się odbyć w kolumnami (pierwsza kolumna z górny na dół, druga kolumna z góry na dół itd.). 
Pamiętaj, że pierwszy indeks w tablicy to numer wiersza.
3) Program powinien wypisać na ekranie odległości w pamięci wszystkich powtórzeń liczby b w tablicy T od elementu T[0][0]. 
Odległość podawaj w bajtach (nie w elementach).

#include <iostream>
#include <cstdlib>

int main() {
    // Blok 1 - Pobieranie od użytkownika dwóch liczb spełniających kryteria
    int a, b;
    int attempts = 0;

    while (attempts < 3) {
        // Wprowadzenie liczby a (ujemnej i nieparzystej)
        std::cout << "Podaj liczbe a (ujemna i nieparzysta): ";
        std::cin >> a;

        if (a < 0 && a % 2 != 0) {
            break;  // Poprawna wartość a
        } else {
            std::cout << "Niepoprawna wartosc a. Sprobuj ponownie." << std::endl;
            attempts++;
        }
    }

    attempts = 0;

    while (attempts < 3) {
        // Wprowadzenie liczby b (dodatniej i parzystej)
        std::cout << "Podaj liczbe b (dodatnia i parzysta): ";
        std::cin >> b;

        if (b > 0 && b % 2 == 0) {
            break;  // Poprawna wartość b
        } else {
            std::cout << "Niepoprawna wartosc b. Sprobuj ponownie." << std::endl;
            attempts++;
        }
    }

    // Blok 2 - Wypełnianie tablicy T liczbami parzystymi z przedziału [2a, b]
    const int rows = 5;
    const int columns = 6;
    int T[rows][columns];

    for (int j = 0; j < columns; ++j) {
        for (int i = 0; i < rows; ++i) {
            T[i][j] = 2 * a + rand() % (b - 2 * a + 1);
        }
    }

    // Blok 3 - Wypisanie odległości w pamięci powtórzeń liczby b od T[0][0]
    std::cout << "Odleglosci w pamieci od T[0][0] do powtorzen liczby b:" << std::endl;

    for (int j = 0; j < columns; ++j) {
        for (int i = 0; i < rows; ++i) {
            if (T[i][j] == b) {
                std::ptrdiff_t distance = &T[i][j] - &T[0][0];
                std::cout << "T[" << i << "][" << j << "]: " << distance << " bajtow" << std::endl;
            }
        }
    }

    return 0;
}