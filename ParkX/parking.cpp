#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

const int MAX_USERS = 100; // Maximum number of users

class Time
{
private:
    time_t currentTime; // Store the current time

public:
    // Constructor to initialize the current time
    Time()
    {
        currentTime = time(0); // Get the current time
    }

    // Function to get the current time as a string
    string getCurrentTimeAsString()
    {
        return ctime(&currentTime); // Convert time to string and return
    }
};

class LoginSystem
{
private:
    string usernames[MAX_USERS];
    string passwords[MAX_USERS];
    int numUsers;

public:
    // Constructor
    LoginSystem()
    {
        numUsers = 0;
    }

    // Function to sign up a new user
    void signUp()
    {
        string newUsername, newPassword;
        cout << "Enter Username: ";
        cin >> newUsername;

        // Check if the username already exists
        for (int i = 0; i < numUsers; i++)
        {
            if (usernames[i] == newUsername)
            {
                cout << "Username already exists. Please choose a different one." << endl;
                return; // Exit the function if username exists
            }
        }

        // If username doesn't exist, proceed with sign-up
        if (numUsers < MAX_USERS)
        {
            cout << "Enter Password: ";
            cin >> newPassword;
            usernames[numUsers] = newUsername;
            passwords[numUsers] = newPassword;
            cout << "User signed up successfully!" << endl;
            numUsers++;
            saveData(); // Save data after sign up
        }
        else
        {
            cout << "Maximum number of users reached. Unable to sign up." << endl;
        }
    }

    // Function to log in a user
    bool login()
    {
        string username, password;
        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter Password: ";
        cin >> password;
        for (int i = 0; i < numUsers; i++)
        {
            if (usernames[i] == username && passwords[i] == password)
            {
                cout << "Login successful!" << endl;
                return true;
            }
        }
        cout << "User not found. Please sign up." << endl;
        return false;
    }

    // Function to reset password
    void resetPassword()
    {
        string username, newPassword;
        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter New Password: ";
        cin >> newPassword;
        for (int i = 0; i < numUsers; ++i)
        {
            if (usernames[i] == username)
            {
                passwords[i] = newPassword;
                cout << "Password reset successful!" << endl;
                saveData(); // Save data after password reset
                return;
            }
        }
        cout << "User not found. Please sign up." << endl;
    }

    // Function to save user data to a file
    void saveData()
    {
        ofstream write("userdata.txt");
        
        if (write.is_open())
        {
            write << numUsers << endl;
            for (int i = 0; i < numUsers; ++i)
            {
                write << "Username : " << usernames[i] << " \t Password : " << passwords[i] << endl;
            }
            write.close();
            cout << "Data saved successfully!" << endl;
        }
        else
        {
            cout << "Unable to open file to save data." << endl;
        }
    }

    // Function to load user data from a file
    void loadData()
    {
        ifstream read("userdata.txt");
        if (read.is_open())
        {
            read >> numUsers;
            for (int i = 0; i < numUsers; i++)
            {
                read >> usernames[i] >> passwords[i];
            }
            read.close();
            cout << "Data loaded successfully!" << endl;
        }
        else
        {
            cout << "No saved data found." << endl;
        }
    }
};

class Vehicle
{
protected:
    string model;
    string year;
    string color;

public:
    string getModel()
    {
        return model;
    }
    string getYear()
    {
        return year;
    }
    string getColor()
    {
        return color;
    }

    // Function to input vehicle information
    void inputInfo()
    {
        cin.ignore();
        cout << "Enter Model: ";
        getline(cin, model);
        cout << "Enter Year: ";
        cin >> year;
        cin.ignore();
        cout << "Enter Color: ";
        getline(cin, color);
    }

    // Function to display vehicle information
    void displayInfo()
    {
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
        cout << "Color: " << color << endl;
    }

    // Function to save vehicle data to a file
    void saveData()
    {
        ofstream write("vehicledata.txt", ios::app);
        if (write.is_open())
        {
            write << "Model : " << model << "\t Year : " << year << " \t Color :  " << color << endl;
            write.close();
            cout << "Vehicle data saved successfully!" << endl;
        }
        else
        {
            cout << "Unable to open file to save vehicle data." << endl;
        }
    }

