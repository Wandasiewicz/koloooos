Napisz kod w języku c++ i wyjaśnij krok po kroku, uwzgledniajac komende using namespace std;:
1) Napisz funkcję do alokacji tablicy typu short, tak aby jej -1 element przechowywał jej rozmiar na starszym bajcie. Na bajcie młodszym zapisz, jej numer mówiący o tym, która to jest taka tablica zapisana od początku pracy programu. Tablica po utworzeniu powinna być zapisana samymi zerami.
2) Napisz 2 funkcje:
- do zapisu tablicy z polecenia 1 do pliku w trybie binarnym,
- do odczytu tablicy z polecenia 1 z pliku w trybie binarnym.
W pliku należy też przechować wymiary tablicy (zauważ, że w tablicy wymiar jest już zapisany).
3) Podziel program na pliki, tak aby napisane wyżej funkcje znalazły się w oddzielnej jednostce translacji.
4) Napisz krótki program główny, który zapisze kilka takich tablic do plików i odczyta poprawnie tą o wskazanym przez użytkownika numerze. Nie zapomnij o poprawnym zwolnieniu pamięci, na koniec pracy programu

ChatGPT
Oto kod C++ zgodny z Twoimi wymaganiami:

Funkcja do alokacji tablicy:
cpp
Copy code
#include <iostream>
#include <cstring>

using namespace std;

short* createArray(int index, int size) {
    // Alokacja pamięci dla tablicy z dodatkowym miejscem na zapisanie jej rozmiaru i indeksu
    short* array = new short[size + 2];

    // Pierwsze dwa bajty wykorzystywane do zapisania informacji o rozmiarze i indeksie
    array[0] = (size >> 8) & 0xFF; // starszy bajt
    array[1] = size & 0xFF;         // młodszy bajt
    array[2] = index;

    // Wypełnienie tablicy zerami
    memset(array + 3, 0, size * sizeof(short));

    return array;
}
Funkcje do zapisu i odczytu tablicy z pliku:
cpp
Copy code
#include <fstream>

void writeArrayToFile(const char* filename, short* array) {
    ofstream file(filename, ios::binary);
    if (file.is_open()) {
        // Zapisanie rozmiaru i zawartości tablicy do pliku
        file.write(reinterpret_cast<char*>(array), (array[0] << 8 | array[1]) * sizeof(short) + 2);
        file.close();
    } else {
        cout << "Unable to open file: " << filename << endl;
    }
}

short* readArrayFromFile(const char* filename) {
    ifstream file(filename, ios::binary);
    if (file.is_open()) {
        // Pobranie rozmiaru tablicy
        int size;
        file.read(reinterpret_cast<char*>(&size), sizeof(int));

        // Alokacja pamięci dla tablicy
        short* array = new short[size];

        // Odczytanie zawartości tablicy
        file.read(reinterpret_cast<char*>(array), size * sizeof(short));
        file.close();

        return array;
    } else {
        cout << "Unable to open file: " << filename << endl;
        return nullptr;
    }
}
Pliki nagłówkowe dla powyższych funkcji:
array_operations.h:

cpp
Copy code
#ifndef ARRAY_OPERATIONS_H
#define ARRAY_OPERATIONS_H

short* createArray(int index, int size);
void writeArrayToFile(const char* filename, short* array);
short* readArrayFromFile(const char* filename);

#endif // ARRAY_OPERATIONS_H
array_operations.cpp:

cpp
Copy code
#include "array_operations.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

short* createArray(int index, int size) {
    // implementacja funkcji createArray
}

void writeArrayToFile(const char* filename, short* array) {
    // implementacja funkcji writeArrayToFile
}

short* readArrayFromFile(const char* filename) {
    // implementacja funkcji readArrayFromFile
}
Program główny:
cpp
Copy code
#include <iostream>
#include "array_operations.h"

using namespace std;

int main() {
    // Zapis kilku tablic do plików
    for (int i = 0; i < 3; ++i) {
        short* array = createArray(i, 5); // Przykładowy rozmiar tablicy: 5
        writeArrayToFile(("array_" + to_string(i) + ".bin").c_str(), array);
        delete[] array;
    }

    // Odczyt tablicy o wskazanym przez użytkownika numerze
    int index;
    cout << "Enter the index of the array you want to read: ";
    cin >> index;

    short* array = readArrayFromFile(("array_" + to_string(index) + ".bin").c_str());
    if (array) {
        // Wyświetlenie zawartości tablicy
        int size = (array[0] << 8 | array[1]);
        cout << "Array size: " << size << endl;
        for (int i = 0; i < size; ++i) {
            cout << array[i + 2] << " ";
        }
        cout << endl;

        delete[] array; // Zwolnienie pamięci
    }

    return 0;
}
Ten program tworzy kilka tablic, zapisuje je do plików binarnych, a następnie odczytuje tablicę o wskazanym przez użytkownika numerze. Na koniec zwalnia pamięć.





