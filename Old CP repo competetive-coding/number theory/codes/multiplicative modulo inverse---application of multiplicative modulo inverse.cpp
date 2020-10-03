// for theory refer notebook pages for proof and better understanding
// inverse modulo only exits wwhen gcd of a&m is 1, gcd(a,b)=1  in (a*b)%m=1, where  is multiplicative modulo inverse
//remember b(inverse modlo of a) is live between moving 1 .... [m-1]      
#include<iostream>
using namespace std;
#define ll long long int
ll gcd(ll a,ll b){
	if(b==0){
		           return a;}
	return (gcd(b,a%b));}
ll x,y,gcdd;
void extendedEuclidMethod(ll a,ll b){
     //base case
	if(b==0){
		x=1;
		y=0;
		gcdd=a;
		return; 
	}//recursive case
	extendedEuclidMethod(b,a%b);
	ll cx=y;
	ll cy=x-(a/b)*y;
	x=cx;
	y=cy;
//cout<<cx<<","<<cy<<endl;
	/*can do this also
	ll z=y;
	y=x-(a/b)y;
	x=z;*/}
ll Multiplicative_Modulo_inverse(ll a,int m){
	if(gcd(a,m)!=1){
		cout<<" Multiplicative-Modulo_inverse NOT possible "<<endl;
		return NULL;   }
	extendedEuclidMethod(a,m);
	//why return x+m)%m because only return x can make the ans negative , but we want only positive ans , remember we always addd m then %m to change the value to positive 
	return ((x+m)%m);
}
int main(){
	/*cout<<gcd(5,4);
	cout<<" bcd extended algo "<<endl;
	//18x+30y=6 // we want to see this solm
		extendedEuclidMethod(18,30);
	cout<<" x "<<x<<" y "<<y<<endl;*/
	// (a8b)%m=1
	// gcd( a,m)==1(always)(condition to multiplicative to be exit;
	//remember    b(inverse modlo of a) is live between moving 1 .... [m-1]      
	cout<<Multiplicative_Modulo_inverse(6,7)<<endl;  // with return x it gain negative value as -1
	cout<<Multiplicative_Modulo_inverse(8,7)<<endl;
	cout<<Multiplicative_Modulo_inverse(18,7);
}
