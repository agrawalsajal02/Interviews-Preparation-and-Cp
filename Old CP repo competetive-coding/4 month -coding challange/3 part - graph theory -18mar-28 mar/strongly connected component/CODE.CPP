//very imp code
//SEE THE TEXT AND VIDEO FOR CLLARIFIATION;
//only for directed graph
//make sure  to delete graph after use --good habit
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll>v[1000];
//trasnpose graph
vector<ll>tt[1000];
//global verti to calculate no of verti in conn component
ll vv=0;
//and its vector
vector<ll>no;
bool vis[1000];
int *level=new int[1000];
stack<ll>s;
void dfs(ll p){
	vis[p]=true;
	level[p]=0;
	for(ll i=0;i<v[p].size();i++){
		if(!vis[v[p][i]]){
			dfs(v[p][i]);
			level[v[p][i]]=level[p]+1;
		}
	}
	
	s.push(p);
}
void dfs_on_transpose(ll p){
	vis[p]=true;
	vv++;
	for(ll i=0;i<tt[p].size();i++){
		if(!vis[tt[p][i]]){
			dfs_on_transpose(tt[p][i]);
		}
	}
}
int main(){
	for(ll i=0;i<1000;i++){
		level[i]=INT_MAX;
		vis[i]=false;
	}
	ll n,m;cin>>n>>m;
	for(ll i=0;i<m;i++){
		ll a,b;cin>>a>>b;
		v[a].push_back(b);//only vertix from a to b
	}
	for(ll i=0;i<n;i++){    //use i=1 if the starting of vertices is 1
		if(!vis[i]){
			dfs(i);
		}
	}
	//step 2 reverse the graph vertices;
	for(ll i=0;i<m;i++){
		//can use iterator also for(i = adj[v].begin(); i != adj[v].end(); ++i) 
        /*{ 
            g.adj[*i].push_back(v); 
        }*/ 
		for(ll j=0;j<v[i].size();j++){
			tt[v[i][j]].push_back(i);
		}
		//only vertix from a to b
	}
	
	
	//step3 make vis to unvisted
	for(ll i=0;i<1000;i++){
		vis[i]=false;
	}cout<<endl;
	cout<<" printing stack value"<<endl;
	ll pp=s.size(),conncom=0;
	for(ll i=0;i<pp;i++){//dont put i<s.stack in loop because every time the stack size s decreasing then the loop part also decraease and it again cal size with diff valu
		ll value=s.top();s.pop();
		cout<<"  value:- "<<value<<endl;
		if(vis[value]==false){
			conncom++;
			dfs_on_transpose(value);
			no.push_back(vv);
			vv=0;
		}
	}
	ll value=no.size();
	for(ll i=0;i<value;i++){
		cout<<no[i]<<" ";
	}
	for(auto& y : v){
		y.clear();
	}
	for(auto &y : tt){
		y.clear();
	}
	
	
}
