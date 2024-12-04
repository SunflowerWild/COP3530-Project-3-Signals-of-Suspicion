//
// Created by megle on 12/2/2024.
//
#include <iostream>
#include <string>
#include <vector>
#include "quicksort.h"
#include "heapsort.h"
#include "dataprocessor.h"

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
        //string outputFilename = "quick_sorted_data_urls.csv";     // Output file name
        DataProcessor dataObj;
        QuickSort sorter;

        vector<DataProcessor::DatasetRow> dataset = dataObj.readDataset(inputFilename);

        vector<DataProcessor::DatasetRow> legitimate, suspicious;
        for (DataProcessor::DatasetRow pair : dataset){
            if (pair.status == 0){
                suspicious.push_back(pair);
            }
            else if (pair.status == 1){
                legitimate.push_back(pair);
            }
        }

        cout <<"Sorting dataset using Quick Sort..." << endl;
        sorter.quickSorting(suspicious);
        sorter.quickSorting(legitimate);

        cout << "Writing sorted dataset to files..." << endl;
        dataObj.writeDataset("quicksort_suspicious_urls.csv", suspicious);
        dataObj.writeDataset("quicksort_legitimate_urls.csv", legitimate);

        cout << "Sorting completed successfully!" << endl;
    }

    else if (choice == 2) {
        string inputFilename = "project3b_data.csv";         // Input file name
        //string outputFilename = "heap_sorted_data_urls.csv";     // Output file name
        DataProcessor dataObj;
        HeapSort sorter;

        vector<DataProcessor::DatasetRow> dataset = dataObj.readDataset(inputFilename);

        vector<DataProcessor::DatasetRow> legitimate, suspicious;
        for (DataProcessor::DatasetRow pair : dataset){
            if (pair.status == 0){
                suspicious.push_back(pair);
            }
            else if (pair.status == 1){
                legitimate.push_back(pair);
            }
        }
        cout <<"Sorting dataset using Heap Sort..." << endl;
        sorter.heapSort(suspicious);
        sorter.heapSort(legitimate);

        cout << "Writing sorted dataset to files..." << endl;
        dataObj.writeDataset("heapsort_suspicious_urls.csv", suspicious);
        dataObj.writeDataset("heapsort_legitimate_urls.csv", legitimate);

        cout << "Sorting completed successfully!" << endl;

    } else {
        cout << "That was an invalid input. Please restart the program and enter 1 or 2." << endl;
    }
}
