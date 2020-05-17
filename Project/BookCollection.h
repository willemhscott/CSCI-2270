#include <string>

using namespace std;


struct BookNode {
    /*
     * A simple struct for holding Books in our linked list
     */
    BookNode *next;
    string title;

    explicit BookNode(string name) {
        title = name;
        next = nullptr;
    }
};

class BookList {
public:
    string author;

    BookList() {
        // Throwaway constructor
        author = "";
        head = nullptr;
    }

    explicit BookList(string name) {
        /*
         * A linked list to store the books
         */
        author = name;
        head = nullptr;
    }

    void append(string title) {
        /*
         * Simple linked list append to end, we don't care much about the ordering
         */
        if (head == nullptr) {
            head = new BookNode(title);
        } else {
            BookNode *n = head;
            while (n->next != nullptr) {
                n = n->next;
            }
            n->next = new BookNode(title);
        }
    }

    BookNode *head;
};


class BookMap {
public:
    BookMap();

    void insert(string, string);

    void insert(BookList *);

    bool pop(string, string);

    BookList *get(string);

    int size;
    BookList **items;

    int hash(string);
};
