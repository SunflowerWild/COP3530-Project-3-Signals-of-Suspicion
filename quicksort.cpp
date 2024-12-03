//
// Created by megle on 12/2/2024.
//
#include "quicksort.h"

// Function to clean a string by removing corrupted characters
string QuickSort::cleanString(const string& str) {
    string cleaned;
    for (char c : str) {
        if (isprint(c) || c == '\n') { // Allow printable characters and newlines
            cleaned += c;
        }
    }
    return cleaned;
}

// Function to read dataset from a CSV file
vector <QuickSort::DatasetRow> QuickSort::readDataset(const string& inputFilename) {
    vector<QuickSort ::DatasetRow> dataset;
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
void QuickSort:: writeDataset(const string& filename, const vector<DatasetRow>& dataset) {
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

// Iterative Quick Sort implementation
void QuickSort::quickSorting(vector<DatasetRow>& data) {
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
