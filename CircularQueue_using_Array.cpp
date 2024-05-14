//Time Complexity for this code :-
//enqueue, dequeue functions - O(1).
//display of size , rear element , front element, empty function  - O(1).

#include <iostream>
#include <cmath>
using namespace std;
class Queue
{
private:
    int *arr;
    int front, rear;

public:
    Queue()
    {
        front = rear = -1;
        arr = new int[5];
        for (int i = 0; i < 5; i++)
        {
            arr[i] = 0;
        }
    }

    void enqueue(int val)
    {
        front = front % 5;
        rear = rear % 5;
        if (front == (rear + 1) % 5)
        {
            cout << "Queue is full. " << endl;
        }
        else if (front == -1)
        {
            front++;
            rear++;
            arr[front] = val;
        }
        else
        {
            rear++;
            rear = rear % 5;
            arr[rear] = val;
        }
    }

    void dequeue()
    {
        front=front%5;
        rear=rear%5;
        if (front == rear && front != -1)
        {
            arr[front] = 0;
            front = -1;
            rear = -1;
        }
        else if(front==rear&&front==-1)
        {
            cout<<"Queue is empty."<<endl;
        }
        else
        {
            arr[front] = 0;
            front++;
            front = front % 5;
        }
    }

    void display()
    {
        if (front == rear && rear == -1)
            cout << "Queue is empty. " << endl;
        else
        {
            int i = 5;
            int j = front;
            cout << "Queue : ";
            while (i--)
            {
                j = j % 5;
                if (arr[j] != 0)
                    cout << arr[j] << " ";
                j++;
            }
        }
    }

    int rear1()
    {
        return arr[rear];
    }

    int front1()
    {
        return arr[front];
    }

    int size()
    {
        return abs(rear - front) + 1;
    }

    bool empty()
    {
        if (front == rear && front == -1)
        {
            return false;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Queue q;
    int num, n;
label:
    cout << "Enter 0 to enqueue\nEnter 1 to dequeue\nEnter 2 to display front element\nEnter 3 to display rear element\nEnter 4 to display size\nEnter 5 to display Queue\nEnter 6 to check whether queue is empty\nEnter 7 to exit\n\n";
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
        cout << "Size of queue is : " << q.size() << endl;
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
