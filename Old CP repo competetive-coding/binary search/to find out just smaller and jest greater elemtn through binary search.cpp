//to find outjust less than and just greater value if the correct value isnot found
//dublicate and triplicateis possible

#define ll long long int
#include<iostream>
using namespace std;
int main(){
	ll a[]={4,8,32,32,32,32,32,60};
	ll n=8;//must be in sorted order
	ll key;
	cout<<" enter the key want to find its first occurance "<<endl;
	cin>>key;
	ll l,r;
	l=0,r=7;
	ll result=-1;   //to store the result  in temp varialble
	while(l<r){
		ll mid=l+(r-l)/2;
		
		if(a[mid]==key){
			cout<<" found - mid :"<<mid<<endl;
			result=mid;//if found then it can be the not the first occurance therefore we shift in r=mid-1 side
			break;
		}
		else if(a[mid]>key){
			r=mid-1;
		}
		else{
			l=mid+1;
		}
		
		
	}
	cout<<l<<"  "<<r<<endl;
	
	
	cout<<"  last occurance "<<endl;
	 key;
	cout<<" enter the key want to find its first occurance "<<endl;
	cin>>key;
	l=0,r=7;
	result=-1;   //to store the result  in temp varialble
	while(l<=r){
		ll mid=l+(r-l)/2;
		
		if(a[mid]==key){
			cout<<" found - mid :"<<mid<<endl;
			l=mid+1;
			result=mid;//if found then it can be the not the first occurance therefore we shift in r=mid-1 side
			
		}
		else if(a[mid]>key){
			r=mid-1;
		}
		else{
			l=mid+1;
		}
		
		
	}
	cout<<result<<endl;
	
	
	
}

