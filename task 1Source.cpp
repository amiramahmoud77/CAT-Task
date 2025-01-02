#include <iostream>
#include <fstream>
#include <string>
using namespace std;
// Function to register a new user
void registerUser() {
    string username, email, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter email: ";
    cin >> email;
    cout << "Enter password: ";
    cin >> password;

    // Save user data to a file
    ofstream file("users.txt", ios::app); // Open file in append mode
    if (file.is_open()) {
        file << username << " " << email << " " << password << endl;
        cout << "User registered successfully!" << endl;
    }
    else {
        cout << "Error: Unable to open file." << endl;
    }
    file.close();
}

// Function to login an existing user
void loginUser() {
    string email, password, line;
    cout << "Enter email: ";
    cin >> email;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");
    bool isAuthenticated = false;
    if (file.is_open()) {
        while (getline(file, line)) {
            size_t emailPos = line.find(email);
            size_t passwordPos = line.find(password);
            if (emailPos != string::npos && passwordPos != string::npos) {
                isAuthenticated = true;
                break;
            }
        }
        file.close();
        if (isAuthenticated) {
            cout << "Login successful!" << endl;
        }
        else {
            cout << "Invalid email or password." << endl;
        }
    }
    else {
        cout << "Error: Unable to open file." << endl;
    }
}

int main() {
    int choice;
    cout << "1. Register\n2. Login\nEnter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        registerUser();
        break;
    case 2:
        loginUser();
        break;
    default:
        cout << "Invalid choice. Please try again." << endl;
    }

    return 0;
}
