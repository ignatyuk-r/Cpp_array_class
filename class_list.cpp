#include <iomanip>
#include <iostream>
using namespace std;

template <class L_Type>
struct Node
{
	L_Type data;
	Node<L_Type>* next;
	Node<L_Type>* prev;
};

template <class L_Type>
class List
{
private:
	Node<L_Type>* head;
	Node<L_Type>* tail;
public:
	List();
	void Add_head(L_Type val);
	void Add_tail(L_Type val);
	void Elem_insert(L_Type num, int val);
	Node<L_Type>* Remove_head();
	Node<L_Type>* Remove_tail();
	void Remove_elem(Node<L_Type>* elem);
	void Outlist_head();
	void Outlist_tail();
	Node<L_Type>* Find_data_head(L_Type data);
	Node<L_Type>* Find_data_tail(L_Type data);
	Node<L_Type>* Find_pos_head(int pos);
	Node<L_Type>* Find_pos_tail(int pos);
	bool Is_empty() { return head == NULL; }
	L_Type Retrive(Node<L_Type>* elem);
};

template <class L_Type>
List<L_Type>::List()
{
	Node<L_Type>* head = NULL;
	Node<L_Type>* tail = NULL;
}

template <class L_Type>
void List<L_Type>::Add_head(L_Type val)
{
	Node<L_Type>* temp = new Node<L_Type>;
	temp->data = val;
	temp->next = NULL;
	temp->prev = NULL;
	if (head == NULL)
	{
		tail = temp;

	}
	else
	{
		temp->next = head;
		head->prev = temp;
	}
	tail->next = temp;
	temp->prev = tail;
	head = temp;
}

template <class L_Type>
void List<L_Type>::Add_tail(L_Type val)
{
	Node<L_Type>* temp = new Node<L_Type>;
	temp->data = val;
	temp->next = NULL;
	temp->prev = NULL;
	if (tail == NULL)
		head = temp;
	else
	{
		temp->prev = tail;
		tail->next = temp;
	}
	temp->next = head;
	head->prev = temp;
	tail = temp;
}

template <class L_Type>
void List<L_Type>::Elem_insert(L_Type num, int val)
{
	Node<L_Type>* temp = new Node<L_Type>;
	Node<L_Type>* temp2 = head;
	for (int i = 0; i < num - 1; i++)
		temp2 = temp2->next;
	temp->data = val;
	temp->next = temp2->next;
	temp->prev = temp2;
	temp2->next = temp;
}

template <class L_Type>
Node<L_Type>* List<L_Type>::Remove_head()
{
	if (head == NULL)
		return 0;
	Node<L_Type>* temp = head;
	head = temp->next;
	delete temp;
	head->prev = tail;
	tail->next = head;
	return head;
}

template <class L_Type>
Node<L_Type>* List<L_Type>::Remove_tail()
{
	if (head == NULL)
		return 0;
	Node<L_Type>* temp = tail;
	tail = temp->prev;
	delete temp;
	tail->next = head;
	head->prev = tail;
	return tail;
}

template <class L_Type>
void List<L_Type>::Remove_elem(Node<L_Type>* elem)
{
	if (head == elem)
	{
		head = Remove_head();
		return;
	}
	if (tail == elem)
	{
		tail = Remove_tail();
		return;
	}
	Node* temp = head;
	if (elem)
	{
		elem->prev->next = elem->next;
		elem->next->prev = elem->prev;
		delete elem;
	}
}

template <class L_Type>
void List<L_Type>::Outlist_head()
{
	Node<L_Type>* temp = head;
	while (temp->next != head)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << temp->data << endl;
}

template <class L_Type>
void List<L_Type>::Outlist_tail()
{
	Node<L_Type>* temp = tail;
	while (temp->prev != tail)
	{
		cout << temp->data << " ";
		temp = temp->prev;
	}
	cout << temp->data << endl;
}

template <class L_Type>
Node<L_Type>* List<L_Type>::Find_data_head(L_Type data)
{
	Node<L_Type>* temp = head;
	while (temp->next != head && temp->data != data)
		temp = temp->next;
	if (temp->data != data)
		return NULL;
	return temp;
}

template <class L_Type>
Node<L_Type>* List<L_Type>::Find_data_tail(L_Type data)
{
	Node<L_Type>* temp = tail;
	while (temp->prev != tail && temp->data != data)
		temp = temp->prev;
	if (temp->data != data)
		return NULL;
	return temp;
}

template <class L_Type>
Node<L_Type>* List<L_Type>::Find_pos_head(int pos)
{
	Node<L_Type>* temp = head;
	for (int i = 0; i < pos; i++)
		temp = temp->next;
	return temp;
}

template <class L_Type>
Node<L_Type>* List<L_Type>::List::Find_pos_tail(int pos)
{
	Node* temp = tail;
	for (int i = 0; i < pos; i++)
		temp = temp->prev;
	return temp;
}

template <class L_Type>
L_Type List<L_Type>::Retrive(Node<L_Type>* elem)
{
	Node<L_Type>* temp = head;
	while (temp->next != head && temp != elem)
		temp = temp->next;
	return temp->data;
}