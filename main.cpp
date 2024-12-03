//
// Created by megle on 12/2/2024.
//
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <stack>
using namespace std;

struct DatasetRow {
    string url;
    int status; // 0 for phishing, 1 for legitimate
};

// Function to clean a string by removing corrupted characters
string cleanString(const string& str) {
    string cleaned;
    for (char c : str) {
        if (isprint(c) || c == '\n') { // Allow printable characters and newlines
            cleaned += c;
        }
    }
    return cleaned;
}

// Function to read dataset from a CSV file
vector<DatasetRow> readDataset(const string& inputFilename) {
    vector<DatasetRow> dataset;
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
void writeDataset(const string& filename, const vector<DatasetRow>& dataset) {
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
void quickSort(vector<DatasetRow>& data) {
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
int main() {
    int choice;
    cout
            << "Welcome to Signals and Systems. This program will take a csv file and sort the data to identify the ratio of legitimate and phishing websites."
            << endl;
    cout
            << "We will be comparing the Heap sort and Quick Sort algorithms to compare their performance while completing the same task \n Enter 1 for Quick Sort and 2 for Heap Sort"
            << endl;
    cin >> choice;
    if (choice == 1) {
        string inputFilename = "project3b_data.csv";         // Input file name
        string outputFilename = "quick_sorted_data_urls.csv";     // Output file name

        vector<DatasetRow> dataset = readDataset(inputFilename);

        cout << "Sorting dataset using Quick Sort..." << endl;
        quickSort(dataset);

        cout << "Writing sorted dataset to: " << outputFilename << endl;
        writeDataset(outputFilename, dataset);

        cout << "Sorting completed successfully!" << endl;
    }

    else if (choice == 2) {

    } else {
        cout << "That was an invalid input. Please restart the program and enter 1 or 2." << endl;
    }
}
