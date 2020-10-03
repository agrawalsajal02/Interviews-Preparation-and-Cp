#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 ll c[20][20];
bool b[20][20];
ll co=0;
void dfs(ll x,ll y,ll n,ll m){
  if(c[x][y]==1)return;
  if(x==n||y==m)return;
  b[x][y]=true;
  co++;

  if(1){
  if((x-1>=0)&&(b[x-1][y]==false)&&(c[x-1][y]==2)){
    dfs(x-1,y,n,m);
  }}
  if(1){
  if((y-1>=0)&&(b[x][y-1]==false)&&(c[x][y-1]==2)){
    dfs(x,y-1,n,m);}}
 if(1){
  if((y+1<m)&&(b[x][y+1]==false)&&(c[x][y+1]==2)){
          dfs(x,y+1,n,m);
          }}
          if(1){

  if(x+1<n&&(b[x+1][y]==false)&&(c[x+1][y]==2)){
          dfs(x+1,y,n,m);
          }
          }

}


int main(){
ll t;
cin>>t;
for(ll i=0;i<t;i++){
        co=0;
    ll n,m;cin>>m>>n;
     ll p1,p2;

        for(ll j=0;j<20;j++){
        for(ll k=0;k<20;k++){
            b[j][k]=0;
c[j][k]=2;
        }
        }
fflush(stdin);
    for(ll j=0;j<n;j++){
    for(ll k=0;k<m;k++){
        char f;
        cin>>f;
        if(f=='#'){

            c[j][k]=1;
           continue;
        }

        if(f=='@'){
            p1=j;
            p2=k;
        }
    }}
fflush(stdin);
    dfs(p1,p2,n,m);
cout<<"Case "<<i+1<<":"<<co<<endl;


    }



}
