#include<iostream>
#include<cstring>
#include<map>
#include<list>
using namespace std;
//generic graph
template<class T>
class graph{
	map<T,list<T>>adjlist;  //for weighted graph map<T,list<pair<T,int>>>   
	public:
		graph(){
			cout<<" initalised "<<endl;
			}
		void addedge(T u,T v,bool bir=true){
			adjlist[u].push_back(v);
			if(bir){
				adjlist[v].push_back(u);
			}
			
		}
			void printadj(){
		for(auto list:adjlist){    // auto can be changr to pair<T,list<T> list:adjlist
			T key=list.first;
			cout<<key<<" -> ";
			for(T ele:list.second){
				cout<<ele<<" , ";
			}
			cout<<endl;
		}
		}
		
		
		
		
};
int main(){
	graph <string>g;
	g.addedge("dholpur","gwalior");
	g.addedge("dholpur","agra");
	g.addedge("delhi","agra");
	g.addedge("delhi","bangalore");
	g.addedge("gwalior","bangalore");
	g.addedge("dholpur","bangalore");
	g.printadj();
}

///***/*/45//**/
