	#include<bits/stdc++.h>
	using namespace std;
	#define ll long long int
	int main(){
		
		ll n;
		cin>>n;
		ll a[n],b[n];
		for(ll i=0;i<n;i++){
			cin>>a[i];
			b[i]=a[i];
		}ll i;ll m=0;
		sort(b,b+n,greater<ll>());
				for(i=n-1;i>=0;i--){
		
			if(a[i]==b[m]){
				m++;
			}
		}
		
		cout<<n-m<<endl;
		
	
	}
