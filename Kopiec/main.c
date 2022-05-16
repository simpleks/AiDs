#include <stdio.h>
#include <stdlib.h>
int size = 0;  //zdefiniowanie zminnej globalnej widocznej w całym programie i przypisanie mu wartości liczbowej 0

void change(int *x , int *y){ // stworzenie metody change
int temp = *y; // przyposanie zmiennej "y" pod adres zmiennej temp
*y = *x; // przypisanie adresu zmiennej "x" do "y"
*x = temp; // przypisanie zmiennej temp pod adres zmiennej "x"
}

void heapify  (int tab[], int size,int i){ //stworzenie metody heapify
    if (size ==1){
        printf(tab[size]); // jeśli tablca ma jeden elemnt to wypisze je tutaj
    }
    else {
    int max = i; // przypisanie zmiennej max wartości "i"
    int lD = 2 * i + 1; //wyliczanie ideksu lewego dziecka
    int pD = 2 * i + 2; // wyliczenie indeksu prawego dziecka
if (lD < size && tab[lD] > tab[max]) //jeśli indeks lewego dziecka jest mniejszy od wielkości kopca oraz wartości lewego dziecka jest większa od wartości obecnie (max) największego dziecka
      max = lD; // zmiana wartości max na wartość lewego dziecka
    if (pD < size && tab[pD] > tab[max])//jeśli indeks prawego dziecka jest mniejszy od wielkości kopca oraz wartość prawego dziecka jest większa od wartości obecnie (max) największego dziecka
      max = pD; //zmiana wartośći max na wartość prawego dziecka

      if (max != i)
    {
      change(&tab[i], &tab[max]); //zamina miejscami wartości z indeksem i oraz wartości z indeksem max*
    heapify(tab, size, max); //wywołaj rekurencyjnie funkcji heapify
    }
}
    }

    void insert(int tab[], int newValue){
 if (size == 0) // jeśli tablica jest pusta
  {
    tab[0] = newValue; // zapisanie "newValue" do tablocy
    size += 1; // zwiększenie zmiennej size o 1
  }
  else
  {
    tab[size] = newValue; // zapisanie wartości newValue do tablicy o indeksie size
    size += 1; // zwiększenie size o 1
    for (int i = size / 2 - 1; i >= 0; i--) // gdzie i to indeks rodizca
    {
     heapify(tab, size, i); // wykonanie rekurenci
    }
  }

}

void deleteRoot(int tab[], int deleteNum)
{
  int i;
  change(&tab[i], &tab[size - 1]); // wstawienie ostatnego elementu w miejsce korzenia
  size -= 1; // zmniejszenie size o 1
    heapify(tab, size, i); // wywolanie rekurencji

}

int main()
{
   int tab[11];

  insert(tab, 18);
  insert(tab, 0);
  insert(tab, 2);
  insert(tab, 16);
  insert(tab, 6);
  insert(tab, 8);
  insert(tab, 12);
  insert(tab, 20);
  insert(tab, 10);
  insert(tab, 14);
  insert(tab, 4);

  for (int i = 0; i < size; ++i)
    printf("%d ", tab[i]);
  printf("\n");
    return 0;
}
