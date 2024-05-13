#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node *next;
    node(int val)
    {
        data=val;
        next=NULL;
    }
};

class Stack
{
    private:
    node *top;
    public:
    Stack()
    {
        top=NULL;
    }
    void push(int val)
    {
        node *tmp=new node(val);
        if(top==NULL)
        {
            top=tmp;
        }
        else
        {
            tmp->next=top;
            top=tmp;
        }              
    }

    void pop()
    {
        if(top==NULL)
        {
            cout<<"Stack is empty ."<<endl;
        }
        else if(top->next==NULL)
        {
            delete top;
            top=NULL;
        }
        else
        {
            top=top->next;
        }
    }

    int top1()
    {
        return top->data;
    }

    int size()
    {
        node *tmp=top;
        int i=0;
        while(tmp->next !=NULL)
        {
            i++;
            tmp=tmp->next;
        }
        i++;
        return i;
    }

    void display()
    {
        node *tmp=top;
        cout<<"Stack : ";
        while(tmp->next != NULL)
        {
            cout<<tmp->data<<" ";
            tmp=tmp->next;
        }
        cout<<tmp->data<<" ";
        cout<<endl;
    }

    bool empty()
    {
        if(top==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

};

int main()
{
    Stack s;
    int num, n;
    label:
    cout << "Enter 0 to push\nEnter 1 to pop\nEnter 2 to display top element\nEnter 3 to display size\nEnter 4 to display Stack\nEnter 5 to check whether stack is empty\nEnter 6 to exit\n\n";
    cin >> num;
    if (num == 0)
    {
        cout << "Enter the number you want to push : ";
        cin >> n;
        s.push(n);
        cout << endl;
        goto label;
    }
    else if (num == 1)
    {
        s.pop();
        cout << endl;
        goto label;
    }
    else if (num == 2)
    {
        cout << "The top element is : " << s.top1() << endl;
        cout << endl;
        goto label;
    }
    else if (num == 3)
    {
        cout << "Size of stack is : " << s.size() << endl;
        cout << endl;
        goto label;
    }
    else if (num == 4)
    {
        s.display();
        cout << endl;
        goto label;
    }
    else if (num == 5)
    {
        n = s.empty();
        if (n == true)
        {
            cout << "Stack is empty . " << endl;
        }
        else
        {
            cout << "Stack is not empty . " << endl;
        }
        cout<<endl;
        goto label;
    }
    else if (num == 6)
    {
        cout << "------------------------------Thank You . Program Ends Here. ------------------------------------------";
        return 0;
    }
    else
    {
        cout << "Enter valid number. ";
        cout << endl<< endl;
        goto label;
    }
}
