#include <iostream>
using namespace std;

class Stack
{
private:
    int top;
    int arr[5];

public:
    Stack()
    {
        top = -1;
        for (int i = 0; i < 5; i++)
        {
            arr[i] = 0;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if (top == 4)
            return true;
        else
            return false;
    }

    void push(int data)
    {
        if (isFull())
            cout << "Stack Overflow" << endl;
        else
        {
            top++;
            arr[top] = data;
        }
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return 0;
        }
        else
        {
            int popedValue = arr[top];
            arr[top] = 0;
            top--;
            return popedValue;
        }
    }

    int count()
    {
        return top + 1;
    }

    int peak(int position)
    {

        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
        }
        else
        {
            return arr[position];
        }
    }

    void change(int position, int data)
    {
        arr[position] = data;
        cout << "Item changed at location: " << position << endl;
    }

    void display()
    {
        cout << "Values in the stack are:" << endl;

        for (int i = 4; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
        cout << endl;
    }
};

int main(int argc, char const *argv[])
{
    Stack s1;
    int option, position, value;

    do
    {
        cout << "1. push()" << endl;
        cout << "2. pop()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. peek()" << endl;
        cout << "6. count()" << endl;
        cout << "7. change()" << endl;
        cout << "8. display()" << endl;
        cout << "9. Clear Screen" << endl;
        cout << endl;
        cout << "Select the Corresponding Option or Enter 0 to Exit: ";

        cin >> option;

        switch (option)
        {

        case 0:
            break;

        case 1:
            cout << "Enter the value you want to push: ";
            cin >> value;
            s1.push(value);
            break;

        case 2:
            cout << "Popped Value: " << s1.pop() << endl;
            break;

        case 3:
            if (s1.isEmpty())
            {
                cout << "Stack is Empty" << endl;
            }
            else
            {
                cout << "Stack is not Empty" << endl;
            }
            break;

        case 4:
            if (s1.isFull())
            {
                cout << "Stack is Full" << endl;
            }
            else
            {
                cout << "Stack is not Full" << endl;
            }
            break;

        case 5:
            cout << "Enter the position you want to peek: ";
            cin >> position;
            cout << "Value at position is: " << s1.peak(position) << endl;
            break;
        case 6:
            cout << "Number of items in the stack are: " << s1.count() << endl;
            break;

        case 7:
            cout << "Enter the position of the you want to change: ";
            cin >> position;
            cout << "Enter the value you want to put in: ";
            cin >> value;
            s1.change(position, value);
            break;

        case 8:
            s1.display();
            break;

        case 9:
            system("clear");
            break;

        default:
            cout << "Please Enter a proper option Number!" << endl;
        }

    } while (option != 0);

    return 0;
}
