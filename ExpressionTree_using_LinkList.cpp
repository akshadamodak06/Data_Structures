#include<iostream>
#include <stack>
using namespace std;
class node
{
    public:
    int data;
    node *left ,*right ;
    node *parent;
    node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
        parent=NULL;
    }
};
class ET
{
    private:
    node *root;
    stack <node *> s1;
    public:
    void tree(string s)
    {
        int i=0;
        while(s[i] != '\0')
        {
            if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
            {
                node *fnode=s1.top();
                s1.pop();
                node *gnode=s1.top();
                s1.pop();
                node *tmp;
                tmp=new node(s[i]);
                tmp->right=fnode;
                tmp->left=gnode;
                tmp->parent =NULL;
                fnode->parent=tmp;
                gnode->parent=tmp;
                root=tmp; 
                s1.push(tmp);               
            }
            else
            {
                cout<<"a";
                node *fnode=new node(s[i]);
                cout<<"b";
                s1.push(fnode);
                cout<<"c";
            }
            i++;
        }
    }

    
    node *left1(node *n)
    {
        if(n->left==nullptr)
        {
            return NULL;
        }
        else
        {
            return n->left;
        }
    }

    node *right1(node *n)
    {
        if(n->right==nullptr)
        {
            return NULL;
        }
        else
        {
            return n->right;
        }
    }

    void inorder(node *nd)
    {
        if(nd!= NULL)
        {
            inorder(left1(nd));
            cout<<(char)nd->data<<" ";
            inorder(right1(nd));
        }
    }

    void preorder(node *nd)
    {
        if(nd!= NULL)
        {
            cout<<(char)nd->data<<" ";
            preorder(left1(nd));
            preorder(right1(nd));
        }
    }

    void postorder(node *nd)
    {
         if(nd!=NULL)
        {
            postorder(left1(nd));
            postorder(right1(nd));
            cout<<(char)nd->data<<" ";
        }
    }

    void display()
    {
        cout<<"Preorder : ";
        preorder(root);
        cout<<endl;
        cout<<"Postorder : ";
        postorder(root);
        cout<<endl;
        cout<<"Inorder : ";
        inorder(root);
        cout<<endl;
    }

    void evaluate(string s)
    {
        stack <int> opndstk;
        int i=0;
        while(s[i] != '\0')
        {
            if(s[i]>=48 && s[i]<=57 )
            {
                opndstk.push(s[i]);
            }
            else
            {
                int a= opndstk.top()-48;
                opndstk.pop();
                int b= opndstk.top()-48;
                opndstk.pop();
                int value;
                if(s[i]=='+')
                {
                    value=a+b;
                } 
                else if(s[i]=='-')
                {
                    value=a-b;
                }
                else if(s[i]=='*')
                {
                    value=a*b;
                }
                else if(s[i]=='/')
                {
                    value=a/b;
                }
                opndstk.push(value+48);
            }
            i++;
        }
         
        cout<<"Evaluation : "<<opndstk.top()-48<<endl;
        opndstk.pop();
    }

    int evaluate2()
    {
        int a=evaluate1(root);
        return a;
    }

    int evaluate1(node *nd)
    {
        if(nd->left == NULL && nd->right ==NULL)
        {
            return nd->data -48;
        }   
        else
        {
            int lvalue,rvalue;
            lvalue=evaluate1(nd->left);
            rvalue=evaluate1(nd->right);
            if(nd->data=='+')
            {
                return lvalue+rvalue;
            }
            else if(nd->data=='-')
            {
                return lvalue-rvalue;
            }
            else if(nd->data=='*')
            {
                return lvalue*rvalue;
            }
            else if(nd->data=='/')
            {
                return lvalue/rvalue;
            }
        }     
    }

};

int main()
{
    string s;
    s="359+2*+";
    ET e;
    e.tree(s);
    cout<<endl;
    e.display();
    e.evaluate(s);
    int a= e.evaluate2();
    cout<<"Evaluation : "<<a<<endl;
}
