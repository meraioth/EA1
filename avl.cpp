#include "avl.h"
#include <iostream>
using namespace std;

BinarySearchTree::tree_node* AVL::insert(BinarySearchTree::tree_node* p, int data) 
{
    cout<<"insertando : "<<data<<endl;
    if(isEmpty()) {
        cout<<"es raiz"<<endl;
        BinarySearchTree::tree_node* child = new tree_node;
        child->data = data;
        child->left = NULL;
        child->right = NULL;
        root=child;
        return root;


    }
    if( !p){ 
    
	    	BinarySearchTree::tree_node* child = new tree_node;
		    child->data = data;
		    child->left = NULL;
		    child->right = NULL;
            cout<<"creo nueva hoja"<<endl;
		    return child;
			}
    if( data<p->data ){
       cout<<"el dato:"<<data<<" es hijo izquierdo"<<endl;
        p->left = insert(p->left,data);
        //cout<<"padre :"<<p->data<<endl;
    }
    else{
        cout<<"el dato:"<<data<<" es hijo derecho"<<endl;
        p->right = insert(p->right,data);
       // cout<<"padre :"<<p->data<<" hijo derecho :"<<p->left->data<<endl;
    }
    imprimir(NULL);
    tree_node * t=balance(p);
    cout<<"p dspues d balance : "<<t->data<<endl;
    return t;
}

// BinarySearchTree::tree_node* AVL::insert(BinarySearchTree::tree_node* root, int value){
//     if (root == NULL)
//     {
//         root = new BinarySearchTree::tree_node;
//         root->data = value;
//         root->left = NULL;
//         root->right = NULL;
//         return root;
//     }
//     else if (value < root->data)
//     {
//         root->left = insert(root->left, value);
//         root = balance (root);
//     }
//     else if (value >= root->data)
//     {
//         root->right = insert(root->right, value);
//         root = balance (root);
//     }
//     return root;
// }

BinarySearchTree::tree_node* AVL::insertar(int data){
    
    cout<<"insertando : "<<data<<endl;
    return insert(root,data);
}



int AVL::height(BinarySearchTree::tree_node* temp)
{
    int h = 0;
    if (temp != NULL)
    {
        int l_height = height (temp->left);
        int r_height = height (temp->right);
        int max_height = max (l_height, r_height);
        h = max_height + 1;
        cout<<"altura de :"<<temp->data<<" :"<<h<<endl;
    }

    return h;
}

int AVL::bfactor(BinarySearchTree::tree_node* temp)
{
    cout<<"nodo del bfactor"<<temp->data<<endl;
    int l_height = height (temp->left);
    cout<<"altura izq"<<l_height<<endl;
    int r_height = height (temp->right);
    cout<<"altura der"<<r_height<<endl;
    int b_factor= l_height - r_height;
    cout<<b_factor<<endl;

    return b_factor;
}

BinarySearchTree::tree_node* AVL::rr_rotation(BinarySearchTree::tree_node* p){
    tree_node * temp;
    temp=p->right;
    p->right=temp->left;
    temp->left=p;
    cout<<"nodo raiz dspues d rotar: "<<temp->data<<endl;
    return temp;


}


BinarySearchTree::tree_node* AVL::ll_rotation(BinarySearchTree::tree_node* p){
    tree_node * temp;
    temp=p->left;
    p->left=temp->right;
    temp->right=p;
    

    return temp;


}

BinarySearchTree::tree_node* AVL::lr_rotation(BinarySearchTree::tree_node* p){
    tree_node * temp;
    temp=p->left;
    p->left=rr_rotation(temp);
    
    return ll_rotation(p);


}
BinarySearchTree::tree_node* AVL::rl_rotation(BinarySearchTree::tree_node* p){
    tree_node * temp;
    temp=p->right;
    p->right=ll_rotation(temp);
    
    return rr_rotation(p);


}


BinarySearchTree::tree_node* AVL::balance(BinarySearchTree::tree_node* p)
{
    int b_factor=bfactor(p);
    if( b_factor>1)
    {
        if( bfactor(p->left) > 0 ){
            cout<<"roto simple izq"<<endl;
            p = lr_rotation(p);
        }
        else {
            p=ll_rotation(p);
        }
    }
    else if( b_factor < -1 )
    {
        if( bfactor(p->right) > 0  ){
            p = rl_rotation(p);
        }
        else {
            cout<<"roto simple der"<<endl;
            tree_node * temp=p;
            p=rr_rotation(temp);
            cout<<"p: "<<p->data<<endl;
            cout<<"raiz :"<<root->data<<endl;
        }
    }
    return p;
}

void AVL::display(tree_node *ptr, int level)
{
    int i;
    if (ptr!=NULL)
    {
        display(ptr->right, level + 1);
        cout<<"\n";
        if (ptr == root)
        cout<<"Root -> ";
        for (i = 0; i < level && ptr != root; i++)
            cout<<"        ";
        cout<<ptr->data;
        display(ptr->left, level + 1);
    }
}
void AVL::dis(){
    return display(root,1);
}



