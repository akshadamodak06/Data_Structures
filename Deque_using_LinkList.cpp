//Time Complexity of this code:-
//Deletion and Insertion at front and back end are O(1).
//display of size , front element , rear element are also O(1).
// Displaying Deque in Forward and Backward manner are O(N).

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int y=0;
    int store;
    int m=(2*n)+1;
    for(int i=1;i<=m;i++)
    {
        store=i;
        if(i>(m/2)+1)
        {
            i=m-i+1;
        }
        int k=0;
        int z=(2*i)-1;
        
        for(int j=1;j<=m;j++)
        {
            if(j<(m/2)+1)
            {
                if(j>(m/2)+1-z+y)
                {
                    cout<<k<<" ";
                    k++;
                }
                else 
                {
                    cout<<"  ";
                }
            }
            else if(j==(m/2)+1)
            {
                if(k==0)
                cout<<k;
                else
                cout<<k<<" ";
            }
            else
            {
                if(j<(m/2)+1+z-y)
                {
                    k--;
                    if(k==0)
                    {
                        cout<<k;
                    }
                    else
                    cout<<k<<" ";
                }
            }
        }
        cout<<endl;
        i=store;
        if(i<(m/2)+1)
        {
            y++;
        }
        else
        {
            y--;
        }
        
    }
}
