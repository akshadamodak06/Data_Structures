#include<iostream>
using namespace std;
class node
{
    public:
    int key;
    int value;
    node(){}
    node(int k, int val):key(k),value(val){}
};

class HashLP
{
    private:
    node *hash;
    int size;
    public:
    HashLP()
    {
        cout<<"Enter the size of table . ";
        cin>>size;
        hash = new node[size];
        for(int i=0;i<size;i++)
        {
            hash[i].key=-1;
        }
    }

    int hashfunction(int value)
    {
        return value%size;
    }

    int reversefunction(int key,int value)
    {
        int x;
        if(key>=hashfunction(value))
        return ((key-hashfunction(value))%size);
        else
        return ((key-hashfunction(value))+size);
    }

    void insert(int value)
    {
        int index=hashfunction(value);
        if(hash[index].key==-1)
        {
            hash[index].value=value;
            hash[index].key=index;
        }

        else
        {
            int i=0;
            while(hash[index].key != -1 && i!=size)
            {
                i++;
                index++;
                index=index%size;
            }
            if(hash[index].key == -1)
            {
                hash[index].value=value;
                hash[index].key=index;
            }
            else
            {
                cout<<"Hash Table overflow . "<<endl;
            }
        }
    }

    int hashprobefunction(int value,int i)
    {
        return (hashfunction(value)+i)%size;
    }

    void remove(int k)
    {
        int index=k;
        int index1;
        if(hash[index].key == -1)
        {
            cout<<"No element present . "<<endl;
        }
        else
        {
            while(1)
            {
            hash[index].key = -1;
            index1=index;
            while(1)
            {
                index1=(index1+1)%size;
                if(hash[index1].key==-1)
                {
                    return;
                }
                while (reversefunction(index, hash[index1].value)<reversefunction(index1,hash[index1].value))
                {
                    hash[index].value=hash[index1].value;
                    hash[index1].key=-1;
                    index=index1;
                }
            }
            }
            
        }
    }

    int search(int value)
    {
        int index = hashfunction(value);
        for(int i=0;i<size;i++)
        {
            if(hash[hashprobefunction(value,i)].value == value)
            {
                cout << hashprobefunction(value, i);
                cout << "\tValue   : " << hash[hashprobefunction(value, i)].value << endl;
                return  hashprobefunction(value, i);
            }

            if(i==size-1)
            {
                cout << "Value   : " << value;
                cout << "\tKey : NOT FOUND" << endl;
                return -1;
            }
        }
    }
};

int main()
{
    HashLP h;
    h.insert(74);
    h.insert(43);
    h.insert(93);
    h.insert(18);
    h.insert(82);
    h.insert(38);
    h.insert(92);

    h.search(74);
    h.search(43);
    h.search(93);
    h.search(18);
    h.search(82);
    h.search(38);
    h.search(92);

    h.remove(3);
    cout<<endl;

    h.search(74);
    h.search(43);
    h.search(93);
    h.search(18);
    h.search(82);
    h.search(38);
    h.search(92);
}
