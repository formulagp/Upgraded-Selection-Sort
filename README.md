# Upgraded Selection Sort

## About the Project

The Upgraded Selection Sort Project is a program created from my CS-260 class at Southern New Hampshire University that shows the creation and use of
commonly used algorithms such as selection sort, quick sort, and the newly added upgraded selection sort. With the provided CSV file in this repository, the user can perform any
of these sorting algorithms on the created vectors and see the speed output of each in clock ticks and seconds. 

## Motivation

The motivation of this project comes from trying to learn and understand how these algorithms are created, what they are used for, and how their speeds compare starting with 
some of the more basic ones. Learning and understanding algorithms is critical in the computer science field so getting these concepts down by creating this program and later 
upgrading it has been a great help on my journey learning programming. 

## Installation

To install this program, the user must download the files in this repository and create a new project from the downloaded files with the provided source code. The 
eBid_Monthly_Sales_DEc_2016.CSV must also be placed in the root folder where the main.cpp file is located. Once the program is built in C++, the software will run properly.

## Getting Started

Once the project is built in the C++ IDE of your choice, the project should run bringing the user to the main menu displaying the following options:
1. Load Bids
2. Display Bids
3. Selection Sort
4. Upgraded Selection Sort
5. Quick Sort
9. Exit

## Usage

When the program runs, the user is shown a screen giving them the option to load bids, display bids, perform a selection sort, perform an upgraded selection sort, perform a 
quick sort, or exit the program. To begin, start by selecting load bids to load in the elements from the CSV file into a vector. By choosing display bids next, the user 
will be able to see the unsorted elements displayed to the screen. Next, the user can choose which of the sort algorithms they wish to perform, which they can verify by selecting
display bids again right after. To reset the elements and try another sort algorithm, the user can select load bids again, followed by the new sort they wish to use. Again,
the sort can be verified by selecting display bids right after. To exit the program select option 9 at the menu.

## Changelog

[1.1.0] - 2021-6-10

- For this update, a completely new algorithm function was added into the program to show comprehension of algorithm design and structure for my CS - 499 class. The Upgraded Selection Sort algorithm was added and is now capable of sorting through the loaded .CSV file. This algorithm is somewhat faster than the standard selection sort algorithm and works by first finding the minimum and maximum elements and placing them at the beginning and end of the vector. The algorithm will continue this process every pass, only performing the minimum and maximum search on the left over elements from the previous pass until all elements of the vector have been properly sorted through. The result is a somewhat faster version of the selection sort algorithm. The program gives the operation speeds of each, which allows the user to compare the two and see how they compare! The function was defined and added into the program as option '4' on the main menu. 
- A bug was also fixed that allowed incorrect user input into the menu option. To remedy this, a char variable was used as the switch choice instead of an integer. A default case was also added that will catch any incorrect input and return the user to the main menu.
- Performed a code cleanup and deleted the unused 'addBid' method that would allow the user to input their own bid information into the .CSV file. This was used in a different assignment and was not needed for this project.

[1.0.0] - 2020-6-15

Original project uploaded from my CS - 260 class. Project contains all neccessary files to get the program running and perform selection sorting and quick sorting on the .CSV file.
