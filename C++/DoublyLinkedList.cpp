#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node *previous;
};

class DLL
{
private:
    node *head, *temp, *current;

public:
    DLL()
    {
        head = current = temp = NULL;
    }

    void new_node(int data)
    {
        if (head == NULL)
        {
            head = new node;
            head->next = NULL;
            head->previous = NULL;
            head->data = data;
            current = temp = head;
        }
        else
        {
            current = new node;
            current->data = data;
            current->next = NULL;
            current->previous = temp;
            temp->next = current;
            temp = current;
        }
    }

    void delete_node(int data)
    {
        temp = head;
        while (temp->data != data)
        {
            temp = temp->next;
        }

        if (temp->previous == NULL) // Head node Case
        {
            head = head->next;
            head->previous = NULL;
            delete temp;
            temp = current;
        }
        else if (temp->next == NULL) // Tail node Case
        {
            current = current->previous;
            current->next = NULL;
            delete temp;
            temp = current;
        }
        else // In Between Case
        {
            temp->previous->next = temp->next;
            temp->next->previous = temp->previous;
            delete temp;
            temp = current;
        }
    }

    void display()
    {
        temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    DLL list1;

    list1.new_node(0);
    list1.new_node(1);
    list1.new_node(2);
    list1.new_node(3);
    list1.new_node(4);

    list1.display();

    list1.delete_node(0);
    list1.delete_node(4);
    list1.delete_node(2);

    list1.display();

    return 0;
}