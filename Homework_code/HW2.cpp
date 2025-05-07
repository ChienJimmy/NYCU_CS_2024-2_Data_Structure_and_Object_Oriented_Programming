#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>
using namespace std;
class Book{
private:
    string name;
    int publishyr;
    string author;
    int available;
public:
    Book(string n, int p, string a, int av): name(n), publishyr(p), author(a), available(av){}
    string getName(){return name;}
    int getPublishyr(){return publishyr;}
    string getAuthor(){return author;}
    int getAvailable(){return available;}
    bool isAvailable(){return available > 0;}
    void borrowBook(){
        if(available > 0){
            available--;
        } else {
            cout << "\033[1;31mNo copies available for book " << name << "!\033[0m\n";
        }
    }
    void returnBook(){available++;}
    void showInfo(){
        cout << "Name: " << name << ",\tPublished Year: " << publishyr << ",\tAuthor: " << author << ",\tAvailable: " << available << "\n";
    }
    void showInfoWithoutAvailable(){
        cout << "Name: " << name << ",\tPublished Year: " << publishyr << ",\tAuthor: " << author << "\n";
    }
};
class BookList{
public:
    vector<Book> books;
    BookList(){ books.reserve(100);}
    BookList(int capacity){ books.reserve(capacity);}
    void addBook(string name, int publishyr, string author, int available){
        if (books.size() >= books.capacity()){
            books.reserve(books.capacity() + 10);
        }
        books.push_back(Book(name, publishyr, author, available));
    }
    void sortBooksByName(){
        for (int i = 0; i < books.size() - 1; i++){
            for (int j = 0; j < books.size() - i - 1; j++){
                if (books[j].getName() > books[j + 1].getName()){
                    swap(books[j], books[j + 1]);
                }
            }
        }
    }
};
class Reader{
private:
    string name;
    int id;
    string phone;
    BookList borrowedBooks;
public:
    Reader(string n, int i, string p): name(n), id(i), phone(p){}
    string getName(){return name;}
    int getId(){return id;}
    string getPhone(){return phone;}
    void borrowBook(Book &book){
        if(book.isAvailable()){
            // Add book to borrowedBooks
            borrowedBooks.addBook(book.getName(), book.getPublishyr(), book.getAuthor(), 1);
        } else {
            cout << "\033[1;31mBook "<< book.getName() << " is not available!\033[0m\n";
        }
    }
    bool IsInBorrowedBook(string bookname){
        if (borrowedBooks.books.empty()){
            return false;
        }
        for (auto &book : borrowedBooks.books) {
            if (book.getName() == bookname){
                return true;
            }
        }
        return false;
    }
    void returnBook(Book &book){
        // Remove book from borrowedBooks
        for (auto it = borrowedBooks.books.begin(); it != borrowedBooks.books.end(); ++it) {
            if (it->getName() == book.getName()) {
                borrowedBooks.books.erase(it);
                break;
            }
        }
    }
    void showInfo(){
        cout << "Name: " << name << ",\tID: " << id << ",\tPhone: " << phone << "\n";
        cout << "Borrowed Books:\n";
        for (auto &book : borrowedBooks.books) {
            book.showInfoWithoutAvailable();
        }
        if (borrowedBooks.books.empty()) {
            cout << "No borrowed books.\n";
        }
    }
};
class Library{
private:
    BookList books;
    vector<Reader> readers;
    int bookcount, readercount;
    int bookcapacity, readercapacity;
public:
    Library(int bcap, int rcap): bookcapacity(bcap), readercapacity(rcap), bookcount(0), readercount(0){
        readers.reserve(readercapacity);
    }
    void addBook(string name, int publishyr, string author, int available){
        books.addBook(name, publishyr, author, available);
        bookcount++;
    }
    void addReader(string name, int id, string phone){
        if(readercount < readercapacity){
            readers.push_back(Reader(name, id, phone));
            readercount++;
        }
        else{
            readercapacity += 10;
            readers.reserve(readercapacity);
            readers.push_back(Reader(name, id, phone));
            readercount++;
        }
    }
    void sortBooksByName(){
        books.sortBooksByName();
    }
    BookList searchBookByName(string name){
        BookList booklist;
        for (auto &book : books.books){
            if (book.getName() == name){
                booklist.addBook(book.getName(), book.getPublishyr(), book.getAuthor(), book.getAvailable());
            }
        }
        return booklist;
    }
    BookList searchBookByYear(int year){
        BookList booklist;
        for (auto &book : books.books){
            if (book.getPublishyr() == year){
                booklist.addBook(book.getName(), book.getPublishyr(), book.getAuthor(), book.getAvailable());
            }
        }
        return booklist;
    }
    BookList searchBookByAuthor(string author){
        BookList booklist;
        for (auto &book : books.books){
            if (book.getAuthor() == author){
                booklist.addBook(book.getName(), book.getPublishyr(), book.getAuthor(), book.getAvailable());
            }
        }
        return booklist;
    }
    void checkBook(string name){
        for (auto &book : books.books){
            if (book.getName() == name){
                book.showInfo();
                return;
            }
        }
        cout << "\033[1;31mBook not found!\033[0m\n";
    }
    string getReaderName(int id){ return readers.at(id - 1).getName();}
    void borrowBook(int readerId, string bookName){
        Reader &targetReader(readers.at(readerId-1));
        for (auto &book : books.books){
            if (book.getName() == bookName && book.isAvailable()){
                targetReader.borrowBook(book);
                book.borrowBook();
                cout << "\033[1;32mBook " << book.getName() << " borrowed successfully by reader " << targetReader.getName() << "!\033[0m\n";
                return;
            }
            if(book.getName() == bookName && !book.isAvailable()){
                cout << "\033[1;31mBook [" << book.getName() << "] is not available!\033[0m\n";
                return;
            }
        }
        cout << "\033[1;31mBook not found!\033[0m\n";
    }
    void returnBook(int readerId, string bookName){
        Reader &targetReader(readers.at(readerId-1));
        // check if the book is borrowed by the reader
        bool isBorrowed(targetReader.IsInBorrowedBook(bookName));
        if (!isBorrowed){
            cout << "\033[1;31mReader [" << targetReader.getName() << "] didn't borrowed the Book [" << bookName << "]!\033[0m\n";
            return;
        }
        for (auto &book : books.books){
            if (book.getName() == bookName){
                book.returnBook();
                targetReader.returnBook(book);
                cout << "\033[1;32mBook [" << book.getName() << "] returned successfully by Reader [" << targetReader.getName() << "]!\033[0m\n";
                return;
            }
        }
        cout << "\033[1;31mBook not found!\033[0m\n";
    }
    void listbooks(){
        for (auto &book : books.books){
            book.showInfo();
        }
        if (books.books.empty()){
            cout << "\033[1;31mNo books found!\033[0m\n";
        }
    }
    void listReaders(){
        for (auto &reader : readers){
            reader.showInfo();
        }
        if (readers.empty()){
            cout << "\033[1;31mNo readers found!\033[0m\n";
        }
    }
};

