#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<pair<ll,ll>>v[101];
ll co=0;
bool vis[101];
void dfs(ll value,ll n){
vis[value]=true;
if(v[value].size()>0){

ll p=v[value][0].first;
ll k=v[value][0].second;
if(vis[p]==false)
dfs(p,n);
}
else{
    ll gg=value;
    ll vv;
for(ll j=0;j<n;j++){
    if(v[j][gg].first==gg){
        co=v[j][gg].second+co;
     if(vis[v[j][gg].first]==false)
        dfs(v[j][gg].first,n);
        break;
    }
}


}


}
int main(){
ll t;cin>>t;

for(ll i=0;i<t;i++){
memset(vis,false,sizeof(vis));
ll n;cin>>n;
for(ll j=0;j<n;j++){

ll a,b,c;
cin>>a>>b>>c;
v[a].push_back(make_pair(b,c));

}
dfs(1,n);
cout<<co<<endl;
co=0;


}





}
