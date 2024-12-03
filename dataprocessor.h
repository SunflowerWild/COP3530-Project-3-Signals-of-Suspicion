//
// Created by avick on 12/3/2024.
//

#ifndef COP3530_PROJECT_3_SIGNALS_OF_SUSPICION_DATA_H
#define COP3530_PROJECT_3_SIGNALS_OF_SUSPICION_DATA_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Data processing functions credited to Jellane.
class DataProcessor {

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
};


#endif //COP3530_PROJECT_3_SIGNALS_OF_SUSPICION_DATA_H
