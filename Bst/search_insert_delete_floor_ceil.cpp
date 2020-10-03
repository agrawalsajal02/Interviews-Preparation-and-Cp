//BINARY SEARCH TREE WITH INSERT SEARCH AND DELETE NODE
//THEN IS IT BINARY SEARCH TREE
//THEN FIND FLOOR , CEIL AND OTHER OPERATION
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *left;
    struct node *right;
    node(int v){
        data=v;
left=NULL;
right=NULL;
    } 
};
struct node *createnode(int data){
node *temp=new node(data);
return temp;
};
struct node *head=NULL;

void insertnode(int u){
    struct node *newnode=createnode(u);
    node *temp=head,*par=head;
    if(temp==NULL){
        head=newnode;
    //  return head;
    return;
    }
    while(temp!=NULL){
                if(temp->data>u){
                    par=temp;
                    temp=temp->left;
                }
                else{
                    par=temp;
                    temp=temp->right;
                }       
        }
    
    if(par->data>u){
            par->left=newnode;
    }
    else{
            par->right=newnode;
    }
    
//  return head;
    
}
node * insertnoderecursive(int u,node* root){
    if(root==NULL){
    return createnode(u);
    }
    if(root->data>u){
        root->left=insertnoderecursive(u,root->left);
    }
    else{
        root->right=insertnoderecursive(u,root->right);
    }
}
void inorder(struct node*root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
bool search(int data){
    if(head==NULL){
    return false;
    }
    node *temp=head;
    while(temp!=NULL){  
    if(temp->data>data){
        temp=temp->left;
    }
    else if(temp->data<data){
        temp=temp->right;       
    }
    else{
        return true;
    }
    
}
    return false;
}
node *searchrecusive(int u,struct node *root){
    if(root==NULL){
        return NULL;
    }
    if(root->data==u){
        return root;
    }
    if(root->data>u){
        return (searchrecusive(u,root->left));
    }

        return (searchrecusive(u,root->right));
    
}

node *findinordersuccessor(struct node *root){
    while(root&&root->left!=NULL){
            root=root->left;
    }
        return root;
}
struct node * deletenode(struct node* root,int key){
    if(root==NULL){
        return root;
    }
    if(root->data>key){
        root->left=deletenode(root->left,key);
    }
    else if(root->data<key){
        root->right=deletenode(root->right,key);
    }
    else{
        if(root->left==NULL||root->right==NULL){
            if(root->left==NULL&&root->right!=NULL){
                struct node *temp=root->right;
                free(root);
                return temp;
            }
            else if(root->left!=NULL&&root->right==NULL){
                struct node *temp=root->left;
                free(root);
                return temp;
            }
            else{
                free(root);
                return NULL;
            }
        }
        else{
            //both children
            struct node *temp=findinordersuccessor(root->right);
            root->data=temp->data;
            root->right=deletenode(root->right,root->data);
            return root;
        }
    }
}
int findceil(node *root,int data){
int ans=data;
while(root!=NULL&&root->data!=data){
    if(root->data>data){
        //for floor put here
        root=root->left;
    }
    else if(root->data<data){
        ans=root->data;
        root = root->right;         
    }
    else{
        ans-root->data;
    }
}
if(root!=NULL&&root->data==data){
    return data;
}
return ans;

}
int main(){
//iterative part
/*insertnode(5);
insertnode(9);
insertnode(1);
insertnode(10);
insertnode(2);
insertnode(3);
//if not make head global , then pass head by reference
*/
//recursive method
head=insertnoderecursive(5,head);
head=insertnoderecursive(9,head);
head=insertnoderecursive(2,head);
head=insertnoderecursive(1,head);
inorder(head);

/*          Searching   Part     */
if(search(1)){
    cout<<"YES"<<endl;
}
else{
    cout<<"NO"<<endl;
}

if(searchrecusive(9,head)!=NULL){
    cout<<"YES"<<endl;
}
else{
    cout<<"NO"<<endl;
}


/*----------------------------------*/

/*----  delete node  ---------------*/
/*has 3 case
when leaf
when only one child
when it has two child --then we have to find inorder successor
*/
/*
deletenode(head,2);
inorder(head);
*/
cout<<findceil(head,100)<<endl;


/*-----------------------------------*/
}
