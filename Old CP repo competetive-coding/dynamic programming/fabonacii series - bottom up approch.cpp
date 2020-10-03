//recursive in nature
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int a[1000]{-1};
int fabonacci(int n){
    a[0]=0;    		
	a[1]=1;
	for(int i=2;i<=n;i++){
		a[i]=a[i-1]+a[i-2];
		cout<<a[i]<<endl;
	}		
return a[n];

}


int main(){
	memset(a,-1,sizeof(a));

     int k=fabonacci(5);
     cout<<endl<<endl<<endl<<k;
}
