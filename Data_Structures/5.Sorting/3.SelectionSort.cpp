#include <iostream>
using namespace std;

void selectionSort(int arr[])
{
    for (int i = 0; i < 5 - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < 5; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}

int main(int argc, char const *argv[])
{
    int arr[5] = {4, 3, 6, 7, 1};

    cout << "Before Sorting: ";
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    selectionSort(arr);

    cout << "After Sorting: ";
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
