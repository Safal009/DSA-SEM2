#include <iostream>
using namespace std;
class TBT; // forward declaration
class node
{
 node *left,*right;
 int data;
 bool rbit,lbit;
public:
 node()
{
  left=NULL;
  right=NULL;
  rbit=lbit=0;
}
 node(int d)
 {
  left=NULL;
  right=NULL;
  rbit=lbit=0;
  data=d;
 }
 friend class TBT;
};

class TBT
{
 node *root; 
public:
 TBT() 
{
  root=new node(9999);    
  root->left=root;
  root->rbit=1;
  root->lbit=0;
  root->right=root;
}
 void create();
 void insert(int data);
 node *inorder_suc(node *);
 void inorder_traversal();

};

void TBT::create()
{
 int n;
 cout<<"\nEnter number of nodes to be inserted into the tree : ";
 cin>>n;
 for(int i=0;i<n;i++)
 {
  int info;
  cout<<"\nEnter data for node "<<i+1<<" : ";
  cin>>info;
  this->insert(info);
 }
}
void TBT::insert(int data)
{

 if(root->left==root&&root->right==root) //no node in tree
 {
  node *p=new node(data);
  p->left=root->left;
  p->lbit=root->lbit; //0
  p->rbit=0;
  p->right=root->right;
  root->left=p;
  root->lbit=1;
  return;
 }
 node *cur=new node;
 cur=root->left;
 while(1)
 {

  if(cur->data<data)   //insert right
  {
   node *p=new node(data);
   if(cur->rbit==0)
   {
    p->right=cur->right;
    p->rbit=cur->rbit;
    p->lbit=0;
    p->left=cur;
    cur->rbit=1;
    cur->right=p;
    return;
   }
   else
    cur=cur->right;
  }
  if(cur->data>data) //insert left
  {
   node *p=new node(data);
   if(cur->lbit==0)
   {
    p->left=cur->left;
    p->lbit=cur->lbit;
    p->rbit=0;
    p->right=cur; 
    cur->lbit=1;
    cur->left=p;
    return;
   }
   else
    cur=cur->left;
  }
 }

}

void TBT::inorder_traversal()
{
 node *c=root->left;
 while(c->lbit==1)
  c=c->left;
 while(c!=root)
 {
  cout<<" "<<c->data;
  c=inorder_suc(c);
 }
 cout<<endl;
}
node* TBT::inorder_suc(node *c)
{
 if(c->rbit==0)
  return c->right;
 else
  c=c->right;
 while(c->lbit==1)
 {
  c=c->left;
 }
 return c;
}

int main() {
 TBT t1;
 int value;
 int choice;
 do
 {
  cout<<"\n**************** MENU ****************\n";
  cout<<"\n1.Create a Tree\n2.Insert into the tree\n3.Inorder traversal of tree \n4.Exit\nEnter your choice: ";
  cin>>choice;
  switch(choice)
  {
  case 1:
   t1.create();
   break;
  case 2:
   cout<<"\nEnter Number(data) : ";
   cin>>value;
   t1.insert(value);
   break;
  case 3:
   cout<<"\nInoder Traversal of TBT --> \n"<<endl;;
   t1.inorder_traversal();
   break;
   case 4:
   cout<<"\nThankyou !!\n\n";
   break;
  default:
   cout<<"\nYou had entered a wrong choice \n\n";
  }

 }while(choice<4);


 return 0;
}