    // Function to load vehicle data from a file
    void loadData()
    {
        ifstream read("vehicledata.txt");
        if (read.is_open())
        {
            string line;
            while (getline(read, line))
            {
                cout << line << endl;
            }
            read.close();
            cout << "Vehicle data loaded successfully!" << endl;
        }
        else
        {
            cout << "No saved vehicle data found." << endl;
        }
    }
};

class Car : public Vehicle
{
private:
    int numDoors;

public:
    // Function to input car information
    void inputInfo()
    {
        Vehicle::inputInfo();
        cout << "Enter Number of Doors: ";
        cin >> numDoors;
    }

    // Function to display car information
    void displayInfo()
    {
        Vehicle::displayInfo();
        cout << "Number of Doors: " << numDoors << endl;
    }

    // Function to save car data to a file
    void saveData()
    {
        ofstream write("vehicledata.txt", ios::app);
        if (write.is_open())
        {
            write << "Car: ";
            Vehicle::saveData();
        }
        else
        {
            cout << "Unable to open file to save vehicle data." << endl;
        }
    }
};

class Truck : public Vehicle
{
private:
    int loadCapacity;

public:
    // Function to input truck information
    void inputInfo()
    {
        Vehicle::inputInfo();
        cout << "Enter Load Capacity (in tons): ";
        cin >> loadCapacity;
    }

    // Function to display truck information
    void displayInfo()
    {
        Vehicle::displayInfo();
        cout << "Load Capacity: " << loadCapacity << " tons" << endl;
    }

    // Function to save truck data to a file
    void saveData()
    {
        ofstream write("vehicledata.txt", ios::app);
        if (write.is_open())
        {
            write << "Truck: ";
            Vehicle::saveData();
        }
        else
        {
            cout << "Unable to open file to save vehicle data." << endl;
        }
    }
};

class Bike : public Vehicle
{
private:
    string type;

public:
    // Function to input bike information
    void inputInfo()
    {
        Vehicle::inputInfo();
        cout << "Enter Bike Type: ";
        cin.ignore();
        getline(cin, type);
    }

    // Function to display bike information
    void displayInfo()
    {
        Vehicle::displayInfo();
        cout << "Bike Type: " << type << endl;
    }

    // Function to save bike data to a file
    void saveData()
    {
        ofstream write("vehicledata.txt", ios::app);
        if (write.is_open())
        {
            write << "Bike: ";
            Vehicle::saveData();
        }
        else
        {
            cout << "Unable to open file to save vehicle data." << endl;
        }
    }
};

class PaymentCalculator
{
public:
    // Function to calculate payment based on logic
    static double getAmountFromLogic(int numDays, string vehicleType)
    {
        double amountPerDay = 0.0;

        // Set the amount per day based on the vehicle type
        if (vehicleType == "Car")
        {
            amountPerDay = 10.0;
        }
        else if (vehicleType == "Truck")
        {
            amountPerDay = 15.0;
        }
        else if (vehicleType == "Bike")
        {
            amountPerDay = 5.0;
        }
        else
        {
            // Handle invalid vehicle type
            cout << "Invalid vehicle type!" << endl;
            return 0.0; // Return 0 if the vehicle type is invalid
        }

        // Calculate the total amount based on the number of days
        return amountPerDay * numDays;
    }
};

class ParkingTicket
{
private:
    string username;
    string model;
    string year;
    string color;

public:
    ParkingTicket(string username, string model, string year, string color)
    {
        this->username = username;
        this->model = model;
        this->year = year;
        this->color = color;
    }

    // Function to generate parking ticket
    void generateTicket()
    {
        cout << "\nGenerating Parking Ticket for User: " << username << endl;
        cout << "-------------------------------------" << endl;
        cout << "Model: " << model << endl; // Print model
        cout << "Year: " << year << endl;   // Print year
        cout << "Color: " << color << endl; // Print color
        cout << "Parking ticket generated successfully!" << endl;
    }
};

