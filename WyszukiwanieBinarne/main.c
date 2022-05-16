#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int tab[]){
    int temp;
    for (int i=0; i<10-1; i++){
        for (int j=0; j<10-i-1; j++){
            if(tab[j] > tab[j+1]){
                temp=tab[j];
                tab[j]=tab[j+1];
                tab[j+1]=temp;
            }
        }
    }
}

int main()
{
    int cyf[] ={21,37,4,20,1,4,6,9,8,2};
    int x;
    int a = 0;

    //sortowanie tablicy
    bubbleSort(cyf);

    //ustawianie zadanej wartosci

    printf("Wpisz liczbe ktora szukasz: \n");
    scanf("%d", &x);

//wartosci start i koniec pomoga w okresleniu pivot'a

    int start =0;
    int koniec =9;
    int pivot;


    while(pivot !=0 && pivot!=9){
        pivot =start+(koniec-start)/2;

        //jezeli wartosc znajdzuje sie w pivocie zostanie ona wypisana
        if(x == cyf[pivot]){

        printf("Element znajduje sie pod indeksem %d \n", pivot);
        printf("Element znajduje sie w pamieci  %d \n", &cyf[pivot]);
        a=1;
    }
        //jezeli wartosc jest wieksza od pivot'a powiekszamy ja o 1 , w ten sposob podczas obliczania nowego punktu uwzglednimy tylko gorna czesc tablicy

        else if(x > cyf[pivot]){
         start =pivot+1;
        }
        //jezeli wartosc jest mniejsza od pivot'a pomniejszamy ja o 1 aby  obliczyc dolna polowe tablicy

        else{
            koniec = pivot-1;
        }
        //jezeli nowy punkt jest rowny staremu wtedy petla sie przerwie
        if(pivot==(start+(koniec-start)/2)){
            break;
        }
    }
    if(a==0)
        printf("Elementu nie ma w tablicy");

    return 0;
}
