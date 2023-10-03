#include <iostream>
using namespace std;

void heapify(int arr[], int n, int index)
{
    // Find parent
    int indexOfParent = (index - 1) / 2;

    if (arr[indexOfParent] > 0) {
        // If current node is greater than its parent
        // Swap both of them
        if (arr[index] > arr[indexOfParent]) {
            swap(arr[index], arr[indexOfParent]);

            // Recursively heapify the parent node
            heapify(arr, n, indexOfParent);
        }
    }
}

void insertNode(int arr[], int& n, int Key)
{
    // Insert the element at end of Heap
    arr[n] = Key;
    // Increase the size of Heap
    n = n + 1;
    // Heapify the new node
    heapify(arr, n, n - 1);
}

int main(){
    int a[100];
    int n = 0;

    insertNode(a, n, 10);
    insertNode(a, n, 8);
    insertNode(a, n, 9);
    insertNode(a, n, 7);
    insertNode(a, n, 6);
    insertNode(a, n, 5);
    insertNode(a, n, 4);
    insertNode(a, n, 11);

    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }

    return 0;
}
