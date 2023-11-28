#include <iostream> 
#include <iomanip> 
#include <map> //Map Standard Template Library (STL) header file
#include <string> 

using namespace std;

// User structure to store user information
struct User {
    string username;
    string validID;
    bool loggedIn;
    string rentedCar;
    int rentalDuration;
};
// Car structure - to store car information
struct Car {
    string model;
    string color;
    int topSpeed;
    int pricePerDay;
    bool isRented;
};

// Function to display car choices
void displayCarChoices() {
    cout << "\n" << setw(98) << "--------------------------------------\n";
    cout << "\n" << setw(85) << "CAR SELECTION\n";
    cout << "\n" << setw(98) << "--------------------------------------\n";

    cout << setw(84) << "Choose a car:" << endl;
    cout << setw(85) << "a. 2018 Honda Civic Type R" << endl;
    cout << setw(76) << "b. Honda Civic EG" << endl;
    cout << setw(90) << "c. '99 Honda Civic Type R (EK9)" << endl;
    cout << setw(76) << "d. Bugatti Bolide" << endl;
    cout << setw(77) << "e. Porsche 911 GT3" << endl;
    cout << setw(76) << "f. Tesla Roadster" << endl;
    cout << setw(81) << "g. Ferrari Daytona SP3" << endl;
    cout << setw(82) << "h. Lamborghini Reventon" << endl;
    cout << setw(85) << "i. Lamborghini Sian FKP 37" << endl;
    cout << setw(72) << "j. F8 Tributo" << endl;
    cout << setw(91) << "Enter the car you wish to rent: ";
}

// Display car information
void displayCarInfo(const Car& car) {
    cout << "\n" << setw(98) << "--------------------------------------\n";
    cout << "\n" << setw(84) << "CAR DETAILS\n";
    cout << "\n" << setw(98) << "--------------------------------------\n";
    cout << setw(66) << "Model: " << car.model << endl;
    cout << setw(66) << "Color: " << car.color << endl;
    cout << setw(70) <<"Top Speed: " << car.topSpeed << " km/h" << endl;
    cout << setw(68) <<"Price: P " << car.pricePerDay << " / day\n" << endl;
}

// Update rental status
void updateRentalStatus(map<char, Car>& cars, char carChoice, bool rented) {
    if (cars.count(carChoice)) {
        cars[carChoice].isRented = rented;
    }
}

