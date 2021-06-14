#include <iostream>
#include <queue>
using namespace std;
void rdfs(int,int[],int,int[][10]);
int main()
{
int i,j,k,n,v,s,e,indeg[10],flag[10];
queue<int> q;
cout<<"Enter the no of vertices:\n";
cin>>n;
int a[10][10];
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
a[i][j]=0;}
for(i=1;i<e+1;i++)
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
 flag[i]=0;
 }
 cout<<"Enter the source node: ";
 cin>>s;
 flag[s]=1;
 q.push(s);
 cout<<"\nThe breadth first search order is:";
 while(!q.empty())
{
 v=q.front();
 q.pop();
 cout<<v<<" ";
 for(i=1;i<n+1;i++)
{
 if(a[v][i]==1)
 { if(flag[i]==0)
 {
 flag[i]=1;
q.push(i);
}
 }
 }
 }
 for(i=1;i<n+1;i++)
{
 flag[i]=0;
 }
 cout<<"\nThe depth first search order is:";
 rdfs(s,flag,n,a);
 return 0;
}
void rdfs(int v,int flag[],int n,int a[][10])
{
flag[v]=1;
cout<<v<<" ";
 for(int i=1;i<n+1;i++)
{
 if(a[v][i]==1)
 {
 if(flag[i]==0)
 {
 rdfs(i,flag,n,a);
}
 } }
}