//Time Complexity of this code :-
//enqueue function has O(N).
//dequeue function has O(1).
// dispaly of size , empty function, front and rear element has O(1).

#include <bits/stdc++.h>
using namespace std;

class PriorityQueue
{
private:
    int *arr;
    int front, rear;

public:
    PriorityQueue()
    {
        front = rear = -1;
        arr = new int;
    }
    void enqueue(int val)
    {
        if (front == rear && front == -1)
        {
            front++;
            rear++;
            arr[rear] = val;
        }
        else
        {
            int i = front;
            while (val >= arr[i])
            {
                i++;
            }
            int store = arr[i];
            arr[i] = val;
            for (int j = rear + 1; j > i + 1; j--)
            {
                arr[j] = arr[j - 1];
            }
            arr[i + 1] = store;
            rear++;
        }
    }

    void dequeue()
    {
        if(front==rear && front==-1)
        {
            cout<<"List is empty ."<<endl;
        }
        else if (front == rear)
        {
            front=rear=-1;
        }
        else
        {
            front++;
        }
    }

    int front1()
    {
        return arr[front];
    }

    int rear1()
    {
        return arr[rear];
    }

    int size()
    {
        return rear-front+1;
    }

    bool empty()
    {
        if(front==rear && front ==-1)
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
        if (front == rear && front == -1)
        {
            cout << "List is empty. " << endl;
        }
        else
        {
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
        }
    }
};

int main()
{
   
    PriorityQueue q;
    int num, n;
label:
    cout << "Enter 0 to enqueue\nEnter 1 to dequeue\nEnter 2 to display front element\nEnter 3 to display rear element\nEnter 4 to display size\nEnter 5 to display Queue\nEnter 6 to check whether stack is empty\nEnter 7 to exit\n\n";
    cin >> num;
    if (num == 0)
    {
        cout << "Enter the number you want to enqueue : ";
        cin >> n;
        q.enqueue(n);
        cout << endl;
        goto label;
    }
    else if (num == 1)
    {
        q.dequeue();
        cout << endl;
        goto label;
    }
    else if (num == 2)
    {
        cout << "The front element is : " << q.front1() << endl;
        cout << endl;
        goto label;
    }
    else if (num == 3)
    {
        cout << "The rear element is : " << q.rear1() << endl;
        cout << endl;
        goto label;
    }
    else if (num == 4)
    {
        cout << "Size of Queue is : " << q.size() << endl;
        cout << endl;
        goto label;
    }
    else if (num == 5)
    {
        q.display();
        cout << endl;
        goto label;
    }
    else if (num == 6)
    {
        n = q.empty();
        if (n == true)
        {
            cout << "Queue is empty . " << endl;
        }
        else
        {
            cout << "Queue is not empty . " << endl;
        }
        cout << endl;
        goto label;
    }
    else if (num == 7)
    {
        cout << "------------------------------Thank You . Program Ends Here. ------------------------------------------";
        return 0;
    }
    else
    {
        cout << "Enter valid number";
        cout << endl
             << endl;
        goto label;
    }
}
