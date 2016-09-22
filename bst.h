#ifndef BST
#define BST

class BinarySearchTree
{
protected:
    struct tree_node
    {
       tree_node* left;
       tree_node* right;
       tree_node* parent;
       int height;
       int data;
    };
    tree_node* root;

public:
    BinarySearchTree();
    bool isEmpty();
    tree_node* busqueda(int data);
    tree_node* insertar(int data);
    void imprimir(tree_node* node);
    void postorder(tree_node* node, int indent=0);
};
#endif
