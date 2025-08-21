# SNHU-CS210-Final-project
A C++ console application that reads a list of items from a file, counts their frequencies, and provides a menu for users to view the data in various formats.

Item Frequency Counter
This is a C++ console application designed to read a list of items from a text file, count the frequency of each item, and display the results to the user in a few different formats. The program is built around a robust ItemCounter class that handles all data processing and display logic.

Features
File Processing: The application reads a list of items from a file named groceries.txt.

Item Counting: It uses a std::map to efficiently store and count the occurrences of each unique item.

Interactive Menu: A command-line menu allows the user to:

Look up the frequency of a specific item.

Display a list of all items with their numerical counts.

Display a histogram-like list of all items using 'X' characters to represent the count.

Data Persistence: The program generates a file named frequency.dat that stores the final item counts in a human-readable format.

How to Use
Prerequisites: You need a C++ compiler (like g++ or Clang) installed on your system.

Create a Data File: Before running the program, create a text file named groceries.txt in the same directory as the source code. The file should contain a list of items, with each item on a new line or separated by spaces.

Apple
Banana
Orange
Apple
Banana
Apple
Compile the Code: Open your terminal and compile the program using the following command:

Bash

g++ -o main main.cpp
(Note: Replace main.cpp with your file's name if it's different.)

Run the Program: Execute the compiled file from your terminal:

Bash

./main
Example Usage
Once the program runs, you will be greeted with a main menu.

Option 1 will prompt you to enter an item name and will then display its frequency.

Option 2 will display all items and their counts, like Apple: 3.

Option 3 will display a histogram-style representation, like Apple: XXX.

Option 4 will exit the program and generate the frequency.dat file.

The frequency.dat file will look like this:

Apple: 3
Banana: 2
Orange: 1
Code Structure
ItemCounter Class: Manages the core logic, including adding items, retrieving frequencies, and printing the data in different formats.

mainMenu() Function: A helper function that displays the main menu and gets user input.

wordCheck() Function: Ensures the user only enters a single word when searching for an item's frequency.

main() Function: Contains the program's primary flow, reading the input file, creating an ItemCounter object, and managing the main menu loop.

This project is a great example of file I/O, data structures (std::map), and object-oriented programming in C++.
