//https://codeforces.com/problemset/problem/242/C
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll>v[1000000000];
ll *level=new ll[1000000000];
bool vis[1000000000];
ll *parent=new ll[1000000000];

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


}
int main(){
ll i1,j1,i2,j2;
cin>>i1>>j1>>i2>>j2;

ll n;
cin>>n;
for(ll i=0;i<n;i++){
    ll r,a,b;
    cin>>r>>a>>b;
    ll value=(r-1)*1000000000;
    for(ll j=value+a;j<=value+a+b;j++){


    }
}





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

