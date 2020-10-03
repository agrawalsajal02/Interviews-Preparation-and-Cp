#include<bits/stdc++.h>
using namespace std;
#define MAX 9999;
void builttree(int a[],int b[],int low,int high,int pos){
	if(low>high){
		return;
	}
	if(low==high){
		b[pos]=a[low];
		return;
	}
	int mid=(low+high)/2;
	builttree(a,b,low,mid,2*pos+1);
	builttree(a,b,mid+1,high,2*pos+2);
	b[pos]=min(b[2*pos+1],b[2*pos+2]);
	
}
int findrange(int b[],int low,int high,int qlow,int qhigh,int pos){
	
	if(qlow<=low&&qhigh>=high){
		//complete overlap
		return b[pos];
	}
	else if(qlow>high||qhigh<low){
		//no ovelap
	//	cout<<" max returned "<<endl;
		return MAX;
	}
	//psrtial overlap
	int mid=low+(high-low)/2;
	//cout<<"  mid "<<mid<<"  "<<" low "<<low<<"  high "<<high<<" "<<endl;
	int kl=findrange(b,low,mid,qlow,qhigh,2*pos+1);
	int kh=findrange(b,mid+1,high,qlow,qhigh,2*pos+2);
	//cout<<endl<<" min is "<<min(kl,kh)<<" ";
	
	return (min(kl,kh));

}



//int getMid(int s, int e) {  return s + (e -s)/2;  } 
//int minVal(int x, int y) { return (x < y)? x: y; }

/*
int findran(int *st, int ss, int se, int qs, int qe, int index) 
{ 
    // If segment of this node is a part of given range, then return 
    //  the min of the segment 
    if (qs <= ss && qe >= se) 
        return st[index]; 
  
    // If segment of this node is outside the given range 
    if (se < qs || ss > qe) 
        return INT_MAX; 
  
    // If a part of this segment overlaps with the given range 
    //int mid=ss+(ss-se)/2; 
    int mid = getMid(ss, se); 
    return minVal(findran(st, ss, mid, qs, qe, 2*index+1), 
                  findran(st, mid+1, se, qs, qe, 2*index+2)); 
} */
int main(){
	int n,q;
	cin>>n;
	cin>>q;
	
	int a[n];

	for(int i=0;i<n;i++){
		cin>>a[i];
	}
		int *b=new int[15];
	builttree(a,b,0,7,0);
	cout<<endl;

	for(int i=0;i<q;i++){
	
	for(int i=0;i<15;i++){
		cout<<" "<<b[i]<<" ";
	}
	cout<<endl;
	cout<<" your tree is builted , now its time to get range "<<endl;
	cout<<"enter the range"<<endl<<endl;
	int lo,hi;
	cin>>lo>>hi;
	int k=findrange(b,0,7,lo,hi,0);
	cout<<k;
}

}
