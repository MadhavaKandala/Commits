// maxheap and minheap

#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 100;

// Function to heapify up (maintain max heap property)
void heapifyUp(vector<int> &heap, int index) {
    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (heap[index] <= heap[parentIndex]) {
            break;
        }
        swap(heap[index], heap[parentIndex]);
        index = parentIndex;
    }
}

// Function to heapify down (maintain max heap property)
void heapifyDown(vector<int> &heap, int size, int index) {
    int largest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < size && heap[leftChild] > heap[largest]) {
        largest = leftChild;
    }

    if (rightChild < size && heap[rightChild] > heap[largest]) {
        largest = rightChild;
    }

    if (largest != index) {
        swap(heap[index], heap[largest]);
        heapifyDown(heap, size, largest);
    }
}

// Function to insert an element into the max heap
void insert(vector<int> &heap, int &size, int value) {
    if (size >= MAX_SIZE) {
        cout << "Heap is full\n";
        return;
    }

    heap[size] = value; // Add the element at the end
    size++;
    heapifyUp(heap, size - 1); // Heapify up to maintain max heap property
}

// Function to delete the root element (maximum element) from the max heap
int deleteRoot(vector<int> &heap, int &size) {
    if (size <= 0) {
        cout << "Heap is empty\n";
        return -1;
    }

    int root = heap[0];
    heap[0] = heap[size - 1]; // Replace root with the last element
    size--;
    heapifyDown(heap, size, 0); // Heapify down from the root

    return root;
}

// Function to print the heap
void printHeap(const vector<int> &heap, int size) {
    for (int i = 0; i < size; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> heap(MAX_SIZE);
    int size = 0;

    insert(heap, size, 10);
    insert(heap, size, 20);
    insert(heap, size, 5);
    insert(heap, size, 30);
    insert(heap, size, 15);

    cout << "Heap after insertions: ";
    printHeap(heap, size); // Output will be a max heap

    int deleted = deleteRoot(heap, size);
    cout << "Deleted root element: " << deleted << endl;

    cout << "Heap after deletion: ";
    printHeap(heap, size);

    return 0;
}

======================

// minHeap

#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 100;

// Function to heapify up (maintain min heap property)
void heapifyUp(vector<int> &heap, int index) {
    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (heap[index] >= heap[parentIndex]) {
            break;
        }
        swap(heap[index], heap[parentIndex]);
        index = parentIndex;
    }
}

// Function to heapify down (maintain min heap property)
void heapifyDown(vector<int> &heap, int size, int index) {
    int smallest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < size && heap[leftChild] < heap[smallest]) {
        smallest = leftChild;
    }

    if (rightChild < size && heap[rightChild] < heap[smallest]) {
        smallest = rightChild;
    }

    if (smallest != index) {
        swap(heap[index], heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}

// Function to insert an element into the min heap
void insert(vector<int> &heap, int &size, int value) {
    if (size >= MAX_SIZE) {
        cout << "Heap is full\n";
        return;
    }

    heap[size] = value; // Add the element at the end
    size++;
    heapifyUp(heap, size - 1); // Heapify up to maintain min heap property
}

// Function to delete the root element (minimum element) from the min heap
int deleteRoot(vector<int> &heap, int &size) {
    if (size <= 0) {
        cout << "Heap is empty\n";
        return -1;
    }

    int root = heap[0];
    heap[0] = heap[size - 1]; // Replace root with the last element
    size--;
    heapifyDown(heap, size, 0); // Heapify down from the root

    return root;
}

// Function to print the heap
void printHeap(const vector<int> &heap, int size) {
    for (int i = 0; i < size; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> heap(MAX_SIZE);
    int size = 0;

    insert(heap, size, 10);
    insert(heap, size, 20);
    insert(heap, size, 5);
    insert(heap, size, 30);
    insert(heap, size, 15);

    cout << "Heap after insertions: ";
    printHeap(heap, size); // Output will be a min heap

    int deleted = deleteRoot(heap, size);
    cout << "Deleted root element: " << deleted << endl;

    cout << "Heap after deletion: ";
    printHeap(heap, size);

    return 0;
}