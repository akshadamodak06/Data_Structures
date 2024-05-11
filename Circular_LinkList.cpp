#include <iostream>
#include <stdlib.h>
using namespace std;
struct node
{
    int data;
    struct node *ptr;
}*s;

class CLinkedList
{
    private:
    struct node *fnode,*tmp,*gnode;
    int num,n;
    public:
    CLinkedList(int n)
    {
        fnode=nullptr;
        gnode=nullptr;
        tmp=nullptr;
        s=(struct node*)malloc(sizeof(struct node));
        if(s==NULL)
        {
            cout<<"Memory not allocated"<<endl;
        }
        else
        {
            
            cout<<"Enter the value of first node :";
            cin>>num;
            s->data=num;
            tmp=s;
            struct node *tmp1;
            tmp1=s;
            for(int i=2;i<=n;i++)
            {
                fnode=(struct node *)malloc(sizeof(struct node));
                if(fnode==NULL)
                {
                    cout<<"Memory not allocated.";
                }
                else
                {
                    cout<<"Enter the value of :"<<i<<" node : ";
                    cin>>num;
                    if(i==5)
                    {
                        fnode->data=num;
                        fnode->ptr=NULL;
                        tmp->ptr=fnode;
                        tmp=tmp->ptr;
                    }
                    fnode->data=num;
                    fnode->ptr=NULL;
                    tmp->ptr=fnode;
                    tmp=tmp->ptr;
                   
                    
                }
            }
            tmp->ptr=tmp1;
            
        }
    }
    void display()
    {
        struct node *tmp2;
        tmp2=s;
        int i=1;
        cout<<"The value of node 1 is : "<<tmp2->data<<endl;
        tmp2=tmp2->ptr;
        while(tmp2->ptr != s->ptr)
        {
            i++;
            
            cout<<"The value of node "<<i<<" is : "<<tmp2->data<<endl;
            // if(i==5)
            // {
            //     tmp2=tmp2->ptr;
            //     cout<<"The value of node 6 is : "<<tmp2->data<<endl;
            //     i++;
            // }
            tmp2=tmp2->ptr;
           
        }
    }
    void addab()
    {
        tmp=s;
        struct node *tmp1;
        tmp1=s;
        tmp1=tmp1->ptr;
        cout<<"Enter the value of the node : ";
        cin>>num;
        cout<<"hi";
        gnode = (struct node*)malloc(sizeof(struct node));
        cout<<"hi";
        if(gnode==NULL)
        {
            cout<<"Memory not allocated : ";

        }
        else
        {
            cout<<"hi";
            gnode->data=num;
            cout<<"hi";
            tmp->ptr=gnode;
            cout<<"hi";
            gnode->ptr=tmp1;
            display();          
        }
    }
};


int main()
{
    CLinkedList l1(5);
    l1.display();
    l1.addab();
    return 0;
} 
