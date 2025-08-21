Item Frequency Counter
This README provides a deeper look into the design and thought process behind the Item Frequency Counter C++ program.

Project Summary and Problem Solved
This project is a console-based C++ application that reads a list of items from a file (initially groceries.txt), calculates the frequency of each item, and then presents the results to the user through an interactive menu. The core problem it solves is converting a simple, unstructured list of data into a summarized, structured, and easily understandable format.

For example, a raw list of groceries bought over a week might be long and difficult to analyze. This program automates the process of counting each item, allowing the user to quickly see how many times "Apple" or "Banana" appeared, either numerically or visually. It also creates a data file (frequency.dat) for easy export.

What I Did Particularly Well
I am particularly proud of the object-oriented design of this program. By creating the ItemCounter class, I was able to encapsulate all of the data (item_count map) and the functionality (adding, counting, and printing items) into a single, cohesive unit. This approach makes the main function much cleaner and easier to read, as it only needs to create an ItemCounter object and then call its methods.

Additionally, the use of helper functions like mainMenu() and wordCheck() demonstrates good modularity. This separates the logic for displaying menus and handling user input from the main program flow, making the code more organized and reusable.

Areas for Enhancement
While the program is functional, there are several areas where the code could be enhanced to be more efficient, robust, and adaptable:

File Handling Efficiency: The current implementation reads the entire file into memory before processing. For extremely large files, this could be inefficient. A better approach would be to process the file line by line to reduce memory usage.

Input Validation: The mainMenu() function currently uses cin >> number, which is vulnerable to input failures if the user enters a non-integer value. This can cause an infinite loop. A more robust solution would be to check the state of the input stream using cin.fail() and clear the buffer to prevent such issues.

Adaptability: The program hardcodes the input filename as groceries.txt. To make the program more versatile, I could allow the user to provide the filename as a command-line argument. This would make the program more adaptable for different lists without needing to recompile the code.

Challenges and Solutions
The most challenging piece of code to write was the wordCheck() function. Getting the user input to behave as expected, specifically ensuring they only entered a single word and handling the newline character left in the input buffer by the previous cin >> number, was tricky.

I overcame this by using a do-while loop in combination with cin.ignore() to clear the buffer. I also used getline(cin, userInput) to read the entire line, which is then checked for spaces. If a space is found, the loop prompts the user to try again. This process was a good lesson in the nuances of C++ input streams. I will add a C++ standard library reference to my support network to better understand these low-level behaviors in the future.

Transferable Skills
This project provided a great opportunity to practice several key skills that will be invaluable for future projects and coursework:

File Input/Output (I/O): The ability to read data from and write data to files is a fundamental programming skill.

Data Structures: I gained hands-on experience using the std::map, which is an essential associative container for storing key-value pairs.

Object-Oriented Programming (OOP): Designing and implementing the ItemCounter class reinforced core OOP principles like encapsulation and modularity.

Problem-Solving: Breaking down a larger problem into smaller, manageable functions and classes is a crucial skill.

Input Validation and Error Handling: Learning to anticipate and handle potential user input errors is a mark of a robust and well-written program.

Maintainability, Readability, and Adaptability
This program was designed to be maintainable and readable through several key choices:

Comments: I included comments throughout the code, especially for more complex sections like the input handling, to explain the purpose and logic.

Clear Naming Conventions: The functions and variables are named descriptively (e.g., item_count, mainMenu, createDatFile), making the code's purpose obvious.

Function and Class Separation: Separating concerns into the ItemCounter class and various functions ensures that each part of the code has a single, clear purpose, making it easier to debug and modify.

The current structure makes the code quite adaptable. For example, if I wanted to change the output to a different format (like a CSV file), I would only need to modify the createDatFile() method within the class without affecting any of the other parts of the program.
