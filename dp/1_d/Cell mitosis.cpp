#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(i,a,b) for(ll (i)=(a);(i)<(b);(i)++)
int main(){
ll n;
cin>>n;
ll x,y,z;
cin>>x>>y>>z;
ll dp[n+1];

f(i,0,n+1){
  dp[i]=0;
}
dp[1]=0;

f(i,2,n+1){
if(i%2==1){
  dp[i]=min(dp[i-1]+y,dp[(i+1)/2]+x+z);
}
else{
  dp[i]=min(dp[i-1]+y,dp[i/2]+x);
}
}
cout<<dp[n]<<endl;

}
