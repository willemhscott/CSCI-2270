/****************************************************************/
/*                CountryNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CountryNetwork */
/*     This class uses a linked-list of Country structs to      */
/*     represet communication paths between nations             */
/****************************************************************/

#include "CountryNetwork.hpp"

using namespace std;

/*
 * Purpose: Constructor for empty linked list
 * @param none
 * @return none
 */
CountryNetwork::CountryNetwork() {
    head = nullptr;
}


/*
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool CountryNetwork::isEmpty() {
    return head == nullptr;
}


/*
 * Purpose: Add a new Country to the network
 *   between the Country *previous and the Country that follows it in the network.
 * @param previous name of the Country that comes before the new Country
 * @param countryName name of the new Country
 * @return none
 */
void CountryNetwork::insertCountry(Country *previous, string countryName) {
    if (previous == nullptr) {
        if (head != nullptr) {
            Country *phead = head;
            head = new Country;
            head->numberMessages = 0;
            head->name = countryName;
            head->next = phead;
            cout << "adding: " << countryName << " (HEAD)" << endl;
            return;
        }
        head = new Country;
        head->numberMessages = 0;
        head->name = countryName;
        head->next = nullptr;
        cout << "adding: " << countryName << " (HEAD)" << endl;
    } else {
        Country *node = head;
        while (node != previous) {
            node = node->next;
        }
        Country *pnext = previous->next;
        previous->next = new Country;
        previous->next->name = countryName;
        previous->next->next = pnext;
        previous->next->numberMessages = 0;
        cout << "adding: " << countryName << " (prev: " << previous->name << ")" << endl;
    }

}


/*
 * Purpose: delete the country in the network with the specified name.
 * @param countryName name of the country to delete in the network
 * @return none
 */
void CountryNetwork::deleteCountry(string countryName) {
    if (countryName == head->name) {
        Country *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Country *previous = head;
    Country *country = head->next;
    while (country) {
        if (country->name == countryName) {
            break;
        }
        previous = country;
        country = country->next;
    }
    if (country == nullptr) {
        cout << "Country does not exist." << endl;
        return;
    }
    previous->next = country->next;
    delete country;
}

/*
 * Purpose: populates the network with the predetermined countries
 * @param none
 * @return none
 */
void CountryNetwork::loadDefaultSetup() {
    string countries[] = {"Canada", "Brazil", "India", "China", "Australia"};
    insertCountry(nullptr, "United States");
    Country *previous = head;
    for (int i = 0; i < 5; i++) {
        insertCountry(previous, countries[i]);
        previous = previous->next;
    }
}


/*
 * Purpose: Search the network for the specified country and return a pointer to that node
 * @param countryName name of the country to look for in network
 * @return pointer to node of countryName, or NULL if not found
 * @see insertCountry, deletecountry
 */
Country *CountryNetwork::searchNetwork(string countryName) {
    Country *node = head;
    while (node != nullptr && node->name != countryName) {
        node = node->next;
    }
    return node;
}


/*
 * Purpose: deletes all countries in the network starting at the head country.
 * @param none
 * @return none
 */
void CountryNetwork::deleteEntireNetwork() {
    if (head != nullptr) {
        Country *previous = head;
        Country *current = head->next;
        while (current) {
            cout << "deleting: " << previous->name << endl;
            delete previous;
            previous = current;
            current = current->next;
        }
        cout << "deleting: " << previous->name << endl;
        delete previous;
        head = nullptr;
        cout << "Deleted network" << endl;
    }

}

/*
 * Purpose: Rotate the linked list i.e. move 'n' elements from
 * the back of the the linked to the front in the same order.
 * @param number elements to be moved from the end of the list to the beginning
 * @return none
 */
void CountryNetwork::rotateNetwork(int n) {
    if (isEmpty()) {
        cout << "Linked List is Empty" << endl;
        return;
    }

    int count = 1;
    Country *end = head;
    while (end->next) {
        count++;
        end = end->next;
    }

    if (n > count) {
        cout << "Rotate not possible" << endl;
        return;
    }

    Country *newend = head;
    Country *newhead = head->next;
    for (int i = 0; i < n - 1; i++) {
        newend = newhead;
        newhead = newhead->next;
    }

    end->next = head;
    head = newhead;
    newend->next = nullptr;
    cout << "Rotate Complete" << endl;
}

/*
 * Purpose: reverse the entire network
 * @param ptr head of list
 */
void CountryNetwork::reverseEntireNetwork() {
    if (isEmpty()) {
        return;
    }
    Country *previous = head;
    Country *current = head->next;
    Country *next = head->next->next;
    previous->next = nullptr;

    while (next) {
        //cout << current->name << endl;
        current->next = previous;
        previous = current;
        current = next;
        next = next->next;
    }
    current->next = previous;
    head = current;
}

/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CountryNetwork::printPath() {
    cout << "== CURRENT PATH ==" << endl;
    Country *node = head;
    if (node == nullptr) {
        cout << "nothing in path" << endl << "===" << endl;
        return;
    }
    while (node) {
        //cout << "errr" << endl;
        cout << node->name << " -> ";
        //cout << &node->next;
        node = node->next;
    }
    cout << "NULL" << endl << "===" << endl;

}
