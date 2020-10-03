#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll>v[3000];
ll *level=new ll[3000];
bool vis[1000000];
ll a[1000005][2];
void bfs(ll s){
	queue<ll>q;
	q.push(s);
	level[s]=0;
	vis[s]=true;
	while(!q.empty()){
		ll p=q.front();
		q.pop();
		for(ll i=0;i<v[p].size();i++){
			if(!vis[v[p][i]]){
				level[v[p][i]]=level[p]+1;
				q.push(v[p][i]);
			
				vis[v[p][i]]=true;
			}
			
		}
		
		
		
	}
	
	
	
}










ll k=0;
ll init(ll n){
	for(ll i=0;i<n+5;i++){
		vis[i]=false;
	}
}




int main(){
ll vertix;
	ll edgesno;

ll t;cin>>t;
for(ll j=0;j<t;j++){


	cin>>vertix>>edgesno;



	for(ll i=0;i<edgesno;i++){
		ll m,n;
		cin>>m>>n;
		m--;
		n--;
		v[m].push_back(n);
		v[n].push_back(m);
		a[i][0]=m;
		a[i][1]=n;
		
	}
	init(vertix);
	for(ll i=0;i<vertix;i++){
		if(!vis[i]){
	bfs(i);		
		}
	}
	ll flag=0;
for(ll i=0;i<edgesno;i++){
	
	if((level[a[i][0]]-level[a[i][1]])%2==0){
		flag=1;
	}
}

k++;

if(flag==1){
	cout<<"Scenario #"<<k<<":\nSuspicious bugs found!\n";
}
else{
cout<<"Scenario #"<<k<<":\nNo suspicious bugs found!\n";
	
}


















for(ll i=0;i<vertix;i++){
	v[i].clear();
	}
	
}
}
