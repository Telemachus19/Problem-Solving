#include <iostream>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
void readArray(int arr[], int size);
void printArray(int arr[], int size);
void selectionSort(int arr[], int n);
void bubbleSort(int arr[], int n);
void copyArray(int arr[], int newArray[], int size);
int searchIdx(int arr[], int size, int item);
void merge(int arr[], int l, int m, int r);
void mergesort(int arr[], int l, int r);
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    int *cubes = new int[t];
    readArray(cubes, t);
    mergesort(cubes, 0, (t - 1));
    printArray(cubes, t);
}
void readArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}
void selectionSort(int arr[], int n)
{
    int minIdx;
    for (int i = 0; i < n - 1; i++)
    {
        minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIdx])
                minIdx = j;
        swap(arr[minIdx], arr[i]);
    }
}
void bubbleSort(int arr[], int n)
{
    bool sorted = true;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                sorted = false;
            }
        }
        if (sorted)
            break;
    }
}
void copyArray(int arr[], int newArray[], int size)
{
    for (int i = 0; i < size; i++)
        newArray[i] = arr[i];
}
int searchIdx(int arr[], int size, int item)
{
    int idx = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == item)
        {
            idx = i;
            break;
        }
    }
    return idx;
}
void merge(int arr[], int l, int m, int r)
{
    // define iterators
    int i, j, k;
    // Define sizes of two subarrays
    int SizeLeft = m - l + 1, SizeRight = r - m;

    // Define Two subarrays
    int *aLeft = new int[SizeLeft];
    int *aRight = new int[SizeRight];

    // Fill two subarrays
    for (i = 0; i < SizeLeft; i++)
    {
        aLeft[i] = arr[l + i];
    }
    for (j = 0; j < SizeRight; j++)
    {
        aRight[j] = arr[m + 1 + j];
    }
    // reset iterators
    i = j = 0;
    k = l;
    // merge two subarrays
    while (i < SizeLeft && j < SizeRight)
    {
        if (aLeft[i] <= aRight[j])
        {
            arr[k] = aLeft[i];
            i++;
        }
        else
        {
            arr[k] = aRight[j];
            j++;
        }
        k++;
    }
    while (i < SizeLeft)
    {
        arr[k] = aLeft[i];
        i++;
        k++;
    }
    while (j < SizeRight)
    {
        arr[k] = aRight[j];
        j++;
        k++;
    }
    return;
}
void mergesort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
    return;
}