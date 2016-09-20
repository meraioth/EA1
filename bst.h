#ifndef BST
#define BST

class BinarySearchTree
{
    private:
        struct tree_node
        {
           tree_node* left;
           tree_node* right;
           int height;
           int data;
        };
        tree_node* root;

    public:
        BinarySearchTree();
        bool isEmpty();
        tree_node* busqueda(int data);
        void insertar(int data);
        void imprimir(tree_node* node);
};
#endif
