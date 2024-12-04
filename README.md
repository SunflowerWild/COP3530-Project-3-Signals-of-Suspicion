Signals of Suspicion is a C++ program designed to process and analyze a dataset of website URLs, categorizing them as "legitimate" or "suspicious." The program demonstrates the performance of two sorting algorithms—Quick Sort and Heap Sort—by sorting the data and saving the results into separate CSV files.

The input dataset is expected to be in a CSV format, where each row contains a URL and its status (1 for legitimate, 0 for suspicious).

<H1>Features</h1>
- Quick Sort and Heap Sort Implementation: Compare the performance of Quick Sort and Heap Sort algorithms.
- Data: Separate URLs into "legitimate" and "suspicious" categories.
- Output to CSV Files: Save sorted data into files for further analysis.
- C++ Compiler: Ensure you have a C++17-compatible compiler (e.g., GCC, Clang, or MSVC).
- Input File: The program expects a CSV file named project3b_data.csv in the root directory.

<h2>File Structure</h2>
- main.cpp: The main application logic.
- quicksort.h / quicksort.cpp: Quick Sort implementation.
- heapsort.h / heapsort.cpp: Heap Sort implementation.
- dataprocessor.h / dataprocessor.cpp: Utilities for reading and writing CSV data.
- project3b_data.csv: Input dataset file.

**The program will present a menu:**

- Choose 1 for Quick Sort.
- Choose 2 for Heap Sort.
- Choose 3 to exit the program.
  
The sorted data will be saved to:
*Quick Sort:*
quicksort_suspicious_urls.csv
quicksort_legitimate_urls.csv
*Heap Sort:*
heapsort_suspicious_urls.csv
heapsort_legitimate_urls.csv
Error Handling
Malformed Input Rows: Rows with invalid structure or missing fields will be skipped with a warning message.
File Access Issues: If a file cannot be opened, the program will terminate with an error message.

<h3>Known Limitations</h3>
The program assumes the input file is named project3b_data.csv.
It currently does not support dynamically changing the input or output file names via command-line arguments.

<h4>Credits</h4>
Heap Sort: Ashlynn Vick
Quick Sort and Data Processing: Jellane Fauni
GitHub Repository, and Video: Megan Mendez
Report and code cleaning/debugging: All
