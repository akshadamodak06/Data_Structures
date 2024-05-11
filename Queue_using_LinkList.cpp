#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
}*s;
class LLQueue
{
    private:
    struct node *front=NULL,*rear=NULL,*tmp,*fnode;
    public:   
    int enqueue()
    {
        int value;
        
        if(rear==NULL)
        {
            s=(struct node *)malloc(sizeof(struct node));
            if(s==NULL)
            {
                cout<<"Memory not allocated : ";
            }
            else
            {
                cout<<"Enter value of element ";
                cin>>value;
                s->data=value;
                s->next=NULL;
                front=s; 
                rear=s;               
            }
        }
        else
        {
            cout<<"Enter the value of the element ";
            cin>>value;
            fnode=(struct node *)malloc(sizeof(struct node));
            if(fnode==NULL)
            {
                cout<<"Memory not allocated";
            }
            else
            {
                fnode->data=value;
                fnode->next=NULL;
                rear->next=fnode;
                rear=rear->next;
            }
        }
    }

    int dequeue()
    {
        int item;
        if(rear==NULL)
        {
            cout<<"No elements remained for dequeue";
        }
        else
        {
            item=s->data;
            s=s->next;
            front=s;
        }
        return item;
    }
    
    void display()
    {
        tmp=s;
        int i=1;
        while(tmp != NULL)
        {
            cout<<"The element "<<i<<" is : "<<tmp->data<<endl;
            tmp=tmp->next;
            i++;
        }
    }
};

int main()
{
    LLQueue q;
    int ch;
    cout<<"1) Insert element to queue"<<endl;
    cout<<"2) Delete element from queue"<<endl;
    cout<<"3) Display all the elements of queue"<<endl;
    cout<<"4) Exit"<<endl;
    do {
      cout<<"Enter your choice : ";
      cin>>ch;
      switch (ch) {
         case 1: q.enqueue();
         break;
         case 2: q.dequeue();
         break;
         case 3: q.display();
         break;
         case 4: cout<<"Exit"<<endl;
         break;
         default: cout<<"Invalid choice"<<endl;
      }
   } while(ch!=4);
   return 0;
    
}
