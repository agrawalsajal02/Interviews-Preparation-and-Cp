//time comp :-o(n*log(logn))
/*

t.c:- n/2+n/3+n/5+n/7.............(inner loop).......
    n(1/2+1/3+1/5+1/7+1/11.................)
    n*log(logn))
    

now n*log(logn) is very small therefore it in order of o{n)  .. aproximate linear time complexicity




*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void seive(int x){
 
  bool p[x+1]; 
    memset(p, true, sizeof(p)); 
	for(int i=2;i*i<=x;i++){
		if(p[i]==true){
	
		for(int j=2*i;j<=x;j=j+i){
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
