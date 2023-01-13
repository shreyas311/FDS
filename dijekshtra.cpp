#include<iostream>
using namespace std;
int visit[10];
class graph
{
	private :
		int n,l,i,j,cost[10],mat[10][10],dest[10],path[20];
		int edges, min,ncost,x,curdest,s,d,last,k,m;
	public : 
		graph()
		{
			edges=1;
			ncost=0;
		}
	void dijkshtraw(int mat[10][10],int n);
	void display();
	void read();
};
void graph::read()
{
	cout<<"\n ENTER THE NUMBER OF THE VERTICES=>>"; 
	cin>>n; 
	cout<<"\nENTER THE WEIGHTS OF EDGES IN THE FORM OF ADJACENCY MATRIX=>>"; 
    for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
            cout<<"\n For ["<<i<<","<<j<<"] -->";
            cin>>mat[i][j];
            if(mat[i][j]==0)
            	mat[i][j]=9999;
		}
    }
	dijkshtraw(mat,n);
}
void graph :: dijkshtraw(int mat[10][10],int n)
{
	cout<<"\nEnter the source node : ";
	cin>>s;
	cout<<"\nEnter the destination node : ";
	cin>>d;
	for(i=1;i<=n;i++)
	{
		cost[i]=9999;	
	}
	cost[s]=0;
	x=s;
	visit[x]=1;
	while(x!=d)
	{
		curdest=cost[x];
		min=9999;
		for(i=1;i<=n;i++)
		{
			if (visit[i]==0)
			{
				ncost=curdest+mat[x][i];
				if(ncost<cost[i])
				{
					cost[i]=ncost;
					dest[i]=x;
				}
				if (cost[i]<min)
				{
					min=cost[i];
					k=i;
				}
			}
		}
		x=k;
		visit[x]=1;
	}
	display();
}

void graph :: display()
{
	l=d;
	path[last]=d;
	last++;
	
	while(dest[l]!=s)
	{
		m=dest[l];
		l=m;
		path[last]=l;
		last++;
	}
	path[last]=s;
	cout<<"shortest path is:";
	for(l=last;l>=1;l--)
	{
		cout<<"  "<<path[l]<<"->"<<path[l-1]<<": "<<mat[path[l]][path[l-1]];
	}
	
	cout<<"\n Total Cost: "<<cost[d];

}

int main()
{
	graph g;
	g.read();
}

