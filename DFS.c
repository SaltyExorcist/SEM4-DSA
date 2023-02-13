#include <stdio.h>
#include <stdlib.h>
int i,j, graph[10][10], visited[10], arr[30], total;
int count=0;
int k=0;

void DFS(int vertex)
{
	int c=0;
	count++;
	printf("%d",vertex);
	visited[vertex]=1;
	for(i=0;i<total;i++)
	{
		if(!visited[i] && graph[vertex][i]==1)
		{
			arr[++k]=i;
			c=1;
		}
		
		if(count==total)
		{
			exit(0);
		}
	
	}
	
	 if(c==1)
	 {
	 	DFS(arr[k]);
	 }
	 else
	 {
	 	k--;
	 	DFS(arr[k]);
	 }
	
}

int main()
{
	printf("Enter the no of vertices: \n");
	scanf("%d",&total);
    printf("Enter the Adjacency matrix: \n");	
	for(i=0;i<total;i++)
	{
		for(j=0;j<total;j++)
		{
			scanf("%d",&graph[i][j]);
		}
	}
	
	for(i=0;i<total;i++)
	{
		visited[i]=0;
	}
	
	 printf("DFS Traversal is: \n");
	 DFS(0);
	 return 0;
}
