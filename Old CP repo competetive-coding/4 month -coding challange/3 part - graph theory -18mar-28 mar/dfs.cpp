//decting cycle in graph --ujust some modifiction in normal dfs
#include<bits/stdc++.h>
using namespace std;
#define ll int
vector<int>v[1000];
bool vis[1000];
bool full[1000];
ll t=0;
//int *parent=new int[5];
void dfs(int a){
vis[a]=true;
for(ll i=0;i<v[a].size();i++){

    if(full[v[a][i]]==1){
        t=1;
    }
    if(!vis[v[a][i]]){
            dfs(v[a][i]);

}
 if((i==v[a].size()-1)){
                full[a]=1;

            }
}
}
int main(){
cout<<" enter no of vertix &edges "<<endl;
ll n,m;cin>>n>>m;

for(ll i=0;i<n;i++){
    vis[i]=false;
    full[i]=false;
}
for(ll i=0;i<m;i++){
    ll a,b;
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
}
for(ll i=0;i<m;i++){
    if(vis[i]==0){
   dfs(i);
    }
}
if(t==1){
    cout<<" graph has cycle"<<endl;
}
else{
    cout<<" graph haas no cycle " <<endl;
}
cout<<endl<<endl;

for(ll i=0;i<n;i++){

    cout<<full[i]<<"  ";
}




}
