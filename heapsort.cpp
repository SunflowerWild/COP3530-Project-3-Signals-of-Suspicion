//
// Created by avick on 12/3/2024.
//

#include <iostream>
#include <string>
#include <vector>
#include "heapsort.h"
#include "dataprocessor.h"
using namespace std;

// Is done after deleting to correct the heap
// Corrects a path from the new root to a leaf.
// Parameters: Aman's Discussion 6 Slides-Heaps & Priority Queues, Slide #71
void HeapSort::heapifyDown(vector<DataProcessor::DatasetRow>& arr, int size, int index){

    // "index" moves down the heap to restore the proper form.

    // Calculations: Aman's Slide 5-Heaps, Slide #24
    // Left child
    int leftIndex = 2 * index + 1;
    // Right child
    int rightIndex = 2 * index + 2;

    // Case 1: Left child valid, Right child INVALID.
    if (leftIndex < size && rightIndex >= size){
        // Left child must be greater than the parent value.
        if (arr[leftIndex].url > arr[index].url){
            // Left child VALUE moves up.
            // Left child INDEX now holds parent VALUE, which moved down.
            // Use this index to continue down the heap.
            swap(arr[index], arr[leftIndex]);
            heapifyDown(arr, size, leftIndex);
        }
        // Else, no swap. Heap is in proper form.
    }
        // Case 2: Right child is valid, Left child INVALID.
    else if (rightIndex < size && leftIndex >= size){
        // Right child must be greater than the value index.
        if (arr[rightIndex].url > arr[index].url){
            // Right child VALUE moves up.
            // Right child INDEX now holds parent VALUE, which moved down.
            // Use this index to continue down the heap.
            swap(arr[index], arr[rightIndex]);
            heapifyDown(arr, size, rightIndex);
        }
        // Else, no swap. Heap is in proper form.
    }
        // Case 3: Left and Right children are VALID.
    else if (leftIndex < size && rightIndex < size){
        // Left child is the greater child.
        // Left child is greater than the parent value.
        if (arr[leftIndex].url > arr[index].url &&
            arr[leftIndex].url > arr[rightIndex].url) {
            // Swap with Left child, heapifyDown.
            swap(arr[index], arr[leftIndex]);
            heapifyDown(arr, size, leftIndex);
        }
            // Right child is the greater child.
            // Right child is greater than the parent value.
        else if (arr[rightIndex].url > arr[index].url &&
                 arr[rightIndex].url > arr[leftIndex].url) {
            // Swap parent with Right child, heapifyDown.
            swap(arr[index], arr[rightIndex]);
            heapifyDown(arr, size, rightIndex);
        }
        // Else, no swap. Heap is in proper form.
    }
        // Neither child has a valid index. The heap is in proper form.
    else {
        return;
    }
}

void HeapSort::heapSort(vector<DataProcessor::DatasetRow>& arr) {
    // Get the number of elements in the vector
    int n = arr.size();

    // Build a max heap from the input array
    // Start from the last non-leaf node and heapify down to the root
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyDown(arr, n, i); // Check the subtree rooted at index i is a max heap
    }

    // Extract elements from the heap one by one
    // The largest element (root of the heap) is moved to the end of the array
    for (int i = n - 1; i > 0; i--) {
        // Move the current root (largest element) to the end of the array
        swap(arr[0], arr[i]);

        // Call heapifyDown on the reduced heap to maintain the max heap property
        // The size of the heap is reduced by one (i)
        heapifyDown(arr, i, 0);
    }
}

string HeapSort::extractMax(vector<DataProcessor::DatasetRow>& arr){
    // Check if the vector is empty
    if (arr.empty()) {
        throw std::runtime_error("Heap is empty");
    }
    // Store the maximum value (root)
    string maxURL = arr[0].url;

    // Delete the current max value (root).
    // aka Copy last element to root.
    arr[0] = arr.back();

    // Remove last element.
    // aka Decrease heap size.
    arr.pop_back();

    // Call helper method to update the heap.
    heapifyDown(arr, arr.size(), 0);

    return maxURL;
}