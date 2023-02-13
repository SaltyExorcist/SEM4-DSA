#include <stdio.h>
#define INF 99999
#define v 4
 void printsoln(int dist[][v]);
 
 void floydwarshall(int graph[][v])
 {
 	int i,j,k,dist[v][v];
 	for(i=0;i<v;i++)	
 		for(j=0;j<v;j++)
 			dist[i][j]=graph[i][j];
		 	 
	 
	 for(k=0;k<v;k++)
	 {
	 
	     for(i=0;i<v;i++)
 	      {
 		    for(j=0;j<v;j++)
 		     {
 			if (dist[i][k] + dist[k][j] < dist[i][j])			  
 			  	dist[i][j]= dist[i][k]+dist[k][j];			   
		     }
	      }
      }

	printsoln(dist); 	 	
 }
 
 void printsoln(int dist[][v])
 {
 	int i,j;
 	printf("The all pairs shortest matrix is: \n");
 	for(i=0;i<v;i++)
 	      {
 		    for(j=0;j<v;j++)
 		     {
 			if(dist[i][j]==INF)
 			  	printf("%7s", "INF");
 			  	else
 			  	printf("%7d", dist[i][j]);
			   
		     }
		     printf("\n");
	      }
 	
 }
 
 int main()
 {
 	int i,j;
 	int graph[v][v];
printf("Enter the Adjacency matrix: \n"); 
for (i = 0; i < v; i++)
{
for (j = 0; j < v; j++)
{
scanf("%d", &graph[i][j]);
}
}
printf("\n");
	
 
	      floydwarshall(graph);
	      return 0;
 }
