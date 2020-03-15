#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

class LinkedList
{
private:
    node *head, *tail, *helper;

public:
    LinkedList()
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
            tail = helper = head;
        }
        else
        {
            tail = new node;
            helper->next = tail;
            helper = tail;
            tail->data = data;
            tail->next = NULL;
        }
    }

    bool search(int key)
    {
        bool found = false;
        helper = head;

        while (helper != NULL)
        {
            if (helper->data == key)
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

    void delete_node(int key)
    {
        bool found = search(key);

        if (found)
        {
            helper = head;
            while (helper->data != key)
            {
                helper = helper->next;
            }

            // Case 1: If data is at head
            if (helper == head)
            {
                head = head->next;
                delete helper;
                helper = tail;
            }

            // Case 2: if data is at tail
            else if (helper == tail)
            {
                helper = head;
                while (helper->next != tail)
                {
                    helper = helper->next;
                }
                helper->next = NULL;
                delete tail;
                tail = helper;
            }

            // Case 3: In-Between
            else
            {
                tail = head;
                while (tail->next != helper)
                {
                    tail = tail->next;
                }
                tail->next = helper->next;
                delete helper;
                tail = head;
                while (tail != NULL)
                {
                    tail = tail->next;
                }
                helper = tail;
            }
        }
        else
        {
            cout << "Item not found" << endl;
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
    LinkedList l1;

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
    l1.delete_node(2);
    l1.display();

    return 0;
}
