#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(i,a,b) for(ll (i)=(a);(i)<(b);(i)++)
#define mod 1003
ll dp[110][110][2];
ll find(string s,ll i,ll j,bool p){
if(i>j){
  p=1;
  return 0;
}
if(i==j){
  if(p==true){
    return s[i]=='T';
  }
  else{
    return s[i]=='F';
  }
  }
  if(dp[i][j][p]!=-1){
return dp[i][j][p];
  }
ll fl=0;  
for(int k=i+1; k<j; k=k+2) {
if(s[k]=='|'){
if(p==true){ 
int ways=(find(s,i,k-1,1)*find(s,k+1,j,0))+(find(s,i,k-1,0)*find(s,k+1,j,1))+(find(s,i,k-1,1)*find(s,k+1,j,1));
fl+=ways%mod;
fl=fl%mod;
}
else{
int ways=(find(s,i,k-1,0)*find(s,k+1,j,0));
fl+=ways%mod;
fl=fl%mod;
}
}
else if(s[k]=='&'){
if(p==true){
int ways=(find(s,i,k-1,1)*find(s,k+1,j,1));
fl+=ways%mod;
fl=fl%mod;
}
else{
int ways=(find(s,i,k-1,0)*find(s,k+1,j,0)+find(s,i,k-1,0)*find(s,k+1,j,1)+find(s,i,k-1,1)*find(s,k+1,j,0));
fl+=ways%mod;
fl=fl%mod;  
}
}
else if(s[k]=='^'){
  if(p==true){
int ways=(find(s,i,k-1,1)*find(s,k+1,j,0))+(find(s,i,k-1,0)*find(s,k+1,j,1));
fl+=ways%mod;
fl=fl%mod;
}
else{
int ways=(find(s,i,k-1,1)*find(s,k+1,j,1))+(find(s,i,k-1,0)*find(s,k+1,j,0));
fl+=ways%mod;
fl=fl%mod;

}
}
}
return dp[i][j][p]=fl;
}
int main(){
    ll t;
    cin>>t;
    while(t--){
ll n;
cin>>n;
string s;
cin>>s;
bool p=true;

f(i,0,n+1){
f(j,0,n+1){
  dp[i][j][0]=-1;
  dp[i][j][1]=-1;
}
}
cout<<find(s,0,n-1,p)<<endl;







    }



}
