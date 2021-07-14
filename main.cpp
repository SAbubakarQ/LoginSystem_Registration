// Bismillah - Abubakar Q

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Beginning with boolean logic
bool IsLoggedIn()
{
    string username, password, un, pw; // Variables used for program

    cout << "Enter username: "; // asking user for USERNAME
    cin >> username;

    cout << "Enter password: "; // asking user for PASSWORD
    cin >> password;
    
    ifstream read("data\\" + username + ".txt"); // Creating 'ifstream' variable with parameters 
    getline(read, un);
    getline(read, pw);

    if (un == username && pw == password) { // condition statement to verify password and username
            return true;
        }
    else {
            return false;
        }
}

int main() 
{
    int choice;

    cout << "1: Register\n";
    cout << "2: Login\n";
    cout << "Your Choice: ";
    cin >> choice;

    if (choice == 1)
    {
        string username, password; // string variables

        cout << "Input username: "; cin >> username; // users input
        cout << "Input password: "; cin >> password;

        ofstream userProfiles;
        userProfiles.open("data\\" + username + ".txt");
        userProfiles << username << endl << password;
        userProfiles.close();

        main();

    }
    else if (choice == 2)
    {
        bool status = IsLoggedIn(); // sets status to function to run function

        if (!status)
        {
            cout << "False Login!" << endl;
            cout << "System Terminating...\n";
            for (int i = 5; i > 0; i--)
            {
                cout << ".\n";
            }
            return 0;
        }
        else
        {
            cout << "Login Succesfull\n";
            cout << "Welcome!\n";
            return 1;

        }
    }
}