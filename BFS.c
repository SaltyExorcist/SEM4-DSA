#include <stdio.h>
#include <stdlib.h>

int i,j,front=-1,rear=-1,graph[10][10],visited[10],total,q[10];

int enqueue(int number)
{
	if(rear==total)
	{
		printf("The queue is full\n");
		return 0;
	}
	else
	{
		if(front==-1 && rear==-1)
		{
			front=0;
		}
		rear=rear+1;
		q[rear]=number;
	}
}

int dequeue()
{
	if(front==-1)
	{
		printf("The queue is empty\n");
	}
	else
	{
		int item=q[front];
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else
		front=front+1;
		return item;
	}
}

void BFS()
{
	int n,node;
	printf("Enter the starting vertex:\n");
	scanf("%d",&n);
	printf("The BFS traversal is:\n");
	printf("%d\t",n);
	visited[n]=1;
	enqueue(n);
	while(front!=-1)
	{
		node=dequeue();
		for(i=0;i<total;i++)
	    {
	    	if(visited[i]==0 && graph[node][i]==1)
	    	{
	    		printf("%d\t",i);
	    		visited[i]=1;
	    		enqueue(i);
			}
	    }
	
	}  
}

int main()
{
	printf("Enter the total no of vertices:\n");
	scanf("%d",&total);
	printf("Enter the Adjacency matrix:\n");
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
	BFS();
	printf("\n");
	return 0;
}

