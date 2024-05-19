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

class PriorityQueue
{
private:
    node *head;

public:
    PriorityQueue()
    {
        head = NULL;
    }
    
     void enqueue(int val) {
        node* tmp = new node(val);
        if (head == nullptr || head->data > val)
         {
            tmp->next = head;
            head = tmp;
        } 
        else 
        {
            node* current = head;
            while (current->next != nullptr && current->next->data <= val) 
            {
                current = current->next;
            }
            tmp->next = current->next;
            current->next = tmp;
        }
    }

    void dequeue()
    {
        if (head == NULL)
        {
            cout << "List is empty ." << endl;
        }
        else if (head->next == NULL)
        {
            delete head;
            head = NULL;
        }
        else
        {
            head = head->next;
        }
    }

    int top()
    {
        return head->data;
    }

   int size() {
    if (head == nullptr) 
    {
        return 0;
    } 
    else
    {
        node* tmp = head;
        int count = 0;
        while (tmp != nullptr) {
            count++;
            tmp = tmp->next;
        }
        return count;
    }
}


    bool empty()
    {
        if (head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "Queue is empty. " << endl;
        }
        else
        {
            node *tmp = head;
            while (tmp->next != NULL)
            {
                cout << tmp->data << " ";
                tmp=tmp->next;
            }
            cout << tmp->data << " " << endl;
        }
    }
};

int main()
{
    PriorityQueue q;
    int num, n;
label:
    cout << "Enter 0 to enqueue\nEnter 1 to dequeue\nEnter 2 to display top element\nEnter 3 to display size\nEnter 4 to display Queue\nEnter 5 to check whether queue is empty\nEnter 6 to exit\n\n";
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
        cout << "The front element is : " << q.top() << endl;
        cout << endl;
        goto label;
    }
    else if (num == 3)
    {
        cout << "Size of Queue is : " << q.size() << endl;
        cout << endl;
        goto label;
    }
    else if (num == 4)
    {
        q.display();
        cout << endl;
        goto label;
    }
    else if (num == 5)
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
    else if (num == 6)
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
