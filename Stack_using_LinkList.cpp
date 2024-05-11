#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *ptr;
}*s;

class LLStack
{
    private:
    struct node *tmp,*fnode,*gnode;
    
    int num;
    public:
    LLStack(int n)
    {
        s=(struct node*)malloc(sizeof(struct node));
        if(s==NULL)
        {
            cout<<"Memory not allocated";
        }
        else
        {
            cout<<"Enter value of node 1 : ";
            cin>>num;
            s->data=num;
            s->ptr=NULL;
            tmp=s;
            
            
                for(int i=2;i<=n;i++)
                {
                    fnode=(struct node* )malloc(sizeof(struct node));
            if(fnode==NULL)
            {
                cout<<"Memory not allocated .";
            }
            else
            {
                    cout<<"Enter value of node "<<i<<" : ";
                    cin>>num;
                    fnode->data=num;
                    fnode->ptr=NULL;
                    tmp->ptr=fnode;
                    tmp=tmp->ptr;
                }
            }
        }
    }

    void display()
    {
        tmp=s;
        int i=1;
        while(tmp != NULL)
        {
            cout<<"The value at node "<<i<<" is : "<<tmp->data<<endl ;
            tmp=tmp->ptr;
            i++;
        }
        
    }

    int push()
    {
        cout<<"Enter the value of element you want to push : ";
        cin>>num;
        tmp=s;
        struct node* tmp1;
        tmp1=s;
        tmp1=tmp1->ptr;
        fnode=(struct node *)malloc(sizeof(struct node));
        if(fnode==NULL)
        {
            cout<<"Memory not allocated";
        }
        else
        {
            fnode->data=num;
            fnode->ptr=NULL;
            tmp->ptr=fnode;
            fnode->ptr=tmp1;
        }
        
        display();
    }

    int pop()
    {
        tmp=s;
        struct node *tmp1;
        tmp1=s;
        tmp1=tmp1->ptr;
        int item;
        item =tmp1->data;
        tmp1=tmp1->ptr;
        tmp->ptr=tmp1;
        cout<<"After pop the list is :"<<endl;
        display();
        return item;
    }

    int status()
    {
        tmp=s;
        if(tmp==NULL)
        {
            cout<<"Stack is empty."<<endl;
        }
        else 
        {
            int nodecount=0;
            while(tmp != NULL)
            {
                nodecount++;
                tmp=tmp->ptr;
            }
            cout<<"The Stack has "<<nodecount<<" elements."<<endl;
        }
        return 0;
    }
};

int main()
{
    int n;
    LLStack l(5);
    l.display();
    l.push();
    n=l.pop();
    cout<<"The popped element is : "<<n<<endl;
    l.status();
    return 0;
}
