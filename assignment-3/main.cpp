/****************************************************************/
/*                   Assignment 3 Driver File                   */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "CountryNetwork.hpp"
// you may include more libraries as needed
using namespace std;
// declarations for main helper-functions
void displayMenu();

int main(int argc, char* argv[])
{
    // Object representing our network of cities.
    // (Linked list representation is in CountryNetwork)
    //CountryNetwork CountryNet;
// 1) Construct default setup
    displayMenu();
    cout << "Goodbye!" << endl;
    return 0;
}


/*
 * Purpose; displays a menu with options
 */
void displayMenu()
{
    CountryNetwork countryNet = CountryNetwork();
    while (true) {
        cout << "Select a numerical option:" << endl;
        cout << "+=====Main Menu=========+" << endl;
        cout << " 1. Build Network " << endl;
        cout << " 2. Print Network Path " << endl;
        cout << " 3. Transmit Message " << endl;
        cout << " 4. Add Country " << endl;
        cout << " 5. Quit " << endl;
        cout << "+-----------------------+" << endl;
        cout << "#> ";
        int choice;
        string pass;
        string name;
        string message;
        string cname;
        string pname;
        getline(cin, pass);
        choice = stoi(pass);

        switch (choice) {
            case 5:
                cout << "Quitting..." << endl;
                return;
            case 1:
                countryNet.loadDefaultSetup();
                countryNet.printPath();
                break;
            case 2:
                countryNet.printPath();
                break;
            case 3:
                cout << "Enter name of the country to receive the message:" << endl;
                getline(cin, name);
                cout << "Enter the message to send:" << endl << endl;
                getline(cin, message);
                countryNet.transmitMsg(name, message);
                break;
            case 4:
                Country *prev = nullptr;
                cout << "Enter a new country name:" << endl;
                getline(cin, cname);

                cout << "Enter the previous country name (or First):" << endl;

                while (true) {
                    getline(cin, pname);

                    prev = countryNet.searchNetwork(pname);
                    //cout << pname << prev << endl;
                    if (pname != "First" && prev == nullptr) {
                        cout << "INVALID(previous country name)...Please enter a VALID previous country name!" << endl;
                    } else {
                        break;
                    }
                }

                countryNet.insertCountry(prev, cname);
                countryNet.printPath();
                break;
        }
    }
}
