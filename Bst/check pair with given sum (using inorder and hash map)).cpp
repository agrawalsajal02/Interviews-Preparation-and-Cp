//check pair with given sum using inorder traversal
#include <bits/stdc++.h>
#define MAX_SIZE 100
using namespace std;
struct node
{
    int val;
    struct node *left;
    struct node *right;
    
    node(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};
bool isPairPresent(struct node *root, int target);
struct node *insert(struct node *root,int a){
    if(root==NULL)
        return new node(a);
    if(root->val>a){
        root->left=insert(root->left,a);
    }
    if(root->val<a){
        root->right=insert(root->right,a);
    }
    return root;
}
void inorder(struct node *root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
/*This is a function problem.You only need to complete the function given below*/
/*Complete the function below
Node is as follows
struct node
{
    int val;
    struct node *left, *right;
};
*/
bool flag=0;
unordered_map<int,bool>m;
void inorder(struct node *root, int target){
    if(root==NULL){
        return;
    }
    inorder(root->left,target);
    if(target-root->val>=0){
        if(m[root->val]){
            flag=1;
        }
        m[target-(root->val)]=true;
    }
    inorder(root->right,target);
}
bool isPairPresent(struct node *root, int target)
{
    flag=0;
    inorder(root,target);
    m.clear();
    return flag;
//add code here.
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,target;
        cin>>n>>target;
        struct node *root =  NULL;
        while(n--){
            int a;
            cin>>a;
            if(root==NULL){
                root=new node(a);
            }
            else{
                insert(root,a);
            }
        }
        //inorder(root);
    cout<<isPairPresent(root, target)<<endl;
    }
    return 0;
}
