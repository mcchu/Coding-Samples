#include <iostream>
#include <cstddef>
#include "delist.h"

using namespace std;

DEList::DEList()
{
    head = NULL;
    tail = NULL;
}
 
 // Destructor to clean-up memory of current list
DEList::~DEList()
{
    while (!empty())
    {
	pop_front();
    }
}

// returns a Boolean 'true' if the list is empty
bool DEList::empty()
{
    if (head == NULL || tail == NULL)
    {
	return true;
    }
    else {
	return false;
    }
}

// returns number of items in the list
int DEList::size() 
{
    int size = 0;
    DEItem* temp = head;
    while (temp != NULL)
    {
	size++;
	temp = temp->next;
    }
    return size;
}

 // returns front item or -1 if empty list
int DEList::front()
{
     if (head == NULL)
     {
	return -1;
     }
     else return head->val;

}

 // returns back item or -1 if empty list
int DEList::back()
{
    if(tail == NULL){
	return -1;}
    else
    {
	return tail->val;	
    }		
}
 
 // Adds a new integer to the front of the list
void DEList::push_front(int new_val)
{
    DEItem* new_obj = new DEItem; 		//on stack (new is on heap)
    new_obj->val = new_val;			
    new_obj->prev = NULL;			//new previous
    DEItem* temp = head;
    if (head == NULL || tail == NULL) 
    {
	head = new_obj; 			//update head
	tail = new_obj;				//update tail
	new_obj->next = NULL;			//new next
    }
    else
    {
	new_obj->next = temp;			//new next
	head = new_obj;				//update head
	temp->prev = new_obj;			//old prev
    }
}

 // Adds a new integer to the back of the list
void DEList::push_back(int new_val)
{
    DEItem* new_obj = new DEItem;		//new always returns an address
    new_obj->val = new_val;			
    new_obj->next = NULL;			//new next
    
    //if list is empty
    DEItem* temp = tail;	
    if (head == NULL || tail == NULL)
    {
	head = new_obj;				//update head
	tail = new_obj;				//update tail
	new_obj->prev = NULL;			//new prev
    }
    //items exist in list
    else
    {
	tail = new_obj;				//old next
	new_obj->prev = temp;			//new prev
	temp->next = new_obj;			//new next
    }
}
 
 // Removes the front item of the list (if it exists)
void DEList::pop_front()
{
    DEItem* temp = head;
    if (temp != NULL)
    {
	head = head->next;
	delete temp;
    }

}
  
/// Removes the back item of the list (if it exists)
void DEList::pop_back()
{
    DEItem* temp = tail;
    if (temp != NULL)
    {
	tail = temp->prev;
 	delete temp;
    }
}


