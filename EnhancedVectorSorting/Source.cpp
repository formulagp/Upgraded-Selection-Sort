//============================================================================
// Name        : Enhanced Vector Sorting
// Author      : Jay Authement
// Version     : 1.1
// Copyright   : Copyright © 2017 SNHU COCE
// Description : Vector Sorting Algorithms
//============================================================================

#include <algorithm>
#include <iostream>
#include <time.h>

#include "CSVparser.hpp"

using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

// forward declarations
double strToDouble(string str, char ch);

// define a structure to hold bid information
struct Bid {
    string bidId; // unique identifier
    string title;
    string fund;
    double amount;
    Bid() {
        amount = 0.0;
    }
};

//============================================================================
// Static methods used for testing
//============================================================================

/**
 * Display the bid information to the console (std::out)
 *
 * @param bid struct containing the bid info
 */
void displayBid(Bid bid) {
    cout << bid.bidId << ": " << bid.title << " | " << bid.amount << " | "
        << bid.fund << endl;
    return;
}

/**
 * Load a CSV file containing bids into a container
 *
 * @param csvPath the path to the CSV file to load
 * @return a container holding all the bids read
 */
vector<Bid> loadBids(string csvPath) {
    cout << "Loading CSV file " << csvPath << endl;

    // Define a vector data structure to hold a collection of bids.
    vector<Bid> bids;

    // initialize the CSV Parser using the given path
    csv::Parser file = csv::Parser(csvPath);

    try {
        // loop to read rows of a CSV file
        for (unsigned int i = 0; i < file.rowCount(); i++) {

            // Create a data structure and add to the collection of bids
            Bid bid;
            bid.bidId = file[i][1];
            bid.title = file[i][0];
            bid.fund = file[i][8];
            bid.amount = strToDouble(file[i][4], '$');

            cout << "Item: " << bid.title << ", Fund: " << bid.fund << ", Amount: " << bid.amount << endl;

            // push this bid to the end
            bids.push_back(bid);
        }
    }
    catch (csv::Error& e) {
        std::cerr << e.what() << std::endl;
    }
    return bids;
}

/**
 * Partition the vector of bids into two parts, low and high
 *
 * @param bids Address of the vector<Bid> instance to be partitioned
 * @param begin Beginning index to partition
 * @param end Ending index to partition
 */

 // This is the function called from the quickSort function that splits the elements and finds the smallest elements in the vector.
int partition(vector<Bid>& bids, int begin, int end) {

    int l = begin;
    int h = end;
    int midpoint = 0;
    bool done = false;

    midpoint = begin + (end - begin) / 2;

    while (!done) {
        while (bids.at(l).title.compare(bids.at(midpoint).title) < 0) {
            ++l;
        }

        while (bids.at(midpoint).title.compare(bids.at(h).title) < 0) {
            --h;
        }

        if (l >= h) {
            done = true;
        }

        else {

            // Swaps the higher and lower element.
            swap(bids.at(l), bids.at(h));

            ++l;
            --h;
        }
    }

    return h;
}

/**
 * Perform a quick sort on bid title
 * Average performance: O(n log(n))
 * Worst case performance O(n^2))
 *
 * @param bids address of the vector<Bid> instance to be sorted
 * @param begin the beginning index to sort on
 * @param end the ending index to sort on
 */

 // This is the function that takes the bids and continuously splits the elements in half with the partition function and then sorts the elements accordingly.
void quickSort(vector<Bid>& bids, int begin, int end) {

    unsigned int j = 0;

    if (begin >= end) {
        return;
    }

    // Finds the midpoint value for the given elements to split and sort.
    j = partition(bids, begin, end);

    quickSort(bids, begin, j);
    quickSort(bids, j + 1, end);

}

/**
 * Perform a selection sort on bid title
 * Average performance: O(n^2))
 * Worst case performance O(n^2))
 *
 * @param bid address of the vector<Bid>
 *            instance to be sorted
 */

 // This is the function for selectionSort that compares the first element with all other elements in the list and swaps as it finds a smaller element.
