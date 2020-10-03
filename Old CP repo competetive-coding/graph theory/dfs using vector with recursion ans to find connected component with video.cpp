//https://unacademy.com/lesson/graph-traversal-technique-ii-dfsdepth-first-search/4IXFCEPQ

//dfs implementation to find no of connected component
//time complexicity :- o(v+e)

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

vector<ll>vi[1000];
bool vis[1000];


void dfs(ll s){
	vis[s]=1;
	for(ll i=0;i<vi[s].size();i++){
		if(!vis[vi[s][i]]){
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
			connectedcomponent++;
			dfs(i);
		}
		
	}cout<<endl;
	cout<<" no of compo :"<<connectedcomponent<<endl;
	
}	
