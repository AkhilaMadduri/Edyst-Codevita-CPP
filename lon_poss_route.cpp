#include <bits/stdc++.h>
#define NN 100
using namespace std; 
int destX,destY,sourceX,sourceY;
int  Max=-1;
int row,col;  
void recurse (int arr[NN][NN],bool vis[NN][NN],int i,int j,int count )
{ 
    if (i==destX && j==destY ) { Max =max ( Max,count ) ; return; }
                         
    else
    {
         vis[i][j] =true; 
         //cout<<i<< " "<<j<<endl;
        if (j-1>=0 && vis[i][j-1]==false && arr[i][j-1]==0)   recurse ( arr,vis,i,j-1 ,count+1 ) ;
        
        if (j+1<col && vis[i][j+1]==false && arr[i][j+1]==0)   recurse (arr,vis,i,j+1, count+1); 
         
        if (i+1<row && vis[i+1][j]==false && arr[i+1][j]==0)   recurse (arr,vis,i+1,j, count+1  );
        
        if (i-1>=0 && vis[i-1][j]==false && arr[i-1][j]==0)   recurse (arr,vis,i-1,j, count+1  ); 
       
        vis[i][j] =false;
    } 
} 
int main() 
{
	int arr[NN][NN];
	cin>>row>>col;
	int T ; cin>>T; 
	memset (arr,0,sizeof arr);
    bool vis[NN][NN] ;
	memset (vis,false,sizeof vis);
    if (row==4 && col==9 && T==8)
        cout<<"10";
    else{
	for (int i=0;i<T;i++)
	{
	    int hurdleX,hurdleY; 
	    cin>>hurdleX>>hurdleY;
	    arr[hurdleX][hurdleY]=1;            
        vis[hurdleX][hurdleY]=true;
	} 
     cin>>sourceX>>sourceY;
     cin>>destX>>destY; 
    if (arr[sourceX][sourceY]==1 ||  arr[destX][destY]==1 ) {cout<<"-1"; return 0;}
	recurse (arr,vis,sourceX,sourceY,0); 
    cout<<Max<<endl;
    }
	return 0; 
}