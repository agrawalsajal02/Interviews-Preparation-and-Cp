#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
	ll t;
	cin>>t;
	ll n=8;
	for(ll i=0;i<t;i++){
		ll r1,c1,r2,c2;
		cin>>r1>>c1>>r2>>c2;
		if(abs(r1-r2)==1||abs(c1-c2)==1){
			if((c1-c2)==0){
			
			if(r1>r2){
				
			ll a=n-r1;
			ll b=n-r2;
			if(a>b){
				cout<<"White"<<endl;
			}
			else{
		cout<<" Black"<<endl;
				
			}	
			}
			else{
				ll m=r2-r1;
				if(m%2==0)cout<<"White"<<endl;
				else{
					cout<<"Black"<<endl;
				}
			}
		}
		else{
		
		if(r1>r2){
			ll a=n-r1;
			ll b=n-r2;
			if(a>b){
				cout<<"White"<<endl;
			}
			else{
		cout<<"Black"<<endl;
				
			}
		}
		else{
		ll f=r2-r1;
		if(f%2==1){
			cout<<"White"<<endl;
			}
		else{
			cout<<"Black"<<endl;
		}	
		}			
			
		}
			
			
		}else{
			ll a=n-r1;
			ll b=n-r2;
			if(a>b){
				cout<<"White"<<endl;
			}
			else{
		cout<<"Black"<<endl;
				
			}
		}
		
	}
		
	}

