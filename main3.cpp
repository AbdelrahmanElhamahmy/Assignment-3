#include "Header3.h"
#include <vector>

using namespace std;

vector<int> insertAfter(vector<int> v, int firstValue, int secondValue)
{
    vector<int> newV;

    for (int i = 0; i < v.size(); i++)
    {
        newV.push_back(v[i]);

        if (v[i] == firstValue)
        {
            newV.push_back(secondValue);
        }
    }

    return newV;
}

Node::Node()
{
    next_node = NULL;
    value = numebr_of_occurrences = 0;
}

Node::Node(int value, int numebr_of_occurrences)
{
    this->value = value;
    next_node = NULL;
    this->numebr_of_occurrences = numebr_of_occurrences;
}


LinkedList::LinkedList()
{
    start = NULL;
    end = NULL;
}

void LinkedList::removeNode(int value)
{
    if (start->value == value)
    {
        Node* deletedNode = start;
        start = start->next_node;
        delete deletedNode;
    }
    else
    {
        Node* n = start;
        while (true)
        {
            if (n == NULL)
            {
                break;
            }
            else if (n->next_node->value != value)
            {
                n = n->next_node;
            }
            else
            {
                break;
            }
        }

        Node* nodeToBeDeleted = n->next_node;
        Node* n_node = nodeToBeDeleted->next_node;
        if (nodeToBeDeleted == end)
            end = n;
        n->next_node = n_node;
        delete nodeToBeDeleted;
    }

    return;
}

void LinkedList::insertNode(int value, int numebr_of_occurrences)
{
    if (start != NULL)
    {
        end->next_node = new Node(value, numebr_of_occurrences);
        end = end->next_node;
    }
    else
    {
        start = new Node(value, numebr_of_occurrences);
        end = start;
    }
}

int LinkedList::sum()
{
    Node* n = start;
    int total = 0;

    while (true)
    {
        if (n == NULL)
        {
            break;
        }

        total += n->value;
        n = n->next_node;
    }

    return total;
}

void LinkedList::printList()
{
    Node* n = start;
    while (true)
    {
        if (n == NULL)
        {
            break;
        }

        cout << n->value << " : " << n->numebr_of_occurrences << endl;
        n = n->next_node;
    }
    cout << endl;
}

LinkedList convertIntoLinkedList(vector<int> numbers)
{
    vector<int> token(300, 0);
    LinkedList constructed_list = LinkedList();
    int n = numbers.size();

    for (int i = 0; i < n; i++)
    {
        if (token[numbers[i]] == 0)
        {
            for (auto number : numbers)
                if (numbers[i] == number)
                    token[number]++;
            constructed_list.insertNode(numbers[i], token[numbers[i]]);
        }
    }

    return constructed_list;
}

int main()
{
    vector<int> numbers;
    int n, value1, value2;

    cout << "enter number of values:";
    cin >> n;

    cout << "enter value1 :";
    cin >> value1;

    cout << "enter value2 :";
    cin >> value2;

    cout << "enter vector values:";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        numbers.push_back(x);
    }
    cout << endl;

    numbers = insertAfter(numbers, value1, value2);

    cout << "number in the vector :";
    for (auto number : numbers)
        cout << number << " ";
    cout << endl << endl;

    cout << "Ending of testing vector" << endl;
    cout << endl << endl;

    LinkedList linkedlist = LinkedList();

    linkedlist.insertNode(3, 1);
    linkedlist.insertNode(4, 1);
    linkedlist.insertNode(5, 1);
    linkedlist.insertNode(6, 1);
    linkedlist.insertNode(7, 1);

    cout << "List After insert: " << endl;
    linkedlist.printList();

    linkedlist.removeNode(7);
    cout << "List After remove 7: " << endl;
    linkedlist.printList();

    linkedlist.removeNode(3);
    cout << "List after remove 3: " << endl;
    linkedlist.printList();

    linkedlist.insertNode(9, 1);
    cout << "List after insert 9: " << endl;
    linkedlist.printList();

    vector<int> numbers2 = { 9, 8, 3, 3, 6, 1, 9 };
    LinkedList linkedlist2 = convertIntoLinkedList(numbers2);
    cout << "List : " << endl;
    linkedlist2.printList();

    return 0;
}