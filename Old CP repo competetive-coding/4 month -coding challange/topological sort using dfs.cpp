//topological sort using dfs using lexiographically sorted order
#include<bits/stdc++.h>
using namespace std;
vector<int>v[10000];
int level[1000];
bool vis[1000];
stack<int>s;
void dfs(int a){
level[a]=0;
vis[a]=true;
for(int i=0;i<v[a].size();i++){
    if(vis[v[a][i]]==false){
        dfs(v[a][i]);}
}
s.push(a);

}
int main(){
for(int i=0;i<1000;i++){
    level[i]=0;
    vis[i]=false;
}
int n,m;
cin>>n>>m;
for(int i=0;i<m;i++){
    int a,b;cin>>a>>b;
    v[a].push_back(b);
}
for(int i=1;i<=n;i++){
sort(v[i].begin(),v[i].end(),greater<int>());
}
for(int i=n;i>0;i--){
    if(vis[i]==false){

        dfs(i);
    }
}

for(int i=0;i<n;i++){

cout<<s.top()<<" ";
s.pop();



}


}
