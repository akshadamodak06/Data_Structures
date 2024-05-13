//Time complexity of this code:-
// Time complexity of push and pop are O(1).
//Time Complexity of top , size and empty are O(1).


#include <iostream>
using namespace std;
class Stack
{
private:
    int *arr;
    int top;

public:
    Stack()
    {
        top = -1;
    }
    void push(int val)
    {
        top++;
        arr[top] = val;
    }

    void pop()
    {
        top--;
    }

    int top1()
    {
        return arr[top];
    }

    int size()
    {
        return top + 1;
    }

    bool empty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void display()
    {
        if (top == -1)
        {
            cout << "Stack is empty . " << endl;
        }
        else
        {
            cout << "Stack : ";
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << " ";
            }
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
        cout << "Enter valid number";
        cout << endl<< endl;
        goto label;
    }
}
