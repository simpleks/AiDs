#include <stdio.h>
#include <stdlib.h>
//zmienne globalne
int top=-1;
int *stack;

//funkcja kt�ra sprwdza czy jest pusty
_Bool stack_empty(int top){
    if (top == -1){
            printf("stos pust \n ");
            return 1;
    }
    else{
            printf("stos nie jest pusty \n ");
            return 0;
    }
}

//funkcja  zwraca pierwszy od g�ry element stosu
int Top(){
    return stack[top];
}

//funkcja kt�ra dodaje elementy na szczyt stosu
void push(int element){
    top++;
    stack[top] = element;

}

// funkcja kt�ra usuwa g�rny element je�eli  istnieje
void pop(){
    if (stack_empty(top)==0){
        top--;
    }
}


int main()
{
    stack = (int *) malloc(sizeof(int) * 6); // zarezerwowanie miejsca w pamieci dla 6 elementow

    // p�tla kt�ra dodawanie warto�ci do stosu
    for (int i=0;i<6;i++){
        push(i+1);
    }

    printf("\n Stos po dodaniu wartosci\n");
//p�tla ktora wypisuje warto�ci stosu
    for (int i=0;i<top+1;i++){
        printf("stos[%d]: %d \n", i, stack[i]);
    }

    printf("\n Stos po odjeciu wartosci ");

    //usuwanie wartosci ze stosu za pomoc� metody pop
    pop();
    pop();

    for (int i=0;i<top+1;i++){
        printf("stos[%d]: %d \n", i, stack[i]);
    }

    printf("\n Wywolanie stosu = %d ", Top());
}
