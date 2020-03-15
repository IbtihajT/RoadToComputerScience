#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

class CircularLinkList
{
private:
    node *head, *tail, *helper;

public:
    CircularLinkList()
    {
        head = tail = helper = NULL;
    }

    void insert(int data)
    {
        if (head == NULL)
        {
            head = new node;
            head->data = data;
            head->next = head;
            tail = helper = head;
        }
        else
        {
            tail = new node;
            helper->next = tail;
            tail->next = head;
            tail->data = data;
            helper = tail;
        }
    }

    bool search(int data)
    {
        bool found = false;
        helper = head;

        do
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
        } while (helper != head);

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
                tail->next = head;
                delete helper;
                helper = tail;
            }

            // Case 2: If data at tail
            else if (helper == tail)
            {
                tail = head;
                while (tail->next != helper)
                {
                    tail = tail->next;
                }
                tail->next = head;
                delete helper;
                helper = tail;
            }

            // Case 3: If data inbetween
            else
            {
                tail = helper = head;

                while (helper->data != data)
                {
                    helper = helper->next;
                }
                while (tail->next != helper)
                {
                    tail = tail->next;
                }

                tail->next = helper->next;
                delete helper;

                while (tail->next != head)
                {
                    tail = tail->next;
                }
                helper = tail;
            }
        }
    }

    void display()
    {
        helper = head;
        do
        {
            cout << helper->data << " ";
            helper = helper->next;
        } while (helper != head);
        cout << endl;
        helper = tail;
    }
};

int main(int argc, char const *argv[])
{
    CircularLinkList l1;

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
    l1.delete_node(5);
    l1.display();

    return 0;
}
