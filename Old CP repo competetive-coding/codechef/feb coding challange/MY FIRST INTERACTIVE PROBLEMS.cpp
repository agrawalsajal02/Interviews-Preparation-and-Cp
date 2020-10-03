#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ma=1000000000;
int main(){
	ll t;
	cin>>t;
	for(ll i=0;i<t;i++){
	cout<<"Q "<<"0"<<" "<<"0"<<endl;
	ll n,n2;
	cout<<flush;
	cin>>n;
	if(n<0)return 0;
	ll x1,x2,y1,y2;
	x1=0;
	x2=n;
	y1=n;
	y2=0;ll flag=0;
		ll mid1=0,mid2=0;
	while(x2-x1>1&&y1-y2>1){
		if((x2-x1)%2==0&&(y1-y2)%2==0){
			mid1=(x1+x2)/2;
mid2=(y2+y1)/2;
		
		}else{
			mid1=(x1+x2)/2;
			mid2=(y2+y1)/2+1;
			
		} cout<<"Q "<<mid1<<" "<<mid2<<endl;
			cout<<flush;
			cin>>n;
      if(n==0){
		x1=mid1;
		x2=mid1;
		y1=mid2;
		y2=mid2;
		
		
		break;
	}	
	if(n<0)return 0;
	
	 cout<<"Q "<<mid1-1<<" "<<mid2+1<<endl;
cout<<flush;			cin>>n2;if(n2<0)return 0;
    if(n2==0){
		x1=mid1-1;
		y1=mid2+1;
		mid1=mid1-1;
    	mid2=mid2+1;
    	break;
	}
	if(n2>n){
    	
		x1=mid1+1;
    	y1=mid2-1;
    	continue;
    	
	}
	else{
		x2=mid1-1;
		y2=mid2+1;
	}

	}
	
cout<<"Q "<<x1<<" "<<y1<<endl;
cin>>n;
if(n==0){
		mid1=x1;
		mid2=y1;
	}
else{
	
cout<<"Q "<<x2<<" "<<y2<<endl;
cin>>n2;
mid1=x2;
		mid2=y2;
}	
	
	ll pre1=mid1;
	ll pre2=mid2;
	ll as1,as2;
	//we have x1,y1
	x1=mid1;
	y1=mid2,y2=mid2;
	x2=ma;
	while(x2-x1>1){
		mid1=(x1+x2)/2;
		cout<<"Q "<<mid1<<" "<<y2<<endl;cout<<flush;
		cin>>n;
		if(n<0)return 0;
		if(n==0){
			x1=mid1;
		}
		else{
			x2=mid1-1;
		}
	}
	cout<<"Q "<<x2<<" "<<y2<<endl; cout<<flush;
	cin>>n;
	if(n<0)return 0;
	if(n==0){
		as1=x2;
		//right wala
	}else{
		as1=x1;
		//leftwala
	}	
	
	x1=pre1;
	y1=pre2;
	
		y2=ma;
	x2=x1;
	while(y2-y1>1){
		ll mid1=(y1+y2)/2;
		cout<<"Q "<<x1<<" "<<mid1<<endl;cout<<flush;
		cin>>n;if(n<0)return 0;
		if(n==0){
			y1=mid1;
		}
		else{
			y2=mid1-1;
		}
	}
	cout<<"Q "<<x2<<" "<<y2<<endl;cout<<flush;
	cin>>n;if(n<0)return 0;
	if(n==0){
		as2=y2;
		//right wala
	}else{
		as2=y1;
		//leftwala
	}
	cout<<"A "<<pre1<<" "<<pre2<<" "<<as1<<" "<<as2<<endl;
	cout<<flush;
	cin>>n;if(n<0)return 0;
	
	
	
	
}
}
