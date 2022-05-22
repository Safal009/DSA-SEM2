#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

struct node
{
  int data;
  struct node *left, *right ;
};

struct node *newNode (int item)
{
  struct node *temp = (struct node *) malloc (sizeof (struct node));
  temp->data = item;
  temp->left = temp->right = NULL;
  return temp;
}

struct node *insert (struct node *node, int data)
{

  if (node == NULL)
    return newNode (data);
  if (data < node->data)
    node->left = insert (node->left, data);
  else
    node->right = insert (node->right, data);

  return node;
}

void inorder(struct node *root) {
 if (root != NULL) {
    inorder(root->left);
    cout << root->data << " -> ";
    inorder(root->right);
  }
}

void preorder(struct node *root){
    if(root!=NULL){
        cout<<root->data<<" -> ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" -> ";
    }
}

void Display(struct node *root) {
 if (root != NULL) {
    Display(root->left);
    cout << root->data << ",";
    Display(root->right);
  }
}
vector<int> longestPath(node* root)
{
    if (root == NULL) {
        vector<int> temp= {};
        return temp;
    }
 
    vector<int> rightvect = longestPath(root->right);
    vector<int> leftvect = longestPath(root->left);
 
    if (leftvect.size() > rightvect.size())
        leftvect.push_back(root->data);
 
    else
        rightvect.push_back(root->data);
        
    return (leftvect.size() > rightvect.size() ? leftvect : rightvect);
}


void swap(node *root) 
{ 
    if(root==NULL){
        return;
    }
    node *temp;
    temp=root->left;
    root->left=root->right;
    root->right=temp;
    swap(root->right);
    swap(root->left);
} 

void small(node *root){
   struct node *t = (struct node *) malloc (sizeof (struct node));
   t=root;
   while(t->left!=NULL){
       t=t->left;}
   cout<<t->data;
}


int search(node*root,int key){
    struct node *t = (struct node *) malloc (sizeof (struct node));
    t = root;
    while(t!=NULL){
        if(key==t->data){
            return t->data;
        }
        else if(key > t->data){
            t = t->right;
        }
        
        else{
            t = t->left;
        }
    }
    return 0;
}

int main ()
{
  struct node *root = NULL;
  struct node *key;
  int n;
  cout<<"Enter the number of elements (Including root) : ";
  cin>>n;
  cout<<endl;
  
  for(int i=0;i<n;i++){
      int element;
      cout<<"Enter element no. "<<i+1<<" :";
      cin>>element;
      root = insert(root,element);
  }
  
     int choice;
     int tree_size;
     
     while(choice!=10){
     
     cout<<"\n\n   *********************                  MENU                  *********************\n\n";
     cout<<" 1.Insert\n 2.Display\n 3.Inorder\n 4.Preorder\n 5.Postorder\n 6.Smallest Value\n 7.Search\n 8.Number of nodes in longest path\n 9.Swap BST\n 10.Exit\n";
     cout<<"Enter choice:  ";
     cin>>choice;
     
     switch(choice){
         
         case 1:
         {
          int insert_element;
          cout<<"Enter the element you wish to insert: ";
          cin>>insert_element;
          insert(root,insert_element);
          break;
         }
         
         
         
         case 2:
         {
          cout<<"Following is the display of the tree in ascending order:  ";
          Display(root);
          break;
         }
         
         
         
         
         case 3:
         {
          cout<<"Inorder is :    ";
          inorder(root);
          cout<<"\n";
          break;
         }
          
          
          
         case 4:
         {
          cout<<"Preorder is :    ";
          preorder(root);
          cout<<"\n";
          break;
         }
          
          
          
         case 5:
         {
          cout<<"Postorder is :    ";
          postorder(root);
          cout<<"\n";
          break;
         }
          
          
          
         case 6:
         {
          cout<<"The smallest value is : ";
          small(root);
          break;
         }
         
         
         
         case 7:
         {
          int key_;
          cout<<"Enter the Element to be searched : ";
          cin>>key_;
          cout<<endl;
          int ans=search(root,key_);
          if(ans==0){
              cout<<"Value not found ! ";
          }
          else{
              cout<<"Value found !!";
          }
          break;
         }
         
         
          
         case 8:
         {
         
          vector<int> output = longestPath(root);
          int n = output.size();
          cout<<"The number of nodes in the longest Path is: "<<output.size()<<endl;
          cout << output[n - 1];
          for (int i = n - 2; i >= 0; i--) {
          cout << " -> "<<output[i];
              
          }
          
          break; 
         }
         
         
          
         case 9:
         {
             cout << "After swapping  :"; 
             swap(root);
             inorder(root);
             break;
         }
         
         
          
         case 10:
         {
          cout<<"Done !! Thank you :)";
          break;
         }
          
          
          
         default:
         {
          cout<<"Please enter the correct value :/ ";
          break;
         }
         
          
     }
}
     
 return 0;
}
