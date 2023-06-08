#include<iostream>
#include<string>
using namespace std;

// Define the City struct
struct City {
    string name;  // City name
    int population;  // City population
    int income;  // Median household income
    City* next;  // Pointer to the next city
};

// Initialize the head and tail pointers
City* head = NULL;
City* tail = NULL;

// Function to add a city at the tail of the list
void addCityAtTail() {
    // Get input from the user
    string name;
    int population, income;
    cout << "Enter city name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter city population: ";
    cin >> population;
    cout << "Enter median household income: ";
    cin >> income;

    // Create a new city node
    City* newCity = new City();
    newCity->name = name;
    newCity->population = population;
    newCity->income = income;
    newCity->next = NULL;  // This will be the last node, so next is NULL

    // If the list is empty, this new node is both the head and the tail
    if(head == NULL) {
        head = newCity;
        tail = newCity;
    } else {  // Otherwise, add the new node to the end of the list
        tail->next = newCity;  // Update the old tail node to point to the new node
        tail = newCity;  // The new node is now the tail
    }
}

// Function to add a city at the head of the list
void addCityAtHead() {
    // Get input from the user
    string name;
    int population, income;
    cout << "Enter city name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter city population: ";
    cin >> population;
    cout << "Enter median household income: ";
    cin >> income;

    // Create a new city node
    City* newCity = new City();
    newCity->name = name;
    newCity->population = population;
    newCity->income = income;

    // If the list is empty, this new node is both the head and the tail
    if(head == NULL) {
        newCity->next = NULL;
        head = newCity;
        tail = newCity;
    } else {  // Otherwise, add the new node to the start of the list
        newCity->next = head;  // The new node points to the old head
        head = newCity;  // The new node is now the head
    }
}

// Function to display the city with the largest population
void displayLargestCity() {
    // If the head is NULL, the list is empty, so print "No city records" and return
    if(head == NULL) {
        cout << "No city records" << endl;
        return;
    }

    // Initialize temporary pointer to the head of the list
    City* temp = head;
    // Initialize a pointer to keep track of the city with the largest population
    City* largest = head;

    // Traverse through the list
    while(temp != NULL) {
        // If the current city's population is larger than the largest seen so far,
        // update the largest pointer
        if(temp->population > largest->population) {
            largest = temp;
        }

        // Move to the next city
        temp = temp->next;
    }

    // Display the city with the largest population
    cout << largest->name << ", " << largest->population << ", " << "$" << largest->income << endl;
}


// Function to display all cities in the list
void displayAllCities() {
    // If the list is empty, print "No city records" and return
    if(head == NULL) {
        cout << "No city records" << endl;
        return;
    }

    // Initialize a temporary pointer to the head of the list
    City* temp = head;

    // Traverse the list
    while(temp != NULL) {
        // Print the details of the current city
        cout << temp->name << ", " << temp->population << ", " << "$" << temp->income << endl;
        // Move to the next city
        temp = temp->next;
    }
}


int main() {
    int option;
    // Run the menu until the user chooses to exit (option 5)
    do {
        // Display the menu options
        cout << "\n1. Add city record at the tail.\n";
        cout << "2. Add city record at the head.\n";
        cout << "3. Display the city with largest population.\n";
        cout << "4. Display all the city records.\n";
        cout << "5. Exit\n";
        cout << "Enter your option: ";
        // Take the user's choice
        cin >> option;

        // Perform an action based on the user's choice
        switch(option) {
            case 1:
                // Add a new city at the tail of the list
                addCityAtTail();
                break;
            case 2:
                // Add a new city at the head of the list
                addCityAtHead();
                break;
            case 3:
                // Display the city with the largest population
                displayLargestCity();
                break;
            case 4:
                // Display all the cities in the list
                displayAllCities();
                break;
            case 5:
                // Exit the program
                cout << "Exiting...\n";
                break;
            default:
                // The user entered an invalid option
                cout << "Invalid option. Try again...\n";
                break;
        }
    // If the user chooses option 5, exit the loop and end the program
    } while(option != 5);

    return 0;
}
