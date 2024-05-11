#include<iostream>
using namespace std;
class node
{
    public:
    int key;
    int value;
    node *ptr;
    node(int k,int val)
    {
        key=k;
        value=val;
        ptr=nullptr;       
    }
};
class HashC
{
    private:
    const static int size = 100;
    node *hash[size];
    public:
    HashC()
    {
        for(int i=0;i<size;i++)
        {
            hash[i]=NULL;
        }
    }

    int hashfunction(int k)
    {
        return k%size;
    }
    void insert(int k,int val)
    {
        node *n= new node(k,val);
        int index=hashfunction(k);
        node *tmp=hash[index];
        if(hash[index]==NULL)
        {
            hash[index]=n;
            hash[index]->ptr=nullptr;
        }
        else
        {
            node *fnode=n;
            while(tmp->ptr != nullptr)
            {
                tmp=tmp->ptr;
            }
            tmp->ptr=fnode;
            tmp=tmp->ptr;
        }
    }

    void remove(int k)
    {
        int index=hashfunction(k);
        if(hash[index] != NULL)
        {
            hash[index]=hash[index]->ptr;
        }
    }

    int search(int k)
    {
        int index=hashfunction(k);
        if(hash[index]==NULL)
        {
            cout<<"Key does not exist ."<<endl;
            return 0;
        }
        else
        {
           return hash[index]->value;
        }
    }
};
int main()
{
    HashC h;
    h.insert(1,1);
    h.insert(1,2);
    h.insert(2,5);
    int result = h.search(1);
    if(result != 0)
    {
        cout<<"The value at key 1 is "<<result<<endl;
    }
    int result1 = h.search(2);
    if(result1 != 0)
    {
        cout<<"The value at key 2 is "<<result1<<endl;
    }
    h.remove(1);
    h.remove(2);
    int result2 = h.search(1);
    if(result2 != 0)
    {
        cout<<"The value at key 1 is "<<result2<<endl;
    }
    int result3 = h.search(2);
    if(result3 != 0)
    {
        cout<<"The value at key 2 is "<<result3<<endl;
    }
}
