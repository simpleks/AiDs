#include <stdio.h>
#include <stdlib.h>
// zmienne globlne
int top=-1;
int *queue;

//metoda dodaj�ca element na koniec kolejki
void enqueue(int element){
    top++;
    queue[top] = element;
}

//metoda napisuje element o romiarze 1 usuwaj�c pierwsz� warto�� a nast�pnie skraca kolejk�
void dequeue(int size){
    for(int i=1; i<size;i++){
        queue[i-1] = queue[i];
    }
    top--;
}



int main()
{

    int size=6;
    queue = (int *) malloc(sizeof(int) * size); // rezerwacja przestrzeni w pami�ci dla element�w kolejki

    // dodanie warto�ci do kolejki
    for (int i=0;i<size;i++){
        enqueue(i+1);
    }

    printf("Kolejka po dodaniu warto�ci\n");
    //p�tla wy�wietlaj�ca warto�ci kolejki
    for (int i=0;i<top+1;i++){
        printf("kolejka[%d]: %d \n", i, queue[i]);
    }

    //usuwanie warto�ci z kolejki
    dequeue(size);
    dequeue(size);

    printf("\nKolejka po usuni�ciu warto�ci \n");
//p�tla kt�ra wypisuje warto�ci kolejki po usuni�ciu warto�ci
    for (int i=0;i<top+1;i++){
        printf("kolejka[%d]: %d \n", i, queue[i]);
    }

}
