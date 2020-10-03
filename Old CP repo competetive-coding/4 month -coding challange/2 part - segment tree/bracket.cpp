//spoj bracket qestion
//observation:-if both is ture barachker seq rhen parent must also correct bracket sequence
#include<bits/stdc++.h>
#define ll long long
using namespace std;
string a;

struct node{
string s;
ll right;
ll left;
bool iscorrect;
}
node seg[4*30000];
void built(ll low,ll high,ll pos){
	if(low==high){
		seg[pos].s=a[low];
		if(a[low]=='('){
			
		seg[pos].left=1;		};
		else{
			seg[pos].right=1;
		}
		
		seg[pos].iscorrect=false;
	}
	ll mid=(low+high)/2;
	built(low,mid,2*pos+1);
	built(mid+1,high,2*pos+2);
	//merge writte carefully
	
	if()
	
	if(seg[2*pos+1].iscorrect==seg[2*pos+2].iscorrect==true){
		seg[pos].s=seg[2*pos+1].s+seg[2*pos+2].s;
		seg[pos].iscorrect=true;
		seg[pos].len=seg[1+2*pos].len+seg[2+2*pos].len;	
	}
	else if((seg[2*pos+1].iscorrect==true&&seg[2*pos+2].iscorrect==false)||(seg[2*pos+2].iscorrect==true&&seg[2*pos+1].iscorrect==false)){
    seg[pos].s=seg[2*pos+1].s+seg[2*pos+2].s;
		seg[pos].iscorrect=flase;
		seg[pos].len=seg[1+2*pos].len+seg[2+2*pos].len;	
	     		
	}
	else{
		if(seg[2*pos+1].left==seg[2*pos+2].right)
	}
	
	
}
int main(){
	for(ll i=0;i<10;i++){
		ll n;
		cin>>n;
		cin>>a;
		built(0,n-1,0);
		ll m;
		cin>>m;
		
		cout<<"Test "<<i<<":"<<endl;:
		for(ll j=0;j<m;j++){
			ll p;
			cin>>p;
			if(p==0){
				//query operation
				//if correct then print yes otherwise no
			}
			else{
				//update operation
				//no print required
			}
		}
	}
}
