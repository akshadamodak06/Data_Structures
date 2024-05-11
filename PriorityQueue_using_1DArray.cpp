#include <iostream>
using namespace std;
class PQueueSA
{
    private:
    int arr[100];
    int front=0;
    int rear=-1;
    public:
    void enqueue(int num)
    {
        if(rear==100)
        {
            cout<<"Queue is Full"<<endl;
        }
        else
        {
            rear++;
            int i=0;
            int a=0;
            for(i=0;i<rear;i++)
            {
                if(num>arr[i])
                {
                    a++;
                    break;
                }
            }
            if(a==0)
            {
                arr[rear]=num;
            }
            else
            {
            int temp=arr[i];
            arr[i]=num;
            for(int j=rear;j>=i+1;j--)
            {
                arr[j]=arr[j-1];
            }
            arr[i+1]=temp;
            }
        }
    }

    int dequeue()
    {
        int value;
        value=arr[0];
        for(int i=0;i<rear;i++)
        {
            arr[i]=arr[i+1];
        }
        rear--;
        return value;
    }

    void display()
    {
        for(int i=0;i<=rear;i++)
        {
            cout<<"Element "<<i+1<<" is : "<<arr[i]<<endl;
        }
    }

    void priority()
    {
        cout<<"The priority element is : "<<arr[front]<<endl;
    }
};
int main()
{
    PQueueSA pq;
    for(int i=0;i<5;i++)
    {
        int n;
        cout<<"Enter element "<<i+1<<" : ";
        cin>>n;
        pq.enqueue(n);
    }
    pq.display();
    int value=pq.dequeue();
    cout<<"Deleted Element is :"<<value<<endl;
    pq.display();
    pq.priority();

}
