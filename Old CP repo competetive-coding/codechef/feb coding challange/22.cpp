/*          don't look at my code
            make your own code

            by: SAJAL AGRAWAL
                                    ----XBAR

*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
using namespace std;
ll b[1000000];
int main(){
	for(ll i=0;i<10000;i++){
		b[i]=0;
	}
ll t;
cin>>t;
for(ll i=0;i<t;i++){
	char s[1000000];
	cin>>s;
	ll a[26];
	for(ll j=0;j<26;j++){
		a[j]=0;
	}
	for(ll j=0;j<strlen(s);j++){
		if(s[j]<65||s[j]>90){
			break;
		}
		ll x=s[j];
		x=x-65;
		a[x]++;
		
		
	}
	map<ll,ll>m;
	map<ll,ll>::iterator it;
	
	map<ll,ll>::iterator itt;
	
		for(ll j=0;j<26;j++){
		if(a[j]==0)continue;
		m[a[j]]++;
	}
	ll max=0;
	ll ans=0;
	for(it=m.begin();it!=m.end();it++){
		if(max<=it->first*it->second&&ans<=it->first){
			ans=it->first;
			max=it->first*it->second;
		}
	}
	cout<<"here   "<<ans<<"  "<<max<<"  "<<endl;
	
	ll count=0;
	ll random=0;
	for(it=m.begin();it!=m.end();it++){
		if(it->first!=ans){
				ll value=it->first*it->second;
				ll mod=value%ans;
				value=value/ans;
				ll total=value-
				
				
				
				
				/*
				
				for(itt=m.begin();itt!=m.end();itt++){
				if(itt->first+it->first==ans){
					
					
					
					
					
					if(it->second<=itt->second){
						count=count+it->first*it->second;
						ll cc=itt->second-itt->second;
						count=count+cc*itt->first;
						
	map<ll,ll>::iterator app;
	
						app=m.find(itt->first);
                         m.erase(app);
						
											}
				}
				
				}
				

			
			
				}
	}
	cout<<count<<endl;
	
	
}





}






