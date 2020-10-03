#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll>v[1000000];
ll y=-1;
ll value=0;
bool vis[1000000];
void dfs(ll a){
vis[a]=true;
for(ll i=0;i<v[a].size();i++){
    if(value==v[a][i]){
        y=1;
    }
    cout<<" heee "<<i<<" "<<a<<" "<<v[a][i]<<endl;
    if(vis[v[a][i]]==false){
        dfs(v[a][i]);
    }
}
}
int main(){
ll t;cin>>t;
for(ll r=0;r<t;r++){
    ll n;cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++){
        cin>>a[i];
        vis[i]=false;
    }
    for(ll i=0;i<n;i++){
        v[i].push_back((a[i]+i+1)%n);
    }
    ll cou=0;
    for(ll h=0;h<n;h++){
        value=h;
        cout<<" here "<<h<<endl;
        y=-1;
        dfs(h);
        if(y==1)cou++;
        for(ll w=0;w<n;w++){
        vis[w]=false;
        }
        cout<<h<<" "<<y<<" "<<cou<<endl;

        y=-1;

    }

cout<<cou<<endl;

}
for(auto &b : v){
    b.clear();
}

}

