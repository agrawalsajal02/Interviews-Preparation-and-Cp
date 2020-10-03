//motivation problem
//first problem taht givess me 5 star in hacker rank
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll>v[10000];
bool vis[100000];
ll level[100000];
 void  bfs(ll sou){
     queue<ll>q;
     q.push(sou);
     vis[sou]=true;
    
     level[sou]=0;
     while(!q.empty()){
         ll temp=q.front();q.pop();
         for(ll j=0;j<v[temp].size();j++){
             if(vis[v[temp][j]]==false){
                 q.push(v[temp][j]);
                 vis[v[temp][j]]=true;
                 level[v[temp][j]]=level[temp]+1;             
             }
         }
         
     }
     
     
 }


int main(){
    ll q;cin>>q;
    for(ll i=0;i<q;i++){
        for(ll j=0;j<10000;j++){
            level[j]=INT_MAX;
            vis[j]=false;
        }ll n,m;
        cin>>n>>m;
        for(ll j=0;j<m;j++){
            ll a,b;
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }ll st;cin>>st;
        bfs(st);
            for(ll k=1;k<=n;k++){

        if(level[k]==INT_MAX){
            cout<<"-1 ";
            continue;
        }
        else if(level[k]==0){
            continue;
        }
        else{
            cout<<level[k]*6<<" ";
        }
        
        
        
    }
    
    
    
    cout<<endl;
for (auto& a : v) {
   a.clear();
}
        
    }
    
    
    
    
    
    
    
    
}    
