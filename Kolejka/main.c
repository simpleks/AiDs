#include <stdio.h>
#include <stdlib.h>
// zmienne globlne
int top=-1;
int *queue;

//metoda dodaj¹ca element na koniec kolejki
void enqueue(int element){
    top++;
    queue[top] = element;
}

//metoda napisuje element o romiarze 1 usuwaj¹c pierwsz¹ wartoœæ a nastêpnie skraca kolejkê
void dequeue(int size){
    for(int i=1; i<size;i++){
        queue[i-1] = queue[i];
    }
    top--;
}



int main()
{

    int size=6;
    queue = (int *) malloc(sizeof(int) * size); // rezerwacja przestrzeni w pamiêci dla elementów kolejki

    // dodanie wartoœci do kolejki
    for (int i=0;i<size;i++){
        enqueue(i+1);
    }

    printf("Kolejka po dodaniu wartoœci\n");
    //pêtla wyœwietlaj¹ca wartoœci kolejki
    for (int i=0;i<top+1;i++){
        printf("kolejka[%d]: %d \n", i, queue[i]);
    }

    //usuwanie wartoœci z kolejki
    dequeue(size);
    dequeue(size);

    printf("\nKolejka po usuniêciu wartoœci \n");
//pêtla która wypisuje wartoœci kolejki po usuniêciu wartoœci
    for (int i=0;i<top+1;i++){
        printf("kolejka[%d]: %d \n", i, queue[i]);
    }

}
