//time comp :-o(n*log(logn))
/*

t.c:- n/2+n/3+n/5+n/7.............(inner loop).......
    n(1/2+1/3+1/5+1/7+1/11.................)
    n*log(logn))
    

now n*log(logn) is very small therefore it in order of o{n)  .. aproximate linear time complexicity




*/

/*

1)1 st optimization of seive series

steps:1)marks all odd number as prime;
      2)iterate over only odd numbers

*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void seive(int x){
 
  bool p[x+1]; 
    memset(p,0, sizeof(p)); 
    p[0]=p[1]=0;
    p[2]=1;
    for(int i=3;i<=x;i=i+2){
    	p[i]=1;
	}
	for(int i=3;i<=x;i=i+2){
		if(p[i]==true){
		for(int j=i*i;j<=x;j=j+2i){
			//it is 2 optimization    2*i is even (odd+odd=even)  then j+2i is odd there for only jump at selected odd places only and cancel those in race of becoming prime number
			//for more optimization use j=i*i because betwwin i and i*i , the no that is betwwen them is already cutted by no which is previcious than i
			p[j]=false;
		}
	}
	}
	cout<<endl;
	for(int k=2;k<x;k++){
		if(p[k]){
			cout<<" "<<k<<" ";
		}
		
	}
}
int main(){
	int x;
	cin>>x;
	seive(x);
}
