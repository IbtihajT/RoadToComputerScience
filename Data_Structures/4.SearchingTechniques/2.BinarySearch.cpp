#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int key)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    int key;
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int output;

    cout << "Enter the Key you want to search in the array: ";
    cin >> key;

    output = binarySearch(arr, 0, 9, key);

    if (output == -1)
    {
        cout << "Item not found in the list!" << endl;
    }
    else
    {
        cout << "Item found at index: " << output << endl;
    }

    return 0;
}
