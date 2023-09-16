#include <iostream>

using namespace std;

// 1 -> Red, 0 -> Black
struct Node
{
	int data;
	Node *parent;
	Node *left;
	Node *right;
	int color;
};

typedef Node *NodePtr;

class RedBlackTree
{
public:
	NodePtr root;
	NodePtr TNULL;

	void fixDelete(NodePtr x)
	{
		NodePtr s;
		while (x != root && x->color == 0)
		{
			if (x == x->parent->left)
			{
				s = x->parent->right;
				if (s->color == 1)
				{
					s->color = 0;
					x->parent->color = 1;
					leftRotate(x->parent);
					s = x->parent->right;
				}

				if (s->left->color == 0 && s->right->color == 0)
				{
					s->color = 1;
					x = x->parent;
				}
				else
				{
					if (s->right->color == 0)
					{
						s->left->color = 0;
						s->color = 1;
						rightRotate(s);
						s = x->parent->right;
					}

					s->color = x->parent->color;
					x->parent->color = 0;
					s->right->color = 0;
					leftRotate(x->parent);
					x = root;
				}
			}
			else
			{
				s = x->parent->left;
				if (s->color == 1)
				{
					s->color = 0;
					x->parent->color = 1;
					rightRotate(x->parent);
					s = x->parent->left;
				}

				if (s->right->color == 0 && s->right->color == 0)
				{
					s->color = 1;
					x = x->parent;
				}
				else
				{
					if (s->left->color == 0)
					{
						s->right->color = 0;
						s->color = 1;
						leftRotate(s);
						s = x->parent->left;
					}

					s->color = x->parent->color;
					x->parent->color = 0;
					s->left->color = 0;
					rightRotate(x->parent);
					x = root;
				}
			}
		}
		x->color = 0;
	}

	void rbTransplant(NodePtr u, NodePtr v)
	{
		if (u->parent == nullptr)
		{
			root = v;
		}
		else if (u == u->parent->left)
		{
			u->parent->left = v;
		}
		else
		{
			u->parent->right = v;
		}
		v->parent = u->parent;
	}

	void fixInsert(NodePtr k)
	{
		NodePtr u;
		while (k->parent->color == 1)
		{
			if (k->parent == k->parent->parent->right)
			{
				u = k->parent->parent->left; // uncle
				if (u->color == 1)
				{
					u->color = 0;
					k->parent->color = 0;
					k->parent->parent->color = 1;
					k = k->parent->parent;
				}
				else
				{
					if (k == k->parent->left)
					{
						k = k->parent;
						rightRotate(k);
					}
					k->parent->color = 0;
					k->parent->parent->color = 1;
					leftRotate(k->parent->parent);
				}
			}
			else
			{
				u = k->parent->parent->right; // uncle

				if (u->color == 1)
				{
					u->color = 0;
					k->parent->color = 0;
					k->parent->parent->color = 1;
					k = k->parent->parent;
				}
				else
				{
					if (k == k->parent->right)
					{
						k = k->parent;
						leftRotate(k);
					}
					k->parent->color = 0;
					k->parent->parent->color = 1;
					rightRotate(k->parent->parent);
				}
			}
			if (k == root)
			{
				break;
			}
		}
		root->color = 0;
	}

public:
	RedBlackTree()
	{
		TNULL = new Node;
		TNULL->color = 0;
		TNULL->left = nullptr;
		TNULL->right = nullptr;
		root = TNULL;
	}
	// search the tree for the key k
	// and return the corresponding node
	NodePtr searchTree(NodePtr node, int key)
	{
		if (node == TNULL || node->data == key)
		{
			return node;
		}

		if (key < node->data)
		{
			return searchTree(node->left, key);
		}

		return searchTree(node->right, key);
	}

	// find the node with the minimum key
	NodePtr minimum(NodePtr tempnode)
	{
		while (tempnode->left != TNULL)
		{
			tempnode = tempnode->left;
		}
		return tempnode;
	}

	// find the node with the maximum key
	NodePtr maximum(NodePtr tempnode)
	{
		while (tempnode->right != TNULL)
		{
			tempnode = tempnode->right;
		}
		return tempnode;
	}

