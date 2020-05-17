/****************************************************************/
/*                   Assignment 4 Driver File                   */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "CountryNetwork.hpp"
// you may include more libraries as needed

using namespace std;

void displayMenu();

int main(int argc, char *argv[]) {
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
void displayMenu() {
    CountryNetwork countryNet = CountryNetwork();
    while (true) {
        cout << "Select a numerical option:" << endl;
        cout << "+=====Main Menu=========+" << endl;
        cout << " 1. Build Network " << endl;
        cout << " 2. Print Network Path " << endl;
        cout << " 3. Add Country " << endl;
        cout << " 4. Delete Country " << endl;
        cout << " 5. Reverse Network" << endl;
        cout << " 6. Rotate Network" << endl;
        cout << " 7. Clear Network " << endl;
        cout << " 8. Quit " << endl;
        cout << "+-----------------------+" << endl;
        cout << "#> ";
        int choice;
        string pass;
        string name;
        string message;
        string cname;
        string pname;
        Country *prev = nullptr;
        getline(cin, pass);
        choice = stoi(pass);

        switch (choice) {
            case 8:
                cout << "Quitting... cleaning up path:" << endl;
                countryNet.printPath();
                countryNet.deleteEntireNetwork();
                if (countryNet.isEmpty()) {
                    cout << "Path cleaned" << endl;
                } else {
                    cout << "Error: Path NOT cleaned!" << endl;
                }
                return;
            case 1:
                countryNet.loadDefaultSetup();
                countryNet.printPath();
                break;
            case 2:
                countryNet.printPath();
                break;
            case 3:
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

            case 4:
                cout << "Enter a country name:" << endl;
                getline(cin, pname);
                countryNet.deleteCountry(pname);
                countryNet.printPath();

                break;
            case 5:
                countryNet.reverseEntireNetwork();
                countryNet.printPath();

                break;
            case 6:
                cout << "Enter the count of values to be rotated:" << endl;
                getline(cin, pname);
                countryNet.rotateNetwork(stoi(pname));
                countryNet.printPath();

                break;
            case 7:
                cout << "Network before deletion" << endl;
                countryNet.printPath();
                countryNet.deleteEntireNetwork();
                cout << "Network after deletion" << endl;
                countryNet.printPath();
                break;
        }
    }
}
