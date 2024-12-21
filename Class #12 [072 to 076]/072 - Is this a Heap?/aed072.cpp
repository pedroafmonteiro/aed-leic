#include <iostream>

using namespace std;

bool isMaxHeap(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (2 * i + 1 < n && a[i] < a[2 * i + 1]) {
            return false;
        }
        if (2 * i + 2 < n && a[i] < a[2 * i + 2]) {
            return false;
        }
    }
    return true;
}

bool isMinHeap(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (2 * i + 1 < n && a[i] > a[2 * i + 1]) {
            return false;
        }
        if (2 * i + 2 < n && a[i] > a[2 * i + 2]) {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        int a[l];
        for (int j = 0; j < l; j++) {
            cin >> a[j];
        }
        if (isMaxHeap(a, l) && isMinHeap(a, l)) {
            cout << "max or min heap" << endl;
        } else if (isMaxHeap(a, l)) {
            cout << "max heap" << endl;
        } else if (isMinHeap(a, l)) {
            cout << "min heap" << endl;
        } else {
            cout << "none" << endl;
        }

    }
    return 0;
}