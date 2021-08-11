#include<iostream>
using namespace std;
struct node
{
	int data;
	int count;
	node* right;
	node* left;
};
class BST
{
	node* root;
	node* insert(int val, node* leaf);
	node* deletion( node* leaf, int val);
	node* maximum(node* leaf);

	void inorder_print(node* leaf);
	void postorder_print(node* leaf);
	void preorder_print(node* leaf);


public:
	BST();
	void insert(int x);
	void deletion(int x);
	void inorderprint();
	void preorderprint();
	void postorderprint();
	void duplicate(node* leaf);
	void duplication();
};

BST::BST()
{
	root = NULL;
}

node* BST::insert(int val, node* leaf)
{
	if (leaf == NULL)
	{
		leaf = new node;
		leaf->data = val;
		leaf->count = 1;
		leaf->left = NULL;
		leaf->right = NULL;
	}

	else if (val < leaf->data)
	{
		leaf->left = insert(val, leaf->left);
	}

	else if (val > leaf->data)
	{
		leaf->right = insert(val, leaf->right);
	}
	
	else if (val == leaf->data)
	{
		(leaf->count)++;
		return leaf;
	}
	return leaf;
}

node* BST::maximum(node* leaf)
{
	if (leaf == NULL)
	{
		return NULL;
	}

    if (leaf->right == NULL)
	{
		//cout << "The largest node in tree is " << leaf->right->data << endl;
		return leaf;
	}

	else
	{
		return maximum(leaf->right);
	}
}

node* BST::deletion( node* leaf, int val)
{
	
	if (leaf == NULL)
	{
		return NULL;
	}

	else if (val < leaf->data)
	{
		leaf->left = deletion(leaf->left, val);
	}

	else if (val > leaf->data)
	{
		leaf->right = deletion(leaf->right, val);
	}

	// NO CHILD

	else
	{
		//FOR DUPLICATED NUMBER 
		if (leaf->count > 1)
		{
			(leaf->count)--;
			return leaf;
		}

		if (leaf->right == NULL && leaf->left == NULL)
		{
			delete leaf;
			leaf = NULL;
		}

		// ONE CHILD

		if (leaf->right == NULL)
		{
			node* temp = leaf;
			leaf = leaf->left;
			delete temp;
		}

		if (leaf->left == NULL)
		{
			node* temp = leaf;
			leaf = leaf->right;
			delete temp;
		}

		//TWO CHILD

		else
		{
			node* temp = maximum(leaf->left);
			leaf->data = temp->data;
			leaf->left = deletion(leaf->left, val);
		}

	}

	return leaf;


}


void BST::inorder_print(node* leaf)
{
	if (leaf == NULL)
	{
		return;
	}

	if (leaf->count > 1)
	{
		cout << leaf->data<<" (duplicated number) "<< endl;
	}
	
	else
	{
		inorder_print(leaf->left);
		cout << leaf->data << endl;
		inorder_print(leaf->right);
	}

	
}

void BST::preorder_print(node* leaf)
{
	if (leaf == NULL)
	{
		return;
	}

	else
	{
		cout << leaf->data << endl;
		postorder_print(leaf->left);
		postorder_print(leaf->right);
	}

}

void BST::postorder_print(node* leaf)
{
	if (leaf == NULL)
	{
		return;
	}

	else
	{
		postorder_print(leaf->left);
		postorder_print(leaf->right);
		cout << leaf->data << endl;
	}
}

void BST::insert(int x)
{
	root = insert(x, root);
}
void BST::deletion(int x)
{
	root = deletion( root,x );
}
void BST::inorderprint()
{
	inorder_print(root);
}
void BST::preorderprint()
{
	preorder_print(root);
}
void BST::postorderprint()
{
	postorder_print(root);
}


int main()
{
	BST bst;
	bst.insert(20);
	bst.insert(15);
	bst.insert(10);
	bst.insert(12);
	bst.insert(25);
	bst.insert(30);
	bst.insert(12);
	bst.insert(12);
	bst.insert(22);
	cout << "Inorder arrangement of tree is \n";
	bst.inorderprint();
	bst.deletion(25);
	cout << endl;
	cout << endl;
	bst.inorderprint();
	return 0;
}