// it is using recursion
#include<iostream>
#define ll long long int
#define MAX 1000000007
using namespace std;
ll fastmodexp(ll x,ll y){
	if(y==0){
		return 1;
	}
	ll r=(fastmodexp(x,y/2)%MAX);
	if(y%2==0){
		return ((r*r)%MAX);
	}
	else{
		return ((r*x*r)%MAX);
	}
}
int main(){
	ll x,y;
	cin>>x>>y;
	cout<<" tha ans of x exp y modulo M(10^9+7) "<<endl<<endl;
	cout<<fastmodexp(x,y);
}
