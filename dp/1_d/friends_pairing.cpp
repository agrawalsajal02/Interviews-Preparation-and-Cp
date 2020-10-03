#include<iostream>
using namespace std;
#define ll long long
int main() {
ll t;
cin>>t;
while(t--){
    ll n;
    cin>>n;
    ll dp[n+2];
    for(ll i=0;i<=n+1;i++){
        dp[i]=0;
    }
    dp[0]=1;
    for(ll i=1;i<=n;i++){
        dp[i]=dp[i-1]+(i-1)*dp[i-2];
    //cout<<dp[i]<<" ";
    }

    
    cout<<dp[n]<<endl;
}



}
