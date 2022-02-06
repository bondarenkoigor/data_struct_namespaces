#pragma once
namespace FIFO
{
	template<typename T>
	struct Node
	{
		T value;
		Node<T>* next;

		Node()
		{
			this->value = NULL;
			this->next = nullptr;
		}

		Node(Node<T>* other)
		{
			this->value = other->value;
			this->next = other->next;
		}
	};

	template<typename T>
	class FIFO
	{
	private:
		Node<T>* head;
	public:
		FIFO()
		{
			head = nullptr;
		}
		void add(T value)
		{
			if (this->head == nullptr)
			{
				this->head = new Node<T>;
				this->head->value = value;
				this->head->next = nullptr;
				return;
			}
			Node<T>* iter = this->head;
			while (iter->next != nullptr)
			{
				iter = iter->next;
			}
			iter->next = new Node<T>;
			iter->next->next = nullptr;
			iter->next->value = value;
		}
		void print()
		{
			Node<T>* iter = this->head;
			while (iter != nullptr)
			{
				std::cout << iter << "\t" << iter->next << "\t" << iter->value << "\n";
				iter = iter->next;
			}
		}
		Node<T>* remove()
		{
			Node<T>* forReturn = new Node<T>(this->head);
			Node<T>* forDelete = this->head;
			this->head = this->head->next;
			delete forDelete;
			return forReturn;
		}
	};
}