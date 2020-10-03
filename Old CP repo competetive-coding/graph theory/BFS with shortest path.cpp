//code by sajal agrawal :-one of the best code ever
//adj list implementation
//BFS ALSO INCLUDED
//BFS IS USED TO CALULATE THE SHORTEST PATH IN UNWEIGHTED GRAPH
//IN UNDIRESTED GRAPH BOTH BFS AND DFS CAN BE USED TO DETECT THE CYCLE. IN DIRECTED GRAPH ONLY DFS WORKS
//parent array is used to find out thee shortest path
//use aag wala concept :)
//the node that is first visited is its shortest path from the root from it started (most impotant note)(that is its level from root)
//link :-www.codingblocks.com/ide/#/s/986
//in case of weighted graph :- given below
//dijkstra is used to find the single source shortest path when all road is positive
//when weight is negative use belman fort or floyd warshal
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
	void bfs(int src,int das){
		queue<int>q;
		int *dis=new int[v+1]{0};//or we can say tree level
		int *par=new int[v+1];//parent
		for(int j=0;j<v;j++){
			par[j]=-1;
		}
		bool *visited=new bool[v+1]{0};//initialise array with 0 , node is not visied
		q.push(src);
		
		visited[src]=true;
		while(!q.empty()){
			int k=q.front();
			q.pop();
			cout<<" "<<k<<" ";
					 for (auto i = adjlist[k].begin(); i != adjlist[k].end(); i++){
				if(!visited[*i]){
				par[*i]=k;
					q.push(*i);
					visited[*i]=true;
					dis[*i]=dis[k]+1;
				}
			}
			
			
			cout<<endl;
			
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
		cout<<endl;
		//print the distances from every node  from the source
		for(int u=0;u<v;u++){
			cout<<u<<" node having dis"<<dis[u]<<" "<<endl;
		}
		cout<<endl;
		cout<<" shortest distance is "<<" -> "<<dis[das]<<" "<<endl;
		cout<<" shortest path is "<<endl;
		int temp=das;
		while(temp!=-1){
			cout<<temp<<" -> ";
			temp=par[temp];
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
	g.addedge(4,3);
	g.bfs(0,5);
}
