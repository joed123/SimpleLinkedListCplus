#include <iostream>
#include <string>
#include "node.h"

#ifndef LINKED_LIST_H
#define LINKED_LIST

class linked_list {
   private:
      unsigned int length; 
      node *head; 
      node *tail;
   public:
      linked_list();
      int get_length();
      void set_length(int);
      void clear(); 
      unsigned int push_front(int); 
      unsigned int push_back(int); 
      unsigned int insert(int val, unsigned int index); 
      void sort_ascending(node**); 
      void sort_descending(node**); 
      void create_node();
      node* create_node(int val);
      void count_prime();
      bool is_prime(int val);
      node* gethead();
      void listsplit(node*,node**,node**);
      node* merging(node*, node*);
      void print_while();
      node* reversemerging(node*, node*);
};

#endif