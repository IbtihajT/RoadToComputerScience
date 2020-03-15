#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

class QueueLL
{
private:
    node *front, *back, *helper;

public:
    QueueLL()
    {
        front = back = helper = NULL;
    }

    void enque(int data)
    {
        if (front == NULL)
        {
            front = new node;
            front->next = NULL;
            front->data = data;
            back = helper = front;
        }
        else
        {
            back = new node;
            back->next = NULL;
            back->data = data;
            helper->next = back;
            helper = back;
        }
    }

    int deque()
    {
        int dequed;

        helper = front;
        front = front->next;
        dequed = helper->data;
        delete helper;
        helper = back;
        return dequed;
    }

    void display()
    {
        helper = front;
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

    QueueLL q1;

    q1.enque(0);
    q1.enque(1);
    q1.enque(2);
    q1.enque(3);
    q1.enque(4);

    q1.display();
    q1.deque();
    q1.display();
    q1.deque();
    q1.display();

    return 0;
}
