#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

class StackLL
{
private:
    node *bottom, *helper, *top;

public:
    StackLL()
    {
        bottom = helper = top = NULL;
    }

    void push(int data)
    {
        if (bottom == NULL)
        {
            bottom = new node;
            bottom->data = data;
            bottom->next = NULL;
            helper = top = bottom;
        }
        else
        {
            top = new node;
            top->data = data;
            top->next = NULL;
            helper->next = top;
            helper = top;
        }
    }

    int pop()
    {
        int popped;
        top = bottom;
        while (top->next != helper)
        {
            top = top->next;
        }
        top->next = NULL;
        popped = helper->data;
        delete helper;
        helper = top;
        return popped;
    }

    void display()
    {
        helper = bottom;
        while (helper != NULL)
        {
            cout << helper->data << " ";
            helper = helper->next;
        }
        cout << endl;
        helper = top;
    }
};

int main(int argc, char const *argv[])
{
    StackLL s1;

    s1.push(0);
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.push(6);
    s1.push(7);

    s1.display();

    s1.pop();
    s1.display();

    s1.pop();
    s1.display();

    return 0;
}
