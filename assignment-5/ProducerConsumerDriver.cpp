/****************************************************************/
/*                Producer Consumer Driver File                 */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "ProducerConsumer.hpp"
#include <iostream>
// you may include more libraries as needed

using namespace std;

/*
 * Purpose: displays a menu with options
 * @param none
 * @return none
 */
void menu()
{
	cout << "*----------------------------------------*" << endl;
	cout << "Choose an option:" << endl;
    cout << "1. Producer (Produce items into the queue)" << endl;
	cout << "2. Consumer (Consume items from the queue)" << endl;
	cout << "3. Return the queue size and exit" << endl;
	cout << "*----------------------------------------*" << endl;
}

int main(int argc, char const *argv[])
{
    ProducerConsumer queue = ProducerConsumer();
    while (true) {
        menu();
        string input;
        getline(cin, input);
        int choice = stoi(input);
        bool brk = false;

        switch (choice) {
            case 3:
                cout << "Number of items in the queue:" << queue.queueSize() << endl;
                brk = true;
                break;
            case 1:
                cout << "Enter the number of items to be produced:" << endl;
                getline(cin, input);
                choice = stoi(input);
                for (int i = 0; i < choice; i++) {
                    cout << "Item" << i + 1 << ":" << endl;
                    getline(cin, input);
                    queue.enqueue(input);
                }
                break;
            case 2:
                cout << "Enter the number of items to be consumed:" << endl;
                getline(cin, input);
                choice = stoi(input);
                for (int i = 0; i < choice; i++) {
                    if (queue.isEmpty()) {
                        cout << "No more items to consume from queue" << endl;
                        break;
                    }
                    cout << "Consumed: " << queue.peek() << endl;
                    queue.dequeue();
                }
                break;
        }
        if (brk) {
            break;
        }
    }
}
