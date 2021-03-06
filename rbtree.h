#ifndef RBT
#define RBT

class RedBlackTree : public BinarySearchTree
{
    private:
      BinarySearchTree::tree_node * grandpa(tree_node *);
      BinarySearchTree::tree_node * uncle(tree_node *);

    public:
      void insertarrbt(int data);
      void insert_case1(tree_node *);
      void insert_case2(tree_node *);
      void insert_case3(tree_node *);
      void insert_case4(tree_node *);
      void insert_case5(tree_node *);
      void leftrotate(tree_node *t);
      void rightrotate(tree_node *t);

      void disp();
      void display( tree_node *);

      void rbt_print_dot_null(tree_node* node, int nullcount, FILE* stream);
      void rbt_print_dot_aux(tree_node* node, FILE* stream);
      void rbt_print_dot(tree_node* tree, FILE* stream);
};

#endif
