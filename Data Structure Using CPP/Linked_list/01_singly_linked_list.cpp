//
// Created by CHINTOO on 30-04-2021.
// This program is to demonstrate the single linked list
//

#include "iostream"
using namespace std;

class Node{
protected:
    int data;
public:
    Node * link{};
    explicit Node(int n){
        data = n;
    }
    static void display();

};
Node *head = nullptr;

void Node::display()  {
    Node * temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->link;
    } while (temp != nullptr);
    cout << endl;
}

void insert()
{
    int val{}, pos{};
    cout << "Enter a value: " << endl;
    cin >> val;
    cout << "Enter the position where you want to insert: " << endl;
    cin >> pos;
    if (head == nullptr)
    {
        head = new Node(val);
        head->link = nullptr;
    }
    else{
        Node * temp = head;
        int counter = 1;
        while (counter != pos)
        {
            temp = temp->link;
            counter++;
        }
        Node * ptr = new Node(val);
        ptr->link = temp->link;
        temp->link = ptr;
    }
}

int main()
{
    insert();
    head->display();
    insert();
    head->display();
    insert();
    head->display();
    insert();
    head->display();

    // Node *head = new Node(5);

    return 0;
}
