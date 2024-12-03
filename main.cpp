//
// Created by megle on 12/2/2024.
//
#include <iostream>
#include <string>
#include <vector>
#include "quicksort.h"

using namespace std;


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
        QuickSort sorter;

        vector<QuickSort::DatasetRow> dataset = sorter.readDataset(inputFilename);

        cout <<"Sorting dataset using Quick Sort..." << endl;
        sorter.quickSorting(dataset);

        cout << "Writing sorted dataset to: " << outputFilename << endl;
        sorter.writeDataset(outputFilename, dataset);

        cout << "Sorting completed successfully!" << endl;
    }

    else if (choice == 2) {

    } else {
        cout << "That was an invalid input. Please restart the program and enter 1 or 2." << endl;
    }
}
