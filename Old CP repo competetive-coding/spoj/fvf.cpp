
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
using namespace std;
int main(){
	ll t;
	cin>>t;
	for(ll a=0;a<t;a++){

ll r,c,k;
cin>>r>>c>>k;ll count1=0,count2=0;
ll i;
for(i=r;i>0;i--){
	if(count1>=k){
		break;
	}
	count1++;
}
if(i<=0)i++;
ll j;
for(j=c;j>0;j--){
	if(count2>=k){
		break;
	}
	
	count2++;
}if(j<=0)j++;
ll got=0;
for(ll p=i;p<=r+k;p++){
for(ll m=j;m<=c+k;m++){
   if(p>8||m>8){
   	continue;
   }

got++;

}
}
cout<<got<<endl;
	}

}






