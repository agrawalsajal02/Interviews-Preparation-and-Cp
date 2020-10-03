#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll>v[5];
ll *level=new ll[5];
bool vis[10];
ll *parent=new ll[5];
void bfs(ll a){
queue<ll>q;
q.push(a);
level[a]=0;
vis[a]=1;
while(!q.empty()){
    ll temp=q.front();
    q.pop();
    for(ll i=0;i<v[temp].size();i++){
        if(!vis[v[temp][i]]){
            q.push(v[temp][i]);
            parent[v[temp][i]]=temp;
            level[v[temp][i]]=level[temp]+1;
         cout<<v[temp][i]<<"  level "<<level[v[temp][i]]<<endl;
            vis[v[temp][i]]=1;
        }
    }


}


}int main(){

int x;
cout<<" print total no of edges "<<endl;
cin>>x;
for(ll i=0;i<5;i++){
vis[i]=0;
}
for(ll i=0;i<5;i++){
    ll a,b;
    cin>>a>>        b;

v[a].push_back(b);
v[b].push_back(a);
}
for(ll i=0;i<5;i++){
if(vis[i]==0){
bfs(i);
}
}

}
