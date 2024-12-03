//
// Created by avick on 12/3/2024.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "dataprocessor.h"
using namespace std;

// Data processing functions credited to Jellane.

// Function to clean a string by removing corrupted characters
string DataProcessor::cleanString(const string& str) {
    string cleaned;
    for (char c : str) {
        if (isprint(c) || c == '\n') { // Allow printable characters and newlines
            cleaned += c;
        }
    }
    return cleaned;
}

// Function to read dataset from a CSV file
vector <DataProcessor::DatasetRow> DataProcessor::readDataset(const string& inputFilename) {
    vector<DataProcessor ::DatasetRow> dataset;
    ifstream file(inputFilename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << inputFilename << endl;
        exit(EXIT_FAILURE); // Exit the program if the file cannot be opened
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
            combinedLine.clear(); // Clear the buffer after merging
        }

        size_t commaPos = line.rfind(',');
        if (commaPos != string::npos) { // Ensure a comma was found
            string url = line.substr(0, commaPos);
            string statusStr = line.substr(commaPos + 1);

            try {
                int status = stoi(statusStr); // Parse status as integer
                dataset.push_back({url, status});
            } catch (const exception& e) {
                cerr << "Warning: Malformed row, skipping: " << line << endl;
            }
        } else {
             // Handle rows without a valid comma-separated structure
            cerr << "Warning: Malformed row, skipping: " << line << endl;
        }
    }

    file.close();
    return dataset;
}

// Function to write sorted dataset to a CSV file
void DataProcessor:: writeDataset(const string& filename, const vector<DatasetRow>& dataset) {
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
