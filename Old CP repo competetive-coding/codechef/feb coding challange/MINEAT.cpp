#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll f(ll mid,ll n,ll a[],ll m){
	ll i,count=0;
	for(ll i=0;i<n;i++){
		if(a[i]<=mid){
			count++;
			continue;
		}
		else{
		 if(a[i]%mid==0){
		 	count=count+a[i]/count;
		 }
		 else{
		 	count=count+(a[i]+mid)/mid;
		 }
		}
	}
	if(count<=m){
		return true;
	}
	else{
		return false;
	}
}
int main(){
	ll t;
	cin>>t;
	for(ll x=0;x<t;x++){
		ll n,m;
		cin>>n>>m;
	
		ll a[n];
		for(ll i=0;i<n;i++){
			cin>>a[i];
		}		
		
		sort(a,a+n);
		
		
		ll l=0,r=a[n-1];
		
		
		while(r-l>1){
			mid=l+(r-l)/2;
			if(f(mid,n,a,m)){
				r=mid;
			}
			else{
				l=mid+1;
			}
			
			
		}
		if(f(l,n,a,m)){
			cout<<l<<endl;
		}
		else{
			cout<<r<<endl;
		}
		
		
		
		
		
	}
}
