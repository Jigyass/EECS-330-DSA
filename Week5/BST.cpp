#include <iostream>
using namespace std;

struct Node
{
	int key;
	Node *left, *right, *parent;

	Node(int item)
	{
		key = item;
		left = right = parent = nullptr;
	}
}

class BST
{
	public:
		Node* root;
		BST() {root = nullptr;}
		void insert(int key)
		{
			root = insertRec(root, nullptr, key);
		}
		void inorder()
		{
			inorderRec(root);
			cout<<endl;
		}
		Node* search(int key)
		{
			return searchRec(root, key);
		}
		Node* minimum(Node* node)
		{
			Node* current = node;
			while(current && current->left != nullptr)
			{
				current = current->left;
			}
			return current;
		}
		Node* maximum(Node* node)
		{
			Node* current = node;
                        while(current && current->right != nullptr)
                        {
                                current = current->right;
                        }
                        return current;
		}
		Node* successor(int key)
		{
			Node* node = search(key);
			if( node == nullptr)
				return nullptr;
			if(node->right != nullptr)
			{
				return minimum(node->right);
			}
			Node* p = node->parent;
			while(p != nullptr && node == p->right)
			{
				node = p;
				p = p->parent;
			}
			return p;

		}
		Node* predecessor(int key)
                {
                        Node* node = search(key);
                        if( node == nullptr)
                                return nullptr;
                        if(node->left != nullptr)
                        {
                                return maximum(node->right);
                        }
                        Node* p = node->parent;
                        while(p != nullptr && node == p->left)
                        {
                                node = p;
                                p = p->parent;
                        }
                        return p;

                }
	private:
		Node* insertRec(Node* node, Node* parent, int key)
		{
			if(node == nullptr)
			{
				node = new Node(key);
				node->parent = parent;
				return node;
			}
			if(key < node->key)
			{
				node->left = insertRec(node->left, node, key);
			}
			else if( key > node->key)
			{
				node->right = insertRec(node->right, node, key);
			}

			return node;
		}
		void inorderRec(Node* root)
		{
			if(root != nullptr)
			{
				inorderRec(root->left);
				cout<< root->key << "  ";
				inorderRec(root->right);
			}
		}
		Node* searchRec(Node* root, int key)
		{
			if(root == nullptr || root->key = key)
				return root;
			if(root->key < key)
				return searchRec(root->right, key);
			return searchRec(root->left, key);	
		}