	// rotate left at node x
	void leftRotate(NodePtr nodeX)
	{
		NodePtr nodeY = nodeX->right;
		nodeX->right = nodeY->left;
		if (nodeY->left != TNULL)
		{
			nodeY->left->parent = nodeX;
		}
		nodeY->parent = nodeX->parent;
		if (nodeX->parent == nullptr)
		{
			this->root = nodeY;
		}
		else if (nodeX == nodeX->parent->left)
		{
			nodeX->parent->left = nodeY;
		}
		else
		{
			nodeX->parent->right = nodeY;
		}
		nodeY->left = nodeX;
		nodeX->parent = nodeY;
	}

	// rotate right at node x
	void rightRotate(NodePtr nodeX)
	{
		NodePtr nodeY = nodeX->left;
		nodeX->left = nodeY->right;
		if (nodeY->right != TNULL)
		{
			nodeY->right->parent = nodeX;
		}
		nodeY->parent = nodeX->parent;
		if (nodeX->parent == nullptr)
		{
			this->root = nodeY;
		}
		else if (nodeX == nodeX->parent->right)
		{
			nodeX->parent->right = nodeY;
		}
		else
		{
			nodeX->parent->left = nodeY;
		}
		nodeY->right = nodeX;
		nodeX->parent = nodeY;
	}

	void insert(int key)
	{
		NodePtr node = new Node;
		node->parent = nullptr;
		node->data = key;
		node->left = TNULL;
		node->right = TNULL;
		node->color = 1;

		NodePtr y = nullptr;
		NodePtr x = this->root;

		while (x != TNULL)
		{
			y = x;
			if (node->data < x->data)
			{
				x = x->left;
			}
			else
			{
				x = x->right;
			}
		}

		node->parent = y;
		if (y == nullptr)
		{
			root = node;
		}
		else if (node->data < y->data)
		{
			y->left = node;
		}
		else
		{
			y->right = node;
		}
		if (node->parent == nullptr)
		{
			node->color = 0;
			return;
		}

		if (node->parent->parent == nullptr)
		{
			return;
		}

		fixInsert(node);
	}

	void deleteNode(NodePtr node, int key)
	{
		// find the node containing key
		NodePtr z = TNULL;
		NodePtr x, y;
		while (node != TNULL)
		{
			if (node->data == key)
			{
				z = node;
			}

			if (node->data <= key)
			{
				node = node->right;
			}
			else
			{
				node = node->left;
			}
		}

		if (z == TNULL)
		{
			cout << "Couldn't find key in the tree" << endl;
			return;
		}

		y = z;
		int y_original_color = y->color;
		if (z->left == TNULL)
		{
			x = z->right;
			rbTransplant(z, z->right);
		}
		else if (z->right == TNULL)
		{
			x = z->left;
			rbTransplant(z, z->left);
		}
		else
		{
			y = minimum(z->right);
			y_original_color = y->color;
			x = y->right;
			if (y->parent == z)
			{
				x->parent = y;
			}
			else
			{
				rbTransplant(y, y->right);
				y->right = z->right;
				y->right->parent = y;
			}

			rbTransplant(z, y);
			y->left = z->left;
			y->left->parent = y;
			y->color = z->color;
		}
		delete z;
		if (y_original_color == 0)
		{
			fixDelete(x);
		}
	}

	void preOrder(NodePtr node)
	{
		if (node != TNULL)
		{
			printf("%d -> color ", node->data);
			if (node->color == 0)
				printf("Black \n");
			else
				printf("Red \n");
			preOrder(node->left);
			preOrder(node->right);
		}
	}
};

int main()
{
	RedBlackTree bst;
	while (1)
	{
		printf("1. Insert.\n");
		printf("2. Preorder.\n");
		printf("3. Break\n");
		printf("4. Search\n");
		printf("5. Delete\n");
		int n;
		scanf("%d", &n);
		if (n == 1)
		{
			printf("Enter value: ");
			int x;
			scanf("%d", &x);
			bst.insert(x);
		}
		else if (n == 2)
		{
			printf("Printing Pre-order: \n");
			bst.preOrder(bst.root);
			printf("\n");
		}
		else if (n == 3)
		{
			break;
		}
		else if (n == 4)
		{
			printf("Enter item to search: ");
			int x;
			scanf("%d", &x);
			NodePtr ptr = bst.searchTree(bst.root, x);
			if (ptr == bst.TNULL)
			{
				printf("Not Found\n");
			}
			else
			{
				printf("Found\n");
			}
		}
		else if (n == 5)
		{
			printf("Enter value to delete: ");
			int x;
			scanf("%d", &x);
			bst.deleteNode(bst.root, x);
		}
	}

	return 0;
}
