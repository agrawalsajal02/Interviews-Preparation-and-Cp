// for theory refer notebook pages for proof and better understanding
// base case value of x=1,y=0 always , gcd is always a; 

#include<iostream>
using namespace std;
#define ll long long int
ll gcd(ll a,ll b){
	if(b==0){
		return a;
	}
	return (gcd(b,a%b));
}
ll x,y,gcdd;
void extendedEuclidMethod(ll a,ll b){
	//base case
	if(b==0){
		x=1;
		y=0;
		gcdd=a;
		return;
	}
	//recursive case
	extendedEuclidMethod(b,a%b);
	ll cx=y;
	ll cy=x-(a/b)*y;
	x=cx;
	y=cy;
	
	cout<<cx<<","<<cy<<endl;
	
	/*can do this also
	ll z=y;
	y=x-(a/b)y;
	x=z;
	*/
	
	
	
}

int main(){
	cout<<gcd(5,4);
	cout<<" bcd extended algo "<<endl;
	//18x+30y=6 // we want to see this solm
	
	extendedEuclidMethod(18,30);
	cout<<" x "<<x<<" y "<<y<<endl;
}
