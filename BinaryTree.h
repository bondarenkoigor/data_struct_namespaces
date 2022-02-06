#pragma once
namespace BST
{
	template<typename T>
	struct Node
	{
		T value;
		Node<T>* left;
		Node<T>* right;
	};

	template<typename T>
	class Tree
	{
	private:
		Node<T>* root;

		void add(T value, Node<T>** tmp)
		{
			if ((*tmp) == NULL)
			{
				(*tmp) = new Node<T>;
				(*tmp)->value = value;
				(*tmp)->left = NULL;
				(*tmp)->right = NULL;
				return;
			}
			if (value <= (*tmp)->value) add(value, &(*tmp)->left);
			else add(value, &(*tmp)->right);
		}
		void print(Node<T>* iter, int n)
		{
			if (iter == NULL) return;
			print(iter->left, ++n);
			for (int i = 0; i < n; i++)
			{
				std::cout << " ";
			}
			std::cout << iter->value << "\n";
			n--;
			print(iter->right, ++n);
		}
		Node<T>** find(T key, Node<T>** tmp)
		{
			if ((*tmp) == NULL || (*tmp)->value == key) return tmp;

			Node<T>** left = find(key, &(*tmp)->left);
			if ((*left) != NULL) return left;

			Node<T>** right = find(key, &(*tmp)->right);
			return right;
		}
		Node<T>** find_successor(Node<T>** node)
		{
			if ((*node)->left == NULL) return node;
			else find_successor(&(*node)->left);

		}
		void del(Node<T>** forDelete)
		{
			if ((*forDelete) == NULL) return;

			if ((*forDelete)->right == NULL && (*forDelete)->left == NULL)
			{
				delete (*forDelete);
				(*forDelete) = NULL;
				return;
			}
			if ((*forDelete)->right == NULL)
			{
				Node<T>* tmp = (*forDelete);
				*forDelete = (*forDelete)->left;
				delete tmp;
				return;
			}
			if ((*forDelete)->left == NULL)
			{
				Node<T>* tmp = (*forDelete);
				*forDelete = (*forDelete)->right;
				delete tmp;
				return;
			}
			Node<T>** successor = find_successor(&(*forDelete)->right);
			(*forDelete)->value = (*successor)->value;
			del(successor);
		}
	public:
		Tree()
		{
			this->root = NULL;
		}
		void add(T value)
		{
			add(value, &(this->root));
		}
		void print()
		{
			print(this->root, 0);
		}
		void del(T value)
		{
			del(find(value, &this->root));
		}
	};
}