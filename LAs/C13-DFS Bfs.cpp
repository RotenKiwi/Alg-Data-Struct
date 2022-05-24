#include<iostream>
#include<queue>
using namespace std;
class infomap
{
 int n,pn,a,b,m[10][10]={0,0},visited[10]={0};
 queue<int> bfsq;
 string landm[10];
 public:
 void creategraph();
 void instruct();
 void displaymatrix();
 void displaylist();
 void setvisitedtozero();
 void dfs(int i);
 void bfs(int i);
};
void infomap::creategraph()
{
 char ch;
 cout<<"Enter the number of landmarks: ";
 cin>>n;
 cout<<"Enter the names of the landmarks: "<<endl;
 for(int k=0;k<n;k++)
 {cin>>landm[k];}
 cout<<"\nEntered landmarks are: "<<endl;
 instruct();
 cout<<"\nEnter the number of paths: ";
 cin>>pn;
 cout<<"Enter the landmark codes separated by space to create a path between them:"<<endl;
 for(int k=0;k<pn;k++)
 {
 cin>>a>>b;
 m[a-1][b-1]=m[b-1][a-1]=1;
 }
}
void infomap::instruct()
{
 for(int i=0;i<n;i++)
 {cout<<"Landmark #"<<i+1<<": "<<landm[i]<<endl;}
}
void infomap::displaymatrix()
{
 cout<<endl;
 for(int k=0;k<n;k++)
Code:
 {cout<<"\t"<<landm[k];}
 cout<<endl;
 for(int i=0;i<n;i++)
 {
 cout<<endl<<landm[i];
 for(int j=0;j<n;j++)
 {cout<<"\t"<<m[i][j];}
 cout<<endl;
 }
}
void infomap::displaylist()
{
 for(int j=0;j<n;j++)
 {
 cout<<"\nAdjacency list for "<<landm[j]<<": "<<landm[j];
 setvisitedtozero();
 for(int i=0;i<n;i++)
 {
 if(m[j][i] && !visited[i])
 {
 cout<<" -> "<<landm[i];
 visited[i]=1;
 bfsq.push(i);
 }
 while(!bfsq.empty())
 {bfsq.pop();}
 }
 cout<<endl;
 }
}
void infomap::dfs(int i)
{
 visited[i]=1;
 cout<<landm[i];
 for(int j=0;j<n;j++)
 {
 if(m[i][j] && !visited[j])
 {
 cout<<" -> ";
 dfs(j);
 }
 }
}
void infomap::bfs(int i)
{
 int j;
 if (!visited[i])
 {
 cout<<landm[i];
 bfsq.push(i);
 visited[i]=1;
 while(!bfsq.empty())
 {
 j=bfsq.front();
 for(int i=0;i<n;i++)
 {
 if(m[j][i] && !visited[i])
 {
 cout<<" -> "<<landm[i];
 visited[i]=1;
 bfsq.push(i);
 }
 }
 bfsq.pop();
 }
 }
}
void infomap::setvisitedtozero()
{
 for(int i=0;i<n;i++)
 {visited[i]=0;}
}
void menu()
{
 cout<<"\n***MENU***"<<endl;
 cout<<"0. Display landmark codes"<<endl;
 cout<<"1. Display the adjacency matrix"<<endl;
 cout<<"2. Display the adjacency list"<<endl;
 cout<<"3. Traverse using DFS"<<endl;
 cout<<"4. Traverse using BFS"<<endl;
 cout<<"5. Exit"<<endl;
}
int main()
{
 infomap f;
 int choice,di,bi;
 f.creategraph();
 menu();
 do
 {
 cout<<"\nEnter a choice: ";
 cin>>choice;
 switch(choice)
 {
 case 0:
 f.instruct();
 break;
 case 1:
 f.displaymatrix();
 break;
 case 2:
 f.displaylist();
 break;
 case 3:
 cout<<"Enter the landmark code from which you want to traverse (via DFS): ";
 cin>>di;
 f.setvisitedtozero();
 f.dfs(di-1);
 cout<<endl;
 break;
 case 4:
 cout<<"Enter the landmark code from which you want to traverse (via BFS): ";
 cin>>bi;
 f.setvisitedtozero();
 f.bfs(bi-1);
 cout<<endl;
 break;
 case 5:
 cout<<"Program exited! Thank you!";
 break;
 default:
 cout<<"Invalid choice! Please make a valid choice!"<<endl;
 break;
 }
 }
 while(choice!=5);
 return 0;
}
