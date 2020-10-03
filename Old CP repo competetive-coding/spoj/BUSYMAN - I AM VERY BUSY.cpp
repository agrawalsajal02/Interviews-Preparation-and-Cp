//select the next event which ends as early as possible(which you done by doing shorting)
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
	ll t;
		ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin>>t;
	for(ll i=0;i<t;i++){
		vector< pair<ll,ll> >v;
		ll n;cin>>n;
		for(ll j=0;j<n;j++){
			ll a,b;cin>>a>>b;
			v.push_back({a,b});
			
		}
		sort(v.begin(),v.end());
		ll count=1;
		ll pos1=v[0].first;
		ll pos2=v[0].second;
		for(ll j=1;j<n;j++){
		
			if(pos1==v[j].first&&pos2<=v[j].second){
				continue;
			}
			if(pos1<v[j].first&&pos2<=v[j].second&&v[j].first<pos2){
				continue;
			}
			
			if(pos1<v[j].first&&pos2>v[j].second){
				pos1=v[j].first;
				pos2=v[j].second;
			
				continue;
			}
			if(pos2<=v[j].first){
				count++;
				pos1=v[j].first;
				pos2=v[j].second;
				
			}
			
			
		}
		cout<<count<<endl;
		
		
	}
	
}
