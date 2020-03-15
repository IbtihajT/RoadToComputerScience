#include <iostream>
using namespace std;

void linearSearch(int arr[], int key)
{
    bool found = false;
    for (int i = 0; i < 5; i++)
    {

        if (arr[i] == key)
        {
            cout << "Element found at location: " << i << endl;
            found = true;
        }
    }
    if (!found)
    {
        cout << "Element not found in the array!" << endl;
    }
}

int main(int argc, char const *argv[])
{
    int arr[5] = {1, 22, 34, 5, 7};
    int key;

    cout << "Enter the element you want to search: ";
    cin >> key;

    linearSearch(arr, key);

    return 0;
}
