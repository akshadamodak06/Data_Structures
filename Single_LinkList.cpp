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

class LinkList
{
    private:
    node* head;
    public:
    LinkList()
    {
        head=NULL;
    }
    void insert_front(int val)
    {
        node *tmp=new node(val);
        if(head==NULL)
        {
            head=tmp;
        }
        else
        {
            tmp->next=head;
            head=tmp;
        }
    }

    void insert_back(int val)
    {
        node *tmp=new node(val);
        if(head==NULL)
        {
            head=tmp;
        }
        else
        {
            node *tmp1=head;
            while(tmp1->next !=  NULL)
            {
                tmp1=tmp1->next;
            }
            tmp1->next=tmp;
        }
    }

    void delete_front()
    {
        if(head==NULL)
        {
            cout<<"The list is empty ."<<endl;
        }
        else
        {
            head=head->next;
        }
    }

    void delete_back()
    {
        node *tmp1=head;
        node*tmp=head;
        tmp=tmp->next;
        while(tmp->next != NULL)
        {
            tmp=tmp->next;
            tmp1=tmp1->next;
        }
        tmp1->next=NULL;
    }

    void display()
    {
        cout<<"Linked List : ";
        node *tmp=head;
        while(tmp->next!=NULL)
        {
            cout<<tmp->data<<" ";
            tmp=tmp->next;
        }
        cout<<tmp->data<<" ";
    }
};

int main()
{
    LinkList l;
    int num,num1,n;
    label:
    cout<<"Enter 0 to insert\nEnter 1 to delete\nEnter 2 to display\nEnter 3 to exit\n\n";
    cin>>num;
    if(num==0)
    {
        cout<<"Enter the value to be inserted : ";
        cin>>n;
        cout<<"Enter 0 to insert at front\nEnter 1 to insert at back\n\n";
        cin>>num1;
        if(num1==0)
        {
            l.insert_front(n);
        }
        else
        {
            l.insert_back(n);
        }
        cout<<endl;
        goto label;
    }
    else if (num==1)
    {
        cout<<"Enter 0 to delete at front\nEnter 1 to delete at back ";
        cin>>num1;
        if(num1==0)
        {
            l.delete_front();
        }
        else
        {
            l.delete_back();
        }
        cout<<endl;
        goto label;
    }
    else if(num==2)
    {
        l.display();
        cout<<endl;
        goto label;
    }
    else
    {
        cout<<"------------------------------Thank You . Program Ends Here. ------------------------------------------";
        return 0;
    }
}
