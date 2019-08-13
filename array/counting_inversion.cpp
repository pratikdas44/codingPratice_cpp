//program to find swap numbers where i<j and a[i]>a[j]
#include <iostream>
using namespace std;


long merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int i = 0; i < n2; i++) R[i] = arr[m+1+i];

    int i = 0; int j = 0; int k = l;
    long count = 0;

    while (i<n1 && j<n2) {
        if (L[i]<=R[j]) {
            arr[k] = L[i]; 
            i++; k++;
        }
        else {
            arr[k] = R[j];
            j++; k++;
            count += n1-i;//critical, if a value in L is greater than a 
            //value in R, then the rest of the values will also be greater.
        }
    }

    while (i<n1) {
        arr[k] = L[i];
        i++; k++;
    }
    while (j<n2) {
        arr[k] = R[j];
        j++; k++;
    }
    return count;
}


long mergeSort(int arr[], int l, int r) {
    long count = 0;
    if (l<r) {
        int m = (l+r) / 2;
        count+=mergeSort(arr, l, m);
        count+=mergeSort(arr, m+1, r);
        count+=merge(arr, l, m, r);
    }
    return count;
}


int main()
{
    int t;
    cin >> t;

    while (t-- > 0) {
        int n;
        cin >> n;
        int* arr = new int[n];
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            arr[i] = num;
        }
        cout << mergeSort(arr,0,n-1)<<endl;
    }

        system("pause");
        return 0;
    }