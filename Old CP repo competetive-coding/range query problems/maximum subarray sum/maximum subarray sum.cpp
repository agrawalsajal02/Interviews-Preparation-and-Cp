#include<iostream>
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll calc(ll a[],ll n){
	if(n==1){
		return a[0];
	}
	ll m=n/2;
	ll leftp=calc(a,m);
	ll rightp=calc(a+m,n-m);
	ll sum=0,bestpossblesumleft=INT_MIN,bestpossblesumright=INT_MIN;
	for(ll i=m;i<n;i++){
		sum+=a[i];
		bestpossblesumright=max(sum,bestpossblesumright);
	}	
sum=0;	
	for(ll i=m-1;i>=0;i--){
		sum+=a[i];
		bestpossblesumleft=max(sum,bestpossblesumleft);
	}	
	ll ans=max(leftp,rightp);
	return (max(ans,bestpossblesumright+bestpossblesumleft));
	
	
}
int main(){
	ll n;
	cin>>n;
	ll a[n];
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<calc(a,n);
}
