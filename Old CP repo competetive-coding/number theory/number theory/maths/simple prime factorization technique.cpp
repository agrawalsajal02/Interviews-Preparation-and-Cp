//time complexicity :- o(sqrt(n))  and for 1 to n  :- to find out prime no b/t 1 to n is o(n*sqrt(n))
#include<iostream>
using namespace std;
bool prime(int x){
	for(int i=2;i*i<=x;i++){
		if(x%i==0){
			return false;
		}
	}
	return true;
	
	
}
int main(){
	int x;
	cin>>x;
	if(prime(x)){
		cout<<" it is prime";
	}
	else{
		cout<<" it is not prime";
	}
}
