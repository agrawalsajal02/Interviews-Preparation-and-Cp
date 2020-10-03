#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll f(ll mid,ll a[],ll n,ll m){
	ll count=0;
	for(ll i=0;i<n;i++){
		if(a[i]>=mid){
			count=count+a[i]-mid;
		}
	}
	if(count>=m){
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	ll n,m;
	cin>>n>>m;
	ll a[n];
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	
	ll l=0,r=a[n-1];
	while(l<r-1){
		ll mid=(l+(r-l)/2);
		if(f(mid,a,n,m)){
			l=mid;
		}else{
			r=mid-1;
		}
		
		
	}
	if(f(r,a,n,m)){
		cout<<r;
	}else{
		cout<<l;
	}
}
