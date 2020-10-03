#include<bits/stdc++.h>
using namespace std;
vector<int>v[100];
int level[100];
int parent[100];
bool vis[100];
void bfs(int source,int dest){
queue<int>q;
q.push(source);
vis[source]=true;
parent[source]=-1;
level[source]=0;
while(!q.empty()){

    int temp=q.front();
    q.pop();

    for(int j=0;j<v[temp].size();j++){
        if(vis[v[temp][j]]==false){

            q.push(v[temp][j]);
           parent[v[temp][j]]=temp;
            level[v[temp][j]]=level[temp]+1;
vis[v[temp][j]]=1;
if(v[temp][j]==97){
//    cout<<" here "<<parent[v[temp][j]]<<"  "<<temp<<"  "<<level[v[temp][j]]<<endl;


}
        }

    }




}




}
int main(){
int t;
cin>>t;
for(int i=0;i<t;i++){
    int board[100]={0};
int snake[100]={0};

    int n;
    for(int j=0;j<100;j++){
        vis[j]=false;
        parent[j]=-1;
        level[j]=INT_MAX;

    }
    cin>>n; for(int j=0;j<n;j++){
            int a,b;
    cin>>a>>b;
    a--;
    b--;
    board[a]=b-a;
    }
    cin>>n;
        for(int j=0;j<n;j++){
            int a,b;
    cin>>a>>b;
    a--;
    b--;
    snake[a]=(b-a);
    }
    for(int j=0;j<100;j++){
        for(int dice=1;dice<=6;dice++){
            int u,vs;
            vs=j+dice+board[j+dice]+snake[j+dice];
if(vs<=100&&vs>=0)v[j].push_back(vs);


        }



    }
        bfs(0,99);
//cout<<board[12]<<"b"<<endl;
//cout<<endl<<" final "<<endl;
 /*for(int j=0;j<100;j++){
     cout<<" l "<<level[j]<<" of "<<j<<"  parent " <<parent[j]<<endl;

 }
*/
cout<<level[99]<<endl;
for (auto& v1 : v) {
   v1.clear();
}




}





}
