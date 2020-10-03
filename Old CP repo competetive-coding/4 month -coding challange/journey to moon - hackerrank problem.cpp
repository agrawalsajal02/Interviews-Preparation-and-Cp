//https://unacademy.com/lesson/graph-traversal-technique-ii-dfsdepth-first-search/4IXFCEPQ

//dfs implementation to find no of connected component
//time complexicity :- o(v+e)

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

vector<ll>vi[1000000];
bool vis[1000000];
int kk=0;
vector<ll>noofcon;//size of each connected component

void dfs(ll s){
    vis[s]=1;
    for(ll i=0;i<vi[s].size();i++){
        if(!vis[vi[s][i]]){
            kk++;
            dfs(vi[s][i]);
        }
    }
}




void init(ll n){
    for(ll i=0;i<n;i++){
        vis[i]=0;
    }
}







int main(){
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll edge,vertix,connectedcomponent=0;
    cin>>vertix>>edge;
    
    for(ll i=0;i<edge;i++){
        ll a,b;
        cin>>a>>b;
        vi[a].push_back(b);
    vi[b].push_back(a);
    }
    ll p=0;
    for(ll i=0;i<vertix;i++){
        if(!vis[i]){
            kk++;
            connectedcomponent++;
            dfs(i);
            noofcon.push_back(kk);
            kk=0;
        }
        
    }
    ll sum=0;
ll result=0;    
    for(ll hh=0;hh<connectedcomponent;hh++){
result=sum*noofcon[hh];
sum=sum+noofcon[hh];

}
    /*
    for(ll hh=0;hh<connectedcomponent;hh++){
        for(ll gg=hh+1;gg<connectedcomponent;gg++){
            sum=sum+noofcon[gg]*noofcon[hh];
        }
        
        
    }
    */
    cout<<result<<endl;
    
}    

