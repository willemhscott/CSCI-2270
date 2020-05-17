#include <iostream>
#include <ctime>

#include "AsyncManager.h"

// Checks whether _WIN32 is defined, if so we're on windows
#if defined(_WIN32)
#define unix false // Windows
// This is the windows select equivalent
// I would include it, but because it doesn't work for this project
// I've left it out
//#include <winsock2.h>

int AsyncManager::select(unsigned int fd) {
    /*
     * For full details, see the UNIX definition below
     *
     * NOTE: Windows does not treat stdin as a file, so this function acts as if
     * the file is always ready to read on Windows for cross compatability.
     * Windows does have a select library, but it only works on plain sockets.
     * Timers will resolve in between commands on Windows instead of concurrently
     */
    return 1;
}

#else
#define unix true // Otherwise

#include <sys/select.h>

int AsyncManager::select(unsigned int fd) {
    /*
     * This function takes one argument, fd.
     * fd is an integer representing the file descriptor (or handle) of a file / socket
     * This function returns whether we are ready to read from that fd, which
     * will be the file descriptor of stdin.
     *
     * NOTE: Windows does not treat stdin as a file, so this function acts as if
     * the file is always ready to read on Windows for cross compatibility.
     * Windows does have a select library, but it only works on plain sockets.
     * Timers will resolve in between commands on Windows instead of concurrently
     */
    int readStatus;
    fd_set infd;
    FD_ZERO(&infd);
    FD_SET(fd, &infd);

    // create a time struct that will tell select to wait for 200ms
    struct timeval time;
    time.tv_sec = 0;
    time.tv_usec = 200000;

    // readStatus will be 1 if the fd has received input
    // since we're only tracking one file descriptor (stdin)
    readStatus = ::select(fd + 1, &infd, nullptr, nullptr, &time);
    return readStatus;
}

#endif


bool AsyncManager::manageCheckouts() {
    /*
     * This function checks for due books and processes them between inputs
     * Returns true if any have been processed (and therefore anything has
     * been printed
     */
    time_t stime = time(nullptr); // Get current time
    int ptime;

    // If the current time has passed the time set to end, then that timer needs to be processed
    // Get smallest timer's finish time
    while ((ptime = timers.peek()) != 0 && ptime < (int) stime) {
        // Pop it from the timer queue and let the user know its checked in
        CheckedOutBook cb = timers.pop();
        cout << endl;
        cout << cb.name << " checked in " << cb.title << " by " << cb.author << endl;
        map.insert(cb.author, cb.title);
        return true;
    }
    return false;
}

void AsyncManager::asyncReadLine(string query, unsigned int fd, string &target) {
    /*
     * Return a line when ready, until then call `manageCheckouts`
     * A line is ready to be read when `select` returns a positive value
     * If the value is -1 we've received EOF (which should not happen)
     * If the value is 0, then the line is not yet ready, so check
     * for timmers again
     */
    cout << query << flush;
    string buffer;
    bool c = manageCheckouts();
    if (c) {
        cout << query << buffer << flush;
    }

    while (true) {
        int readStatus = select(fd);

        if (readStatus == -1) { // EOF
            exit(readStatus);
        } else if (readStatus) { // Ready to read
            /*
            char c = getchar();
            if (c == '\n') {
                target = buffer;
            }
            buffer += c;
            */
            getline(cin, target);
            return;
        } else { // Not ready to read, check for timers
            bool c = manageCheckouts();
            if (c) {
                cout << query << buffer << flush;
            }
        }
    }
}

void AsyncManager::printMenu() {
    cout << "1. Add Book" << endl;
    cout << "2. View Books By Author" << endl;
    cout << "3. View All Books" << endl;
    cout << "4. Check out a book" << endl;
    cout << "5. View Checked Out Books" << endl;
    cout << "6. Quit" << endl;
}

void AsyncManager::runCLI() {
    unsigned int fd;
    if (unix)
        fd = fileno(stdin);
    else
        fd = 0;
    printMenu();

    while (true) {
        // Throwaway variables for use inside the switch
        // Since new variables can't be declared inside a switch case
        string input;
        string input2;
        string input3;
        asyncReadLine(">> ", fd, input); // Get the user's choice
        int choice;
        BookList *bl;
        BookNode *n;

        switch (input.front()) {
            case '1':
                // Add a new book
                asyncReadLine("Author Name: ", fd, input);
                asyncReadLine("Book Title: ", fd, input2);
                map.insert(input, input2);
                cout << "Added book " << input2 << " by: " << input << endl;
                break;
            case '2':
                // See books by a given author
                asyncReadLine("Author Name: ", fd, input);
                bl = map.get(input);
                if (bl == nullptr) {
                    cout << "No books by " << input << endl;
                    break;
                }
                cout << "Books by " << input << endl;
                choice = 1;
                n = bl->head;
                while (n != nullptr) {
                    cout << choice << ". " << n->title << endl;
                    n = n->next;
                    choice++;
                }
                cout << endl;
                break;
            case '3':
                // See all books
                for (int i = 0; i < map.size; i++) {

                    bl = map.items[i];
                    if (bl == nullptr) {
                        continue;
                    }
                    cout << "Books by " << bl->author << endl;
                    choice = 1;
                    n = bl->head;
                    while (n != nullptr) {
                        cout << choice << ". " << n->title << endl;
                        n = n->next;
                        choice++;
                    }
                    cout << endl;

                }
                break;
            case '4':
                // Check out a book
                asyncReadLine("Your Name: ", fd, input);
                asyncReadLine("Author Name: ", fd, input2);
                asyncReadLine("Book Title: ", fd, input3);

                choice = map.pop(input2, input3); // "choice" -> success
                if (choice) {
                    timers.checkout(60, input, input2, input3);
                    cout << input << " checked out " << input3 << " by: " << input2 << " for 60 minutes " << endl;
                } else {
                    cout << "That book is not in stock!" << endl;
                }
                break;
            case '5':
                // See the currently checked out books
                timers.printTimers();
                break;
            case '6':
                // Exit
                exit(0);
            default:
                cout << "Invalid input!" << endl;
                break;

        }
        // Repeat the menu
        printMenu();
    }

}