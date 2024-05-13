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

class Queue
{
    private:
    node *front;
    node *rear;
    public:
    Queue()
    {
        front=rear=NULL;
    }
    void enqueue(int val)
    {
        node *tmp=new node(val);
        if(front==NULL)
        {
            front=rear=tmp;
        }
        else
        {
            rear->next=tmp;
            rear=tmp;
        }
    }

    void dequeue()
    {
        if(front==NULL)
        {
            cout<<"The Queue is empty . ";
        }
        else if(front == rear)
        {
            delete front;
            delete rear;
            front=rear=NULL;
        }
        else
        {
            front=front->next;
        }
    }

    int front1()
    {
        return front->data;
    }

    int rear1()
    {
        return rear->data;
    }

    int size()
    {
        node *tmp =front;
        int i=0;
        while(tmp->next != rear)
        {
            i++;
            tmp=tmp->next;
        }
        i+=2;
        return i;
    }

    void display()
    {
        node *tmp=front;
        cout<<"Queue : ";
        while(tmp->next != rear)
        {
            cout<<tmp->data<<" ";
            tmp=tmp->next;
        }
        cout<<tmp->data<<" ";
        tmp=tmp->next;
         cout<<tmp->data<<" ";
    }

    bool empty()
    {
        if(front==NULL)
        {
            return true;
        }
        return false;
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
        cout << "Size of stack is : " << q.size() << endl;
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
