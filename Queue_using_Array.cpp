#include <iostream>
using namespace std;
class AQueue
{
    private:
    int arr[100];
    int front,rear;
    public:
    AQueue()
    {
        front =0;
        rear=-1;
    }
    int enqueue()
    {
        if(rear==100)
        {
            cout<<"Queue is full ."<<endl;
        }
        else
        {
            cout<<"Enter the value of the element : ";
            rear=rear+1;
            cin>>arr[rear];
          
        }

        return 0;
    } 

    int dequeue()
    {
        int item;
        if(rear==-1)
        {
            cout<<"Queue is empty."<<endl;
        }
        else
        {
            item=arr[front];
            for(int i=0;i<100;i++)
            {
                arr[i]=arr[i+1];
            }
            rear--;
            return item;            
        }

    }
    void display()
    {
        for(int i=0;i<=rear;i++)
        {
            cout<<"The element "<<i+1<<" is : "<<arr[i]<<endl;
        }
    }
    
};

int main()
{
    AQueue q;
    for(int i=0;i<5;i++)
    {
        q.enqueue();
    }
    q.display();
    int result=q.dequeue();
    cout<<"The element popped is "<<result<<endl;
    q.display();
    return 0;

}
