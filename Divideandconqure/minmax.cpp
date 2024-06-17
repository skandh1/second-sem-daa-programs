#include <iostream>
#include <climits>
using namespace std;

pair<int, int> findMinMax(int arr[], int low, int high)
{
    pair<int, int> minMax;
    if (low == high)
    {
        minMax.first = arr[low];
        minMax.second = arr[low];
        return minMax;
    }
    else if (high == low + 1)
    {
        if (arr[low] > arr[high])
        {
            minMax.first = arr[high];
            minMax.second = arr[low];
        }
        else
        {
            minMax.first = arr[low];
            minMax.second = arr[high];
        }
        return minMax;
    }
    else
    {
        int mid = (low + high) / 2;
        pair<int, int> leftMinMax = findMinMax(arr, low, mid);
        pair<int, int> rightMinMax = findMinMax(arr, mid + 1, high);

        minMax.first = min(leftMinMax.first, rightMinMax.first);
        minMax.second = max(leftMinMax.second, rightMinMax.second);

        return minMax;
    }
}

int main()
{
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    int n = sizeof(arr) / sizeof(arr[0]);

    pair<int, int> minMax = findMinMax(arr, 0, n - 1);

    cout << "Minimum element in array: " << minMax.first << endl;
    cout << "Maximum element in array: " << minMax.second << endl;

    return 0;
}
