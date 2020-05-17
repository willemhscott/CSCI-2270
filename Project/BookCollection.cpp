#include <iostream>
#include "BookCollection.h"

using namespace std;

BookMap::BookMap() {
    /*
     * Create a new HashMap of size 8
     * All collisions are handled by increasing the size
     * of the HashMap.
     */
    size = 8;
    items = new BookList *[size];
    for (int i = 0; i < size; i++) {
        items[i] = nullptr;
    }
}

int BookMap::hash(string author) {
    /*
     * Hashing is just the sum of the ordinals
     * of the characters in the author's name
     * Just as soon this could be replaced with the
     * address of the string to ensure no guaranteed
     * collisions when the map is resized
     */
    int sum = 0;
    for (int i = 0; i < author.size(); i++) {
        sum += author[i];
    }
    return sum % size;
}

BookList *BookMap::get(string author) {
    /*
     * Return a pointer to the BookList for the given author
     * Return nullptr if an entry hasn't been created for the author
     */
    int h = hash(author);

    BookList *l = items[h];
    if (l == nullptr || l->author != author)
        return nullptr;
    return l;
}

void BookMap::insert(string author, string title) {
    /*
     * Insert a title where it belongs
     * If there is a hash collision, increase the size of the table and try again
     * Recursion should resolve all issues if there are multiple consecutive
     * collisions
     */
    int h = hash(author);

    if (items[h] == nullptr) { // Author entry hasn't been created
        items[h] = new BookList(author);
        items[h]->append(title);
    } else if (items[h]->author == author) { // Found the entry for the author
        items[h]->append(title);
    } else { // Hash collision, increase the size of the table
        BookList **oldList = items;
        int osize = size;
        size *= 2;
        items = new BookList *[size];
        for (int i = 0; i < size; i++) { // Init all entries to null
            items[i] = nullptr;
        }

        for (int i = 0; i < osize; i++) { // Reinsert all old items
            insert(oldList[i]);
        }
        insert(author, title); // Reinsert the new item
    }
}

void BookMap::insert(BookList *authorlist) {
    /*
     * A simple method to reinsert the items without remaking the author's Linked List
     * Similar to above
     */
    if (authorlist == nullptr)
        return;
    int h = hash(authorlist->author);
    if (items[h] == nullptr) {
        items[h] = authorlist;
    } else {
        BookList **oldList = items;
        int osize = size;
        size *= 2;
        items = new BookList *[size];
        for (int i = 0; i < osize; i++) {
            insert(oldList[i]);
        }
        for (int i = osize; i < size; i++) {
            items[i] = nullptr;
        }
        insert(authorlist);
    }
}

bool BookMap::pop(string author, string title) {
    /*
     * Remove a title, usually for checking out a book
     * Return true if successful, false otherwise
     */
    BookList *books = get(author); // Try to get the LL for the author
    if (books == nullptr) { // If it doesn't exist, then the book doesn't exist, return false
        return false;
    }
    BookNode *prev = nullptr;
    BookNode *cnode = books->head;
    while (cnode != nullptr && cnode->title != title) { // Traverse for the book
        prev = cnode;
        cnode = cnode->next;
    }

    if (cnode != nullptr) { // If found, remove the item from the LL
        if (cnode == books->head) {
            books->head = books->head->next;
        } else {
            prev->next = cnode->next;
        }
        delete cnode;
        return true;
    }
    return false;
}