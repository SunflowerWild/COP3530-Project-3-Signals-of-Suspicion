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

    // Calculations: Aman's Slide 5-Heaps, Slide #24

    int largest = index; // Initialize the largest URL as root
    int leftIndex = 2 * index + 1; // Left child index
    int rightIndex = 2 * index + 2; // Right child index

    // Check if left child exists (Is it a valid index in arr?)
    // Check if the left child is greater than the current largest/parent.
    if (leftIndex < size && arr[leftIndex].url > arr[largest].url) {
        largest = leftIndex;
    }

    // Check if right child exists (Is it a valid index in arr?)
    // Check if the right child is greater than current largest (parent or left child).
    if (rightIndex < size && arr[rightIndex].url > arr[largest].url) {
        largest = rightIndex;
    }

    // NOTE: Duplicate Value handling
    // If both children are equal to the parent, no swap occurs.
    // The largest index remains unchanged.
    // If one child is larger than parent, then swap occurs below.
    // The largest index does change.

    // Is the current node in the correct position in the heap?
    // The current node (index) must be swapped with the larger child (largest)
    // if they are not the same.
    if (largest != index) {
        swap(arr[index], arr[largest]); // Ensures parent node is >= children
        heapifyDown(arr, size, largest);    // Restores heap property down the affected subtree
    }
}

void HeapSort::heapSort(vector<DataProcessor::DatasetRow>& arr) {
    // Conceptual: Aman's Slide 5-Heaps, Slide #44-47

    // Get the number of elements in the vector
    int n = arr.size();

    // Build a max heap from the input array
    // Zero-indexed array representation of binary tree
    // Last non-leaf node is at index n/2-1.
    // Start from the last non-leaf node and move upwards towards the root
    for (int i = n / 2 - 1; i >= 0; i--) {
        // Check nodes that could violate max heap property
        // Fix heap violations as we go so that non-leaf node children already satisfy property
        heapifyDown(arr, n, i);
    }

    // Extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move the current root (largest element) to the end of the array
        swap(arr[0], arr[i]);

        // As the heap gets smaller/reduces, maintain the max heap property.
        // Reduce the size of the heap by 1, or i
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