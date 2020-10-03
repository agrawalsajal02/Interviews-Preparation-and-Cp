//mistakes
// always think of edge case like in this if seg[pos]=5 and 5 block is there theerfore all have 1 value there no need to go in child (0 not allwed)
// motivate- you are crating thee corrt ssegment tree yoiprr;
    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long
    ll seg[16*100000];
    ll v[100000];
     void build(ll low,ll high,ll pos){
    	if(low==high){
    		seg[pos]=v[low];
    		return;
    	}
    	ll mid=low+(high-low)/2;
    	build(low,mid,2*pos+1);
    	build(mid+1,high,2*pos+2);
    	seg[pos]=(seg[2*pos+1])+(seg[2*pos+2]);
    	
    	
    	}
     ll queries(ll low,ll high,ll x,ll y,ll pos){
     
    	ll result ;
    result=0;
    if(low>=x&&high<=y){
    		return seg[pos];
    	}
    	else if(y<low||x>high){
    		return result;
    	}
    	ll mid=low+(high-low)/2;
    	if(mid>=high){
    	
    	ll left=queries(low,mid,x,y,2*pos+1);
    	result=(left);
    	return result;	
		}
		else if(mid<low){
		
		ll right=queries(mid+1,high,x,y,2*pos+2);
    	result=(right);
    	return result;
		}
		else{
			
    	ll left=queries(low,mid,x,y,2*pos+1);
    	ll right=queries(mid+1,high,x,y,2*pos+2);
    	result=(left+right);
    	return result;
		}
    }
    
    void update(ll low,ll high,ll pos,ll x,ll y){
    	if(seg[pos]==high-low+1){
    		return;
		}
		
    	if(low==high&&low>=x&&high<=y){
    		seg[pos]=sqrt(seg[pos]);
    		
    		return;
		}
		if(low>y||high<x){
			return;
		}
		ll mid=(low+high)/2;
		if(mid>=y){
		update(low,mid,2*pos+1,x,y);
	
		}
		else if(x>mid){
			
		update(mid+1,high,2*pos+2,x,y);
		}
		else{
	update(low,mid,2*pos+1,x,y);
		  		 update(mid+1,high,2*pos+2,x,y);
		}   
    	seg[pos]=(seg[2*pos+1])+(seg[2*pos+2]);
    	  	
}
     int main(){
     	    ll p=1;
    ll n,m;
	 while (scanf("%lld",&n) != EOF){		
		for(ll i=0;i<n;i++){
    	scanf("%lld",&v[i]);
    	}
    	build(0,n-1,0);
    	printf("Case #%lld:\n",p);		
	scanf("%lld",&m);
    	for(ll j=0;j<m;j++){
    	ll k;ll x,y;
scanf("%lld",&k);
			   		scanf("%lld",&x);
    		scanf("%lld",&y);			            
			if (x > y) {
                swap(x, y);}
    	if(k==0){
    		x--;y--;
    	update(0,n-1,0,x,y);
		
		}else if(k==1){
		x--;y--;
    		//queries
    		cout<<queries(0,n-1,x,y,0)<<endl;
    			
			
		}
    	}p++;
    	cout<<endl;
    }
    
    }
