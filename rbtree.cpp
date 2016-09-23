#include "bst.h"
#include "rbtree.h"
#include <stdlib.h>
#include <stdio.h>
#include<iostream>
using namespace std;

void RedBlackTree::insertarrbt(int data)
{
  tree_node *p,*q;
  tree_node *t = new tree_node; //creamos un nuevo nodo
  t->data = data;
  t->left = NULL;
  t->right=NULL;
  t->color='r'; //inicializar en rojo
  p=root;
  q=NULL;
  if(root==NULL) //si no hay nodos entonces la clave es la raiz
  {
        root=t;
        t->parent=NULL;
  }
  else
  {
      while(p!=NULL)//mientras haya un padre
      {
           q=p;
           if(p->data<t->data) //Busca hoja donde insertar
               p=p->right;
           else
               p=p->left;
      }
      t->parent=q; //asigna como padre al nodo correspondiente
      if(q->data<t->data)
           q->right=t;
      else
           q->left=t;
  }
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
  tree_node *g = new tree_node;
  if ((t!=NULL) && (t->parent != NULL)) {
    g = t->parent->parent; //abuelo
  }else{
    g = NULL;
  }

  tree_node *u = new tree_node;
  //Buscar Tio
  if(g->left == t->parent)
  {
    if (g->right != NULL) {
        u = g->right; //tio
    }else{
        rightrotate(g);
    }

  }else{
      if (g->left != NULL) {
        u = g->left;  //tio
      }else{
        leftrotate(g);
      }
  }
  //cambiar colores
  if ((u != NULL) && (u->color == 'r'))
  {
    t->parent->color = 'b';
    u->color = 'b';
    g->color = 'r';
    insert_case1(g);
  }else{
    insert_case4(t);
  }
}

//Padre ROJO pero tio NEGRO
void RedBlackTree::insert_case4(tree_node *t)
{
  tree_node *g = t->parent->parent; //abuelo

  if ((t == t->parent->right) && (t->parent == g->left))
  {
      leftrotate(t);
      t=t->left;
  }else{
      if ((t == t->parent->left)&&(t->parent==g->right))
      {
      rightrotate(t);
      t->right;
      }
  }
  insert_case5(t);
}

//Ambos rojos
void RedBlackTree::insert_case5(tree_node *t)
{
  tree_node *g = t->parent->parent; //abuelo
  t->parent->color = 'b';
  g->color = 'r';
  if (t == t->parent->left)
    rightrotate(g);
  else
    leftrotate(g);
}

void RedBlackTree::leftrotate(tree_node *t)
{
     if(t->parent->right==NULL)
           return ;
     else
     {
       tree_node *aux = t->parent;
       tree_node *aux2 = t->right;
       tree_node *aux3 = t->left;
       aux->parent->parent->left = t;
       t->parent = aux->parent;
       t->left = aux;
       t->right = aux2;
       aux->parent = t;
       aux->right = aux3;
     }
}

void RedBlackTree::rightrotate(tree_node *t)
{
     if(t->parent->left==NULL)
          return ;
     else
     {
       tree_node *aux = t->parent;
       tree_node *aux2 = t->right;
       tree_node *aux3 = t->left;
       aux->parent->parent->right = t;
       t->parent = aux->parent;
       t->left = aux2;
       t->right = aux;
       aux->parent = t;
       aux->left = aux3;
     }
}

void RedBlackTree::postleftrotate(tree_node *g)
{
  if (g->left->parent==NULL) {
    return;
  }
  tree_node *temp  = g->left;
  tree_node *temp2 = g->left->right;
  temp->parent=g->parent;
  temp->right=g;
  g->parent = temp;
  g->left=temp2;
}

void RedBlackTree::postrightrotate(tree_node *g)
{
  if (g->right->parent==NULL) {
    return;
  }
  tree_node *temp  = g->right;
  tree_node *temp2 = g->right->left;
  temp->parent=g->parent;
  temp->left=g;
  g->parent = temp;
  g->right=temp2;
}


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


/*
void RedBlackTree::insertarrbt(int data)
{
  int z,i=0;
  z = data; //guardo el valor insertado
  tree_node *p,*q;
  tree_node *t = new tree_node; //creamos un nuevo nodo
  t->data = z;
  t->left = NULL;
  t->right=NULL;
  t->color='r'; //inicializar en rojo
  p=root;
  q=NULL;
  if(root==NULL) //si no hay nodos entonces la clave es la raiz
  {
        root=t;
        t->parent=NULL;
  }
  else
  {
      while(p!=NULL)//mientras haya un padre
      {
           q=p;
           if(p->data<t->data) //propiedad de BinaryTree
               p=p->right;
           else
               p=p->left;
      }
      t->parent=q; //propiedad de BinaryTree
      if(q->data<t->data)
           q->right=t;
      else
           q->left=t;
  }
  insert2(t);
}

void RBtree::insert2(tree_node *t)
{
  tree_node *u;
  if(root==t) //comprueba elementos unicos
  {
    t->color='b';
    return;
  }
  while(t->parent!=NULL&&t->parent->color=='r')
  {
      tree_node *g = t->parent->parent;//g es nodo abuelo
      if(g->left==t->parent)//hijo izq igual al padre de t
      {
                   if(g->right!=NULL)//
                   {
                         u=g->right;
                         if(u->color=='r')
                         {
                              t->parent->color='b';
                              u->color='b';
                              g->color='r';
                              t=g;
                         }
                   }
                   else
                   {
                       if(t->parent->right==t)
                       {
                            t=t->parent;
                            leftrotate(t);
                       }
                       t->parent->color='b';
                       g->color='r';
                       rightrotate(g);
                   }
      }
      else
      {
                   if(g->left!=NULL)
                   {
                        u=g->left;
                        if(u->color=='r')
                        {
                             t->parent->color='b';
                             u->color='b';
                             g->color='r';
                             t=g;
                        }
                   }
                   else
                   {
                       if(t->parent->left==t)
                       {
                              t=t->parent;
                              rightrotate(t);
                       }
                       t->parent->color='b';
                       g->color='r';
                       leftrotate(g);
                   }
      }
      root->color='b';
  }
}

void RedBlackTree::leftrotate(tree_node *p)
{
     if(p->right==NULL)
           return ;
     else
     {
           tree_node *y=p->right;
           if(y->left!=NULL)
           {
                  p->right=y->left;
                  y->left->parent=p;
           }
           else
                  p->right=NULL;
           if(p->parent!=NULL)
                y->parent=p->parent;
           if(p->parent==NULL)
                root=y;
           else
           {
               if(p==p->parent->left)
                       p->parent->left=y;
               else
                       p->parent->right=y;
           }
           y->left=p;
           p->parent=y;
     }
}

void RedBlackTree::rightrotate(tree_node *p)
{
     if(p->left==NULL)
          return ;
     else
     {
         tree_node *y=p->left;
         if(y->right!=NULL)
         {
                  p->left=y->right;
                  y->right->parent=p;
         }
         else
                 p->left=NULL;
         if(p->parent!=NULL)
                 y->parent=p->parent;
         if(p->parent==NULL)
               root=y;
         else
         {
             if(p==p->parent->left)
                   p->parent->left=y;
             else
                   p->parent->right=y;
         }
         y->right=p;
         p->parent=y;
     }
}
*/
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
