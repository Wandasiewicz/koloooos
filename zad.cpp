#include <iostream>
#include <cstdlib>  
#include <iomanip> 
#include <cmath>
using namespace std;
main()
{
    float wzrost;
    float waga;
    float BMI;
    int liczba;
    
    
    do
    {
        cout<<"Podaj wszrost: "<<endl;
        cin>>wzrost;
    }while(wzrost<=0);

    do
    {
        cout<<"Podaj wage: "<<endl;
        cin>>waga;
    }while(waga<=0);

    BMI=wzrost/(waga* waga);
    cout<<(setprecision(3))<<BMI;
    cout<<"Podaj liczbe calkowita (a): ";
    cin>>liczba;

    srand(time(NULL));
    const int kolumna = 5;
    const int wiersz = 6;
    int tablica[kolumna][wiersz]={};
    int wylosowana;
    int suma=0;

    for(int j=0; j < wiersz; j++)
    {
        for(int i=0; i < kolumna; i++)
        {
            wylosowana = (rand() % (liczba+1));
            tablica[i][j]=wylosowana;
    
        }
        suma = tablica[0][j]+tablica[1][j]+tablica[2][j]+tablica[3][j]+tablica[4][j];
        cout<<"Suma wiersza nr: "<<j<<" to: "<<suma<<endl;
    }
    int x1;
    int x2;
    int y1;
    int y2;
    int odleglosc;

    cout<<"Podaj pierwsza wspolrzedna."<<endl;
    cin>>x1;
    cout<<"Podaj druga wspolrzedna."<<endl;
    cin>>x2;
    cout<<"Podaj trzecia wspolrzedna."<<endl;
    cin>>y1;
    cout<<"Podaj czwarta wspolrzedna."<<endl;
    cin>>y2;
    int * jeden = &tablica[x1][y1];
    int * dwa = &tablica[x2][y2];
    
    ptrdiff_t distance = abs(jeden - dwa);
    cout << "Odleglosc miedzy T[" << x1 << "][" << y1 << "] a T[" << x2 << "][" << y2 << "]: " << distance << " bajtow" << endl;

    return 0;
}

//b
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
using namespace std;
// Funkcja do obliczania BMI
int main() {
    // Blok 1 - Pobieranie od użytkownika dwóch liczb większych od 0
    int height, max_value;
    double weight;

    // Pobieranie wzrostu
    do {
        cout << "Podaj wzrost (wiekszy od 0): ";
        cin >> height;
    } while (height <= 0);

    // Pobieranie wagi
    do {
        cout << "Podaj wage (wieksza od 0): ";
        cin >> weight;
    } while (weight <= 0);

    // Blok 2 - Obliczanie i wyświetlanie BMI
    double bmi = (weight / (height * height));
    cout << "BMI: " << setprecision(2) << bmi << endl;

    // Blok 3 - Wypełnianie tablicy dwuwymiarowej i wyświetlanie sumy wierszy
    cout << "Podaj maksymalna wartosc (liczba calkowita) dla tablicy dwuwymiarowej: ";
    cin >> max_value;

    const int rows = 5;
    const int columns = 6;
    int T[rows][columns];

    for (int i = 0; i < rows; ++i) {
        int row_sum = 0;
        for (int j = 0; j < columns; ++j) {
            T[i][j] = rand() % (max_value + 1);
            row_sum += T[i][j];
        }
        cout << "Suma wiersza " << i + 1 << ": " << row_sum << endl;
    }

    // Blok 4 - Obliczanie i wyświetlanie odległości pomiędzy komórkami pamięci
    int x1, y1, x2, y2;

    cout << "Podaj wspolrzedne x1, y1, x2, y2 (w zakresie [0, 4] dla x i [0, 5] dla y): ";
    cin >> x1 >> y1 >> x2 >> y2;

    int* ptr1 = &T[x1][y1];
    int* ptr2 = &T[x2][y2];

    ptrdiff_t distance = abs(ptr1 - ptr2);
    cout << "Odleglosc miedzy T[" << x1 << "][" << y1 << "] a T[" << x2 << "][" << y2 << "]: " << distance << " bajtow" << endl;

    return 0;
}