#include "bst.h"
#include "rbtree.h"
#include <stdlib.h>
#include <stdio.h>
#include<iostream>
using namespace std;

BinarySearchTree::tree_node* RedBlackTree::grandpa(BinarySearchTree::tree_node *t)
{
  if ((t != NULL) && (t->parent != NULL))
    return t->parent->parent;
  else
    return NULL;
}

BinarySearchTree::tree_node* RedBlackTree::uncle(BinarySearchTree::tree_node *t)
{
  tree_node *g = grandpa(t);
  if (g == NULL)
    return NULL; // No grandparent means no uncle
  if (t->parent == g->left)
    return g->right;
  else
    return g->left;
}

void RedBlackTree::insertarrbt(int data)
{
  tree_node *t = insertar(data);
  t->color = 'r';
  insert_case1(t);
}

//primer caso: Arbol vacio
void RedBlackTree::insert_case1(tree_node *t)
{
  if (t->parent == NULL)
    t->color = 'b';
  else
    insert_case2(t);
}

//Segundo caso: El padre es NEGRO
void RedBlackTree::insert_case2(tree_node *t)
{
  if (t->parent->color == 'b')
    return;
  else
    insert_case3(t);
}


//Padre y Tio son ROJOS
void RedBlackTree::insert_case3(tree_node *t)
{
    tree_node *u = uncle(t);
    tree_node *g;
    if ((u!=NULL)&&(u->color=='r'))
    {
      t->parent->color = 'b';
      u->color = 'b';
      g = grandpa(t);
      g->color = 'r';
      insert_case1(g);
    }else{
      insert_case4(t);
    }
}

//Padre ROJO pero tio NEGRO o no existe
void RedBlackTree::insert_case4(tree_node *t)
{
  tree_node *g = grandpa(t); //abuelo

  if ((t == t->parent->right) && (t->parent == g->left))
  {
      leftrotate(t->parent);
      t=t->left;
  }else{
      if ((t == t->parent->left)&&(t->parent==g->right))
      {
      rightrotate(t->parent);
      t->right;
      }
  }
  insert_case5(t);
}

//Ambos rojos
void RedBlackTree::insert_case5(tree_node *t)
{
  tree_node *g = grandpa(t); //abuelo
  t->parent->color = 'b';
  g->color = 'r';
  if (t == t->parent->left)
    rightrotate(g);
  else
    if((t == t->parent->right))
      leftrotate(g);
}

void RedBlackTree::leftrotate(tree_node *node)
{
  tree_node* x = node->right;
      tree_node* grandparent = node->parent;
      if(x){
          tree_node* b = x->left;
          node->right = b;
          if(b){
              b->parent = node;
          }
          x->parent = grandparent;
          x->left = node;
          node->parent = x;
      }
      if(grandparent){
          if(node == grandparent->right){
              grandparent->right = x;
          }else{
              grandparent->left = x;
          }
      }else{
          root = x;
      }
}


void RedBlackTree::rightrotate(tree_node *node)
{
  tree_node* x = node->left;
  tree_node* grandparent = node->parent;
  if(x){
      tree_node* b = x->right;
      node->left = b;
      if(b){
          b->parent = node;
      }
      x->parent = grandparent;
      x->right = node;
      node->parent = x;
  }
  if(grandparent){
      if(node == grandparent->right){
          grandparent->right = x;
      }else{
          grandparent->left = x;
      }
  }else{
      root = x;
  }
}

//MOSTRAR****
void RedBlackTree::disp()
{
     display(root);
}
void RedBlackTree::display(tree_node *p)
{
     if(root==NULL)
     {
          cout<<"\nEmpty Tree.";
          return ;
     }
     if(p!=NULL)
     {
                cout<<"\n\t NODE: ";
                cout<<"\n data: "<<p->data;
                cout<<"\n Colour: ";
    if(p->color=='b')
     cout<<"Black";
    else
     cout<<"Red";
                if(p->parent!=NULL)
                       cout<<"\n Parent: "<<p->parent->data;
                else
                       cout<<"\n There is no parent of the node.  ";
                if(p->right!=NULL)
                       cout<<"\n Right Child: "<<p->right->data;
                else
                       cout<<"\n There is no right child of the node.  ";
                if(p->left!=NULL)
                       cout<<"\n Left Child: "<<p->left->data;
                else
                       cout<<"\n There is no left child of the node.  ";
                cout<<endl;
    if(p->left)
    {
                 cout<<"\n\nLeft:\n";
     display(p->left);
    }
    /*else
     cout<<"\nNo Left Child.\n";*/
    if(p->right)
    {
     cout<<"\n\nRight:\n";
                 display(p->right);
    }
    /*else
     cout<<"\nNo Right Child.\n"*/
     }
}

//GRAFICARRRRRR*****
void RedBlackTree::rbt_print_dot_null(tree_node* node, int nullcount, FILE* stream)
{
    fprintf(stream, "    node [fontname=\"Arial\" color=black];\n");
    fprintf(stream, "    null%d [shape=point];\n", nullcount);
    fprintf(stream, "    %d -> null%d;\n", node->data, nullcount);
}

void RedBlackTree::rbt_print_dot_aux(tree_node* node, FILE* stream)
{
    static int nullcount = 0;
    if (node==root) {
      fprintf(stream, "    node [fontname=\"Arial\" color=black];\n");
      fprintf(stream, "    %d;\n", node->data);
    }
    if (node->left)
    {
        if (node->left->color == 'r') {
          fprintf(stream, "    node [fontname=\"Arial\" color=red];\n");
          fprintf(stream, "    %d -> %d;\n", node->data, node->left->data);
          rbt_print_dot_aux(node->left, stream);
        }else{
          fprintf(stream, "    node [fontname=\"Arial\" color=black];\n");
          fprintf(stream, "    %d -> %d;\n", node->data, node->left->data);
          rbt_print_dot_aux(node->left, stream);
        }
    }
    else
        rbt_print_dot_null(node, nullcount++, stream);

    if (node->right)
    {
        if (node->right->color=='r') {
          fprintf(stream, "    node [fontname=\"Arial\" color=red];\n");
          fprintf(stream, "    %d -> %d;\n", node->data, node->right->data);
          rbt_print_dot_aux(node->right, stream);
        }else{
          fprintf(stream, "   node [fontname=\"Arial\" color=black];\n");
          fprintf(stream, "    %d -> %d;\n", node->data, node->right->data);
          rbt_print_dot_aux(node->right, stream);
        }

    }
    else
        rbt_print_dot_null(node, nullcount++, stream);
}


void RedBlackTree::rbt_print_dot(tree_node* tree, FILE* stream)
{
    if(isEmpty()){
        return;
    }
    if(tree == NULL){
    	tree = root;
    }
    fprintf(stream, "digraph BST {\n");

    if (!tree)
        fprintf(stream, "\n");
    else if (!tree->right && !tree->left){
        fprintf(stream, "    %d;\n", tree->data);
    }
    else
        rbt_print_dot_aux(tree, stream);

    fprintf(stream, "}\n");
}
