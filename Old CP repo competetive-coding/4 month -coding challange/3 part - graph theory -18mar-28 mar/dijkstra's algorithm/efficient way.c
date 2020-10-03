#include<bits/bits/stdc++.h>
using namespace std;
template<typename T>
class graph{
unordered_map<T,list<pair<T,int> > hmap;
public:
    void addedge(T u,T v,int dist,bool bidir=true){
    hmap[u].push_back(make_pair(v,dist));
    if(bidir){
        hmap[v].push_back(make_pair(u,dist));

    }



    }
    void printadj(){/*
for(ll i=0;i<m.size();i++){
    for(j=0;j<m[i].size();j++){

    }*/
    for(auto j:m){
        cout<<j.first<<" -> ";
        //iterate over the list of citeies
        for(auto l:j.second){
            cout<<"("<<l.first<<","<<l.second<<")";
        }
        cout<<endl;
    }

}
    }
    void dijsktrasssp(T src){
    }


};
int main(){
graph<string>india;
india.addedge("Amiritsar","Delhi",1);
india.addedge("Amiritsar","jaipur",4);
india.addedge("jaipur","delhi",2);
india.addedge("jaiput","mumbai",8);


}