void selectionSort(vector<Bid>& bids) {

    // Variable used to hold the smallest element in the vector while looping through.
    unsigned int indexSmallest;

    // This loops through the bids starting with i at index 0. j element starts at index 1 and goes through the entire list to compare what is smaller than i element.
    // After finding a smaller element it is swapped with the i index at zero, then loops through again with i at index 1 until the end of list.
    for (unsigned int i = 0; i < bids.size(); ++i) {
        indexSmallest = i;

        for (unsigned int j = i + 1; j < bids.size(); ++j) {
            if (bids.at(j).title.compare(bids.at(indexSmallest).title) < 0) {
                indexSmallest = j;
            }
        }

        if (i != indexSmallest) {
            swap(bids.at(i), bids.at(indexSmallest));
        }
    }
}

/**
 * This is an enhanced version of the
 * selection sort method that is slightly faster!
 */

void upgradedSelectionSort(vector<Bid>& bids, int n) {

    // This loops through and continually finds the maximum and minimum values in vector,
    // then places them at the beginning and end. One the next pass it performs the same operation,
    // only between the remaining elements.
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        string min = bids.at(i).title, max = bids.at(i).title;
        int min_i = i, max_i = i;
        for (int k = i; k <= j; k++) {
            if (bids.at(k).title > max) {
                max = bids.at(k).title;
                max_i = k;
            }
            else if (bids.at(k).title < min) {
                min = bids.at(k).title;
                min_i = k;
            }
        }
        swap(bids.at(i).title, bids.at(min_i).title);
        if (bids.at(min_i).title == max) {
            swap(bids.at(j).title, bids.at(min_i).title);
        }
        else {
            swap(bids.at(j).title, bids.at(max_i).title);
        }
    }
}

/**
 * Simple C function to convert a string to a double
 * after stripping out unwanted char
 *
 * credit: http://stackoverflow.com/a/24875936
 *
 * @param ch The character to strip out
 */
double strToDouble(string str, char ch) {
    str.erase(remove(str.begin(), str.end(), ch), str.end());
    return atof(str.c_str());
}

/**
 * The one and only main() method
 */
int main(int argc, char* argv[]) {

    // process command line arguments
    string csvPath;
    switch (argc) {
    case 2:
        csvPath = argv[1];
        break;
    default:
        csvPath = "eBid_Monthly_Sales_Dec_2016.csv";
    }

    // Define a vector to hold all the bids
    vector<Bid> bids;

    // Define a timer variable
    clock_t ticks;

    //====================================================================================
    int y = bids.size();


    char choice = '0';

    while (choice != '9') {

        cout << "****************** Main Menu ******************:" << endl;
        cout << "  1. Load Bids" << endl;
        cout << "  2. Display All Bids" << endl;
        cout << "  3. Selection Sort All Bids" << endl;
        cout << "  4. Upgraded Selection Sort All Bids" << endl;
        cout << "  5. Quick Sort All Bids" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case '1':
            // Initialize a timer variable before loading bids
            ticks = clock();

            // Complete the method call to load the bids
            bids = loadBids(csvPath);

            cout << bids.size() << " bids read" << endl;

            // Calculate elapsed time and display result
            ticks = clock() - ticks; // current clock ticks minus starting clock ticks
            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

            break;

        case '2':
            // Loop and display the bids read
            for (int i = 0; i < bids.size(); ++i) {
                displayBid(bids[i]);
            }
            cout << endl;

            break;

        case '3':

            ticks = clock();

            // Calls the selectionSort on the bids.
            selectionSort(bids);

            cout << bids.size() << " bids read" << endl;

            // Shows the time it took to perform the selectionSort operation.
            ticks = clock() - ticks;
            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

            break;

        case '4':

            ticks = clock();

            // Calls the upgradedSelectionSort on the bids.
            upgradedSelectionSort(bids, bids.size());

            cout << bids.size() << " bids read" << endl;

            // Shows the time it took to perform the selectionSort operation.
            ticks = clock() - ticks;
            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

            break;

        case '5':

            ticks = clock();

            // Calls the quickSort function with bids starting at the very beginning and ending at the last element.
            quickSort(bids, 0, bids.size() - 1);

            cout << bids.size() << " bids read" << endl;

            // Shows the time it took to perform the quickSort operation.
            ticks = clock() - ticks;
            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

            break;

        case '9':
            cout << "Thanks for using the program! Goodbye!" << endl;
            break;

        // Catches an input other than the case characters.
        default:

            cout << "Please enter a correct input!" << endl;



        }
    }

    return 0;
}
