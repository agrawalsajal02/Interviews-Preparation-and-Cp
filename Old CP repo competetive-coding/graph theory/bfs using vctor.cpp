//source video https://unacademy.com/lesson/dfs-implementation-in-c/35BFPHHI
#include<bits/stdc++.h>
using namespace std;

vector<int>v[10];
int *level=new int[10];
bool vis[10];
void bfs(int s){
	queue<int>q;
	q.push(s);
	level[s]=0;
	vis[s]=1;
	cout<<s<<"  level "<<level[s]<<endl;
	while(!q.empty()){
		int p=q.front();
		q.pop();
		for(ll i=0;i<v[p].size();i++){
			if(!vis[v[p][i]]){
				level[v[p][i]]=level[p]+1;
				q.push(v[p][i]);
				cout<<v[p][i]<<" level "<<level[v[p][i]]<<endl;
				vis[v[p][i]]=1;
			}
			
		}
		
		
		
	}
	
	
	
}

int main(){
int vertix;
	int edgesno;
	cin>>vertix>>edgesno;



	while(edgesno--){
		int m,n;
		cin>>m>>n;
		v[m].push_back(n);
		v[n].push_back(m);
		
		
	}
	for(int i=1;i<=vertix;i++){
		if(!vis[i]){
	bfs(i);		
		}
	}
	
	
	
}
