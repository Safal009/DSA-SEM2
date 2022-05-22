#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

struct node{
  string data,meaning;
  struct node *left{}, *right{};
};


void insert(node *&root, const string& k, const string& meaning_){
    if(root == NULL){
        root = new node;
        root->data = k;
        root->meaning = meaning_;
        root->left = NULL;
        root->right = NULL;
    }
    else{
        if(k < root->data){
            insert(root->left, k , meaning_);
        }
        
        else{
            insert(root->right, k , meaning_);
        }
    }
}

void print(node *n){
    if(n!= NULL){
        print(n->left);
        cout<< n->data <<" : "<<n->meaning<<"\n";
        print(n->right);
    }
}

node *find(node *root, const string& k) {
    if (root == NULL)
        return NULL;
        
 /*  int c=0;
    while(root!=NULL){
        c++;
        if(k==root->data){
            cout<<"No. of comparisons: "<<c;
            cout<<"\n\n";
            return root;
        }
    }*/

    if (k == root->data)
        return root;

    if (k < root->data)
        return find(root->left, k);
    else
        return find(root->right, k);
}

node *small(node *root){
    node *t;
    t = root;
    while(t->left!=NULL){
        t = t->left;
    }
    cout<<"The smallest value in the BST is: "<<t->data;
    return t;
}

void swap(node *root){
    node *temp;
    if(root != NULL){
        temp= new node;
        temp = root->left;
        root->left = root->right;
        root->right = temp;
        swap(root->left);
        swap(root->right);
    }
}

node *update(node *root, const string& k,const string& update_key) {
    if (root == NULL)
    {
        return NULL;}

    if (k == root->data)
    {
        root->meaning = update_key;
        return root;}

    if (k < root->data)
    {
        root->meaning = update_key;
        return update(root->left, k , root->meaning);
    }
    else
    {
        root->meaning = update_key;
        return update(root->right, k , root->meaning);
    }
}

node *del(node *root,const string& key){
    if(root==NULL){
        return root;
    }
    
    if(key < root->data){
        root->left = del(root->left,key);
    }
    
    else if(key > root->data){
        root->right = del(root->right ,key);
    }
    
    else{
        if(root->left && root->right == NULL){
            return NULL;
        }
        
        else if(root->left == NULL){
            node *temp = root->right;
            delete(root);
            return temp;
        }
    
        else if(root->right == NULL){
            node *temp = root->left;
            delete(root);
            return temp;
        }
    node *temp = small(root->right);
    root->data = temp->data;
    
    root->right = del(root->right, temp->data);
    }
    return root;
    
}


int main(){
    node *root = NULL;
    
    
    int choice;
    while(choice!=9){
    cout<<"\n\n\t      *************************    MENU     ***********************\n\n";
    cout<<"\t\t\t\t  1.CREATE\n\t\t\t\t  2.DISPLAY\n\t\t\t\t  3.ADD\n\t\t\t\t  4.DELETE\n\t\t\t\t  5.SEARCH\n\t\t\t\t  6.SMALLEST VALUE\n\t\t\t\t  7.SWAP\n\t\t\t\t  8.UPDATE\n\t\t\t\t  9.EXIT\n\n";
    cout<<"\t      *************************************************************\n\n";
    cout<<"Enter choice:  ";
    cin>>choice;
    cout<<endl;
    
    switch(choice){
        case 1:
        {        
                 int n;
                 cout<<"\n\nEnter the number of strings: ";
                 cin>>n;
                 cout<<endl;
                 for(int i=0;i<n;i++){
                    string element,mean;
                    cout<<"Enter string "<<i+1<<" : ";
                    cin>>element;
                    cout<<"Enter its meaning: ";
                    cin>>mean;
                    insert(root,element,mean);
                    cout<<endl;
                 }
                 cout<<"\n -------       Binary Search Tree (String) Created successfully, press 2 to verify !!    -----------\n\n";
            break;
        }
        
        case 2:
        {   
            cout<<"Following is the display of the BST:  \n";
            print(root);
            cout<<"\n\n";
            break;
        }
        
        case 3:
        {   
            string add,mean_;
            cout<<"Enter the string to be added: ";
            cin>>add;
            cout<<"Enter its meaning: ";
            cin>>mean_;
            insert(root,add,mean_);
            cout<<"\n       ---------    String added , press 2 to verify !!     ---------   \n\n";
            break;
        }
        
        case 4:
        {   
            string del_key;
            cout<<"Enter the string you wish to delete: ";
            cin>>del_key;
            del(root,del_key);
            cout<<"         --------------      string deleted       ----------";
            break;
        }
        
        case 5:
        {   
            string find_;
            cout<<"Enter the string you want to Search: ";
            cin>>find_;
            node *ans;
            ans = find(root,find_);
            if(ans==NULL){
                cout<<"  -------------        Value not found !!      -------------- ";
            }
            
            else{
                cout<<"   -------------      Value found !!   ------------ ";   
            }
            
            break;
        }
        
        case 6:
        {   
            small(root);
            break;
        }
        
        case 7:
        {   
            cout<<"     --------         After swapping :         --------\n";
            swap(root);
            print(root);
            break;
        }
        
        
        case 8:
        {   
            string update_,string;
            cout<<"Enter the string: ";
            cin>>string;
            node *ans;
            ans = find(root,string);
            if(ans==NULL){
                cout<<"  -------------        Value not found !!      -------------- \n";
            }
            
            else{
            cout<<"Enter the meaning of the string you wish to update: ";
            cin>>update_;
            update(root,string,update_);
            cout<<" \n     -------------          String Updated !!!      ------------\n\n";
            }
            break;
        }
        
        case 9:
        {   
            cout<<"\n\n    DONE , thank you :) \n\n";
            break;
        }
        
        
        default:
        {
            cout<<"               ----------   Please enter the correct value !!   ----------          \n\n";
        }
    }
    
}
    
    return 0; 
}
