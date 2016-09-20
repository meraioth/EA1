#ifndef BST
#define BST

class BinarySearchTree
{
    public:
        struct tree_node
        {
           tree_node* left;
           tree_node* right;
           int data;
        };
        tree_node* root;
        BinarySearchTree();
        bool isEmpty();
        tree_node* busqueda(int data);
        void insertar(int data);
        void imprimir(tree_node* node);
};
#endif
