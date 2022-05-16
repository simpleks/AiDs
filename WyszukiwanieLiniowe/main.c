#include <stdio.h>
#include <stdlib.h>


//Wyszukiwanie liniowe Linear Search
int main()
{
    int z=10;
    int tab[z],x,i;
    int a=0;


    printf("Wpisz elementy :\n");
    //pentla ktora dodaje elementy do tablicy
    for(i=0;i<z;++i)
        scanf("%d",&tab[i]);


        //deklarowanie jakiej wartosci szukamy
    printf("\n Jakiego elementu szukasz:");
    scanf("%d",&x);

    //jesli wartosc tablicy jest rowna wartosci szukanej wyjdz z petli
   for(i=0;i<z;i++){
        if(tab[i]==x){

        printf("\nElement zostal znaleziony na indeksie %d",i);

        printf("\n Element znajduje sie pod adresem  %d",&tab[i]);
         a++;

        }
   }
        //jesli wartosci nie ma w tablicy program wypisze komunikat
          if(a==0)
        printf("Takiego elementu nie ma w tablicy");


    return 0;
}
