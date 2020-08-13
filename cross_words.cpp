#include <bits/stdc++.h>
using namespace std; 
struct sarr
{
    int x,y,co;
    char select;
    bool done=false;
    string STR="";
    int ans=0;
} ;
struct sarr Sarr[50];
bool Ncomplete (struct sarr Sarr[],int *r,int *c,char *s,int *co,int *pos,int M)
{
    for (int i=0;i<M;i++)
    {
        if (Sarr[i].done==false)
        {
            *r=Sarr[i].x;
            *c=Sarr[i].y;
            *s=Sarr[i].select;
            *co=Sarr[i].co;
            *pos=i;
            return true;
        }
    }
    return false;
}
bool isSafe (char **arr ,string str ,int r,int c,int co,char s)
{
    if (str.length ( )!=co) return false; 
    if (s=='a')
    {
        int cc=0;
        for (int i=c;i<c+co;i++)
        {
            if (arr[r][i]=='y') { cc++; }
            else if (arr[r][i]!=str[cc++]) {   return false; }
        }
    }
    else if (s=='d')
    {
        int cc=0;
        for (int i=r;i<r+co;i++)
        {
            if (arr[i][c]=='y') { cc++; }
            else if (arr[i][c]!=str[cc++]) {  return false;}
        }
    } 
    return true;
}
bool solve (char **arr ,string str[5],int M)
{
    int r,c,co,pos; char s;
    if ( !Ncomplete(Sarr,&r,&c,&s,&co,&pos,M)) return true;
    for (int i=0;i<M;i++)
    {
        if (isSafe(arr,str[i],r,c,co,s))
        {
            if (s=='a')
            {
                int cc=0;
                for (int j=c;j<c+co;j++)
                {
                    arr[r][j]=str[i][cc++]; 
                }
                Sarr[pos].STR=str[i];
                Sarr[pos].done=true; 
            }
            else if (s=='d')
            {
                int cc=0;  
                for (int j=r;j<r+co;j++)
                {
                    arr[j][c]=str[i][cc++]; 
                } 
                Sarr[pos].STR=str[i];
                Sarr[pos].done=true;
            }
 
            if (solve (arr,str,M)) return true;
            if (s=='a')
            {
                for (int j=c;j<c+co;j++)
                {  
                    arr[r][j]='y';
                }
            }
            else if (s=='d')
            {
                for (int j=r;j<r+co;j++)
                {  
                    arr[j][c]='y';
                }
            }
            Sarr[pos].STR="";
            Sarr[pos].done=false;
        }
    }
    return false;
}
void func (struct sarr Sarr[],int M,char **arr,int N)
{ int d=0;
    for (int i=0;i<N;i++)
    {
        for (int j=0;j<N;j++)
        {
            if (arr[i][j]=='y')
            {
                if ( ( j-1<0 ||  arr[i][j-1]=='n' ) && j+1<N && arr[i][j+1]=='y')
                {
                    int count=0;
                    for (int s=j;s<N;s++) if (arr[i][s]=='y') count++; else break;
                    Sarr[d].x=i; Sarr[d].y=j; Sarr[d].co=count; 
                    Sarr[d++].select='a'; 
                }
                if ( ( i-1 <0 ||  arr[i-1][j]=='n' )  && i+1<N  && arr[i+1][j]=='y')
                {
                    int count=0;
                    for (int s=i;s<N;s++) if (arr[s][j]=='y') count++; else break;
                    Sarr[d].x=i; Sarr[d].y=j; Sarr[d].co=count; 
                    Sarr[d++].select='d'; 
                }  
            }
        }
    }
    return;
}
int main() 
{
    int N; cin>>N;   
    char **arr;
    arr = new char*[N];
    for(int i = 0; i <N; i++)
    arr[i] = new char[N];
    for (int i=0;i<N;i++) for (int j=0;j<N;j++) arr[i][j]='y';
    for (int i=0;i<N;i++)
    { 
        string divar; cin>>divar;
        stringstream check1(divar); 
        int ddd[15]; int ccc=0;
        string intermediate; 
        while(getline(check1, intermediate, ',')) 
        { 
            ddd[ccc++]= stoi (intermediate);   
        }  
        for (int j=0;j<ccc;j+=2)
        { 
            for (int k=ddd[j]-1;k<ddd[j+1]+ddd[j]-1;k++) arr[i][k]='n';
        }
    }  
    int M; cin>>M;  string str[M];
    for (int s=0;s<M;s++) cin>>str[s]; 
    func (Sarr,M,arr,N);  
    solve (arr,str,M); 
     Sarr[0].ans=1;
    for (int i=0;i<M-1;i++)
    {   if (Sarr[i].ans==0) Sarr[i].ans=Sarr[i-1].ans+1;
        for (int j=i+1;j<M;j++)
        {if (Sarr[j].ans==0)
        {
            if (Sarr[i].x==Sarr[j].x && Sarr[i].y==Sarr[j].y) Sarr[j].ans=Sarr[i].ans;
        }}
    }
    if (Sarr[M-1].ans==0) Sarr[M-1].ans=Sarr[M-2].ans+1;
    for (int i=0;i<M;i++)
    {  
         cout<<Sarr[i].ans<<","<< char (  toupper ( Sarr[i].select ) ) <<","<<Sarr[i].STR << endl;
    }
	return 0;}