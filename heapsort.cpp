//
// Created by avick on 12/3/2024.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "heapsort.h"
using namespace std;

// Function to clean a string by removing corrupted characters
string HeapSort::cleanString(const string& str) {
    string cleaned;
    for (char c : str) {
        if (isprint(c) || c == '\n') { // Allow printable characters and newlines
            cleaned += c;
        }
    }
    return cleaned;
}

// Function to read dataset from a CSV file
vector <HeapSort::DatasetRow> HeapSort::readDataset(const string& inputFilename) {
    vector<HeapSort::DatasetRow> dataset;
    ifstream file(inputFilename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << inputFilename << endl;
        exit(EXIT_FAILURE);
    }

    string line, combinedLine;
    while (getline(file, line)) {
        line = cleanString(line); // Clean corrupted characters
        if (count(line.begin(), line.end(), ',') < 1) {
            combinedLine += line; // Append incomplete line
            continue;
        }

        if (!combinedLine.empty()) {
            line = combinedLine + line; // Combine with previous incomplete line
            combinedLine.clear();
        }

        size_t commaPos = line.rfind(',');
        if (commaPos != string::npos) {
            string url = line.substr(0, commaPos);
            string statusStr = line.substr(commaPos + 1);

            try {
                int status = stoi(statusStr); // Parse status as integer
                dataset.push_back({url, status});
            } catch (const exception& e) {
                cerr << "Warning: Malformed row, skipping: " << line << endl;
            }
        } else {
            cerr << "Warning: Malformed row, skipping: " << line << endl;
        }
    }

    file.close();
    return dataset;
}

// Function to write sorted dataset to a CSV file
void HeapSort:: writeDataset(const string& filename, const vector<DatasetRow>& dataset) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << " for writing." << endl;
        exit(EXIT_FAILURE);
    }

    for (const auto& row : dataset) {
        file << row.url << "," << row.status << "\n";
    }

    file.close();
}

// Is done after deleting to correct the heap
// Corrects a path from the new root to a leaf.
// Parameters: Aman's Discussion 6 Slides-Heaps & Priority Queues, Slide #71
void HeapSort::heapifyDown(vector<DatasetRow>& arr, int size, int index){

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

void HeapSort::heapSort(vector<DatasetRow>& arr) {
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

string HeapSort::extractMax(vector<DatasetRow>& arr){
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