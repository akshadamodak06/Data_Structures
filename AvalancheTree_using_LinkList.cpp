#include <iostream>
using namespace std;
class node 
{
    public:
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data=val;
        left=right=NULL;
    }
};
class AVL
{
    public:
    node *root;
    AVL()
    {
        root=NULL;
    }

    void insert1(int val)
    {
        root=insert(root,val);
    }

    node *insert(node *nd,int val)
    {
        if(nd==NULL)
        {
            nd=new node(val);
            return nd;
        }
        else
        {
            if(val>nd->data)
            {
                nd->right=insert(nd->right,val);
            }
            else if(val<nd->data)
            {
                nd->left=insert(nd->left,val);
            }
        }

        int balance = bf(nd);
        if(balance<-1)
        {
            if(val>nd->right->data)
            {
                return left_rotation(nd);
            }
            else
            {
                nd->right=right_rotation(nd->right);
                return left_rotation(nd);                
            }
        }
        else if(balance > 1)
        {
            if(val<nd->left->data)
            {
                return right_rotation(nd);
            }
            else
            {
                nd->left=left_rotation(nd->left);
                return right_rotation(nd);
            }
        }

        return nd;
    }

    node* in_succ(node* nd){
        node* current = nd;
        
        while(current->left != NULL){
            current = current->left;
        }
        return current;
    }

    void remove1(int val)
    {
        root=remove(root,val);
    }

    node * remove(node *nd,int val)
{
    if(nd==NULL)
    {
        return NULL;
    }
    else if(val < nd->data)
    {
        nd->left=remove(nd->left,val);
    }
    else if(val > nd->data)
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
            return nd;
        }
        node *in_succ1=in_succ(nd->right);
       
        nd->data=in_succ1->data;
        
        nd->right=remove(nd->right,in_succ1->data);
    }
    nd= balance(nd);
    return nd;
}


    node *balance(node *nd)
    {
        int balance = bf(nd);
        if(balance< -1)
        {
            if(bf(nd->right)>1)
            {
                nd->right=right_rotation(nd->right);
                return left_rotation(nd);
            }
            else
            {
                return left_rotation(nd);
            }
        }
        else if(balance>1)
        {
            if(bf(nd->left)<-1)
            {
                nd->left=left_rotation(nd->left);
                return right_rotation(nd);
            }
            else
            {
                return right_rotation(nd);
            }
        }
        return nd;
    }

    node * left_rotation(node *nd)
    {
        node *pivot= nd->right;
        node *hold=pivot->left;
        pivot->left=nd;
        nd->right=hold;
        return pivot;
    }

    node *right_rotation(node *nd)
    {
        node *pivot=nd->left; 
        node *hold=pivot->right;
        pivot->right=nd;
        nd->left=hold;
        return pivot;
    }

    int max(int a,int b)
    {
        if(a>=b)
        {
            return a;
        }
        else
        {
            return b;
        }
    }

    int height(node *nd)
    {
        if(nd==NULL)
        {
            return 0;
        }
        else
        {
            return max(height(nd->left),height(nd->right))+1;
        }
    }

    int bf(node *nd)
    {
        return height(nd->left)-height(nd->right);
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
    AVL a;
    a.insert1(8);
    a.insert1(9);
    a.insert1(10);
    a.insert1(2);
    a.insert1(1);
    a.insert1(5);
    a.insert1(3);
    a.insert1(6);
    a.insert1(4);
    a.insert1(7);
    a.insert1(11);
    a.insert1(12);
    a.display();
    a.remove(a.root,11);
    a.display();

}
