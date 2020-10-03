//video https://www.youtube.com/watch?v=6j-vHQMXXiA
//fgreat video
#include<bits/stdc++.h>
using namespace std;
class Edge{
	public:
		int source,dest,weight;
};
bool comp(Edge i,Edge j){
	if(i.weight<j.weight){
		return true;
	}
	else{
		return false;	
	}
}

int findparent(int v,int *parent){
	//as soon as the index and array value is same we can return as it is
if(parent[v]==v){
	return v;//v is a topmost parent
}
//cal recursion to find parent
return findparent(parent[v],parent);
	}


void kruskals(Edge *input,int n,int E){
//sort the input array --ascending array based on their wight
sort(input,input+n,comp);	
 	
	Edge *output = new Edge[n-1];
		 int *parent = new int[n];
		 for(int i=0;i<n;i++){
		 	parent[i]=i;
//har node abi khud ka parent he
		 }
	int count=0;//currently kitni eges ko add kar diya bst me ..output array me
	int i=0;//currently konsi edge par he
	 while(count!=n-1){
	 	Edge  currentedge=input[i];
	 	///union find algo
	//is check we can add the current edgein mst or not
	//we have to  figure out parent of both the vertices of the edge
	int sourceparent = findparent(currentedge.source,parent);
	                                      //to find out final parent or topmost parent
	int destparent = findparent(currentedge.dest,parent);//to find out final parent or topmost parent
	//check if equal
	if(sourceparent!=destparent){
		output[count]=currentedge;
		count++;
		//make uniiom//kissi ko kisi ka bhi parent baa sakte he
		parent[sourceparent]=destparent;
	}
		 i++;
		 
	 	
	 }
	
	for(int i=0;i<n-1;i++){
if(output[i].source<output[i].dest)
cout<<output[i].source<<"  "<<output[i].dest<<" "<<output[i].weight<<endl;

else{
cout<< "  "<<output[i].dest<<"  "<<output[i].source <<" "<<output[i].weight<<endl;
	
}
	}
	
	
	
}


int main(){
	int n,E;
	cin>>n>>E;
	Edge *input= new Edge[E];
	for(int i=0;i<E;i++){
		int s,d,w;
		cin>>s>>d>>w;
		input[i].source=s;
        input[i].dest=d;
		input[i].weight=w;		
	}
	kruskals(input,n,E);
	
	
	
	
	
}
