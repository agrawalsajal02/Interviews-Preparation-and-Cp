//verti https://www.youtube.com/watch?v=mXExj8SAQKs
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll findMinVetix(int *weight,bool *  visited , int n){
int minVertix = -1;
for(ll i=0;i<n;i++){
    if(((weight[i]<weight[minVertix])||minVertix==-1)&&(!visited[i])){
        minVertix= i;
    }}
return minVertix;}

void prims(int **edge,int n){

bool *visit=new bool[n];
int *weight= new int[n];
int *parent = new int[n];
for(ll i=0;i<n;i++){
    visit[i]=false;
    weight[i]=INT_MAX;  //int max definees in climit header file
}
parent[0]=-1;
weight[0]=0;
//out of all the available vertices pick the one which have minimum vertices and uske coreesponding uske neighbour ko visit karenge , explero karenge , jo unvisited hr
for(ll i=0;i<n;i++){//ir take i<n-1 bcoxlast verti neigh already visited
    int minVerti = findMinVetix(weight,visit,n);//t find minimum vertix
//also minVerti is visited also
visit[minVerti]=true;
for(ll j=0;j<n;j++){
    if(edge[minVerti][j]!=0&&!visit[j]){
        //explore its neighbou
        //expolre means is the min vertix edge is a better opion
        // if yes then take it
       if(edge[minVerti][j]<weight[j]){
        weight[j]=edge[minVerti][j];
        parent[j]=minVerti;
       }


    }


}


}
//NOW ITS TIME TO EEXPORE ITS UNVISITED NEIGH BOOUR
for(ll i=1;i<n;i++){
    if(parent[i]<i){
        cout<< parent[i]<<"  "<<i<<" "<<weight[i]<<endl;
    }
    else{
     cout<<"  "<<i<<"  "<< parent[i]<<" "<<weight[i]<<endl;

    }


}




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
    cout<<endl;
}
    prims(edge,n);
    for(int i=0;i<n;i++){
      delete []edge[i];
    }
    delete [] edge;



}



