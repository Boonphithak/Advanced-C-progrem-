#include <iostream>
#include <iomanip>
#include <chrono>
using namespace std;

void printArray(int arr[], int n, string label) {
    cout << label;
    for (int i = 0; i < n; i++) {
        cout << setw(4) << arr[i];
    }
    cout << endl;
}

void printPartition(int arr[], int n, int pivotIdx) {
    cout << "  Pivot at index " << pivotIdx << " (value: " << arr[pivotIdx] << "): ";
    for (int i = 0; i < n; i++) {
        if (i == pivotIdx)
            cout << "[" << arr[i] << "] ";
        else
            cout << arr[i] << " ";
    }
    cout << endl;
}

int partition(int arr[], int low, int high, int n, int depth) {
    int pivot = arr[high];
    int i = low - 1;
    
    string indent(depth * 2, ' ');
    cout << indent << "├─ Partitioning range [" << low << "-" << high << "]" << endl;
    
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    
    cout << indent << "├─ ";
    printPartition(arr, n, i + 1);
    
    return i + 1;
}

void quickSort(int arr[], int low, int high, int n, int depth = 0) {
    if (low < high) {
        int pi = partition(arr, low, high, n, depth);
        quickSort(arr, low, pi - 1, n, depth + 1);
        quickSort(arr, pi + 1, high, n, depth + 1);
    }
}

int main() {
    int A[10] = {10, 2, 7, 4, 9, 5, 3, 1, 6, 8};
    int n = 10;
    
    cout << "\n╔════════════════════════════════════════╗" << endl;
    cout << "║     QUICK SORT VISUALIZATION           ║" << endl;
    cout << "╚════════════════════════════════════════╝\n" << endl;
    
    printArray(A, n, "Original Array:  ");
    cout << "\n────────────────────────────────────────" << endl;
    cout << "Starting Quick Sort Process...\n" << endl;
    
    auto start = chrono::high_resolution_clock::now();
    quickSort(A, 0, n - 1, n);
    auto end = chrono::high_resolution_clock::now();
    
    cout << "\n────────────────────────────────────────" << endl;
    printArray(A, n, "Sorted Array:    ");
    
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "\n⏱️  Execution Time: " << duration.count() << " microseconds" << endl;
    cout << "✓  Sorting Complete!\n" << endl;
    
    return 0;
}