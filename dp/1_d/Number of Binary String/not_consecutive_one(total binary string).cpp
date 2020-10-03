//https://hack.codingblocks.com/app/practice/1/p/1272
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
ll t;
cin>>t;
while(t--){
	ll n;
	cin>>n;
	if(n==1){
		cout<<"2"<<endl;
	}
	else if(n==2){
		cout<<"3"<<endl;
	}
	else{
		ll *dp=new ll[100]{0};
		dp[0]=0;
		dp[1]=2;
		dp[2]=3;
		for(ll i=3;i<=n;i++){
dp[i]=dp[i-1]+dp[i-2];
	}
cout<<dp[n]<<endl;
	
	
	}
}
	return 0;
}
