//Time Complexity of this code :-
//The enqueue and dequeue are of time complexity O(1).
//size and display of front and rear element are of time complexity O(1).

#include <iostream>
using namespace std;
class Queue
{
private:
    int arr[10];
    int front, rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }
    void enqueue(int val)
    {
        if (rear == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = val;
    }

    void dequeue()
    {
        if (front == rear)
        {
            front = -1;
            rear = -1;
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
        return rear - front + 1;
    }

    void display()
    {
        if (front == -1)
        {
            cout << "Queue is empty . ";
        }
        else
        {
            cout << "Queue : ";
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
        }
    }

    bool empty()
    {
        if (front == -1 && rear == -1)
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
        cout << "hh";
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
