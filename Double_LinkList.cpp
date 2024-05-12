//Time Complexity for this code :-
//Insertion and Deletions at front end and back end are O(1).
//Display forward and Display backward have O(N) time complexity.
// Search function has worst case time complexity of O(N) and best case time complexity of O(1).

#include<iostream>
using namespace std;
class node 
{
    public:
    int data;
    node* left;
    node *right;
    node(int val)
    {
        data=val;
        left=right=NULL;
    }
};

class DLinkList
{
    private:
    node *head,*tail;
    public:
    DLinkList()
    {
        head=tail=NULL;
    }
    void insert_front(int val)
    {
        node *tmp=new node(val);
        if(head==NULL)
        {
            head=tail=tmp;
        }
        else
        {
            tmp->right=head;
            head->left=tmp;
            head=tmp;
        }
    }

    void insert_back(int val)
    {
        node *tmp=new node(val);
        if(head==NULL)
        {
            head=tail=tmp;
        }
        else
        {
            tmp->left=tail;
            tail->right=tmp;
            tail=tmp;
        }
    }

    void delete_front()
    {
        if(head==NULL)
        {
            cout<<"List is empty."<<endl;
        }
        else if (head == tail)
        {
            delete head;
            delete tail;
            head=NULL;
            tail=NULL;
        }
        else
        {
            head=head->right;  
            head->left=NULL;          
        }
    }

     void delete_back()
    {
        if(head==NULL)
        {
            cout<<"List is empty."<<endl;
        }
        else if (head == tail)
        {
            delete head;
            delete tail;
            head=NULL;
            tail=NULL;
        }
        else
        {
            tail=tail->left; 
            tail->right=NULL;           
        }
    }

    void display_f()
    {
        node *tmp=head;
        cout<<"Double LinkList Forward : ";
        while(tmp->right != NULL)
        {
            cout<<tmp->data<<" ";
            tmp=tmp->right;
        }
        cout<<tmp->data<<" "; 
    }

    void display_b()
    {
        node *tmp=tail;
        cout<<"Double LinkList Backward : ";
        while(tmp->left != NULL)
        {
            cout<<tmp->data<<" ";
            tmp=tmp->left;
        }
        cout<<tmp->data<<" "; 
    }

    void search(int val)
    {
        node *tmp=head;
        while(tmp->right != NULL)
        {
            if(tmp->data==val)
            {
                cout<<"Value "<<val<<" exists in the Circular Linked List .";
                return;
            }
            tmp=tmp->right;
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
    DLinkList d;
    int num, num1, n;
    label:
    cout << "Enter 0 to insert\nEnter 1 to delete\nEnter 2 to display list forward \nEnter 3 to display list backward \nEnter 4 to search\nEnter 5 to exit\n\n";
    cin >> num;
    if (num == 0)
    {
        cout << "Enter the value to be inserted : ";
        cin >> n;
        cout << "Enter 0 to insert at front\nEnter 1 to insert at back\n\n";
        cin >> num1;
        if (num1 == 0)
        {
            d.insert_front(n);
        }
        else
        {
            d.insert_back(n);
        }
        cout << endl;
        goto label;
    }
    else if (num == 1)
    {
        cout << "Enter 0 to delete at front\nEnter 1 to delete at back ";
        cin >> num1;
        if (num1 == 0)
        {
            d.delete_front();
        }
        else
        {
            d.delete_back();
        }
        cout << endl;
        goto label;
    }
    else if (num == 2)
    {
        d.display_f();
        cout << endl;
        goto label;
    }
    else if (num == 3)
    {
        d.display_b();
        cout << endl;
        goto label;
    }
    else if (num==4)
    {
        cout<<"Enter the number you want to search : ";
        cin>>num1;
        d.search(num1);
        cout<<endl<<endl;
        goto label;
    }
    else  if(num == 5)
    {
        cout << "------------------------------Thank You . Program Ends Here. ------------------------------------------";
        return 0;
    }
    else
    {
        cout<<"Enter valid number";
        cout<<endl<<endl;
        goto label;
    }
}
