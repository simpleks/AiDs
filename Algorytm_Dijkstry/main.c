#include<stdio.h>
#include<conio.h>
#define INFINITY 99999999
#define MAX 10

void dijkstra(int G[MAX][MAX],int n,int startnode)
{

    int cost[MAX][MAX], distance[MAX], pred[MAX];
    int visited[MAX], count, mindistance, nextnode, i, j;
    //pred[] przechowuje poprzednika ka¿dego wêz³a
    //distance[] zawiera odleg³oœci do s¹siednich wierzcho³ków
    //count przechowuje liczbê wêz³ów widzianych do tej pory

    //utwórz macierz kosztów
    //która jest tak¹ sam¹ macierz¹ jak
    //macierz s¹siedztwa, ale
    //odleg³oœci 0 oznaczaj¹ce, ¿e
    //nie ma po³¹czenia s¹ zastêpowane
    //z INFINITY, aby 0 nie
    //przeszkadzaæ w znalezieniu lepszego
    //œcie¿ki przez nextnode
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(G[i][j]==0)
                cost[i][j]=INFINITY;
            else
                cost[i][j]=G[i][j];
        }
    }
    //zainicjowaæ pred[], distance[] and visited[]
    for(i=0;i<n;i++){
        distance[i]=cost[startnode][i];
        pred[i]=startnode;
        visited[i]=0;
    }

    //inicjuje startNode indeksy
    //tabele , bo nie musimy iœæ
    //przez nich
    distance[startnode]=0;
    visited[startnode]=1;
    count=1;

    //
    while(count<n-1){
        //printf("\n Count = %d \n",count);
        mindistance=INFINITY;

        //znajduje nextnode , który jest wêz³em, który
        //nie by³ jeszcze odwiedzany i czy
        //najbli¿ej wêz³a pocz¹tkowego
        for(i=0;i<n;i++){
            if(distance[i]<mindistance&&!visited[i]){
                mindistance=distance[i];
                nextnode=i;
            }
        }

        //printf("mindistance = %d \n",mindistance);
        //printf("nextnode = %d \n",nextnode);

        //sprawdza, czy istnieje lepsza œcie¿ka przez nextnode
        //przechodzi i sprawdza tylko nieodwiedzone wêz³y
        //gdyby odkryto lepsz¹ œcie¿kê z „dalej”
        //wêze³ nastêpnie aktualizujemy odleg³oœæ do nowego
        //który przechodzi przez wiêcej wêz³ów
        visited[nextnode]=1;
        for(i=0;i<n;i++){
            if(!visited[i]){
                //printf("mindistance+cost[%d][%d]<distance[%d] = %d + %d < %d \n",nextnode, i, i, mindistance, cost[nextnode][i], distance[i]);

                if(mindistance+cost[nextnode][i]<distance[i]){
                    ///printf("\n true\n");

                    distance[i]=mindistance+cost[nextnode][i];
                    pred[i]=nextnode;

                    //printf("distance[%d] = %d \n \n",i, distance[i]);
                }
            }
        }
        count++;
    }

    //drukuje œcie¿kê i odleg³oœæ do ka¿dego wêz³a
    for(i=0;i<n;i++){
        if(i!=startnode){
            printf("\nShortest distance to node%d = %d",i,distance[i]);
            printf("\nPath=%d",i);
            j=i;
            do{
                j=pred[j];
                printf("<-%d",j);
            }while (j!=startnode);
            printf("\n");
        }
    }
}

int main()
{
    //ustawienie matrycy i
    //deklarowanie wêz³a pocz¹tkowego

    int G[MAX][MAX], i,j,n,u;
    printf("Enter no. of vertices: (up to 10)");
    scanf("%d",&n);
    printf("\nEnter the adjacency matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&G[i][j]);
        }
    }
    printf("\nEnter the starting node:");
    scanf("%d",&u);
    dijkstra(G,n,u);
    //stona
    //https://www.thecrazyprogrammer.com/2014/03/dijkstra-algorithm-for-finding-shortest-path-of-a-graph.html

//0 6 0 1 0
//6 0 5 2 2
//0 5 0 0 5
//1 2 0 0 1
//0 2 5 1 0
    return 0;
}
