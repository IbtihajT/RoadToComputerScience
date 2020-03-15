#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node *previous;
};

class DoublyLinkList
{
private:
    node *head, *tail, *helper;

public:
    DoublyLinkList()
    {
        head = tail = helper = NULL;
    }

    void insert(int data)
    {
        if (head == NULL)
        {
            head = new node;
            head->data = data;
            head->next = NULL;
            head->previous = NULL;
            tail = helper = head;
        }
        else
        {
            tail = new node;
            tail->data = data;
            tail->previous = helper;
            helper->next = tail;
            tail->next = NULL;
            helper = tail;
        }
    }

    bool search(int data)
    {
        bool found = false;
        helper = head;

        while (helper != NULL)
        {
            if (helper->data == data)
            {
                found = true;
                break;
            }
            else
            {
                helper = helper->next;
            }
        }

        return found;
    }

    void delete_node(int data)
    {
        bool found = search(data);

        if (found)
        {
            helper = head;
            while (helper->data != data)
            {
                helper = helper->next;
            }

            // Case 1: If data at head
            if (helper == head)
            {
                head = head->next;
                head->previous = NULL;
                delete helper;
                helper = tail;
            }

            // Case 2: If data at tail
            else if (helper == tail)
            {
                tail = tail->previous;
                tail->next = NULL;
                delete helper;
                helper = tail;
            }

            // Case 3: If data in between
            else
            {
                helper->previous->next = helper->next;
                helper->next->previous = helper->previous;
                delete helper;
                helper = tail;
            }
        }
    }

    void display()
    {
        helper = head;
        while (helper != NULL)
        {
            cout << helper->data << " ";
            helper = helper->next;
        }
        cout << endl;
    }
};

int main(int argc, char const *argv[])
{
    DoublyLinkList l1;

    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.insert(4);
    l1.insert(5);
    l1.insert(6);
    l1.insert(7);
    l1.insert(8);
    l1.insert(9);

    l1.display();
    l1.delete_node(8);
    l1.display();

    return 0;
}
