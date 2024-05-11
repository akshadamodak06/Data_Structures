#include <iostream>
using namespace std;
class node
{
public:
    int key;
    int value;
    node(int k, int val)
    {
        key = k;
        value = val;
    }
};
class Hash
{
private:
    static const int size = 100;
    node *hash[size];

public:
    Hash()
    {
        for (int i = 0; i < size; i++)
        {
            hash[i] = NULL;
        }
    }

    int hashfunction(int key)
    {
        return key % size;
    } 

    void insert(int k, int val)
    {
        int index = hashfunction(k);
        node *n = new node(k, val);
        hash[index] = n;
    }

    void remove(int k)
    {
        int index = hashfunction(k);
        hash[index]=NULL;
    }
    int search(int k)
    {
        int index = hashfunction(k);
        if (hash[index] != NULL && hash[index]->key == k )
        {
            return hash[index]->value;
        }
        else 
        {
            cout << "Key does not exist ." << endl;
            return 0;
        }
        
    }
};
int main()
{
    Hash h;
    h.insert(1, 1);
    h.insert(2, 2);
    h.insert(3, 3);
    int result = h.search(3);
    if (result != 0)
    {
        cout << "The value at key 3 is : " << result << endl;
    }
    h.remove(3);
    int result1 = h.search(3);
    if (result1 != 0)
    {
        cout << "The value at key 3 is : " << result1 << endl;
    }
    h.insert(3, 3);
    int result2 = h.search(3);
    if (result2 != 0)
    {
        cout << "The value at key 3 is : " << result2 << endl;
    }
}
