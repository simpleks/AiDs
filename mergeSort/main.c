#include <stdio.h>
#include <stdlib.h>

//############################
//#     MERGE SORT !!!!!!!   #
//############################

void merge(int tab[], int l_side, int middle, int r_side) //tworzenie funkcji z argumentami
{
    int i, j, k;
    int n1 = middle - l_side + 1; //przypisanie do zmiennej n1, liczby pod postacią zmiennej "middle", która odejmowana jest od liczby pod postacią zmiennej "l_size" po czym wszystkim jest dodane 1
    int n2 = r_side - middle;  //przypisanie do zmiennej n2, liczby pod postacią zmiennej "r_side", która odejmowana jest od liczby pod postacią zmiennej "middle"
    int L_temp[n1], R_temp[n2];


    for (i = 0; i < n1; i++) // pętla która wykona przejścia po n1 elementach tablicy  umieszczonych w tablicy
    {
        L_temp[i] = tab[l_side + i]; // przypisanie do lewej tablicy pomocniczej wartości z "głównej" tablicy od pierwszego elementu do elementu o indeksie "i")
    }

    for (j = 0; j < n2; j++) // pętla która wykonuje przejście po n2 elementach tablicy "głownej" danych
    {
        R_temp[j] = tab[middle + 1 + j];// przypisanie do prawej tablicy pomocniczej wartości z tablicy "głównej" od środkowego elementu +1 do elementu o indeksie "j" 
    }


    i = 0;
    j = 0;
    k = l_side;
    while (i < n1 && j < n2) // Pętla która będzie się wykonywać dopóki "i" będzie mniejsze od n1 i "j" będize mniejsze od n2
        {
            if (L_temp[i] <= R_temp[j]) // Jeżeli lewa tablica pomocnicza o indeksie "i" będzie mniejsza albo równa prawej tablicy pomocniczej  o indeksie "j" to wykona się dana część kodu 
            {
                tab[k] = L_temp[i]; // przypisanie do głownej tablicy o indeskie "k" wartości z lewej tablicy pomocniczej o indeksie "i"
                i++;
            }
            else
            {
                tab[k] = R_temp[j];//przypisanie do głownej tablicy o indeksie "k" wartości z prawje tablicy pomocniczej o indeksie "j"
                j++;
            }
        k++;
        }


    while (i < n1) // pętla która będize się wykonywać dopóki "i" będzie mniejsze od n1
        {
            tab[k] = L_temp[i]; // Przypisanie do głownej tablicy o indeksie "k" wartości z lewej tablicy o indeksie "i"
            i++;
            k++;
        }

    while (j < n2) // pętla która będize się wykonywać dopóki "j" będzie mniejsze od n2
        {
            tab[k] = R_temp[j]; // przypisanie do głownej tablicy o indeksie "k" wartości z prawej tablicy o indeksie "j"
            j++;
            k++;
        }
}


void mergeSort(int tab[], int l_side, int r_side)
{
    if (l_side < r_side) { // jeżeli lewa strona będize mniejsza od prawej to wykona się dana część instrukci

        int middle = l_side + (r_side - l_side) / 2; // przypisanie do zmiennej middle liczby pod postacią zmiennej "r_side" która odejmowana jest od loczby pod postacią "l_size" dzielona przez dwa


        mergeSort(tab, l_side, middle);//podzelenie lewej częsci tablicy
        mergeSort(tab, middle + 1, r_side);//podzelenie prawej częsci tablicy
        merge(tab, l_side, middle, r_side);//połączenie lewej i prawej tablicy
    }
}

int main()
{
    int tab[] = { 4, 13, 5325, 1231, 23, 5, 9, -1 }; // przypiszanie tablicy z liczbami do posortowania
    int tab_size = sizeof(tab) / sizeof(tab[0]); //wyznaczanie długości tablicy

    mergeSort(tab, 0, tab_size - 1);  //uruchomienie funkcji

    printf("Wynik sortowania tablicy: \n");
    for (int i = 0; i < tab_size; i++) // pętla przejdzie tyle razy ile jest elementów w tablicy
    {
        printf("%d ", tab[i]); // wyświetelenie już posortowanej tablicy
    }

    return 0;
}