// Main function
int main() {
    // Map - to store car information - to implement an associative container that stores key-value pairs
    map<char, Car> cars = {
        {'a', {"2018 Honda Civic Type R", "White", 272, 3000, false}},
        {'b', {"Honda Civic EG", "Yellow", 200, 2500, false}},
        {'c', {"'99 Honda Civic Type R (EK9)", "Yellow", 225, 2800, false}},
        {'d', {"Bugatti Bolide", "Black & Blue", 500, 5000, false}},
        {'e', {"Porsche 911 GT3", "White", 319, 10000, false}},
        {'f', {"Tesla Roadster", "Orange", 410, 10500, false}},
        {'g', {"Ferrari Daytona SP3", "Dark Blue", 340, 10300, false}},
        {'h', {"Lamborghini Reventon", "Red", 340, 10300, false}},
        {'i', {"Lamborghini Sian FKP 37", "Dark Green", 350, 12000, false}},
        {'j', {"Ferrari F8 Tributo", "Dark Blue", 340, 12000, false}}
    };

    // Map - to store user information
    map<int, User> users;

    // Display main menu
    while (true) {

        cout << "\n" << setw(98) << "--------------------------------------\n";
        cout << "\n" << setw(98) << "Welcome to Caxie's Car Rental Company!\n";
        cout << "\n" << setw(98) << "--------------------------------------\n";

        cout << setw(80) << "Main Menu:" << endl;
        cout << setw(80) << "1. Create an account" << endl;
        cout << setw(68) << "2. Login" << endl;
        cout << setw(67) << "3. Exit" << endl;
        cout << "\n" << setw(82) << "Enter an option: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                // Create an account
                User newUser;
                cout << setw(78) << "Enter a username: ";
                cin >> newUser.username;
                cout << setw(86) << "Enter number of valid ID: ";
                cin >> newUser.validID;

                newUser.loggedIn = false;
                newUser.rentedCar = "";
                newUser.rentalDuration = 0;

                users[1] = newUser; // Assuming for only one user. Couldn't make it for multiple users it's too advance for me
                cout << "\n" << setw(89) << "Account created successfully!" << endl;
                break;
            }
            case 2: {
                // Login
                string username;
                string validID; 
                cout << setw(81) << "Enter your username: ";
                cin >> username;
                cout << setw(81) << "Enter your valid ID: ";
                cin >> validID;

                if (users.count(1) && users[1].username == username && users[1].validID == validID) {
                    users[1].loggedIn = true;
                    cout << "\n" << setw(77) << "Login successful!" << endl;
                } else {
                    cout << "\n" << setw(98) << "User not found or invalid credentials." << "\n" << setw(87) << "Returning to the main menu." << endl;
                    continue;
                }

                // Car rental menu
                while (users[1].loggedIn) {
                    displayCarChoices();

                    char carChoice;
                    cin >> carChoice;

                    if (cars.count(carChoice)) {
                        if (!cars[carChoice].isRented) {
                            // Display user's car choice
                            cout << "\n" << setw(87) << "You have chosen: \n" << setw(77) << carChoice << endl;

                            // Display car information
                            displayCarInfo(cars[carChoice]);

                            // Confirmation of rental
                            cout << "\n" << setw(96) << "Do you want to rent this car? (y/n): ";
                            char confirmChoice;
                            cin >> confirmChoice;

                            if (confirmChoice == 'y') {
                            

                                // Enter the rental duration
                                cout << setw(97) << "Enter the duration of rent (in days): ";
                                cin >> users[1].rentalDuration;

                                // Update rental status to true
                                updateRentalStatus(cars, carChoice, true);

                                // Calculation of rental price
                                int totalPrice = users[1].rentalDuration * cars[carChoice].pricePerDay;

                                // Display price and ask for user's payment
                                cout << setw(74) << "Total Price: P " << totalPrice << endl;
                                cout << "\n" << setw(90) << "Enter the amount of payment: P ";
                                int payment;
                                cin >> payment;

                                // Check whether payment is sufficient
                                if (payment >= totalPrice) {
                                    // Display receipt if the value of payment is enough
                                    cout << "\n" << setw(98) << "--------------------------------------\n";
                                    cout << "\n" << setw(82) << "RECEIPT\n";
                                    cout << "\n" << setw(98) << "--------------------------------------\n";

                                    cout << setw(77) <<"Duration of Rent: " << users[1].rentalDuration << " day/s" << endl;
                                    cout << setw(74) << "Total Price: P " << totalPrice << endl;
                                    cout << setw(74) << "Amount Paid: P " << payment << endl;
                                    cout << setw(69) << "Change: P " << (payment - totalPrice) << endl;
                                    cout << "\n" << setw(95) << "Thank you for renting a car with us!" << "\n" << setw(87) << "Until our next transaction!\n" << endl;
                                    cout << setw(84) << "Logged out.\n" << endl;

                                    // Update the user information
                                    users[1].rentedCar = cars[carChoice].model;
                                    users[1].loggedIn = false;
                                    users[1].rentalDuration = 0;
                                } else {
                                    cout << setw(80) << "Insufficient payment." << "\n" << setw(85) << "Rental canceled." << endl;
                                }
                            } else {
                                cout << setw(85) << "Rental canceled." << endl;
                            }
                        } else {
                            cout << setw(85) << "The car is already rented." << "\n" << setw(85) << " Select another car choice." << endl;
                        }
                    } else {
                        cout << setw(74) << "Invalid choice." << "\n" << setw(85) << " Please choose a valid car." << endl;
                    }
                }
                break;
            }
            case 3: {
                // Exit
                cout << setw(87) << "Exiting program. Bye!" << endl;
                return 0;
            }
            default: {
                // Invalid option
                cout << setw(80) << "Invalid choice." << "\n" << setw(87) << " Please enter a valid option." << endl;
                break;
            }
        }
    }

    return 0;
}
