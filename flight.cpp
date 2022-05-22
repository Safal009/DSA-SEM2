#include<iostream>
using namespace std;
class A
{   
    int n,cost[10][10]={0,0},visited[10]={0};
    string city[10];
    char choice[10][10];

    
    public:
    void input();
    void displaypaths();
    void dfs(int i);
    bool checkconnect();
};


void A::input()
{
    cout<<"Enter the number of cities: ";
    cin>>n;
    
    for(int i=0;i<n;i++){
        cout<<"Enter city no. "<<i+1<<" : ";
        cin>>city[i];
    }
    
    cout<<endl;
    
   
  
  
  for(int i=0;i<n;i++){
      
      for(int j=i+1;j<n;j++){
          
      cout<<"Is there flight between "<<city[i]<<" and "<<city[j];
      cout<<"  :  y/n    - ";
      cin>>choice[i][j];
      cout<<endl;
      
      

    if(choice[i][j]=='y'){
      cout<<"Enter the flight cost  between "<<city[i]<<" and "<<city[j]<<" : ";
      cin>>cost[i][j];
      cout<<endl;
    }
    
    else{
        cost[i][j]==0;
        cout<<endl;
    }
      }
  }
  
  cout<<endl;
}




void A::displaypaths()
{    
     cout<<"The adjacency matrix representation of the flights is : \n";
  cout<<" ";
  
       for(int k=0;k<n;k++){
           cout<<" "<<city[k]<<" ";
         }
         
         cout<<endl;
  for(int i=0;i<n;i++){
      
      cout<<city[i];
      for(int j=0;j<n;j++){
              cout<<" "<<cost[i][j]<<" ";
     
      }
      cout<<" ";
      cout<<endl;
      
  }
}



void A::dfs(int i)
{
    visited[i]=1;
    //cout<<city[i];
    for(int j=0;j<n;j++)
    {
        if(cost[i][j] && !visited[j])
        {
            //cout<<" -> ";
            dfs(j);
        }
    }
}


bool A::checkconnect()
{
    dfs(0);
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
        {
            return false;
        }
    }
    return true;
}


void menu()
{
    cout<<"\n*-------MENU-------*\n"<<endl;
    cout<<"1. Adjacency Representaion"<<endl;
    cout<<"2. Check graph connectivity"<<endl;
    cout<<"3. Exit"<<endl;
}

int main()
{  
    A f;
    int choice_;
    bool isconn;
    f.input();
    menu();
    do
    {
        cout<<"\nEnter a choice: ";
        cin>>choice_;
        switch(choice_)
        {    
            case 1:
            f.displaypaths();
            break;
            case 2:
            isconn=f.checkconnect();
            if(isconn==1)
            {
                cout<<"Graph is connected!"<<endl;
            }
            else
            {
                cout<<"Graph is disconnected!"<<endl;
            }
            break;
            
            
        }
    }
    while(choice_!=3);
    return 0;
}
