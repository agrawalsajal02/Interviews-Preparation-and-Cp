//very hard to make program !!!takes days to build it;
// with updates query on point

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
	struct node{
	ll preval,prefre,suffval,suffre,maxv,all;

};
node tree[16*50010];
ll a[50010];
void merge(node &file,node &cl,node &cr)                                                          
{ 

	  if(cl.all==1&&cr.all==1&&cl.preval==cr.suffval){
	  file.all=1;
	  }
	  else{
	  	file.all=0;
	  }
    file.preval=cl.preval;


    if(cl.all==1&&cl.prefre==cl.maxv&&cr.preval==cl.preval){
file.prefre=cl.maxv+cr.prefre;

    }
    else if((cl.all==1&&cl.prefre==cl.maxv&&cr.preval!=cl.preval)){
file.prefre=cl.maxv;       
    }
    else{
    	file.prefre=cl.prefre;
    }
file.suffval=cr.suffval;



if(cr.all==1&&cr.suffre==cr.maxv&&cr.suffval==cl.suffval){
file.suffre=cr.maxv+cl.suffre;
    }
    else if((cr.all==1&&cr.suffre==cr.maxv&&cr.suffval!=cl.suffval)){
file.suffre=cr.maxv;       
    
	}
    else{
    
    	file.suffre=cr.suffre;   }
  
  
  
   if(cl.suffre==cl.maxv&&cl.suffval==cr.preval){
   	
   	file.maxv=cl.maxv+cr.prefre;
   }
   else if(cr.prefre==cr.maxv&&cl.suffval==cr.preval){
   	
	   file.maxv=cr.maxv+cl.suffre;
   }
   else{
   	
       file.maxv=max(cl.maxv,cr.maxv);


   }



   


//ll p=0;

}

void builttree(ll start,ll end,ll pos){
	if(start==end){
	
		tree[pos].prefre=1;
		tree[pos].preval=a[start];
		tree[pos].suffre=1;
		tree[pos].suffval=a[start];
	tree[pos].all=1;
	tree[pos].maxv=1;
/*	
	cout<<p<<": max: "<<tree[pos].maxv<<"  "<<"pval: "<<tree[pos].preval<<"  "<<"pfre:"<<tree[pos].prefre<<"  "<<"sufv: "<<tree[pos].suffval<<"  "<<" suffre: "<<tree[pos].suffre<<"   all: "<<tree[pos].all;
		cout<<" value "<<a[start]<<endl;*/
	}
	else{
	
	ll mid=(start+end)/2;
	builttree(start,mid,2*pos+1);
	builttree(mid+1,end,2*pos+2);
	//cout<<tree[pos]<<tree[2*pos+1]<<tree[2*pos+2]<<endl;
	//cout<<"  pos "<<pos<<"  start "<<start<<"  end  "<<end<<"  "<<"  treevalue "<<tree[pos]<<endl;
	
	merge(tree[pos],tree[2*pos+1],tree[2*pos+2]);
	
	
	/*
	p++;
	
	
	cout<<p<<" max: "<<tree[pos].maxv<<"  "<<"pval: "<<tree[pos].preval<<"  "<<"pfre:"<<tree[pos].prefre<<"  "<<"sufv: "<<tree[pos].suffval<<"  "<<" suffre: "<<tree[pos].suffre<<"   all: "<<tree[pos].all<<endl;
	cout<<endl;
	cout<<" pos "<<pos<<"  a: "<<2*pos+1<<"  b:  "<<2*pos+2<<endl;
/*	if(pos==6){
		cout<<" all :"<<tree[pos].all<<"  "<<endl;
		cout<<"  "<<tree[2*pos+1].all<<"  "<<tree[2*pos+2].all<<"  "<<tree[2*pos+1].preval<<"  "<<tree[2*pos+2].preval<<" "<<tree[2*pos+1].suffval<<" "<<tree[2*pos+1].preval<<endl;
	
	//cl.all==1&&cr.all==1&&cl.preval==cr.preval&&cl.suffval==cr.suffre
}*/
	/*  uses merge function to solve in one line
	tree[pos].maxpre=max(tree[2*pos+1].maxpre,tree[2*pos+1].tsum+tree[2*pos+2].maxpre);
	tree[pos].maxsuff=max(tree[2*pos+2].maxsuff,tree[2*pos+2].tsum+tree[2*pos+1].maxsuff);
	tree[pos].tsum=tree[2*pos+1].tsum+tree[2*pos+2].tsum;
//	tree[pos].mms=max(tree[pos].maxpre,max(tree[pos].maxsuff,max(tree[2*pos+1].maxsuff+tree[2*pos+2].maxpre,max(tree[2*pos+1].mms,tree[2*pos+2].mms))));
	tree[pos].mms=max(tree[2*pos+1].maxsuff+tree[2*pos+2].maxpre,max(tree[2*pos+1].mms,tree[2*pos+2].mms));
*/
}

}


node query(ll start,ll end,ll l,ll r,ll pos){
node result ;
result.maxv=result.preval=result.suffval=result.prefre=result.suffre=INT_MIN;
//result.prefre=0;result.suffre=0;
//	result.maxv=0;
result.all=0;	
	
	
	if(l<=start&&r>=end){
		return tree[pos];
	}
	if(r<start||end<l){
		return result;
	}
	
	
	
	ll mid=(start+end)/2;
	node left=query(start,mid,l,r,2*pos+1);
	node right=query(mid+1,end,l,r,2*pos+2);
merge(result,left,right);/*	
	result.tsum=left.tsum+right.tsum;
	result.maxpre=max(left.maxpre,left.tsum+right.maxpre);
	result.maxsuff=max(right.maxsuff,right.tsum+left.maxsuff);
//	result.mms=max(result.maxpre,max(result.maxsuff,max(left.maxsuff+right.maxpre,max(left.mms,right.mms))));
	result.mms=max(left.maxsuff+right.maxpre,max(left.mms,right.mms));
*/	
	return result;
	
}



int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
freopen("input.txt", "r", stdin);
	 freopen("output.txt","w",stdout);//redirects standard output
	ll n;
	cin>>n;
	ll q;
	cin>>q;
	fflush(stdin);
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	builttree(0,n-1,0);
	fflush(stdin);
	ll d,y;
	for(ll i=0;i<q;i++){
	fflush(stdin);	
		
cin>>d>>y;
		ll p=query(0,n-1,d,y,0).maxv;
            cout<<p<<endl;
		/*
	for(ll d=0;d<30;d++){
		cout<<"max: "<<tree[d].maxv<<"  "<<"pval: "<<tree[d].preval<<"  "<<"pfre:"<<tree[d].prefre<<"  "<<"sufv: "<<tree[d].suffval<<"  "<<" suffre: "<<tree[d].suffre<<"   all: "<<tree[d].all<<endl;
		
	}
		
		*/
		
		
	}
}
