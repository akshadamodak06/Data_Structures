#include<iostream>
using namespace std;
class node 
{
    public:
    int data;
    node *left;
    node *right;
    node *parent;
    node(int val)
    {
        data=val;
        left=right=parent=NULL;
    }
};

class IBST
{
    private:
    node *root;
    public:
    IBST()
    {
        root = NULL;
    }
    void insert(int val)
    {
        node *n = new node (val);
        if(root==NULL)
        {
            root=n;
            return;
        }
        node *tmp=root;
        while(1)
        {
            if(val>tmp->data)
            {
                if(tmp->right == NULL)
                {
                    tmp->right=n;
                    n->parent=tmp;
                    return;
                }
                else
                {
                    tmp=tmp->right;
                }
            }
            else
            {
                if(tmp->left == NULL)
                {
                    tmp->left=n;
                    n->parent=tmp;
                    return;
                }
                else
                {
                    tmp=tmp->left;
                }
            }

        }
    }

    int search(int val)
    {
        if(root == NULL)
        {
            return 0;
        }
        if(root->left == NULL && root->right ==NULL)
        {
            if(root->data== val)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        node *tmp=root;
        while(1)
        {
            if(tmp->left==NULL && tmp->right==NULL)
            {
                if(tmp->data== val)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
            if(val== tmp->data)
            {
                return 1;
            }
            else if(val>tmp->data)
            {
                if(tmp->right)
                {
                    tmp=tmp->right;
                }
                else
                {
                    return 0;
                }
                
            }
            else
            {
                if(tmp->left)
                {
                    tmp=tmp->left;
                }
                else
                {
                    return 0;
                }
            }
            
        }
    }

    node *in_succ(node *nd)
    {
        while(nd->left != NULL)
        {
            nd=nd->left;
        }
        return nd;
    }

    node *search1(node *nd,int val)
    {
        if(nd->data==val)
        {
            return nd;
        }
        else
        {
            if(val>nd->data)
            {
                search1(nd->right,val);
            }
            else
            {
                search1(nd->left,val);
            }

        }
    }

    // void remove(int val)
    // {
    
    //         node *del=search1(root,val);
    //         node *in_succ1,*in_pred1;
    //         if(del->right==NULL && del->left==NULL)
    //         {
    //             in_succ1=del;
    //         }
    //         else
    //         {
    //             in_succ1=in_succ(del->right);
    //         }
    //         if(del->right==NULL && del->left==NULL)
    //         {
    //             in_pred1=del;
    //         }
    //         else
    //         {
    //             in_pred1=in_pred(del->left);   
    //         }
    //         if(in_succ1->left==NULL && in_succ1->right==NULL )
    //         {
    //             node* parent1=in_succ1->parent;
    //             if(parent1->data > in_succ1->data)
    //             {
    //                 parent1->left=NULL;
    //             }
    //             else
    //             {
    //                 parent1->right=NULL;
    //             }   
    //             del->data=in_succ1->data;            
    //             delete in_succ1;
    //             return ;
    //         }
    //         if(in_pred1->left==NULL && in_pred1->right==NULL )
    //         {
    //             node* parent1=in_pred1->parent;
    //             cout<<parent1->data;
    //             if(parent1->data > in_pred1->data)
    //             {
    //                 parent1->left=NULL;
    //             }
    //             else
    //             {
    //                 parent1->right=NULL;
    //             }
    //             del->data=in_pred1->data;               
    //             delete in_pred1;
    //             return ;
    //         }

    // }

    node* remove1(int val)
    {
        remove(root,val); 
    }

    node *remove(node *nd ,int val)
    {
        if(nd==NULL)
        {
            return NULL;
        }
        else if(val<nd->data)
        {
            nd->left=remove(nd->left,val);
        }
        else if(val>nd->data)
        {
            nd->right=remove(nd->right,val);
        }
        else
        {
            if(nd->left==NULL || nd->right== NULL)
            {
                if(nd->left==NULL)
                {
                    nd=nd->right;
                }
                if(nd==NULL)
                {
                    return nd;
                }
            }

        }

        node* in_succ1= in_succ(nd->right);
        nd->data=in_succ1->data;
        nd->right=remove(nd->right,in_succ1->data);
    }

     void inorder(node *nd)
    {
        if(nd)
        {
            inorder(left1(nd));
            cout << nd->data << " ";
            inorder(right1(nd));
        }
    }

    void preorder(node *nd)
    {
        if(nd)
        {
            cout<<nd->data<<" ";
            preorder(left1(nd));
            preorder(right1(nd));
        }
    }

    void postorder(node *nd)
    {
        if(nd)
        {
            postorder(left1(nd));
            postorder(right1(nd));
            cout<<nd->data<<" ";
        }
    }

    node *left1(node *nd)
    {
        if (nd)
        {
            return nd->left;
        }
        else
        {
            return NULL;
        }
    }

    node *right1(node *nd)
    {
        if (nd)
        {
            return nd->right;
        }
        else
        {
            return NULL;
        }
    }

    void display()
    {
        cout << "Inorder : ";
        inorder(root);
        cout<<endl;
        cout << "Preorder : ";
        preorder(root);
        cout<<endl;
        cout << "Postorder : ";
        postorder(root);
        cout<<endl;
    }

    

};


int main()
{
    IBST i;
    i.insert(100);
    i.insert(500);
    i.insert(20);
    i.insert(10);
    i.insert(30);
    i.display();
    i.insert(40);
    i.display();
    i.remove1(100);
    i.display();



}
