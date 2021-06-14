#include <iostream>
#include <queue>
using namespace std;
int main()
{
int i,j,k,n,v,e,indeg[10];
queue<int> q;
cout<<"Enter the no of vertices:\n";
cin>>n;
int a[n][n]={0};
cout<<"Enter the no of edge:\n";
cin>>e;
int adj[e][2];
cout<<"Enter the edge list:\n";
for(i=1;i<e+1;i++)
{
cout<<"Enter edge"<<i<<"\n";
for(j=1;j<3;j++)
cin>>adj[i][j];
}
cout<<"The adjacency matrix:\n";
for(i=1;i<n+1;i++)
{
for(j=1;j<n+1;j++)
a[i][j]=0;
}for(i=1;i<e+1;i++)
{
a[adj[i][1]][adj[i][2]]=1;
}
for(i=1;i<n+1;i++)
{
for(j=1;j<n+1;j++)
cout<<a[i][j]<<" ";
cout<<"\n";
}
for(i=1;i<n+1;i++)
{
 indeg[i]=0;
 }
 for(i=1;i<n+1;i++)
 {
 for(j=1;j<n+1;j++)
 {
 indeg[i]=indeg[i]+a[j][i];
 }
 if(indeg[i]==0)
 q.push(i);
 }
 cout<<"\nThe topological order is:";
 while(!q.empty())
{
 v=q.front();
 q.pop();
 cout<<v<<" "; for(i=1;i<n+1;i++)
{
 if(a[v][i]==1)
 {
 --indeg[i];
 if(indeg[i]==0)
 q.push(i);
 }
 }
 }
 return 0;
}