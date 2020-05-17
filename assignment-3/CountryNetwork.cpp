/****************************************************************/
/*                CountryNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CountryNetwork */
/*     This class uses a linked-list of Country structs to      */
/*     represet communication paths between nations             */
/****************************************************************/

#include "CountryNetwork.hpp"

using namespace std;

int size;
/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
CountryNetwork::CountryNetwork()
{
    head = nullptr;
    size = 0;
}


/*
 * Purpose: Add a new Country to the network
 *   between the Country *previous and the Country that follows it in the network.
 * @param previous name of the Country that comes before the new Country
 * @param countryName name of the new Country
 * @return none
 */
void CountryNetwork::insertCountry(Country* previous, string countryName)
{
    size += 1;
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
 * Purpose: populates the network with the predetermined countries
 * @param none
 * @return none
 */
void CountryNetwork::loadDefaultSetup()
{
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
 */
Country* CountryNetwork::searchNetwork(string countryName)
{
    Country *node = head;
    while (node != nullptr && node->name != countryName) {
        node = node->next;
    }
    return node;
}

/*
 * Purpose: Transmit a message across the network to the
 *   receiver. Msg should be stored in each country it arrives
 *   at, and should increment that country's count.
 * @param receiver name of the country to receive the message
 * @param message the message to send to the receiver
 * @return none
 */
void CountryNetwork::transmitMsg(string receiver, string message)
{
    if (head == nullptr) {
        cout << "Empty list" << endl;
        return;
    }
    if (searchNetwork(receiver) == nullptr) {
        cout << "Country not found" << endl;
        return;
    }
    Country *node = head;
    //Country *previous = nullptr;
    node->message = message;
    node->numberMessages +=1;
    cout << node->name << " [# messages received: " << node->numberMessages << "] received: " << node->message << endl;
    while (node->name != receiver) {
        //previous = node;
        node = node->next;

        node->message = message;
        node->numberMessages += 1;
        cout << node->name << " [# messages received: " << node->numberMessages << "] received: " << node->message << endl;
    }

}


/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CountryNetwork::printPath()
{
    cout << "== CURRENT PATH ==" << endl;
    Country *node = head;
    if (node == nullptr) {
        cout << "nothing in path" << endl << "===" << endl;
        return;
    }
    int i = 0;
    for (; i < size; i++) {
        //cout << "errr" << endl;
        cout << node->name << " -> ";
        //cout << &node->next;
        node = node->next;
    }
    cout << "NULL" << endl << "===" << endl;
}
