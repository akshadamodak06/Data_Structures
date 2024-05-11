#include <iostream>
#include <queue>
using namespace std;
class node 
{
    public:
    int data;
    node *left;
    node *right;
    node *parent;
    int lvalue;
    int rvalue;
    node (){}
    node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
        parent=NULL;
        lvalue=0;
        rvalue=0;
    }
};

class TBT
{
    public:
    node *root =NULL;
    int *arr;
    int n;
    public:
    TBT()
    {
        root=NULL;
    }    
    void construct(int val)
    {
        node *n=new node(val);
        n->lvalue=1;
        n->rvalue=1;
        int a=0;
        node *tmp1;
        node *tmp;
        if(root==NULL)
        {
            root=n;
            return;
        }
       queue<node *>q;
       q.push(root);
       while(!q.empty())
       {
            tmp=q.front();
            q.pop();
            if(tmp->left==NULL)
            {
                a=1;
                break;
            }
            else
            {
                a=2;
                q.push(tmp->left);
            }
            if(tmp->right==NULL)
            {
                break;
            }
            else
            {
                q.push(tmp->right);
            }
       }

       if(a==1)
       {
           tmp->right=n;
           tmp->left=n->left;
           n->left=tmp;
           tmp->lvalue=0;
       }
       if(a==2)
       {
        tmp->right=n->right;
        tmp->left=n;
        n->right=tmp;
        tmp->rvalue=0;
       }


    }

    node *in_succ(node *nd)
    {
        if(nd==NULL)
        {
            return NULL;
        }
        while(nd->left !=NULL)
        {
            nd=nd->left;
        }
        return nd;
    }

    void inorder(node *nd)
    {
        node *r=in_succ(nd);
        while(r!=NULL)
        {
            cout<<r->data<<" ";
            if(r->rvalue !=0)
            {
                r=r->right;
            }
            else
            {
                r=in_succ(r->right);
            }
        }
    }

    
};

int main()
{
    TBT t;
    t.construct(20);
    t.construct(10);
    t.construct(30);
    t.construct(5);
    t.construct(16);
    t.construct(14);
    t.construct(17);
    t.construct(13);

    t.inorder(t.root);


}



