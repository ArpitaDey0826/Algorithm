#include <iostream>

using namespace std;

void bubbleSort(int arr[], int n) {

    bool swapped;

    do {

        swapped = false;

        for (int i = 0; i < n - 1; ++i) {

            if (arr[i] > arr[i + 1]) {

                int temp = arr[i];

                arr[i] = arr[i + 1];

                arr[i + 1] = temp;

                swapped = true;

            }

        }

    } while (swapped);

}

void printArray(int arr[], int size) {

    for (int i = 0; i < size; i++)

        cout << arr[i] << " ";

    cout << endl;

}

int main() {

    int arr[] = {64, 34, 25, 12, 22, 11, 90};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array: ";

    printArray(arr, n);

    bubbleSort(arr, n);

    cout << "Sorted array: ";

    printArray(arr, n);

    return 0;

}



