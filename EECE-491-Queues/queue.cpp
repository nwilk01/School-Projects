#include "queue.h"


Queue::Queue()
{
	rearPtr = nullptr;
}

bool Queue::IsFull() const
{
	return false;
}
// IsFull()
// Returns true if queue is full.  Returns false otherwise.  DOES NOT MODIFY THE QUEUE

bool Queue::IsEmpty() const
{
	if (rearPtr == nullptr)
	{
		return true;
	}
	return false;
}
// IsEmpty()
// Returns true if queue is empty.  Returns false otherwise.  DOES NOT MODIFY THE QUEUE

void Queue::Enqueue(int n)
{
	if (!IsFull())
	{
		if (count ==0)
		{
			Node *temp = new Node;
			temp->data = n;
			temp->nextPtr = temp;
			rearPtr = temp;
			count++;
		}
		else
		{
			Node *first = rearPtr->nextPtr;
			Node *temp = new Node;
			temp->data = n;
			temp->nextPtr = first;
			rearPtr->nextPtr = temp;
			rearPtr =temp;
			count++;
		}
	}
	else
	{
		throw QueueFull();
	}
}
// Adds value n to rear of queue and increments count.
// If queue is already full, throws QueueFull exception

void Queue::Dequeue()
{
	if (!IsEmpty())
	{
		if(count ==1)
		{
			Node *temp = rearPtr;
			rearPtr = nullptr;
			delete temp;
			count--;
		}
		else
		{
			Node *temp = rearPtr-> nextPtr;
			Node *newhead = temp->nextPtr;
			rearPtr->nextPtr = newhead;
			delete temp;
			count--;
		}
	}
	else
	{
		throw QueueEmpty();
	}
}
// Removes front value from queue and decrements count.
// If queue is empty, throws QueueEmpty exception

int Queue::Front() const
{
	if(!IsEmpty())
	{
		return rearPtr->nextPtr->data;
	}
	else
	{
		throw QueueEmpty();
	}
}
// Returns integer from front of queue
// If queue is empty, throws QueueEmpty exception
// DOES NOT MODIFY THE QUEUE

int Queue::Rear() const
{
	if(!IsEmpty())
	{
		return rearPtr->data;
	}
	else
	{
		throw QueueEmpty();
	}
}
// Returns integer from rear of queue
// If queue is empty, throws QueueEmpty exception
// DOES NOT MODIFY THE QUEUE

int Queue::Peek(int n) const
{
	if (Size() > n) 
	{
		Node *temp = rearPtr->nextPtr;
		for (int i = 0; i < n; i++)
		{
			temp = temp->nextPtr;
		}
		return temp->data;
	}
	else 
	{
		throw QueueInvalidPeek();
	}
}
// Returns integer n positions from front of queue
// If queue is empty, throws QueueEmpty
// If position n does not exist, throws QueueInvalidPeek
// DOES NOT MODIFY THE QUEUE

int Queue::Size() const
{
	return count;
}
// Returns number of items stored in queue.  DOES NOT MODIFY THE QUEUE

void Queue::MakeEmpty()
{
	while (!IsEmpty())
	{
		Dequeue();
	}
}
// Deallocates all queue nodes and returns queue to empty ready-to-use state 

Queue::~Queue()
{
	MakeEmpty();
}