#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <filesystem>
#include <sstream>

using namespace std;

//created a robust class that handles storing the data as well as displaying
class ItemCounter {
    public: 
        //this function handles the data storing into a map
        void addItem(const string& word){
            item_count[word]++;
        }


        //creates the .dat file
        void createDatFile() const {
            ofstream outputfile;
            outputfile.open("frequency.dat");

            if(outputfile.is_open()) {
                for (const auto& pair : item_count) {
                outputfile << pair.first << ": " << pair.second << endl;
            }
            outputfile.close();
            } else {
                cerr << "Error: Unable to open the file" << endl;
            }
        }

        //prints out frequency of the word in question
        void getFrequency(const string& word) const {
            auto it = item_count.find(word);
            if(it != item_count.end()) {
                cout << it->first << ": " << it->second << endl;
            }
            else {
                cout << "Item not found" << endl;
            }
        }
        
        //prints out list that include numberic item counter
        void printItemNums() const {
            for (const auto& pair : item_count) {
                cout << pair.first << ": " << pair.second << endl;
            }
        }

        //prints out list that includes item counter in the form of 'X'
        void printItemAst() const {
            for (const auto& pair : item_count) {
                cout << pair.first << ": ";
                for (int i = 0; i < pair.second; ++i) {
                    cout << 'X';
                }
                cout << endl;
            }
        }
    
    private:
        map< string, int> item_count; 
};

//function that displays initial main menu
int mainMenu() {
    int number;
    cout << "This program reads data from a list of items and displays the information in the following manner:" << endl;
    cout << "1. Select an item and find specifc frequency" << endl;
    cout << "2. Displays list of items by 'Item: count'" << endl;
    cout << "3. Displays list of items by 'Item: XXX'" << endl;
    cout << "4. Exit" << endl;
    cout << endl;
    cout << "Please choose from the options above: ";
    cin >> number;
    return number;
}

//function that checks if user inputted just one word
string wordCheck() {
    string userInput;
    cout << "Input word to find frequency: ";
    
    // Clear the input buffer from previous cin >>
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    do {
        getline(cin, userInput);

        if (userInput.find(' ') != string::npos) {
            cout << "Please only type one word. Try again: ";
        }

    } while (userInput.find(' ') != string::npos);

    return userInput;
}

int main() {

    ItemCounter counter; //object of type itemcounter
    ifstream inputFile("groceries.txt"); //opens groceries.txt file

    //checks to see if file is openned properly
    //i wanted to make this into a function but was not successful, so it remains in main
    if(!inputFile.is_open()) {
        cerr << "Error: Count not open groceries.txt" << endl;
        return 1;
    }
    string item;
    while (inputFile >> item) {
        counter.addItem(item);
    }
    inputFile.close();

    //displays message to user that data was read and stored, so that the program can continue
    cout << "File sucessfully read and stored" << endl;
    cout << endl;

    int choice;
    do {
        choice = mainMenu(); //displays menu and stores user input
        switch (choice) {
            case 1:
                counter.getFrequency(wordCheck());
                break;
            case 2:
                cout << endl;
                cout << "---List of items with numbers---" << endl;
                counter.printItemNums();
                cout << endl;
                break;
            case 3:
                cout << endl;
                cout << "---List of items with 'X'---" << endl;
                counter.printItemAst();
                cout << endl;
                break;
            case 4:
                cout << "Exiting Program" << endl;
                break;
            default:
                cout << "Invalid choice. Please select a valid option(1-4)" << endl;
                break;
            }
            cout << endl;
    } while (choice != 4);

    counter.createDatFile();
    return 0;

}