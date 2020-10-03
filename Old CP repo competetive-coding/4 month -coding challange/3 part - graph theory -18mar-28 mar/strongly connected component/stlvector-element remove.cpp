#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
	vector<ll>v;
	v.push_back(5);
	v.push_back(2);
	v.push_back(3);
	v.push_back(9);
	v.push_back(6);
	v.push_back(7);
	
	vector<ll>::iterator it;
	it=remove(v.begin(),v.end(),3); // retrueen the itrator to the end of vector of newly created vecot(note lement is not removed it is 
	//just thrown in end of container you can cheach this by printing all elements  this emements can take any valye after beign thrwn	)
	for(vector<ll>::iterator iit=v.begin();iit!=it;iit++){
		cout<<*iit<<"  ";
	}cout<<endl;
	for(vector<ll>::iterator ti=v.begin();ti!=v.end();ti++){
		cout<<*ti<<"  ";
	}//note that exta element that is thrown (3) to end of container can become any vale(in this case become 7)
	cout<<endl;
	cout<<" now see "<<endl;
	//now erase
	v.erase(it,v.end());
	for(vector<ll>::iterator ti=v.begin();ti!=v.end();ti++){
		cout<<*ti<<"  ";
	}
	
	
	
	
	
}
