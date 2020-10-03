//time complexicity:-o(n^2)
//for optimization use
// 1)use adjancy list
// 2) compute min distance (priority queue)
//  with priority queue and adjancy list wwe can achieve in o((v+e)*log v);
/*
input:=5 7
0 1 4
0 2 8
1 2 2
1 3 5
2 3 5
2 4 9
3 4 4

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int findminvertix(int *dis,bool *visited,int n){
	int minvertix = -1;
	for(ll i=0;i<n;i++){
	    if((minvertix==-1)&&(!visited[i])){
	        minvertix=i;
	        continue;
	    }
		if((dis[minvertix]>dis[i])&&(!visited[i])){
			minvertix=i;
		}
	}
return minvertix;
}
void kruskals(int **edge,int n){
	int *dis = new int[n];
	bool * visited= new bool[n];
	for(ll i=0;i<n;i++){
		dis[i]=INT_MAX;
		visited[i]=false;
	}	dis[0]=0;

	for(ll k=0;k<n-1;k++){
		int minvertix = findminvertix(dis,visited,n);
	     visited[minvertix]=true;
		 for(ll j=0;j<n;j++){
		  	if((edge[minvertix][j]!=0)&&(!visited[j])){
	     		int dist = dis[minvertix]+edge[minvertix][j];
	     	      if(dist<dis[j]){
	     	      	dis[j]=dist; }
			 }


		 }}

	for(ll i=0;i<n;i++){
		cout<<" i "<<i<<" "<<dis[i]<<" "<<endl;
	}
	delete []visited;
	delete []dis;


}
int main(){
ll n,e;cin>>n>>e;

int **edge = new int*[n];
for(int i=0;i<n;i++){
    edge[i]=new int[n];
    for(int j=0;j<n;j++){

        edge[i][j]=0;
    }
}
for(ll i=0;i<e;i++){
    ll a,b,c;cin>>a>>b>>c;
    edge[a][b]=c;
    edge[b][a]=c;

}
cout<<endl;
    kruskals(edge,n);
  for(int i=0;i<n;i++){
      delete []edge[i];
    }
    delete [] edge;



}



