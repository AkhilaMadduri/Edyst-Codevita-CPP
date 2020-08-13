#include<iostream>
#include<vector>
using namespace std;


int main()
{
    int t;cin>>t;
    while(t--)
    {
        int s;cin>>s;
        vector<int> v;
        for(int i=0;i<s;i++)
        {
            int a;cin>>a;
            v.push_back(a);
        }
        if(s==1)
            cout<<v[0];
        else
        {
            int res=0;
            int curr=1;
            int end_index=0;
            for(int i=1;i<s;i++)
            {
                if(v[i]<v[i-1])
                    curr=1;
                else
                {
                    curr++;
                    if(curr>res)
                        end_index=i;
                    res=max(res,curr);
                }
            }
          //  cout<<res<<" "<<end_index<<endl;

            for(int i=end_index-res+1 ; i<=end_index;i++)
                cout<<v[i]<<" ";
        }
        cout<<endl;

    }
}




