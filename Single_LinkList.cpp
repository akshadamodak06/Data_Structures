//Time Complexity for this code :-
//Insertion at front end and Deletion at front end are O(1).
//Insertion at back end and Deletion at back end are O(N).
//Search Function has worst case time complexity O(N) and best case time complexity O(1).

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

    void search(int val)
    {
        node *tmp=head;
        while(tmp->next != NULL)
        {
            if(tmp->data==val)
            {
                cout<<"Value "<<val<<" exists in the Circular Linked List .";
                return;
            }
        }
        if(tmp->data==val)
        {
            cout<<"Value "<<val<<" exists in the Circular Linked List .";
        }
        else
        {
            cout<<"Value "<<val<<" does not exist in the Circular Linked List .";
        }

    }
};

int main()
{
    LinkList l;
    int num,num1,n;
    label:
    cout<<"Enter 0 to insert\nEnter 1 to delete\nEnter 2 to display\nEnter 3 to search\nEnter 4 to exit\n\n";
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
    else if (num==3)
    {
        cout<<"Enter the number you want to search . ";
        cin>>num1;
        l.search(num1);
        cout<<endl;
        goto label;
    }
    else if(num==4)
    {
        cout<<"------------------------------Thank You . Program Ends Here. ------------------------------------------";
        return 0;
    }
    else
    {
        cout<<"Enter valid number .";
        cout<<endl;
        goto label;
    }
}
