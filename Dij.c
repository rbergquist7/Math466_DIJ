#include <stdio.h>
#define infinity 999
#define max 10

/********************************
*	Ryan Bergquist		*
*	Math 466		*
*	Dijkstra's		*
*	011385143		*
********************************/


void dij(int n,int v,int cost[max][max],int dist[])
{
	int i,u,count,w,flag[max],min;
 	for(i=1;i<=n;i++){
  		flag[i]=0;
		dist[i] = cost[v][i];
 	}
 	count=2;
 	while(count<=n)
 	{
  		min=99;
  		for(w = 1; w <= n; w++){
   			if(dist[w] < min && !flag[w]){
    				min=dist[w];
				u=w;
   			}
  		}
  		flag[u]=1;
  		count++;
  		for(w=1;w<=n;w++){
   			if( (dist[u]+cost[u][w] < dist[w]) && !flag[w]){
    				dist[w]=dist[u]+cost[u][w];
   			}
  		}
 	}
}
 
int main()
{
 printf("\nSolving Figure 4.15\n");
 int n,v,i,j,dist[max];
 n = 6;
 int cost[max][max] = { {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		      {0, 0, 2, 8, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 5, 3, 0, 0, 0, 0, 0},
                      {0, 0, 6, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 1, 0, 7, 6, 0, 0, 0},
                      {0, 0, 0, 0, 4, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
                     };
	for(i=0;i<=n;i++){
  		for(j=0;j<=n;j++)
  		{
   			if(cost[i][j]==0)
    			cost[i][j]=infinity;
  		}
 	}
	int k = 1;
	while(k < n+1){
 		dij(n,k,cost,dist);
 		printf("\n Shortest path:\n");
 		for(i=1;i<=n;i++){
  			if(i !=k ){
   				if(dist[i] != infinity) printf("%d->%d,cost=%d\n",k,i,dist[i]);
			}
		}
		k++;
	}
return 0;
}
