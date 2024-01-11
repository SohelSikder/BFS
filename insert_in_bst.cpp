#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
        int val;
        Node * left;
        Node * right;
    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
Node* input_tree(){
    int value;
    cin>>value;
    Node * root;
    if(value==-1){
        root = NULL;
    }else{
        root = new Node(value);
    }
    queue<Node * >q;
    if(root){
        q.push(root);
    }
    while (!q.empty()){
        Node * p = q.front();
        q.pop();
        int l , r;
        cin>>l >>r;
        Node * myLeft;
        Node * myRight;
        if(l==-1){
            myLeft = NULL;
        }else{
            myLeft = new Node(l);
        }
        if(r==-1){
            myRight = NULL;
        }
        else{
            myRight = new Node(r);
        }
        p->left = myLeft;
        p->right = myRight;

        if(p->left){
            q.push(p->left);
        }
         if(p->right){
            q.push(p->right);
        }
    
    }
    return root;
}
void level_order(Node *root)
{
    if (root == NULL)
    {
        cout << "Tree nai" << endl;
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        // 1. ber kore ana
        Node *f = q.front();
        q.pop();

        // 2. jabotiyo ja kaj ache
        cout << f->val << " ";

        // 3. tar children gulo ke rakha
        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
}
void insert_value(Node * &root, int x){
    if(root==NULL){
        root = new Node(x);
        return;
    }
    if(x < root->val){
        if(root->left==NULL){
              root->left = new Node(x);
            }
            else{
                insert_value(root->left,x);
            }
    }
    else{
       if(root->right==NULL){
                root->right = new Node(x);
            }
            else{
                insert_value(root->right,x);
            } 
    }
    
}
int main(){
    Node * root = input_tree();
    
    insert_value(root, 12);

    level_order(root);
    return 0;
}

