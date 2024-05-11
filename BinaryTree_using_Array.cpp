#include<iostream>
#include<cmath>
using namespace std;
class BTA
{
    private:
    int arr[8];
    int nodes=7;
    public:
    BTA()
    {
        for(int i=1;i<=nodes;i++)
        {
            arr[i]=-1;
        }
    }

    void insert()
    {
        int a,num;
        cout<<"Do you want it to be in the right or left subtree .\nEnter 0 for for left and 1 for right : ";
        cin>>a;
        cout<<"Enter the number you want to insert : ";
        cin>>num;
        int c=0;
        for(int i=1;i<=nodes;i++)
        {
            int b=log2(i);
            if(i>=4)
            {
                b=b/pow(2,b-1);
            }
            else if (b==0)
            {
                b=0;
            }
            else
            {
                b=i;
            }
            
            if(a==0)
            {
                if((b==1||b==2) && arr[i]==-1)
                {
                    arr[i]=num;
                    c=1;
                }
                else if(b==0 && arr[i]==-1)
                {
                    arr[i]=num;
                    c=1;
                }
            } 
            else
            {
                if((b==1||b==3) && arr[i]==-1)
                {
                    arr[i]=num;
                    c=1;
                }
                else if(b==0 && arr[i]==-1)
                {
                    arr[i]=num;
                    c=1;
                }
            }
            if(c==1)
            {
                c=0;
                break;
            }    

        }
        if(c!=0)
        {
            cout<<"Memory full. Try at other position";
        }    
    }

    void display()
    {
        for(int i=1;i<=7;i++)
        {
            cout<<arr[i]<<" ";
        }

    }


    void remove()
    {
        int num;
        cout<<"Enter the value of the node you want to delete : ";
        cin>>num;
        for(int i=1;i<=nodes;i++)
        {
            if(arr[i]==num)
            {
                arr[i]=-1;
                return;
            }
        }
    }

    int leftchild(int index)
    {
        if(arr[index]!=-1&& (2*index<=nodes))
        {
            return 2*index;
        }
        return -1;
    }

    int rightchild(int index)
    {
        if(arr[index]!=-1 && (2*index +1)<=nodes)
        {
            return 2*index+1;
        }
        return -1;
    }

    void preorder(int index)
    {
        if(index >0 && arr[index]!=-1)
        {
            cout<<arr[index]<<" ";
            preorder(leftchild(index));
            preorder(rightchild(index));
        }
    }

    void postorder(int index)
    {
        if(index>0 && arr[index] != -1)
        {
            postorder(leftchild(index));
            postorder(rightchild(index));
            cout<<arr[index]<<" ";
        }
    }

    void inorder(int index)
    {
        postorder(leftchild(index));
        cout<<arr[index]<<" ";
        postorder(rightchild(index));
    }
};
int main()
{
    BTA b;
    for(int i=0;i<7;i++)
    {
        b.insert();
        b.display();
    }
    cout<<"Preorder : ";
    b.preorder(1);
    cout<<endl;
    cout<<"Postorder : ";
    b.postorder(1);
    cout<<endl;
    cout<<"Inorder : ";
    b.inorder(1);

}
