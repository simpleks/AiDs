#include <stdio.h>


void bubbleSort(int bombel[], int roz) {  //stworzenie  funkci sortujacej


  for (int i= 0; i < roz - 1; i++) {  //stworzenie petli umozliwiajacej dostep do kazdego elementu zawartego w tablicy


    for (int j = 0; j < roz - i - 1; j++) {  // petla sluzaca do porównywania elementów  tablicy


      if (bombel[j] > bombel[j + 1]) {    // porownywanie dwuch sasiednich elementow



        int temp = bombel[j];       //w liniach 17 ,18  19 nasepuje zamiana elemenow  tak aby byly one posortowane
        bombel[j] = bombel[j + 1];
        bombel[j + 1] = temp;
      }
    }
  }
}

int main() {
  int bombel[] = {7,14,21,28,35,42,49,56,63,70,5,10,15,20,25};  //dodanie wartosci do tablicy


  int roz = sizeof(bombel) / sizeof(bombel[0]);   //znajdowanie dlugosci tablicy

  bubbleSort(bombel, roz); // inicjacja  funkci

  printf("Tablica ``bombel`` posortowana metoda bombelkowa:\n");  //wyswietlanie tablicy juz posortowaniej
  for (int i = 0; i < roz ; ++i) {
    printf("%d  ", bombel[i]);
  }
  printf("\n");
}
