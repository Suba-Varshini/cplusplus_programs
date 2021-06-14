#include <iostream>
#include <queue>
int INT_MAX=5;
using namespace std;
void dijkstra(int,int,int[][10]);
int min(int[],bool[],int);
int main()
{
int i,j,k,n,v,s,e,a[10][10],indeg[10],length[10][10];
cout<<"Enter the no of vertices:\n";
cin>>n;
cout<<"Enter the no of edge:\n";
cin>>e;
int adj[e][3],ab[10][10];
cout<<"Enter the edge list:\n";
for(i=1;i<e+1;i++)
{
cout<<"Enter edge"<<i<<"\n";
for(j=1;j<4;j++)
cin>>adj[i][j];
}
cout<<"The adjacency matrix:\n";
for(i=1;i<n+1;i++)
{
for(j=1;j<n+1;j++)
{
 a[i][j]=0; ab[i][j]=0;
}
}
for(i=1;i<e+1;i++)
{
a[adj[i][1]][adj[i][2]]=1;
a[adj[i][2]][adj[i][1]]=1;
}
for(i=1;i<e+1;i++)
{
ab[adj[i][1]][adj[i][2]]=adj[i][3];
ab[adj[i][2]][adj[i][1]]=adj[i][3];
}
for(i=1;i<n+1;i++)
{
for(j=1;j<n+1;j++)
cout<<a[i][j]<<" ";
cout<<"\n";
}
 cout<<"Enter the source node: ";
 cin>>s;
 cout<<"The shortest path from source to other nodes are:";
 dijkstra(s,n,ab);
 return 0;
}
void dijkstra(int v,int n,int ab[][10])
{
int dist[n];
bool set[n];for(int i=1;i<n+1;i++)
{
 dist[i]=INT_MAX;
 set[i]=false;
 }
 dist[v]=0;
 for(int j=1;j<n+1;j++)
 {
 int m=min(dist,set,n);
 set[m]=true;
 for(int i=1;i<n+1;i++) 
{
if(!set[i] && ab[m][i] && dist[m]!=INT_MAX && 
dist[m]+ab[m][i]<dist[i])
dist[i]=dist[m]+ab[m][i];
}
}
for(int i=1;i<n+1;i++)
cout<<dist[i]<<" ";
}
int min(int dist[],bool set[],int n) 
{
int mi=INT_MAX,index; 
for(int i=1;i<n+1;i++) 
{
if(set[i]==false && dist[i]<=mi) 
{
mi=dist[i];
index=i;
}}
return index;
}