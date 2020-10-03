//here n represent  , no of ways to reach at a perticular step
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//time complexicity of recursion o(3 pow n):-very large
int fac(int n){
	if(n==0){    // standing on ground only one way
		return 1;
	}
	if(n<0){  // underground se aane ka koi matlab nahi he
		return 0;
	}
	return (fac(n-1)+fac(n-2)+fac(n-3));
}


int topdowndp(int n,int *dp){
	if(n==0){    // standing on ground only one way
		dp[n]=1;
		return 1;
	}
	if(n<0){  // underground se aane ka koi matlab nahi he
		return 0;
	}
	if(dp[n]!=-1){
		return dp[n];
	}
	dp[n]=topdowndp(n-1,dp)+topdowndp(n-2,dp)+topdowndp(n-3,dp);
	return (dp[n]);
	
}
// it is another recursive approch ,it can be converted into bottom up dp
int ways(int n,int k){
	
	if(n==0){
		return 1;
	}
	if(n<0){
		return 0;
	}
	int ans=0;
	for(int i=1;i<=k;i++){
		ans=ans+ways(n-i,k);
	}
	return ans;
}
//time comp:- o(kn)
int waysbotmup(int n,int k){
	int *dp=new int[n];
	dp[0]=1;
	for(int step=1;step<=n;step++){
		dp[step]=0;
		for(int j=1;j<=k;j++){
			if(step-j>=0){
				dp[step]=dp[step]+dp[step-j];   // we have to check d[step-j] is goig negative r not
			}
		}
		}
		return dp[n];
	}
//more optimized o(n)
/*
int waysbotmup(int n,int k){
	int *dp=new int[n];
	dp[0]=1;
	for(int step=1;step<=n;step++){
		dp[step]=0;
			if(step-j>=0){
				dp[step]=2dp[step-1]-dp[step-j-1];   // we have to check d[step-j] is goig negative r not
			}
		}
		}
		return dp[n];
	}

*/
int main(){
	int n;
	cin>>n;
	int dp[1000];

memset(dp,-1,sizeof(dp));

cout<<topdowndp(n,dp); //check for n=4	
cout<<endl<<endl;
//cout<<ways(5,3);
cout<<waysbotmup(7,3);
//cout<<fac(n);

}
