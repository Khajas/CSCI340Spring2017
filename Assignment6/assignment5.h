#ifndef ASSIGNMENT5
#define ASSIGNMENT5

class binTree;
class BST;

class Node {
	public:
		int value;
		Node *right, *left;
		Node(int v=0, Node* r=nullptr, Node* l=nullptr):value(v),right(r),left(l){}
};

class binTree {
    public:
        binTree();
        virtual void insert( int );
        int height() const;
        unsigned size() const;
        void inorder( void(*)(int) );
        void preorder( void(*)(int) );
        void postorder( void(*)(int) );

    protected:
        Node* root;

    private:
        void insert( Node*&, int );
        int height( Node* ) const;
        unsigned size( Node* ) const;
	void inorder( Node*, void(*)(int) );
	void preorder( Node*, void(*)(int) );
	void postorder( Node*, void(*)(int) );
};
#endif
