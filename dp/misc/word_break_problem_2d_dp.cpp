#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(i,a,b) for(ll (i)=(a);(i)<(b);(i)++)
map<string,ll>m;
string k;
ll dp[1010][1010];
bool wordb(ll i,ll j){
if(m[k.substr(i,j-i+1)]!=0){
    return 1;
}
if(dp[i][j]!=-1){return dp[i][j];}
bool p=false;
for(ll k=i;k<j;k++){
if(wordb(i,k)==true&&wordb(k+1,j)==true){
    p=true;
}
}
return dp[i][j]=p;
}
int main(){

    ll t;
    cin>>t;
    while(t--){
ll n;
cin>>n;
m.clear();
f(i,0,n){
    string x;
    cin>>x;
    m[x]++;
}
cin>>k;
ll len=k.length()-1;
f(i,0,len+2){
    f(j,0,len+2){
        dp[i][j]=-1;
    }
}
cout<<wordb(0,len)<<endl;







    }


}
