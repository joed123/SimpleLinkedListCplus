/******************************************************
** Program: Assignment5main.cpp
** Author: Joseph Di Lullo
** Date: 06/07/2021
** Description: Create a linked list then sort it by ascending and desecnding, counting primes.
** Input: linked list, choices
** Output: statements
******************************************************/

#include <iostream>
#include <string>
#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main(){
    linked_list l1;
    int yes = 0;
    signed int add_number;
    int replay = 0;
    unsigned int index = 0;
    int length;
    while (yes == 0){
        replay = 0;
        cout << "Would you like to add a number to the list? (1 for no or 0 for yes): ";
        cin >> yes;
        if (yes == 0){ 
            cout << "What integar would you like to enter?" << endl;
            cin >> add_number;
            while (!cin){
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Enter an integer!" << endl;
                cin >> add_number;
            }
            l1.set_length(l1.insert(add_number, index));            
        }                       
        else if(yes == 1){
            yes = 1;
        }
        else{
            cout << "Invalid choice!" << endl;
            yes = 0;
            index--;
        }
    index++;
    }
    l1.print_while();
    l1.count_prime();
    l1.print_while();
    int game = 0;
    int choice;
    int hi = 0;
    node* temp = l1.gethead();
    cout << "The head is: " << temp -> val << endl;
    while (game == 0){
        choice = 0;
        cout << "Would you like to asort by ascending or descending? (1 for ascending or 2 for descedning)" << endl;
        cin >> choice;
        while (!cin){
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Enter an integer!" << endl;
            cin >> choice;
        }
        if (choice == 1){
            l1.sort_ascending(&temp);
            l1.print_while();
        }
        else if (choice == 2){
            l1.sort_descending(&temp);
            l1.print_while();
        }
        else{
            cout << "Invalid entry!" << endl;
            choice = 0;
        }
        hi = 0;
        while (hi == 0){
            cout << "Would you like to continue?(0 for yes or 1 for no)" << endl;
            cin >> hi;
            while (!cin){
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Enter an integer!" << endl;
                cin >> choice;
            }
            if (hi == 1){
                hi = 1;
                game = 1;
                break;
            }
            else if (hi == 0){
                hi = 1;
            }
            else {
            cout << "Invalid input please try again!" << endl;
            hi = 0;
            }
        }
    }
    return 0;
}