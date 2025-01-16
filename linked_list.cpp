/******************************************************
** Author: Joseph Di Lullo
** Date: 06/07/2021
** Description: linked list implementation file
** Input:
** Output:
******************************************************/

#include <iostream>
#include <string>
#include "linked_list.h"

using namespace std;

/*********************************************************************
** Function: linked_list::linked_list()
** Description: linked list constrctor
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
linked_list::linked_list(){
    tail = nullptr;
    head = nullptr;
}

/*********************************************************************
** Function: node* linked_list::create_node(int val1)
** Description: creates a new node
** Parameters: val1
** Pre-Conditions:
** Post-Conditions: new node is created
*********************************************************************/
node* linked_list::create_node(int val1){
    node* n1 = new node();
    n1 -> val = val1;
    n1 -> next = nullptr;
    return n1;
}

/*********************************************************************
** Function: unsigned int linked_list::insert(int val, unsigned int index)
** Description: creating the linked list
** Parameters: int val, unsigned int index
** Pre-Conditions:
** Post-Conditions: new libked list value is created
*********************************************************************/
unsigned int linked_list::insert(int val, unsigned int index){
    node* temp;
    temp = head;
    node* temp2;
    node* temp3;
    temp3 = head;
    if (length == 0){
        head = create_node(val);
        tail = head;
    }
    else{
        for (int i = 0; i < index; i++){
            temp = temp -> next;
        }
        for (int i = 0; i < index - 1; i++){
            temp3 = temp3 -> next;
        }
    temp2 = create_node(val);
    tail = temp2;
    temp2 -> next = temp;
    temp3 -> next = temp2;
    }
    length++;
    return length;
}

/*********************************************************************
** Function: void linked_list::set_length(int length1)
** Description: setting length
** Parameters: int length1
** Pre-Conditions:
** Post-Conditions: length is set
*********************************************************************/
void linked_list::set_length(int length1){
    length = length1;
}

/*********************************************************************
** Function: int linked_list::get_length()
** Description: return length
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
int linked_list::get_length(){
    return length;
}

/*********************************************************************
** Function: void linked_list::print_while()
** Description: prints out the linked list
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
void linked_list::print_while(){
    node* temp = head;
    cout << endl;
    cout << "The printed list is: ";
    while (temp != nullptr){
        cout << temp -> val << " ";
        temp = temp -> next;
    }
    cout << endl;
}

/*********************************************************************
** Function: unsigned int linked_list::push_back(int val)
** Description: did not use this function but wrote it so I included it
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
unsigned int linked_list::push_back(int val){ 
	tail -> next = create_node(val);
    length++;
    return length;   
} 

/*********************************************************************
** Function: unsigned int linked_list::push_front(int val)
** Description: did not use this function but wrote it so I included it
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
unsigned int linked_list::push_front(int val){
    node* temp = nullptr;
    temp = create_node(val);
    temp -> next = head;
    head = temp;
    length++;
    return length;
}

/*********************************************************************
** Function: bool linked_list::is_prime(int val)
** Description: checkks if each number is prime
** Parameters:
** Pre-Conditions:
** Post-Conditions: returns true if it is prime
*********************************************************************/
bool linked_list::is_prime(int val){
    int m;
    int flag = 0;
    m = val/2;
    if (val < 0){
        return false;
    }
    for (int j = 2; j <= m; j++){
        if(val % j == 0){
            flag = 1;
        }
    }
    if (flag == 0){
        return true;
    }
    else{
        return false;   
    } 
}

/*********************************************************************
** Function: void linked_list::count_prime()
** Description: counts the primes and calls the is prime function
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
void linked_list::count_prime(){
    node* temp1;
    temp1 = head;
    int num_prime = 0;
    for (int i = 0; i < length; i++){
        if (i == 0){
            if(is_prime(temp1 -> val)){
                num_prime++;
            }
        }
        else{
            temp1 = temp1 -> next;
            if(is_prime(temp1 -> val)){
                num_prime++;
            }
        }
    }
    cout << "The number of primes is: " << num_prime << endl;
}

/*********************************************************************
** Function: node* linked_list::merging(node* first, node* second)
** Description: merges the sorted seperate lists toghther
** Parameters: node* first, node* second
** Pre-Conditions: 
** Post-Conditions:
*********************************************************************/
node* linked_list::merging(node* first, node* second) { 
	node* result = NULL; 
	if (first == NULL)
		return (second);
    
	else if (second == NULL)
		return (first);

	if (first->val <= second->val) { 
		result = first; 
		result->next = merging(first->next, second); 
	} 
	else { 
		result = second;
		result->next = merging(first, second->next); 
	} 
	return result; 
} 

/*********************************************************************
** Function: void linked_list::listsplit(node* list, node** fhead, node** bhead)
** Description: splits the list up
** Parameters: node* list, node** fhead, node** bhead
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
void linked_list::listsplit(node* list, node** fhead, node** bhead) {
    node* temp = nullptr;
	node* ptr1; 
	node* ptr2; 
	ptr2 = list; 
	ptr1 = list->next; 
	while (ptr1 != NULL) { 
		ptr1 = ptr1->next; 
		if (ptr1 != NULL) { 
			ptr2 = ptr2->next; 
			ptr1 = ptr1->next; 
		} 
	} 
	*fhead = list; 
	*bhead = ptr2->next; 
	ptr2->next = NULL; 
} 

/*********************************************************************
** Function: void linked_list::sort_ascending(node** temp)
** Description: sorts ascending
** Parameters: node** temp
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
void linked_list::sort_ascending(node** temp){
	node* temphead = *temp; 
	node* ptr1; 
	node* ptr2; 
	if ((temphead== NULL) || (temphead->next == NULL)) { 
		return; 
	} 
	listsplit(temphead, &ptr1, &ptr2); 
	sort_ascending(&ptr1); 
	sort_ascending(&ptr2); 
	*temp = merging(ptr1, ptr2); 
    this -> head = *temp;
} 

/*********************************************************************
** Function: node* linked_list::gethead()
** Description: returns the head
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
node* linked_list::gethead(){
    return head;
}

/*********************************************************************
** Function: node* linked_list::reversemerging(node* first, node* second)
** Description: merges the list back toghther in descending
** Parameters: node* first, node* second
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
node* linked_list::reversemerging(node* first, node* second) { 
	node* result = NULL; 
	if (first == NULL)
		return (second);
    
	else if (second == NULL)
		return (first);

	if (first->val >= second->val) { 
		result = first; 
		result->next = reversemerging(first->next, second); 
	} 
	else { 
		result = second;
		result->next = reversemerging(first, second->next); 
	} 
	return result; 
} 

/*********************************************************************
** Function: void linked_list::sort_descending(node** temp)
** Description: sorts descending
** Parameters: node** temp
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
void linked_list::sort_descending(node** temp){
    node* temphead = *temp; 
	node* ptr1; 
	node* ptr2; 
	if ((temphead== NULL) || (temphead->next == NULL)) { 
		return; 
	} 
	listsplit(temphead, &ptr1, &ptr2); 
	sort_descending(&ptr1); 
	sort_descending(&ptr2); 
	*temp = reversemerging(ptr1, ptr2); 
    this -> head = *temp;
}