#include<iostream>
#include<bits/stdc++.h>
#include <queue>
using namespace std;

class Graph
{
  int N,cost[10][10]={0,0},visited[10]={0},visited1[10]={0};
  string cities[10];
  public:
  void get_data();
  void matrix();
  void dfs(int i);
  void node_display();
  void bfs(int start,int N);
  void list(int x);
};


void Graph::get_data(){
  cout<<"Enter the number of landmarks : ";
  cin>>N;
  cout<<"\n";
  char ch;
  for(int i=0;i<N;i++){
    cout<<"Enter landmark  "<<i+1<<" :";
    cin>>cities[i];
  }
  cout<<"\n";

  for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++)
        {   cout<<"Do you want to connect "<<cities[i]<<" and "<<cities[j]<<"  (y/n) -";
            cin>>ch;
            if(ch=='y'){
           cost[i][j]=1;
           cost[j][i]=cost[i][j];
        }
  else{
        cost[i][j]=0;
      }
    }
  }
}


void Graph::matrix(){
     
  cout<<" ";
  for(int i=0;i<N;i++){
    cout<<"  "<<cities[i]<<" ";
  }
  cout<<"\n";
  for(int k=0;k<N;k++){
  cout<<cities[k];
    for(int j=0;j<N;j++){
         cout<<"  "<<cost[k][j]<<" ";
    }
    cout<<"  ";
    cout<<"\n";
  }
}


void Graph::dfs(int i)
{
    visited[i]=1;
    cout<<cities[i];
    for(int j=0;j<N;j++)
    {
        if(cost[i][j] && !visited[j])
        {   
          cout<<" -> ";
          dfs(j);
        }
    }
}

void Graph::list(int x)
{
    visited1[x]=1;
    cout<<cities[x];
    for(int j=0;j<N;j++)
    {
        if(cost[x][j] && !visited1[j])
        {   
          cout<<" -> ";
          list(j);
        }
    }
}


void Graph::node_display(){
    for(int i=0;i<N;i++){
      cout<<i+1<<"."<<cities[i]<<"\n";
    }
}


void Graph::bfs(int start ,int N)
{
    queue<int> bfsqueue;
    for(int i=0; i<N; i++)
        visited[i] = 0;
    
    if(!visited[start]) {
        cout <<"The BFS for "<< cities[start] << " is as  -> ";
        bfsqueue.push(start);
        while(!bfsqueue.empty()) {
            int temp = bfsqueue.front();
            for(int i=0; i<N; i++) {
                if(cost[temp][i] && !visited[i]) {
                    cout << cities[i] << " ";
                    visited[i] = 1;
                    bfsqueue.push(i);
                }
            }
            bfsqueue.pop();
        }
    }
}

int main(){


   Graph g;
   cout<<"  \n\n================       WELCOME         ===============\n\n";
   g.get_data();
   
   int menu_choice; 
   while(menu_choice!=5){

      cout<<" \n\n **************  \n      MENU     \n  ***************  \n\n\n";
      cout<<"1.Matrix\n2.DFS\n3.BFS\n4.List\n5.Exit\n\n\n";
      cout<<"Enter choice: ";
      cin>>menu_choice;
      cout<<" \n\n ********************************************************** \n\n\n";
  

  switch(menu_choice){

    case 1:
    
    cout<<"The MATRIX representation of the graph is: \n";
    g.matrix();
    cout<<"\n\n";
    break;
    
    

    case 2:
    
      int dfs_vertex;
      cout<<"Choose any Vertex: \n";
      g.node_display();
      cout<<"\n";
      cin>>dfs_vertex;
      cout<<"The DFS sequence is as follows : ";
      dfs_vertex=dfs_vertex-1;
      g.dfs(dfs_vertex);
      cout<<"\n\n";
      break;
    

    case 3:
     
    
    int start_;
    g.node_display();
    cout<<"Enter start vertex: ";
    cin>>start_;
    start_=start_ - 1;
    g.bfs(start_,10);
    cout<<"\n\n";

    break;
    

    case 4:
       int choice;
       cout<<"Choose any Vertex: \n";
       g.node_display();
       cout<<"\n";
       cin>>choice;
       cout<<"The list is as follows : ";
       choice=choice-1;
       g.list(choice);
       cout<<"\n\n";
       break;
     

    
    case 5:
       cout<<"Program Executed Thank you !! ";
       break;
    
    default:
       cout<<"Please enter valid input :) ";
  }
}
return 0;
}
