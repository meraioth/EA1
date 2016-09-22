#include "avl.h"
#include <iostream>
using namespace std;

// class AVL
// {
//     public:
//         struct tree_node
//         {
//            tree_node* left;
//            tree_node* right;
//            int data;
//            int height;
//         };
//         tree_node* root;
       
// AVL(){
//     root = NULL;
// }

// bool isEmpty()
// {
//     return root==NULL;
// }

// tree_node* busqueda(int data){
//     tree_node* curr;
//     curr = root;
//     while(curr)    {
//         if(data == curr->data){
//             return curr;
//         }
//         else if(data < curr->data){
//             curr = curr->left;
//         }
//         else{
//             curr = curr->right;
//         }
//     }
//     return NULL;
// }

// void imprimir(tree_node* node){
//     if(isEmpty()){
//         return;
//     }
//     if(node == NULL){
//     	node = root;
//     }
//     if(node->left){
//     	imprimir(node->left);
//     }  
//     cout << node->data << endl;
// 	if(node->right){
//     	imprimir(node->right);
//     }  
// }


tree_node* insert(tree_node* p, int data) // insert k data in a tree with p root
{
	cout<<"data :" <<data<<endl;
    if(isEmpty()){
    	tree_node* child = new tree_node;
    	child ->data =data;
    	child->left=NULL;
    	child->right = NULL;
        root = child;

        return root;
    }

    if( !p ){ 
	    	tree_node* child = new tree_node;
		    child->data = data;
		    child->left = NULL;
		    child->right = NULL;
		    return child;
			}
    if( data<p->data )
        p->left = insert(p->left,data);
    else
        p->right = insert(p->right,data);
    return balance(p);
}

tree_node* insertar(int data){

	return insert(root,data);
}


int height(tree_node* p)
{
    if(p==NULL) return 0;
    else return p->height;
}

int bfactor(tree_node* p)
{
    return height(p->right)-height(p->left);
}

void fixheight(tree_node* p)
{
    unsigned char hl = height(p->left);
    unsigned char hr = height(p->right);

    p->height = (hl>hr?hl:hr)+1;
}

tree_node* rotateright(tree_node* p)
{
    tree_node* q = p->left;
    p->left = q->right;
    q->right = p;
    fixheight(p);
    fixheight(q);
    return q;
}

tree_node* rotateleft(tree_node* q)
{
    tree_node* p = q->right;
    q->right = p->left;
    p->left = q;
    fixheight(q);
    fixheight(p);
    return p;
}

tree_node* balance(tree_node* p) // balancing the p node
{
    fixheight(p);
    if( bfactor(p)==2 )
    {
        if( bfactor(p->right) < 0 )
            p->right = rotateright(p->right);
        return rotateleft(p);
    }
    if( bfactor(p)==-2 )
    {
        if( bfactor(p->left) > 0  )
            p->left = rotateleft(p->left);
        return rotateright(p);
    }
    return p; // balancing is not required
}


// tree_node* findmin(tree_node* p) // find a node with minimal data in a p tree 
// {
//     return p->left?findmin(p->left):p;
// }

// tree_node* removemin(tree_node* p) // deleting a node with minimal data from a p tree
// {
//     if( p->left==0 )
//         return p->right;
//     p->left = removemin(p->left);
//     return balance(p);
// }

// tree_node* remove(tree_node* p, int k) // deleting k data from p tree
// {
//     if( !p ) return 0;
//     if( k < p->data )
//         p->left = remove(p->left,k);
//     else if( k > p->data )
//         p->right = remove(p->right,k);  
//     else //  k == p->data 
//     {
//         tree_node* q = p->left;
//         tree_node* r = p->right;
//         delete p;
//         if( !r ) return q;
//         tree_node* min = findmin(root);
//         min->right = removemin(root);
//         min->left = q;
//         return balance(min);
//     }
//     return balance(p);
// }

};