//
// Created by avick on 12/3/2024.
//

#ifndef COP3530_PROJECT_3_SIGNALS_OF_SUSPICION_HEAPSORT_H
#define COP3530_PROJECT_3_SIGNALS_OF_SUSPICION_HEAPSORT_H

#include <vector>
#include <string>
using namespace std;

class HeapSort {

public:
    // Data type for csv data.
    struct DatasetRow {
        string url;
        int status; // 0 for phishing, 1 for legitimate
    };

    // Data read/write/clean functions credited to Jellane.
    string cleanString(const string& str);
    vector<DatasetRow> readDataset(const string& inputFilename);
    void writeDataset(const string& filename, const vector<DatasetRow>& dataset);

    // Function declarations
    void heapifyDown(vector<DatasetRow>& arr, int size, int index);
    void heapSort(vector<DatasetRow>& arr);
    string extractMax(vector<DatasetRow>& arr);

};

#endif //COP3530_PROJECT_3_SIGNALS_OF_SUSPICION_HEAPSORT_H
