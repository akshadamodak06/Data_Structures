#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *ptr;
}*s;

class LinkedList
{
    private:
    int n;
    int num;
    struct node *fnode,*tmp,*gnode;
    public :
    LinkedList(int n)
    {
        s=(struct node*)malloc(sizeof(struct node));
        tmp=nullptr;
        fnode=nullptr;
        gnode=nullptr;
        if(s==NULL)
        {
            cout<<"Memory not allocated."<<endl;
        }
        else
        {
            cout<<"Input data for first node :";
            cin>>num;
            s->data=num;
            s->ptr=NULL;
            tmp=s;
            for(int i=1;i<n;i++)
            {
            fnode=(struct node*)malloc(sizeof(struct node));
            if(fnode == NULL)
            {
                cout<<"Memory not allocated"<<endl;
            }
            else
            {
                cout<<"Input data for "<<i+1<<" node :";
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
        struct node *s2;
        s2=s;
        while(s2!=NULL)
        {
            cout<<s2->data<<endl;
            s2=s2->ptr;
        }

    }
    int addbb()
    {
        cout<<"Enter the value for first node : ";
        cin>>num;
        gnode=(struct node*)malloc(sizeof(struct node));
        if(gnode==NULL)
        {
            cout<<"Memory not allocated"<<endl;
        }
        else{
        
        gnode->data=num;
        gnode->ptr=s;
        s=gnode;        
        cout<<"The updated list is : "<<endl;
        display();
        }  
        return 0;
    }
    
    int addee()
    {
        cout<<"Enter value for the last node : ";
        cin>>num;
        gnode=(struct node *)malloc(sizeof(struct node));
        if(gnode == NULL)
        {
            cout<<"Memory not allocated";
        }
        else
        {
            gnode->data=num;
            gnode->ptr=NULL;
            tmp=nullptr;
            tmp=s;
            while(tmp->ptr != NULL)
            {
                tmp=tmp->ptr;
            }
            tmp->ptr=gnode;
            cout<<"The updated list is : "<<endl;
            display(); 
            return 0;

        }
    }

    int addan()
    {
        cout<<"Enter the value after which you want to add ";
        cin>>num;
        cout<<"Enter the value you want to add :";
        int n1;
        cin>>n1;
        tmp=s;
        struct node* tmp1;
        tmp1=s;
        tmp1=tmp1->ptr;
        gnode=(struct node*)malloc(sizeof(struct node));
        if(gnode ==NULL)
        {
            cout<<"Memory not allocated";
        }
        else
        {
            gnode->data=n1;
            while(tmp->data != num)
            {
                tmp=tmp->ptr;
                tmp1=tmp1->ptr;
            }
            tmp->ptr=gnode;

            gnode->ptr=tmp1;
            cout<<"The updated list is :"<<endl;
            display();
        }
        return 0;
    }
    
    int addbn()
    {
        cout<<"Enter the value before which you to add : ";
        cin>>num;
        cout<<"Enter the value you want to add : ";
        int n1;
        cin>>n1;
        gnode=(struct node* )malloc(sizeof(struct node));
        if(gnode ==NULL)
        {
            cout<<"Memory not allocated";
        }
        else
        {
            gnode->data=n1;
            tmp=s;
            struct node*tmp1;
            tmp1=s;
            tmp1=tmp1->ptr;
            while(tmp1->data != num)
            {
                tmp=tmp->ptr;
                tmp1=tmp1->ptr;
            }
            tmp->ptr=gnode;
            gnode->ptr=tmp1;
            cout<<"The updated list is : "<<endl;
            display();
        }

    }
    int rembb()
    {
        tmp=s;
        tmp=tmp->ptr;
        s=tmp;
        display();
        return 0;   
    }
    int remee()
    {
        tmp=s;
        struct node *tmp1;
        tmp1=nullptr;
        tmp=tmp->ptr;
        tmp1=s;
        while(tmp->ptr != NULL)
        {
            tmp=tmp->ptr;
            tmp1=tmp1->ptr;
        }
        tmp1->ptr=NULL;
        display();
    }

    int remon()
    {
        struct node *tmp1;
        cout<<"Enter the value you want to remove : ";
        cin>>num;
        tmp1=s;
        tmp1=tmp1->ptr;
        tmp=s;
        while(tmp1->data != num)
        {
            tmp1=tmp1->ptr;
            tmp=tmp->ptr;
        }
        tmp1=tmp1->ptr;
        tmp->ptr=tmp1;
        display(); 
    }

    int reman()
    {
        struct node *tmp1;
        cout<<"Enter the value after which the node is to be removed : ";
        cin>>num;
        tmp1=s;
        tmp=s;
        tmp1=tmp1->ptr;
        while(tmp->data != num)
        {
            tmp=tmp->ptr;
            tmp1=tmp1->ptr;
        }
        tmp1=tmp1->ptr;
        tmp->ptr=tmp1;
        display();
    }
};




int main()
{
    LinkedList l1(5);
    l1.display();
    l1.addbb();
    l1.addee();
    l1.addan();
    l1.addbn();
    l1.rembb();
    l1.remee();
    l1.remon();
    l1.reman();
    return 0;
}
