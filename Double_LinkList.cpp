#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node*next;
    struct node*prev;
}*s,*s1;

class DoubleLinkedList
{
    private:
    struct node *tmp,*fnode,*gnode;
    int num;
    public:
    DoubleLinkedList(int n)
    {
        cout<<"Enter element 1 : ";
        cin>>num;
        s=(struct node*)malloc(sizeof (struct node));
        if(s==NULL)
        {
            cout<<"Memory not allocated";
        }
        else
        {
            s->data=num;
            s->next=NULL;
            s->prev=NULL;
            tmp=s;
            for(int i=2;i<=n;i++)
            {
                cout<<"Enter element "<<i<<" : ";
                cin>>num;
                fnode=(struct node *)malloc(sizeof(struct node));
                if(fnode==NULL)
                {
                    cout<<"Memory not allocated.";
                }
                else
                {
                    
                    fnode->data=num;
                    fnode->prev=tmp;
                    fnode->next=NULL;
                    tmp->next=fnode;
                    tmp=tmp->next;
                }
            }
        }
        s1=tmp;
    }

    void DisplayF()
    {
        tmp=s;
        while(tmp!=NULL)
        {
            cout<<"Element is : "<<tmp->data<<endl;
            tmp=tmp->next;

        }
    }

    void DisplayB()
    {
        tmp=s1;
        while(tmp->prev !=NULL)
        {
            cout<<"Element is : "<<tmp->data<<endl;
            tmp=tmp->prev;
        }
        cout<<"Element is : "<<tmp->data<<endl;
    }
};

int main()
{
    DoubleLinkedList dll(5);
    dll.DisplayF();
    dll.DisplayB();
}
