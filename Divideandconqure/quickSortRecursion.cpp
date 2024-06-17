#include <iostream>
#include <stack>
using namespace std;

struct bound {
    int lb;
    int ub;
};

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int Partition(int a[], bound p) {
    int down = p.lb;
    int up = p.ub;
    int x = a[down];

    while (down <= up) {
        while (a[down] <= x) {
            down += 1;
        }
        while (a[up] > x) {
            up -= 1;
        }
        if (down <= up) {
            swap(a[down], a[up]);
        }
    }
    swap(a[up], a[p.lb]);

    return up;
}

void quickSort(int a[], int lb, int ub) {
    if (lb < ub) {
        int j = Partition(a, {lb, ub});
        quickSort(a, lb, j - 1);
        quickSort(a, j + 1, ub);
    }
}

int main() {
    int a[] = {20, 10, 3, 2, 1, 25, 35, 21, 23, 12, 11};
    int n = sizeof(a) / sizeof(a[0]);
    quickSort(a, 0, n - 1);

    cout << "sorted array" << endl;

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
