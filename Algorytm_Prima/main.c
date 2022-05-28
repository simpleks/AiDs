#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#define NIESKONCZONOSC 99999999
#define MAX 11

void prim(int graf[MAX][MAX], int n, int startNode)
{
    int rodzic[MAX], waga[MAX];
    bool MDS[MAX];
    int i, j;

    //rodzic[] przechowuje skonstruowane drzewo
    //waga[] zawiera wartosci uzyte do znalezienia krawedzi o minimalnej wadze

    //inicjalizacja tabel na poczatku zakladamy, ze nie ma polaczeñ
    for(i=0;i<n;i++){
        waga[i]=NIESKONCZONOSC;
        MDS[i]=false;
    }

    //inicjalizuje indeksy startNode o wartosci tabele, poniewaz chcemy zaczac od tego miejsca
    waga[startNode]=0;
    rodzic[startNode]=-1;


    for(i=0;i<n-1;i++){

        //znalezienie minimalnej wagi z zestawu  wierzcholkow, których nie ma w MDS[]
        int min = NIESKONCZONOSC, minIndex;

        for (int j = 0; j < n; j++){

            if (MDS[j] == false && waga[j] < min){
                min = waga[j];
                minIndex = j;

            }
        }
        //dodanie wierzcholka za minimala waga do zbioru dolaczonych wierzcholków
        MDS[minIndex]=true;

        for (j=0; j<n;j++){


            //MDS[j] jest falszywy dla wierzcholków, które nie zostaly jeszcze uwzglednione w drzewie
            //aktualizuj tylko wtedy, gdy sasiedni wierzcholek jest mniejszy niz biezacy

            //waga drogi do tego wierzcholka
            if(graf[minIndex][j]>0 && MDS[j]==false && graf[minIndex][j]<waga[j]){
                rodzic[j] = minIndex;
                waga[j]=graf[minIndex][j];
            }
        }

    }

    //wyprowadzanie skonstruowanego drzewa
    printf("\nWiezcholek \tWaga\n");
    for (int i = 0; i < n; i++){
        if (i!=startNode){
            printf("%c - %c \t%d \n", (char)(rodzic[i]+65), (char)(i+65), graf[i][rodzic[i]]);
        }
    }

}

int main()
{
    //ustawienie matrycy i deklarowanie wezla poczatkowego

    int graf[MAX][MAX], i, j, n, u;
    printf("Wpisz nr. wierzcholkow: ");
    scanf("%d",&n);
    printf("\nWprowadz macierz sasiedztwa:\n");

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&graf[i][j]);
        }
    }

    printf("\nWprowadz wezel poczatkowy: ");
    scanf("%d",&u);
    prim(graf,n,u);
    return 0;
}

/*
macierz sasiedztwa dla wykres ze skryptu

0 0 1 4 5 5 0 0 22 0 0
0 0 16 0 0 0 0 0 3 30 0
1 16 0 1 0 0 0 0 0 0 0
4 0 1 0 1 0 0 0 0 0 0
5 0 0 1 0 12 0 0 0 0 0
5 0 0 0 12 0 27 0 0 0 0
0 0 0 0 0 27 0 5 0 10 18
0 0 0 0 0 0 5 0 5 20 0
22 3 0 0 0 0 0 5 0 25 0
0 30 0 0 0 0 10 20 25 0 3
0 0 0 0 0 0 18 0 0 3 0

*/
