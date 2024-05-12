//If we include tail pointer deletion and insertion functions at front take place in O(1) time complexity .
//If we use Circular Double Link List the insertions and deletions at front and back take place in O(1) time complexity.

//Time Complexity for this Code :-
//Insertions and Deletions at front end and back end are O(N).
//Search Function has worst time complexity O(N) and best time complexity O(1).

#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class CLinkList
{
private:
    node *head;

public:
    CLinkList()
    {
        head = NULL;
    }
    void insert_front(int val)
    {
        node *tmp = new node(val);
        tmp->next = head;
        if (head == NULL)
        {
            head = tmp;
            head->next = head;
        }
        else
        {
            node *tmp1 = head;
            while (tmp1->next != head)
            {
                tmp1 = tmp1->next;
            }
            tmp1->next = tmp;
            tmp->next = head;
            head = tmp;
        }
    }

    void insert_back(int val)
    {
        node *tmp = new node(val);
        if (head == NULL)
        {
            head = tmp;
            head->next = head;
        }
        else if (head->next == head)
        {
            delete head;
            head = NULL;
        }
        else
        {
            node *tmp1 = head;
            while (tmp1->next != head)
            {
                tmp1 = tmp1->next;
            }
            tmp1->next = tmp;
            tmp->next = head;
        }
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "List is Empty .";
        }
        else
        {
            node *tmp = head;
            cout << "Cirular Linked List : ";
            while (tmp->next != head)
            {
                cout << tmp->data << " ";
                tmp = tmp->next;
            }
            cout << tmp->data << " ";
        }
    }

    void delete_front()
    {
        if (head == NULL)
        {
            cout << "List is empty ." << endl;
        }
        else if (head->next ==head)
        {
            delete head;
            head=NULL;
        }
        else
        {
            node *tmp = head;
            while (tmp->next != head)
            {
                tmp = tmp->next;
            }
            head = head->next;
            tmp->next = head;
        }
    }

    void delete_back()
    {
        if (head == NULL)
        {
            cout << "List is empty ." << endl;
        }
        else if(head->next==head)
        {
            delete head;
            head=NULL;
        }
        else
        {
            node *tmp = head;
            while (tmp->next->next != head)
            {
                tmp = tmp->next;
            }
            delete tmp->next;
            tmp->next = head;
        }
    }

    void search(int val)
    {
        node *tmp=head;
        while(tmp->next!=head)
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
    CLinkList c;
    int num, num1, n;
    label:
    cout << "Enter 0 to insert\nEnter 1 to delete\nEnter 2 to display\nEnter 3 to search\nEnter 4 to exit\n\n";
    cin >> num;
    if (num == 0)
    {
        cout << "Enter the value to be inserted : ";
        cin >> n;
        cout << "Enter 0 to insert at front\nEnter 1 to insert at back\n\n";
        cin >> num1;
        if (num1 == 0)
        {
            c.insert_front(n);
        }
        else
        {
            c.insert_back(n);
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
            c.delete_front();
        }
        else
        {
            c.delete_back();
        }
        cout << endl;
        goto label;
    }
    else if (num == 2)
    {
        c.display();
        cout << endl;
        goto label;
    }
    else if (num==3)
    {
        cout<<"Enter the number you want to search : ";
        cin>>num1;
        c.search(num1);
        cout<<endl<<endl;
        goto label;
    }
    else  if(num == 4)
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
