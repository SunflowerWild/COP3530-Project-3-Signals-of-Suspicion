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

void displayMenu() {
    cout << "=================================" << endl;
    cout << "Please select an option:" << endl;
    cout << "1. Quick Sort" << endl;
    cout << "2. Heap Sort" << endl;
    cout << "3. Exit" << endl;
    cout << "=================================" << endl;

}

int main() {

    cout << "Welcome to Signals of Suspicion." << endl;
    cout << "This program will take a CSV file and sort the data to prioritize website URLs based on their legitimacy." << endl;
    cout << "We will compare the algorithm performance of Quick Sort and Heap Sort while completing the same task." << endl;

    int choice = -1;

    do {
        displayMenu();
        cin >> choice;

        if (choice == 1) {
            string inputFilename = "project3b_data.csv";         // Input file name
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

        }

        else if (choice == 3) {
            break;
        }

        else {
            cout << "That is an invalid input." << endl;
        }

    } while (choice != 3);

    cout << "Thank you for using Signals of Suspicion!" << endl;
    cout << "Have a good day!" << endl;

    return 0;
}
