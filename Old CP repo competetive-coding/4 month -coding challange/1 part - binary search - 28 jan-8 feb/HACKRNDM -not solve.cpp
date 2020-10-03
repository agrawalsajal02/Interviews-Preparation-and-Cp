#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ll n,k;
	cin>>n>>k;
	ll a[n];
	vector<ll>v;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	
	ll count=1;
	ll pos=a[0];
	v.push_back(a[0]);
	for(ll i=1;i<n;i++){
	for(ll j=0;j<v.size();j++){
		if(a[i]-v[j]==k){
			count++;
			v.push_back(a[i]);
			break;
		}
		
	}	
	}
	
	if(count==1){
		cout<<"0";
	}else{
	cout<<count<<endl;	
	}
	
}
