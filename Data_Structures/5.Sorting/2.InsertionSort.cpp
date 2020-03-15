#include <iostream>
using namespace std;

void insertionSort(int arr[])
{
    int key;
    int j = 0;

    for (int i = 1; i < 5; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
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

    insertionSort(arr);

    cout << "After Sorting: ";
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
