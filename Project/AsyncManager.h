#include "CheckoutTimers.h"
#include "BookCollection.h"

class AsyncManager {
    /*
     * This class manages the parts of the application
     * 1. The Book Mapping - A HashMap mapping authors to lists of their books
     * 2. The Timers - A priority queue of books which have been checked out
     * 3. The select function, which manages these two and invokes them as necessary
     */
public:
    AsyncManager() {
        timers = CheckoutTimers();
        map = BookMap();
    }
    static int select(unsigned int fd);
    bool manageCheckouts();
    void asyncReadLine(string, unsigned int, string&);
    void runCLI();
    static void printMenu();

private:
    CheckoutTimers timers;
    BookMap map;
};
