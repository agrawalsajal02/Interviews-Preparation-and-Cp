// it is wih the hrlp of binary
//it is a itterative approch and better because it uses no extra space
//refer the notes in notebook for more
//time complexicity o(n)
#include<iostream>
using namespace std;
#define ll long long int
#define M 1000000009
int fastmodexp(int a,int b){
	ll res=1;
	while(b>0){
		 if (b & 1)
		res=(res*a)%M;
		a=(a*a)%M;
		b=b>>1;
	}
	return res;
}

int main(){
		ll x,y;
	cin>>x>>y;
	cout<<" tha ans of x exp y modulo M(10^9+7) "<<endl<<endl;
	cout<<fastmodexp(x,y);
}
