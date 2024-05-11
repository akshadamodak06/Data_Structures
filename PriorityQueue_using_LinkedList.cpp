#include <iostream>
using namespace std;
struct node 
{
    int data;
    struct node *ptr;
}*s,*s1;
class PQueueLL
{
    private:
    int rear=-1;
    struct node *fnode,*gnode,*tmp,*tmp1;
    public:
    void enqueue(int n)
    {
        if(rear == -1)
        {
            s=(struct node *)malloc(sizeof(struct node ));
            if(s==NULL)
            {
                cout<<"Memory not alloted ."<<endl;
            }
            else
            {
                s->data=n;
                s->ptr=NULL;
                tmp=s;
                tmp1=s;
                rear++;
            }
        }
        else
        {
            fnode=(struct node *)malloc(sizeof(struct node));
            if(fnode==NULL)
            {
                cout<<"Memory not allocated"<<endl;
            }
            else if(tmp->data < n)
            {
                fnode->data=n;
                fnode->ptr=tmp;
                s=fnode;
                rear++;
            }
            else
            {
                fnode->data = n;
                tmp = s;
                int i = 1;
                while (tmp->ptr != NULL && tmp->ptr->data > n) // Find the correct position to insert
                {
                    tmp = tmp->ptr;
                    i++;
                }
                fnode->ptr = tmp->ptr;
                tmp->ptr = fnode;
                rear++; // Update rear

            }
        }
        tmp=s;
        tmp1=s;
    }

    int dequeue()
    {
        if(s == NULL)
        {
            cout<<"Queue is empty ."<<endl;
        }
        else
        {
            int item;
            item=s->data;
            s=s->ptr;
            rear--;
            return item;
        }
    }

    void display()
    {
        tmp=s;
        int i=1;
        while(tmp->ptr != NULL)
        {
            cout<<"Element "<<i<<" is : "<<tmp->data<<endl;
            tmp=tmp->ptr;
            i++;
        }
        cout<<"Element "<<i<<" is : "<<tmp->data<<endl;
    }

    void priority()
    {
        tmp=s;
        cout<<"The priority element is : "<<tmp->data<<endl;
    }

    void size()
    {
        cout<<"Number of elements in queue are : "<<rear+1<<endl;
    }
};


int main()
{
    PQueueLL pq;
    for(int i=0;i<5;i++)
    {
        int n;
        cout<<"Enter the value of element "<<i+1<<" : ";
        cin>>n;
        pq.enqueue(n);
    }
    pq.display();
    pq.size();
    int item =pq.dequeue();
    cout<<"Element dequeued is : "<<item<<endl;
    pq.size();
    pq.priority();
    pq.size();

}
