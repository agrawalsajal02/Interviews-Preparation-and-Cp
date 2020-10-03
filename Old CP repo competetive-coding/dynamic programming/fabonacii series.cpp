#include<iostream>
#include<bits/stdc++.h>
#define in long long int
using namespace std;

in a[100000]{-1};
in fabonacci(in n,vector<in>&v){
	if(n==0||n==1){
		a[n]=n;
		return n;
	}
	if(a[n]!=-1){
		return a[n];
	}
	a[n]=fabonacci(n-1,v)+fabonacci(n-2,v);

	
	return (a[n]);
}


int main(){
	memset(a,-1,sizeof(a));
in a;
cin>>a;
vector<in>v;
     in k=fabonacci(a,v);
     cout<<endl<<endl<<endl<<k;
}
