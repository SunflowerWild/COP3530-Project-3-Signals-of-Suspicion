//
// Created by megle on 12/2/2024.
//

#ifndef COP3530_PROJECT_3_SIGNALS_OF_SUSPICION_QUICKSORT_H
#define COP3530_PROJECT_3_SIGNALS_OF_SUSPICION_QUICKSORT_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <stack>
using namespace std;

class QuickSort{
public:
    struct DatasetRow {
        string url;
        int status; // 0 for phishing, 1 for legitimate
    };
// Function declarations
    string cleanString(const string& str);
    vector<DatasetRow> readDataset(const string& inputFilename);
    void writeDataset(const string& filename, const vector<DatasetRow>& dataset);
    void quickSorting(vector<DatasetRow>& data);

};
#endif //COP3530_PROJECT_3_SIGNALS_OF_SUSPICION_QUICKSORT_H
