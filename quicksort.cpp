//
// Created by megle on 12/2/2024.
//

#include "quicksort.h"
#include "dataprocessor.h"

// Iterative Quick Sort implementation
void QuickSort::quickSorting(vector<DataProcessor::DatasetRow>& data) {
    stack<pair<int, int>> stack; // Stack to store low and high indices
    stack.push({0, (int)data.size() - 1});

    while (!stack.empty()) {
        int low = stack.top().first;
        int high = stack.top().second;
        stack.pop();

        if (low < high) {
            string pivot = data[high].url; // Pivot
            int i = low - 1;

            for (int j = low; j < high; j++) {
                if (data[j].url < pivot) {
                    i++;
                    swap(data[i], data[j]);
                }
            }
            swap(data[i + 1], data[high]);
            int pi = i + 1;

            // Push subarrays onto the stack
            stack.push({low, pi - 1});
            stack.push({pi + 1, high});
        }
    }
}
