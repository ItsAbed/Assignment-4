

// Aabed Elghadban 900223106

#include <iostream>
#include <vector>
#include "linkedlist.h"
using namespace std;

void insertAfter(vector<int> &vec, int firstValue, int secondValue) // a function that inserts the second value after the first value in each occurance of the first value in the linked list
{
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == firstValue)
        {
            vec.insert(vec.begin() + i + 1, secondValue);
            i++;
        }
    }
}

int main()
{
    int n;
    vector<int> vec; // defining vector vec

    cout << "Please, enter size of linked list: ";
    cin >> n; // input of size
    cout << "Enter your integers (remember, they are only " << n << " integers): ";
    for (int i = 0; i < n; i++) // input of values in linked list
    {
        int x;
        cin >> x;
        vec.push_back(x);
    }
    int firstValue, secondValue;
    cout << "Enter the value that you want to target: ";
    cin >> firstValue; // input of target value (first value)
    cout << "Enter the value you want added after your target value: ";
    cin >> secondValue; // input of second value

    insertAfter(vec, firstValue, secondValue); // modifying the vector list by putting second value after each first value occurance

    cout << "The Modified Vector is: ";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;

    LinkedList list = createLinkedList(vec); // modifying the linked list

    cout << "The Linked list: ";
    list.printList();                                         // printing the list
    cout << "The Sum of nodes: " << list.SumOfList() << endl; // printing the sum of the values in the linked list
    return 0;
}