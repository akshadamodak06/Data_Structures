#include <iostream>
using namespace std;
class AStack
{
    private:
    int num[100];
    int top; 
    public:
    AStack()
    {
        top=-1;
    }
    int push(int n)
    {
        top++;
        num[top]=n;
        return 0;
    }

    int pop()
    {
        int item;
        item=num[top];
        top=top-1;
        return item;
    }

    int status()
    {
        if(top==-1)
        {
            cout<<"The stack is empty.";
        }
        else if(top>=100)
        {
            cout<<"The stack is full.";
        }
        else
        {
            cout<<"The stack is not empty and also not full";
        }
    }
    void display()
    {
        for(int i=0;i<=top;i++)
        {
            cout<<"Element "<<i<<" is : "<<num[i]<<endl;
        }

    }
};

int main()
{
    AStack a;
    int n;
    for(int i=0;i<5;i++)
    {
        cout<<"Enter element "<<i<<" :";
        cin>>n;
        a.push(n);
    }
    a.display();
    n=a.pop();
    cout<<"The popped element is : "<<n<<endl;
    a.display();
    a.status();
}
