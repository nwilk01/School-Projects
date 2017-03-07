#include "linked_list.h"

Linked_List::Linked_List() { head = nullptr; }
Linked_List::~Linked_List() {}

void Linked_List::ClearList()
{

}

bool Linked_List::Search(int key, float *reVal)
{
	ListItem *nextnode = new ListItem;
	ListItem *previousnode = new ListItem;
	nextnode = head;
	while (nextnode != nullptr && nextnode->key != key)
	{
		previousnode = nextnode;
		nextnode = previousnode->next;
	}
	if (nextnode != nullptr) {
		*reVal = nextnode->theData;
	}
	else
	{
		return false;
	}
	return true;
}

int Linked_List::ListLength()
{
	ListItem *nextnode = new ListItem;
	ListItem *previousnode = new ListItem;
	int count = 0;
	nextnode = head;
	while (nextnode != nullptr)
	{
		previousnode = nextnode;
		nextnode = previousnode->next;
		count++;
	}
	
	return count;
}

bool Linked_List::Insert(int key, float f)
{
	ListItem *nextnode = new ListItem;
	ListItem *previousnode = new ListItem;
	ListItem *newnode = new ListItem;
	if (head == nullptr) {
		newnode->key = key;
		newnode->theData = f;
		head = newnode;
		newnode->next = nullptr;
	}
	else {
		nextnode = head;
		while (nextnode != nullptr)
		{
			previousnode = nextnode;
			nextnode = previousnode->next;
		}
		newnode->key = key;
		newnode->theData = f;
		previousnode->next = newnode;
		newnode->next = nullptr;
	}
	return true;
	}
bool Linked_List::Delete(int key)
{
	ListItem *nextnode = new ListItem;
	ListItem *previousnode = new ListItem;
	if (head->key == key) 
	{
		nextnode = head->next;
		previousnode = head;
		delete previousnode;
		head = nextnode;
	}
	else
	{
		nextnode = head;
		while (nextnode != nullptr && nextnode->key != key)
		{
			previousnode = nextnode;
			nextnode = previousnode->next;
		}
		if (nextnode != nullptr) {
			previousnode->next = nextnode->next;
			delete nextnode;
		}
		else
		{
			return false;
		}
	}
	return true;
}

bool Linked_List::isEmpty()
{
	if (head == NULL)
	{
		return true;
	}
	else {
		return false;
	}
}

bool Linked_List::isFull()
{
	return false;
}

void Linked_List::PrintList()
{
	ListItem *nextnode = new ListItem;
	ListItem *previousnode = new ListItem;
	nextnode = head;
	while (nextnode!=nullptr)
	{
		cout << "Key: " << nextnode->key << ", Data: " << nextnode->theData << endl;
		previousnode = nextnode;
		nextnode = previousnode->next;
	}
	cout << endl;
}