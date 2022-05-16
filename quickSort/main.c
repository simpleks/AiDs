#include <stdio.h>
#include <stdlib.h>

// ###################
// #     QUICKSORT   #
// ###################

void quickSort(int tab[], int start_element, int last_element)//stworzenie funkci
{
    if (last_element <= start_element) return; //Jeżeli ostatni element będzie mniejdzy bądz równy pierwszemu elementow to program zwróci nowego pivot'a
    int pivot = partitionFunction(tab, start_element, last_element);//Przypisanie zminnej pivot liczbę z ostatniego indeksu
    quickSort(tab,start_element, pivot - 1);// Podzelenie na lewą część tablicy zmiennej "pivot" 
    quickSort(tab, pivot + 1, last_element);// Podzelenie na prawą część tablicy zmiennej "pivot"
}

int partitionFunction(int tab[], int start_element, int last_element)
{
    int i = start_element - 1;//Przypisanie do zmiennej "i" liczby pod postacią zmiennej "start_element", od której odejmowana jest liczba 1
    int pivot = tab[last_element];//przypisanie do zmiennej pivot tablicy o indeksie "last_element"

    for(int k = start_element; k <= last_element; k++)//pętla dla której zmienna "k" osiąga wartości zmiennej "start_element", która wykona przejście po "last_element"tablicy
        {
        if(tab[k] < pivot)//jeżeli tablica o indeksie "k" będzie mniejsza od zmiennej "pivot"to wykona się dana część instrukci sortującej
         {
            i++;
			int temp = tab[i];//przypisanie do zmiennej "temp" wartości z tablicy o indeksie "i"
			tab[i] = tab[k];//przypisanie do tablicy o indeksie "i" wartości z tablicy o indeksie "k"
			tab[k] = temp;//przypisanie do tablicy o indeksie "k" wartości ze zmiennej temp
         }
        }
        i++;
        int temp = tab[i];//przypisanie do zmiennej temp warości z tablicy o indeksie "i"
        tab[i] = tab[last_element];//przypisanie do tablicy o indeksie "i" wartości z tablicy o indeskie "last_element"
        tab[last_element] = temp;//przypisanie do tablicy o indeksie "last_element" wartości ze zmiennej temp

        return i;
}

int main()
{
    int tab[] = {2, 4, 5, 10, 23, 65, 1000, 13, -982};// przypisanie do tablicy wartości
    int tab_size = sizeof(tab) / sizeof(tab[0]);//określenie długości tablicy

    quickSort(tab,0,tab_size - 1);//uruchomienie funkci sortującej

    printf("Wynik sortowania tablicy: \n");
    for (int i = 0; i < tab_size; i++)//pętla która wykona się tyle razy ile elementów ma tablica
    {
        printf("%d ", tab[i]);//wyświetelenie posortowanej tablicy
    }
    return 0;
}
