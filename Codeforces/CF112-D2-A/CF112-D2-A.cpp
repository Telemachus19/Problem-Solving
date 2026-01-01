#include <cstring>
#include <iostream>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
void readArray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    scanf("%d", &arr[i]);
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
  int idx;
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
int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  string t1, t2;
  int sum_1 = 0, sum_2 = 0;
  cin >> t1 >> t2;
  for (int i = 0; i < t1.length(); i++)
  {
    if (t1.at(i) >= 'A' && t1.at(i) <= 'Z')
    {
      t1.at(i) += 32;
    }
  }
  for (int i = 0; i < t2.length(); i++)
  {
    if (t2.at(i) >= 'A' && t2.at(i) <= 'Z')
    {
      t2.at(i) += 32;
    }
  }
  cout << t1.compare(t2);
}
