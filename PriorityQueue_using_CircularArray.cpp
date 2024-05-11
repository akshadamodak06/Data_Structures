#include <iostream>
using namespace std;
class PQueueCA
{
    private:
    int arr[100];
    int front =0;
    int rear=-1;
    public:
    void enqueue(int n)
    {
        if(rear==100)
        {
            cout<<"Queue is full"<<endl;            
        }
        else if(rear==-1)
        {
            rear++;
            arr[rear]=n;
        }
        else
        {
            rear++; 
            rear=rear%100;
            int a=0;
            int i; 
            if(front < rear)
            {
                for(i=front;i<rear;i++)
                {
                    if(n>arr[i])
                    {
                        a++;
                        break;
                    }
                }
                if(a==0)
                {
                    arr[rear]=n;
                }
                else
                {
                    for(int j=rear;j>i;j--)
                    {
                        arr[j]=arr[j-1];
                    }
                    arr[i]=n;
                }
                a=0;
            }

            else
            {
                for(i=front;i<100-front+rear+1;i++)
                {
                    if(n>arr[i])
                    {
                        break;
                    }
                }
            }
        }

        
    }

    int dequeue()
    {
        if(front == rear-1 || rear== -1 )
        {
            cout<<"Queue is empty."<<endl;
        }
        else
        {
        int value=arr[front];
        front++;
        front=(front%100);
        return value;
        }
    }

    void display()
    {
        if(front < rear)
        {
        for(int i=front;i<=rear;i++)
        {
            cout<<"Element is : "<<arr[i]<<endl;
        }
        }

        else if (rear<front)
        {
            for(int i=front;i<=100-front+rear+1;i++)
            {
                int j=i;
                j=j%100;
                cout<<"Element is : "<<arr[j]<<endl;
            }
        }
    }
    
    void size()
    {
        cout<<"The size of the queue is "<<rear-front+1;
    }

    void top()
    {
        cout<<"The top element of the queue is "<<arr[front]<<endl;
    }

};
int main()
{
    PQueueCA pq;
    for(int i=0;i<5;i++)
    {
        int n;
        cout<<"Enter the element "<<i+1<<" : ";
        cin>>n;
        pq.enqueue(n);

    }
    pq.display();
    pq.size();
    cout<<endl;
    pq.top();
    int item=pq.dequeue();
    cout<<"Deleted item is : "<<item<<endl;
    pq.display();
    pq.size();
    cout<<endl;
    pq.top();    
}
