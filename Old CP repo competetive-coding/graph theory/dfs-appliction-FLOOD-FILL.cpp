//appliccation of dfs
// can be done by both bfs and dfs
// FLOOD - THE COLORING ALGORITHM
//USED INPAINT BUCKET TOOL
//used in computer graphics
#include<iostream>
using namespace std;
int r,c;
void printmat(char mat[][50]){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cout<<mat[i][j];
		}
		cout<<endl;
	}
	
}
//char ch = konse character ko replace karna he :- identifies the component
//recursive algirithm ; recursion hi dfs he;
void floodfill(char mat[][50],int i,int j,char ch,char color){
	if(i<0||j<0||i>=r||j>=c||mat[i][j]!=ch){
		return;
	}
	
	mat[i][j]=color;
	printmat(mat);
	// call to fill the color on neighbouring cell
	floodfill(mat,i+1,j,ch,color);
	floodfill(mat,i,j+1,ch,color);
	floodfill(mat,i-1,j,ch,color);
	floodfill(mat,i,j-1,ch,color);
	
}
int main(){
	
	char mat[50][50];
	cin>>r>>c;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin>>mat[i][j];
		}
	}
	printmat(mat);
	floodfill(mat,8,13,'.','r');	printmat(mat);
	
}


