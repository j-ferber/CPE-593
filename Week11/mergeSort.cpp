#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Photo {
    string fileName;
    int fileSizeInKB;
    int resolutionWidth;
    int resolutionHeight;
};

// Function to display a sorted list of photos
void displaySortedPhotos(Photo photos[], int size) {
    cout << "Sorted Photos: \n";
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ". " << photos[i].fileName << "\n";
        cout << "File size: " << photos[i].fileSizeInKB << " KB\n";
        cout << "Resolution: " << photos[i].resolutionWidth << "x" << photos[i].resolutionHeight << "\n";
    }
}

// Merge two subarrays of photos array based on file size
void merge(Photo A[], int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = low;
    Photo B[high + 1];
    while (i <= mid && j <= high) {
        if (A[i].fileSizeInKB < A[j].fileSizeInKB) {
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }
    while (i <= mid) {
        B[k++] = A[i++];
    }
    while (j <= high) {
        B[k++] = A[j++];
    }
    for (int i = low; i <= high; i++) {
        A[i] = B[i];
    }
}

// Main mergeSort function for sorting by file size
void mergeSort(Photo A[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, low, mid, high);
    }
}

int main() {
    const int maxPhotos = 100;
    Photo photos[maxPhotos];

    // Initialize photos with sample data
    photos[0] = {"Photo001.jpg", 240, 800, 600};
    photos[1] = {"Photo002.jpg", 200, 640, 480};
    photos[2] = {"Photo003.jpg", 320, 1024, 768};
    photos[3] = {"Photo004.jpg", 320, 1600, 1200};

    int size = 4;

    // Sort the photos by file size
    mergeSort(photos, 0, size - 1);

    // Display the sorted photos
    displaySortedPhotos(photos, size);

    return 0;
}