class Payment
{
private:
    string username;
    double amount;
    Time currentTime; // Add a Time object to get the current time

public:
    // Function to set username, amount, and current time
    void setPaymentDetails(string username, double amount)
    {
        this->username = username;
        this->amount = amount;
    }

    // Function to process payment with parking duration and display receipt
    void processPayment(double parkingDuration)
    {
        // Display the payment receipt
        cout << "Payment Receipt:" << endl;
        cout << "----------------" << endl;
        cout << "Username: " << username << endl;
        cout << "Amount: $" << amount << endl;
        cout << "Payment Time: " << currentTime.getCurrentTimeAsString(); // Display the current time
    }
};

class LogoutSystem
{
public:
    // Function to log out a user
    void logout()
    {
        cout << "Logged out successfully!" << endl;
    }
};

int main()
{
    LoginSystem loginSystem;
    loginSystem.loadData();

    Vehicle vehicle;
    Payment payment;
    LogoutSystem logoutSystem;

    int choice = 0;
    while (choice != 5)
    {
        cout << "\nWelcome to Parking System!" << endl;
        cout << "1. Login" << endl;
        cout << "2. Sign up" << endl;
        cout << "3. Reset Password" << endl;
        cout << "4. Display All Vehicle Data" << endl;
        cout << "5. Logout" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (loginSystem.login())
            {
                int vehicleChoice;
                cout << "Enter the type of vehicle to add:" << endl;
                cout << "1. Car" << endl;
                cout << "2. Truck" << endl;
                cout << "3. Bike" << endl;
                cin >> vehicleChoice;

                string vehicleType;

                switch (vehicleChoice)
                {
                case 1:
                {
                    vehicleType = "Car";
                    Car car;
                    car.inputInfo(); // Input car information
                    car.saveData();  // Save car data
                    vehicle = car;   // Assign car to vehicle
                    break;
                }
                case 2:
                {
                    vehicleType = "Truck";
                    Truck truck;
                    truck.inputInfo(); // Input truck information
                    truck.saveData();  // Save truck data
                    vehicle = truck;   // Assign truck to vehicle
                    break;
                }
                case 3:
                {
                    vehicleType = "Bike";
                    Bike bike;
                    bike.inputInfo(); // Input bike information
                    bike.saveData();  // Save bike data
                    vehicle = bike;   // Assign bike to vehicle
                    break;
                }
                default:
                    cout << "Invalid choice!" << endl;
                    continue; // Go back to the main menu
                }

                // Generate parking ticket
                string username;
                cout << "Enter username for parking ticket: ";
                cin >> username;

                // Pass vehicle details to the ParkingTicket constructor
                ParkingTicket ticket(username, vehicle.getModel(), vehicle.getYear(), vehicle.getColor());
                ticket.generateTicket();

                // Get number of days
                int numDays;
                cout << "Enter number of days for parking: ";
                cin >> numDays;

                // Calculate payment amount
                double amount = PaymentCalculator::getAmountFromLogic(numDays, vehicleType);

                // Process payment
                double parkingDuration = numDays * 24.0;     // Assuming 24 hours per day
                payment.setPaymentDetails(username, amount); // Set payment details with username and amount
                payment.processPayment(parkingDuration);     // Pass the parking duration to processPayment
            }
            break;

        case 2:
            loginSystem.signUp();
            break;

        case 3:
            loginSystem.resetPassword();
            break;

        case 4:
        {
            cout << "\nLoading and displaying all vehicle data from file:" << endl;
            vehicle.loadData();

            cout << "\n--------------------------------------" << endl;
            cout << "All Vehicle Data:" << endl;

            // Display the data in a formatted manner
            ifstream read("vehicledata.txt");
            if (read.is_open())
            {
                string line;
                while (getline(read, line))
                {
                    cout << line << endl;
                }
                read.close();
                cout << "--------------------------------------" << endl;
                cout << "End of Vehicle Data" << endl;
            }
            else
            {
                cout << "No saved vehicle data found." << endl;
            }
            break;
        }

        case 5:
            logoutSystem.logout();
            exit(0);

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }

    return 0;
}
