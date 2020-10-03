#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
ll n;cin>>n;
ll count=0;
string s;
cin>>s;
ll c1=0,c2=0,c3=0;
ll a[3][3];

for(ll i=0;i<3;i++){
	for(ll j=0;j<3;j++){
a[i][j]=0;	
	}}

for(ll i=0;i<3;i++){
	for(ll j=0;j<3;j++){
		ll count=0;
		for(ll k=j;k<n;k=k+3){
		  if(i==0){
		  	if(s[k]=='R'){	 cout<<" here "<<i<<" "<<j<<" "<<k<<endl; count++; continue;}
		  	
		  }
		  else if(i==1){
		  	if(s[k]=='G'){count++;continue;}
		  	
		  }
		  else if(i==2){
		  	if(s[k]=='B'){count++;continue;}
		  	
		  }
		    
		}
		a[i][j]=count;
	}
}
ll total=0;
string k="RGB";
for(ll i=0;i<3;i++){
for(ll j=0;j<3;j++){
cout<<a[i][j]<<" ";
}cout<<endl;}

ll f=-1;
for(ll i=0;i<3;i++){
	ll j=0,max=a[i][0],index=0;
	for(j=0;j<3;j++){
if(a[i][j]>max){
	
max=a[i][j];if(f!=index)index=j;}
}

ll cc=0;
f=index;
cout<<"  index "<<index<<endl; 
for(j=index;j<n;j=j+3){
	if(s[j]!=k[i]){
		cc++;
		s[j]=k[i];
	}

}

total=total+cc;
}





cout<<total<<" "<<s<<endl;
}
