#include "stack.h"


Stack::Stack()
{
	topPtr = nullptr;
}

void Stack::Push(int n)
{
	Node *temp = new Node;
	temp->data = n;
	temp->previous = nullptr;
	topPtr = temp;
}

void Stack::Pop()
{
		if (!IsEmpty)
		{
			Node *temp = topPtr;
			topPtr = topPtr->next;
			topPtr->previous = nullptr;
			delete temp;
		}
		else {
			StackEmpty;
		}

}

bool Stack::IsEmpty() 
{
	if (topPtr = nullptr)
	{
		return true;
	}
	else
	{
		return false
	}
}

bool Stack::IsFull()
{
	return false;
}

void Stack::MakeEmpty()
{
	while (!IsEmpty)
	{
		pop();
	}
}

int Stack::Top() 
{
	if (!IsEmpty) {
		return topPtr->data;
	}
	else
	{
		StackEmpty;
	}
}

int Stack::Size()
{
	int count;
	Node *temp = topPtr;
	while (!IsEmpty)
	{
		temp = temp->next;
		count++;
	}
	return count;
}

int Stack::Max()
{
	if (!IsEmpty) {
		Node *temp = topPtr;
		int max = temp->data;
		while (!IsEmpty)
		{
			temp = temp->next;
			if (max < temp->data)
			{
				max = temp->data;
			}
		}
		return max;
	}
	else
	{
		StackEmpty;
	}
}

int Stack::min()
{
	if (!IsEmpty) {
		Node *temp = new Node;
		temp = topPtr;
		int min = temp->data;
		while (!IsEmpty)
		{
			temp = temp->next;
			if (min > temp->data)
			{
				min = temp->data;
			}
		}
		return min;
	}
	else
	{
		StackEmpty;
	}
}

int Stack::Peek(int n)
{
	if (Size() > n) {
		Node *temp = topPtr;
		for (int i = 0; i < n; i++)
		{
			temp = temp->next;
		}
		return temp->data;
	}
	else {
		StackInvalidPeek;
	}
}

Stack::~Stack()
{
	MakeEmpty();
}