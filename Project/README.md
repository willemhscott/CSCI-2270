The files were compiled on both OSX and Windows with both Clang and g++. The program is ideally run on OSX / Unix due to the
presence of the *select* module.
`g++ AsyncManager.cpp BookCollection.cpp CheckoutTimers.cpp main.cpp`
`./a.out`

```
1. Add Book
2. View Books By Author
3. View All Books
4. Check out a book
5. View Checked Out Books
6. Quit
>> 1
Author Name:J. R. R. Tolkien
Book Title:The Lord of the Rings
Added book The Lord of the Rings by: J. R. R. Tolkien
1. Add Book
2. View Books By Author
3. View All Books
4. Check out a book
5. View Checked Out Books
6. Quit
>> 2
Author Name:J. R. R. Tolkien
Books by J. R. R. Tolkien
1. The Lord of the Rings

1. Add Book
2. View Books By Author
3. View All Books
4. Check out a book
5. View Checked Out Books
6. Quit
>> 3
Books by J. R. R. Tolkien
1. The Lord of the Rings

1. Add Book
2. View Books By Author
3. View All Books
4. Check out a book
5. View Checked Out Books
6. Quit
>> 4
Your Name:Willem
Author Name:J. R. R. Tolkien
Book Title:The Lord of the Rings
Willem checked out The Lord of the Rings by: J. R. R. Tolkien for 60 minutes
1. Add Book
2. View Books By Author
3. View All Books
4. Check out a book
5. View Checked Out Books
6. Quit
>> 5
Willem has The Lord of the Rings by J. R. R. Tolkien for another 37 minutes
1. Add Book
2. View Books By Author
3. View All Books
4. Check out a book
5. View Checked Out Books
6. Quit
>>
Willem checked in The Lord of the Rings by J. R. R. Tolkien
>> 5
No books are currently checked out.
1. Add Book
2. View Books By Author
3. View All Books
4. Check out a book
5. View Checked Out Books
6. Quit
>> 6
Process finished with exit code 0
```