int main(){
    const string filename = "System_log.txt";
    // check if the file System_log.txt exists, if not, create one
    ifstream ifile(filename);
    if (!ifile){
        cout << "\033[1;31mFile " << filename << " not found!\033[0m\n";
        // make a new file
        ofstream newfile(filename);
        if (newfile){
            cout << "\033[1;32mFile " << filename << " created successfully!\033[0m\n";
        }
        else{
            cout << "\033[1;31mFailed to create file " << filename << "!\033[0m\n";
            return 1;
        }
    }
    string command_history;
    time_t starttimestamp, endtimestamp;
    time(&starttimestamp);
    ofstream ofile(filename, ios::app);
    if (ofile.is_open()){
        ofile << "Log in at " << string(ctime(&starttimestamp)) << "\n";
        ofile.close();
    }
    else{
        cout << "\033[1;31mFailed to open file " << filename << "!\033[0m\n";
    }
    cout << "\033[1;47mWelcome to the Library Management System!\033[0m " << "\033[1;34mCurrent time: " << ctime(&starttimestamp) << "\033[0m"
    << "1. Add a new book\n"
    << "2. Search for a book by published year\n"
    << "3. Search for a book by name\n"
    << "4. Search for a book by author\n"
    << "5. Check out book status\n"
    << "6. Borrow a book\n"
    << "7. Return a book\n"
    << "8. List all books\n"
    << "9. Add a new reader\n"
    << "10. List all readers\n"
    << "\033[1;31m-1. Exit\033[0m\n\n";  
    string command_str;
    int command;
    int initial_reader_id(0); // Initialize reader ID distributed to next new reader, which also represents the number of readers
    Library library(0, 0);
    while ((cout << "Enter the command: ") && (cin >> command_str)){
        // hidden command, I don't show it in the report and README.md
        if (command_str == "CLEAR"){ // clear the records in System_log.txt
            time_t cleartimestamp;
            time(&cleartimestamp);
            ifstream ifile(filename);
            ofstream clearfile(filename, ios::trunc);
            if (clearfile.is_open()){
                clearfile.close();
                // because timestamp contains '\n' in the end of the string, so erase it
                string timestamp_str = string(ctime(&cleartimestamp));
                timestamp_str.erase(timestamp_str.find('\n'));
                cout << "\033[1;32mFile " << filename << " cleared successfully at " << timestamp_str << "!\033[0m\n";
            }
            else{
                cout << "\033[1;31mFailed to clear file " << filename << "!\033[0m\n";
            }
            ofstream ofile(filename, ios::app);
            if (ofile.is_open()){
                ofile << "Log in at " << string(ctime(&starttimestamp)) << "\n";
                ofile << "Clear System.txt at " << string(ctime(&cleartimestamp)) << "\n";
                ofile.close();
            }
            else{
                cout << "\033[1;31mFailed to open file " << filename << "!\033[0m\n";
            }
            continue;
        }
        try{ // using try to prevent invalid input terminating the program
            command = stoi(command_str);
        }
        catch (const invalid_argument &e){
            cout << "\033[1;31mInvalid command!\033[0m\n";
            continue;
        }
        // using switch case instead of if-else because the command options are many, and it is easier to add new options
        switch(command){
            case 1:{
                // TODO: Add book
                string bookname, bookauthor;
                int publishyr, availability;
                cout << "Enter book name: ";
                cin >> bookname;
                cout << "Enter published year: ";
                cin >> publishyr;
                cout << "Enter author name: ";
                cin >> bookauthor;
                cout << "Enter number of available copies: ";
                cin >> availability;
                library.addBook(bookname, publishyr, bookauthor, availability);
                command_history = "Add Books: Name " + bookname + " Published year " + to_string(publishyr) + " Author " + bookauthor + " Available Copies " + to_string(availability) + "\n";
                ofstream ofile(filename, ios::app);
                if (ofile.is_open()){
                    ofile << command_history << "\n";
                    ofile.close();
                }
                else{
                    cout << "\033[1;31mFailed to open file " << filename << "!\033[0m\n";
                }
                break;
            }
            case 2:{
                // TODO: Search book by published year
                library.sortBooksByName();
                int publishyr;
                cout << "Enter published year: ";
                cin >> publishyr;
                BookList booklist = library.searchBookByYear(publishyr);
                cout << "\033[1mBooks published in " << publishyr << ":\033[0m\n";
                for (auto &book : booklist.books){
                    book.showInfo();
                }
                if (booklist.books.empty()){
                    cout << "\033[1;31mNo books found!\033[0m\n";
                    break;
                }
                cout << "\033[1;32mTotal books found: " << booklist.books.size() << "\033[0m\n";
                command_history = "Search Books by published year: " + to_string(publishyr) + "\n";
                ofstream ofile(filename, ios::app);
                if (ofile.is_open()){
                    ofile << command_history << "\n";
                    ofile.close();
                }
                else{
                    cout << "\033[1;31mFailed to open file " << filename << "!\033[0m\n";
                }
                break;
            }
            case 3:{
                // TODO: Search book by name
                library.sortBooksByName();
                string bookname;
                cout << "Enter book name: ";
                cin >> bookname;
                BookList booklist = library.searchBookByName(bookname);
                cout << "\033[1mBooks with name " << bookname << ":\033[0m\n";
                for (auto &book : booklist.books){
                    book.showInfo();
                }
                if (booklist.books.empty()){
                    cout << "\033[1;31mNo books found!\033[0m\n";
                    break;
                }
                cout << "\033[1;32mTotal books found: " << booklist.books.size() << "\033[0m\n";
                command_history = "Search Books by name: " + bookname + "\n";
                ofstream ofile(filename, ios::app);
                if (ofile.is_open()){
                    ofile << command_history << "\n";
                    ofile.close();
                }
                else{
                    cout << "\033[1;31mFailed to open file " << filename << "!\033[0m\n";
                }
                break;
            }
            case 4:{
                // TODO: Search book by author
                library.sortBooksByName();
                string bookauthor;
                cout << "Enter author name: ";
                cin >> bookauthor;
                BookList booklist = library.searchBookByAuthor(bookauthor);
                cout << "\033[1mBooks by author " << bookauthor << "\033[0m\n";
                for (auto &book : booklist.books){
                    book.showInfo();
                }
                if (booklist.books.empty()){
                    cout << "\033[1;31mNo books found!\033[0m\n";
                    break;
                }
                cout << "\033[1;32mTotal books found: " << booklist.books.size() << "\033[0m\n";
                command_history = "Search Books by author: " + bookauthor + "\n";
                ofstream ofile(filename, ios::app);
                if (ofile.is_open()){
                    ofile << command_history << "\n";
                    ofile.close();
                }
                else{
                    cout << "\033[1;31mFailed to open file " << filename << "!\033[0m\n";
                }
                break;
            }
            case 5:{
                // TODO: Check book
                string bookname;
                cout << "Enter book name: ";
                cin >> bookname;
                library.checkBook(bookname);
                command_history = "Check book status by name: " + bookname + "\n";
                ofstream ofile(filename, ios::app);
                if (ofile.is_open()){
                    ofile << command_history << "\n";
                    ofile.close();
                }
                else{
                    cout << "\033[1;31mFailed to open file " << filename << "!\033[0m\n";
                }
                break;
            }
            case 6:{
                // TODO: A reader borrows a book
                string bookname;
                cout << "Enter book name: ";
                cin >> bookname;
                int reader_id;
                cout << "Enter reader ID: ";
                cin >> reader_id;
                if (reader_id > initial_reader_id || reader_id < 1){
                    cout << "\033[1;31mReader not found!\033[0m\n";
                    break;
                }
                library.borrowBook(reader_id, bookname);
                command_history = "Borrow book: " + bookname + " by reader ID: " + to_string(reader_id) + "\n";
                ofstream ofile(filename, ios::app);
                if (ofile.is_open()){
                    ofile << command_history << "\n";
                    ofile.close();
                }
                else{
                    cout << "\033[1;31mFailed to open file " << filename << "!\033[0m\n";
                }
                break;
            }
            case 7:{
                // TODO: A reader returns a book
                string bookname;
                cout << "Enter book name: ";
                cin >> bookname;
                int reader_id;
                cout << "Enter reader ID: ";
                cin >> reader_id;
                if (reader_id > initial_reader_id || reader_id < 1){
                    cout << "\033[1;31mReader not found!\033[0m\n";
                    break;
                }
                library.returnBook(reader_id, bookname);
                command_history = "Return book: " + bookname + " by reader ID:" + to_string(reader_id) + "\n";
                ofstream ofile(filename, ios::app);
                if (ofile.is_open()){
                    ofile << command_history << "\n";
                    ofile.close();
                }
                else{
                    cout << "\033[1;31mFailed to open file " << filename << "!\033[0m\n";
                }
                break;
            }
            case 8:{
                // TODO: List all books
                cout << "\033[1mBooks in libraries:\033[0m\n";
                library.sortBooksByName();
                library.listbooks();
                command_history = "List all books\n";
                ofstream ofile(filename, ios::app);
                if (ofile.is_open()){
                    ofile << command_history << "\n";
                    ofile.close();
                }
                else{
                    cout << "\033[1;31mFailed to open file " << filename << "!\033[0m\n";
                }
                break;
            }
            case 9:{
                // TODO: Add reader
                string readername, phone;
                cout << "Enter reader name: ";
                cin >> readername;
                initial_reader_id++;
                cout << "Enter reader phone number: ";
                cin >> phone;
                library.addReader(readername, initial_reader_id, phone); // reader ID starts from 1
                command_history = "Add reader: Name" + readername + " ID " + to_string(initial_reader_id) + " Phone number " + phone + "\n";
                ofstream ofile(filename, ios::app);
                if (ofile.is_open()){
                    ofile << command_history << "\n";
                    ofile.close();
                }
                else{
                    cout << "\033[1;31mFailed to open file " << filename << "!\033[0m\n";
                }
                break;
            }
            case 10:{
                // List all readers
                cout << "\033[1mReaders in libraries:\033[0m\n";
                library.listReaders();
                command_history = "List all readers\n";
                ofstream ofile(filename, ios::app);
                if (ofile.is_open()){
                    ofile << command_history << "\n";
                    ofile.close();
                }
                else{
                    cout << "\033[1;31mFailed to open file " << filename << "!\033[0m\n";
                }
                break;
            }
            case -1:{
                // Exit the system
                time(&endtimestamp);
                cout << "\033[1;47mExiting the system. Goodbye!\033[0m \033[1;34mCurrent time: " << ctime(&endtimestamp) << "\033[0m";
                int total_time = difftime(endtimestamp, starttimestamp);
                int hours = total_time / 3600;
                int minutes = (total_time % 3600) / 60;
                int seconds = total_time % 60;
                cout << "Your working time: ";
                if (hours != 0){
                    cout << hours << " hours ";
                    cout << minutes << " minutes ";
                    cout << seconds << " seconds.\n";
                }
                else if (minutes != 0){
                    cout << minutes << " minutes ";
                    cout << seconds << " seconds.\n";
                }
                else if (seconds != 0){
                    cout << seconds << " seconds.\n";
                }
                // if using SIGINT(^C) or SIGQUIT(^\) to force termination, the program won't record the log out status
                ofstream ofile(filename, ios::app);
                if (ofile.is_open()){
                    ofile << "Log out at " << string(ctime(&endtimestamp)) << "\n";
                    ofile.close();
                }
                else{
                    cout << "\033[1;31mFailed to open file " << filename << "!\033[0m\n";
                }
                return 0;
            }
            default: {
                cout << "\033[1;31mInvalid command!\033[0m\n";
                command_history = "Invalid command: " + to_string(command) + "\n";
                ofstream ofile(filename, ios::app);
                time_t errortimestamp;
                time(&errortimestamp);
                if (ofile.is_open()){
                    ofile << "Error occurred at " << string(ctime(&errortimestamp)) << "\n";
                    ofile.close();
                }
                else{
                    cout << "\033[1;31mFailed to open file " << filename << "!\033[0m\n";
                }
                break;
            }
        }
    }
    // if the program excute here, it represents that the while loop ended in a strange way
    cerr << "unknown error\n";
    return 1; // return 1 to spike runtime error
}