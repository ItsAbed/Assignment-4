#include <iostream>
#include <vector>
using namespace std;

struct Node // struct for node
{
    int value;
    int count;
    Node *next;
    Node(int v, int c) : value(v), count(c), next(nullptr) {}
};

class LinkedList // class definition of a linkedlist (I learned from a youtube video a while ago, and I can't remember which video it was.)
{
    Node *head;

public:
    LinkedList() : head(nullptr) {}
    void add_Node(int v, int c) // void function to add a node to the front
    {
        Node *newNode = new Node(v, c);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *tmp = head;
            while (tmp->next != nullptr)
            {
                tmp = tmp->next;
            }
            tmp->next = newNode;
        }
    }
    void remove_Node(int v, int c) // void function to remove a node
    {
        if (head == nullptr)
        {
            return;
        }
        Node *tmp = head;
        Node *prev = nullptr;
        while (tmp != nullptr && (tmp->value != v || tmp->count != c))
        {
            prev = tmp;
            tmp = tmp->next;
        }
        if (tmp == nullptr)
        {
            return;
        }
        if (tmp == head)
        {
            head = head->next;
        }
        else
        {
            prev->next = tmp->next;
        }
        delete tmp;
    }
    void printList() // void function to print the current node values
    {
        Node *tmp = head;
        while (tmp != nullptr)
        {
            cout << tmp->value << "(" << tmp->count << ")"
                 << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }
    int SumOfList() // voide function to calculate then return the sum of all values of all the nodes.
    {
        Node *tmp = head;
        int sum = 0;
        while (tmp != nullptr)
        {
            sum += tmp->value * tmp->count;
            tmp = tmp->next;
        }
        return sum;
    }
};

LinkedList createLinkedList(vector<int> &vec) // Implementation of number 4- Create a function that creates a linked list based on the vector’s elements given that if
{                                             //  the value occurs more than once in the vector then it should be reflected in the number
                                              //  of occurrences of that node in the LinkedList. This function should then return the linked
                                              //  list. (Node is a struct that contains the value of the number and its number of

    LinkedList list;
    for (int i = 0; i < vec.size(); i++)
    {
        int value = vec[i];
        int count = 1;
        for (int j = i + 1; j < vec.size(); j++)
        {
            if (vec[j] == value)
            {
                count++;
                vec.erase(vec.begin() + j);
                j--;
            }
        }
        list.add_Node(value, count);
    }
    return list;
}
