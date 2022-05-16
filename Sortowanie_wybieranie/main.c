#include <stdio.h>


void insertionSort(int sortowanie[], int roz) {  // tworzenie funcki
  for (int i = 1; i < roz; i++) {
    int klucz = sortowanie[i];
    int j = i - 1;




    while (klucz < sortowanie[j] && j >= 0) {// porownanie klucz z kazdym elementem na lewo od niego, az znajdzie sie element mniejszy od niego
      sortowanie[j + 1] = sortowanie[j];  //[rzesumiiecie elementu tablicy  jedno miejsce
      --j;
    }
    sortowanie[j + 1] = klucz;  // wstawienie elementu tablicy w odpowiednie miejsce w tablicy
  }
}

int main() {
  int sortowanie[] = {27,38,87,90,17,45,68,92,13,1,28,99,77,49,22};  //wypelnenie tablicy elementami
  int roz = sizeof(sortowanie) / sizeof(sortowanie[0]);   //znajdowanie dlugosci tablicy
  insertionSort(sortowanie, roz); //inicjacja funckji
  printf("oto posortowana tablica:\n");
    for (int i = 0; i < roz; i++) {   // petla sluzaca do wyswietlenia talicy
    printf("%d ", sortowanie[i]);  //wyswietlenie tablicy
  }
  printf("\n");
}
