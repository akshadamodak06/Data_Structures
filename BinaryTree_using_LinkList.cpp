#include <iostream>
using namespace std;
#include <queue>
class node
{
public:
    int data;
    node *left;
    node *right;
    node *parent;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class IBT
{
private:
    node *root;

public:
    IBT()
    {
        root = NULL;
    }
    void insert(int val)
    {
        node *n = new node(val);
        if (root == NULL)
        {
            root = n;
            return;
        }

        else
        {
            queue<node *> q;
            q.push(root);
            while (!q.empty())
            {

                node *tmp = q.front();
                q.pop();
                if (tmp->left == NULL)
                {
                    tmp->left = n;
                    n->parent=tmp;
                    return;
                }
                else
                {
                    q.push(tmp->left);
                }

                if (tmp->right == NULL)
                {
                    tmp->right = n;
                    n->parent=tmp;
                    return;
                }
                else
                {
                    q.push(tmp->right);
                }
            }
        }
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

    void remove(int val)
    {
        if(root == NULL)
        {
            return;
        }
        if(root->left==NULL && root ->right==NULL)
        {
            if(root->data==val)
            {
                root==NULL;
                return; 
            }
        }
            queue <node *> q;
            q.push(root);
            node *key,*tmp;
            while(!q.empty())
            {
                tmp=q.front();
                q.pop();
                if(tmp->data== val)
                {
                    key=tmp;
                }
                if(tmp->left)
                {
                    q.push(tmp->left);
                }
                if(tmp->right)
                {
                    q.push(tmp->right);
                }
            }
            if(key != NULL )
            {
                int x= tmp->data;
                key->data=x;
                node *temp=tmp;
                temp=temp->parent;
                if(temp->right !=NULL)
                {
                    temp->right=NULL;
                }
                else
                {
                    temp->left=NULL;
                }
                delete tmp;
            }
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
    IBT i;
    i.insert(1);
    i.insert(2);
    i.insert(3);
    i.insert(4);
    i.insert(5);
    i.insert(6);
    i.insert(7);

    i.display();

    i.remove(2);

    i.display();
}
