#pragma once
#include<iostream>

using namespace std;

struct Node
{
    int value;
    int numebr_of_occurrences;
    Node* next_node;

    Node();

    Node(int value, int numebr_of_occurrences);
};

class LinkedList
{
    Node* start;
    Node* end;
public:
    LinkedList();

    void removeNode(int value);

    void insertNode(int value, int numebr_of_occurrences);

    int sum();

    void printList();
};