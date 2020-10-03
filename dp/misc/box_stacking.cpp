// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int maxHeight(int height[],int width[],int length[],int n);

int main()
{
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    

    int A[1000],B[1000],C[10001];
    for(int i=0;i<n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        A[i]=a;
        B[i]=b;
        C[i]=c;
    }
    cout<<maxHeight(A,B,C,n)<<endl;
}
 
} // } Driver Code Ends
/*The function takes an array of heights, width and 
length as its 3 arguments where each index i value 
determines the height, width, length of the ith box. 
Here n is the total no of boxes.*/
struct node{
    int hei,wid,len;
    node(int h,int w,int l){
        hei=h;
        wid=w;
        len=l;
    }
};
bool comp(node n1,node n2){
    return (n1.wid*n1.len<n2.wid*n2.len);
}
int maxHeight(int h[],int w[],int l[],int n)
{
vector<node>v;
for(int i=0;i<n;i++){
    v.push_back(*(new node(h[i],w[i],l[i])));
    v.push_back(*(new node(h[i],l[i],w[i])));
    v.push_back(*(new node(w[i],h[i],l[i])));
    v.push_back(*(new node(w[i],l[i],h[i])));
    v.push_back(*(new node(l[i],w[i],h[i])));
    v.push_back(*(new node(l[i],h[i],w[i])));
}
sort(v.begin(),v.end(),comp);

int np=v.size();
int dp[np+1];
for(int i=0;i<=np;i++){
    dp[i]=v[i].hei;
}
int ans=0;
for(int i=1;i<np;i++){
    for(int j=0;j<i;j++){
        if(v[j].wid<v[i].wid&&v[j].len<v[i].len){
            if(dp[j]+v[i].hei>dp[i]){
                dp[i]=dp[j]+v[i].hei;
                ans=max(ans,dp[i]);
            }
        }
    }
}

return ans;
/*
2
4
4 6 7 1 2 3 4 5 6 10 12 32
3
1 2 3 4 5 6 3 4 1

op:
60
15


*/


}
