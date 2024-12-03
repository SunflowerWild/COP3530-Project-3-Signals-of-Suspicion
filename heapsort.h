//
// Created by avick on 12/3/2024.
//

#ifndef COP3530_PROJECT_3_SIGNALS_OF_SUSPICION_HEAPSORT_H
#define COP3530_PROJECT_3_SIGNALS_OF_SUSPICION_HEAPSORT_H

#include <vector>
#include <string>
#include "dataprocessor.h"
using namespace std;

class HeapSort {

public:

    // Function declarations
    void heapifyDown(vector<DataProcessor::DatasetRow>& arr, int size, int index);
    void heapSort(vector<DataProcessor::DatasetRow>& arr);
    string extractMax(vector<DataProcessor::DatasetRow>& arr);

};

#endif //COP3530_PROJECT_3_SIGNALS_OF_SUSPICION_HEAPSORT_H
