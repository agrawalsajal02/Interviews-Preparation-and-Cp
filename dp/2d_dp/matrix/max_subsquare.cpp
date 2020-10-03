#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(i,a,b) for(ll (i)=(a);(i)<(b);(i)++)
int main(){
    ll t=1;
    //cin>>t;
    while(t--){
ll n,m;
cin>>n>>m;
ll a[n][m];
ll dp[n][m];
ll fl=0;
f(i,0,n){
  f(j,0,m){
    cin>>a[i][j];
dp[i][j]=a[i][j];
if(a[i][j]==1){
  fl=1;
  }
}
}

ll ma;
if(fl==1){
  ma=1;
}
else{
  ma=0;
}

f(i,1,n){
  f(j,1,m){
    if(a[i][j]==0){
        dp[i][j]=0;
      continue;
    }
ll val=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
dp[i][j]=val+1;
       ma=max(dp[i][j],ma);

  }
}
f(i,0,n){
  f(j,0,m){
 //cout<<dp[i][j]<<" ";
  }///cout<<endl;
}
cout<<ma<<endl;


    }


}
