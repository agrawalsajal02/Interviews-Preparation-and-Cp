//nlogn complexicity 
#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
ll binary(ll a[],ll n,ll num){
	ll l=0,r=n-1;
	while(l<=r){
		ll mid=l+(r-l)/2;
		
		if(a[mid]==num){
		return mid;
		}
		if(a[mid]>num){
			r=mid-1;
		}
		else{
			l=mid+1;
		}
		
		
	}
	
	return -1;
}
int main(){
	ll n,k;
	cin>>n>>k;
	ll a[n];
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	ll count=0;
    for(ll i=0;i<n;i++){
    	ll num=(a[i]+k);
    	
    	//finding number through binary search
    	     if(binary(a,n,num)>=0){
    	     	
    	     count++;	
			 }
			 
    	
    	
	}
	cout<<count<<endl;
}
