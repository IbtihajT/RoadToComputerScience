#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

class Que
{
private:
    node *head, *current, *temp;

public:
    Que()
    {
        head = current = temp = NULL;
    }

    void enque(int data)
    {
        if (head == NULL)
        {
            head = new node;
            head->data = data;
            head->next = NULL;
            temp = current = head;
        }
        else
        {
            current = new node;
            temp->next = current;
            temp = current;
            current->data = data;
            current->next = NULL;
        }
    }

    void deque()
    {
        if (head == NULL)
        {
            cout << "Que is Empty" << endl;
        }
        else
        {
            temp = head;
            head = head->next;
            delete (temp);
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
    Que que1;

    que1.enque(1);
    que1.enque(2);
    que1.enque(3);
    que1.enque(4);
    que1.enque(5);
    que1.enque(6);

    que1.display();
    que1.deque();
    que1.display();

    que1.deque();
    que1.display();

    que1.deque();
    que1.display();

    que1.deque();
    que1.display();

    que1.deque();
    que1.display();

    que1.deque();
    que1.display();

    que1.deque();
    que1.display();

    return 0;
}