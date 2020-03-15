#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int front, rear, item_count;
    int arr[5];

public:
    CircularQueue()
    {
        item_count = 0;
        front = rear = -1;
        for (int i = 0; i < 5; i++)
        {
            arr[i] = 0;
        }
    }

    bool isEmpty()
    {
        if (front == -1 && rear == -1)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if ((rear + 1) % 5 == front)
            return true;
        else
            return false;
    }

    void enque(int data)
    {
        if (isFull())
        {
            cout << "Que is Full" << endl;
            return;
        }
        else if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % 5;
        }
        arr[rear] = data;
        item_count++;
    }

    int deque()
    {
        int holder;

        if (isEmpty())
        {
            cout << "Que is Empty" << endl;
            return 0;
        }
        else if (front == rear)
        {
            holder = arr[front];
            arr[front] = 0;
            rear = front = -1;
            item_count--;
            return holder;
        }
        else
        {
            holder = arr[front];
            arr[front] = 0;
            front = (front + 1) % 5;
            item_count--;
            return holder;
        }
    }

    int count()
    {
        return item_count;
    }

    void display()
    {
        cout << "Values in the Queue are: ";
        for (int i = 0; i < 5; i++)
        {
            cout << arr[i] << "  ";
        }
        cout << endl;
    }
};

int main(int argc, char const *argv[])
{
    CircularQueue q1;
    int option, value;

    do
    {
        cout << "1. enque()" << endl;
        cout << "2. deque()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. count()" << endl;
        cout << "6. display()" << endl;
        cout << "7. Clear Screen" << endl;
        cout << endl;
        cout << "Select the Corresponding Option or Enter 0 to Exit: ";

        cin >> option;

        switch (option)
        {

        case 0:
            break;

        case 1:
            cout << "Enter the value you want to enque: ";
            cin >> value;
            q1.enque(value);
            break;

        case 2:
            cout << "Dequed Value: " << q1.deque() << endl;
            break;

        case 3:
            if (q1.isEmpty())
            {
                cout << "Queue is Empty" << endl;
            }
            else
            {
                cout << "Queue is not Empty" << endl;
            }
            break;

        case 4:
            if (q1.isFull())
            {
                cout << "Queue is Full" << endl;
            }
            else
            {
                cout << "Queue is not Full" << endl;
            }
            break;

        case 5:
            cout << "Number of items in the que are: " << q1.count() << endl;
            break;

        case 6:
            q1.display();
            break;

        case 7:
            system("clear");
            break;

        default:
            cout << "Please Enter a valid option Number!" << endl;
        }

    } while (option != 0);

    return 0;
}
