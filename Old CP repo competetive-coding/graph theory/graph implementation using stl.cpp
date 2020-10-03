//code by sajal agrawal
//adj list implementation
#include<iostream>
#include<list>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
class graph{
	//you need array of list
	int v;
	list<int>*adjlist;
//	list<int>*a=new list<int>[v];
    	public:
		graph(int v2){
    		v=v2;
    		adjlist=new list<int>[v];
		}
		
		void addedge(int u,int v,bool bir=true){
			adjlist[u].push_back(v);
			if(bir){
				adjlist[v].push_back(u);
			}
		}
		
		void printadj(){
			
			for(int i=0;i<v;i++){
				cout<<i<<" ->";
				// below two method to apply
				//1 method (by iteator)
			/*	list<int>::iterator it;
				for(it=adjlist[i].begin();it!=adjlist[i].end();it++){
					cout<<*it<<" , ";
				}*/
				//2 method :-Range base for loop (for each loop)
				for(int node:adjlist[i]){
					cout<<node<<",";
				}
				cout<<endl;
				
			}
		}
	void bfs(int src){
		queue<int>q;
		
		bool *visited=new bool[v]{0};//initialise array with 0 , node is not visied
		q.push(src);
		visited[src]=true;
		while(!q.empty()){
			int k=q.front();
			q.pop();
			cout<<" "<<k<<" ";
					 for (auto i = adjlist[k].begin(); i != adjlist[k].end(); i++){
				if(!visited[*i]){
					q.push(*i);
					visited[*i]=true;
				}
			}
			
			/*
			for(int nei:adjlist[k]){
				if(!visited[k]){
					cout<<" here "<<k<<" ";
					q.push(nei);
					visited[nei]=true;
				}
			}
			
			*/
			
		}
		
	}
};
int main(){
	graph g(6);
	g.addedge(0,1);
	g.addedge(1,2);
	g.addedge(0,4);
	g.addedge(2,4);
	g.addedge(3,2);
	g.addedge(3,5);
	g.addedge(2,3);
	g.bfs(0);
}
