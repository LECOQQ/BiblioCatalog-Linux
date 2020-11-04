#include "Functions.h"
#include "biblioExceptions.h"

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <utility>
#include <sstream>
#include <stdexcept>


void checkCSVFile(const string& filename) {
	ifstream myFile;
	myFile.open(filename);
	//if it can't open we create one
	if (!myFile.is_open()) {
		ofstream myFileBis(filename);
		myFileBis << "Author;Title;Collection;Type;KeyWords" << endl;
		myFileBis.close();
	}
	myFile.close();
}

void Reset(const string& filename) {
	system("clear");
	char* char_array = new char[filename.length() + 1];
	strcpy(char_array, filename.c_str());
	if (remove(char_array) != 0) {
		perror("Can't reset");
	}
	delete[] char_array;
}

bool sure() {
	string answer;
	cout << "Are you sure ? y/n" << endl;
	cin >> answer;
	cin.ignore();
	if (answer == "y") return 1;
	else return 0;
}

void write_books_csv(const string& filename, vector<string> book) {
	ofstream myFile(filename, ios::in | ios::out | ios::app);
	if (myFile.good()) {
		for (size_t i = 0; i < book.size(); i++) {
			myFile << book[i] << ";";
		}
		myFile << endl;
	}
	else {
		throw biblioExceptions(2);
	}
	myFile.close();
}

vector<vector<string>> read_books_csv(const string& filename) {
	vector<vector<string>> result;
	string line, column;
	ifstream myFile(filename);
	if (!myFile.is_open()) throw biblioExceptions(0);

	//extracting column names
	if (myFile.good()) {

		while (getline(myFile, line)) {
			vector<string> col;
			stringstream ss(line);
			while (getline(ss, column, ';')) {
				col.push_back(column);
			}
			result.push_back(col);
		}
	}
	else {
		throw biblioExceptions(2);
	}

	myFile.close();
	return result;
}

void addBook() {
	string title, author, collection, type("N/A"), keywords("N/A");
	vector<string> book;
	unsigned char choice;

	system("clear");
	cout << "What is the author of the book?" << endl;
	getline(cin, author);
	book.push_back(author);

	system("clear");
	cout << "What is the title of the book ?" << endl;
	getline(cin, title);
	book.push_back(title);

	system("clear");
	cout << "From which collection does your book belong ?" << endl;
	cout << "Answer N/A if you don't want/can't answer." << endl;
	getline(cin, collection);
	book.push_back(collection);

	//added to fill the csv for future usage
	book.push_back(type);
	book.push_back(keywords);

	system("clear");
	write_books_csv("BiblioCatalogBooks.csv", book);

	cout << "Any other books to add ?" << endl;
	cout << "1 - Yes     2 - No" << endl;
	cin >> choice;
	cin.ignore();
	system("clear");

	if ((int)choice - '0' == 1) {
		addBook();
	}
}

void listBooks() {
	vector<vector<string>> vec = read_books_csv("BiblioCatalogBooks.csv");
	system("clear");
	cout << vec;
}

void rewrite_books_csv(const string& filename, Books_data csv) {
	Reset(filename);
	vector<vector<string>> _csv = csv.getCSV();
	for (size_t i = 0; i < _csv.size(); i++) {
		write_books_csv(filename, _csv[i]);
	}
}

void sort(Books_data& csv) {
	unsigned char choice;

	system("clear");
	cout << "How do you want to sort ?" << endl;
	cout << "1 - By author    2 - By title" << endl;
	cout << "3 - By collection" << endl;
	cin >> choice;
	cin.ignore();

	if ((int)choice - '0' == 1) {
		csv.sortByAuthor();
		rewrite_books_csv("BiblioCatalogBooks.csv", csv);
	}
	else if ((int)choice - '0' == 2) {
		csv.sortByTitle();
		rewrite_books_csv("BiblioCatalogBooks.csv", csv);
	}
	else if ((int)choice - '0' == 3) {
		csv.sortByCollection();
		rewrite_books_csv("BiblioCatalogBooks.csv", csv);
	}
}

void search(Books_data csv) {
	unsigned char choice;
	string response;

	system("clear");
	cout << "What do you want to search for ?" << endl;
	cout << "1 - Author        2 - Title" << endl;
	cout << "3 - Collection" << endl;
	cin >> choice;
	cin.ignore();

	if ((int)choice - '0' == 1) {
		system("clear");
		cout << "Which author ?" << endl;
		cin >> response;
		cin.ignore();
		cout << csv.searchAuthors(response);
	}
	else if ((int)choice - '0' == 2) {
		system("clear");
		cout << "Which title ?" << endl;
		cin >> response;
		cin.ignore();
		cout << csv.searchBooks(response);
	}
	else if ((int)choice - '0' == 3) {
		system("clear");
		cout << "Which collection ?" << endl;
		cin >> response;
		cin.ignore();
		cout << csv.searchBooks(response);
	}
}

unsigned char userChoice() {
	checkCSVFile("BiblioCatalogBooks.csv");
	Books_data csv(read_books_csv("BiblioCatalogBooks.csv"));
	unsigned char choice;
	
	cout << "What do you want to do ?" << endl;
	cout << "1 - Add a book     2 - Leave" << endl;
	cout << "3 - Reset catalog  4 - List of my books" << endl;
	cout << "5 - Sort my books  6 - Search" << endl;
	cin >> choice;		//care here cause we are only reading the char, not the newline char after. in doing so we need to erase the newline char else we cant use getline(cin,string) after
	cin.ignore();

	if ((int)choice - '0' == 1) {
		addBook();
		userChoice();
	}
	else if ((int)choice - '0' == 2) {
		return 0;
	}
	else if ((int)choice - '0' == 3) {
		if (sure()) {
			Reset("BiblioCatalogBooks.csv");
			cout << "Reset has been done" << endl;
			userChoice();
		}
		else userChoice();
	}
	else if ((int)choice - '0' == 4) {
		listBooks();
		cout << endl;
		userChoice();
	}
	else if ((int)choice - '0' == 5) {
		sort(csv);
		cout << "Books have been sorted" << endl;
		userChoice();
	}
	else if ((int)choice - '0' == 6) {
		search(csv);
		userChoice();
	}
	else {
		system("clear");
		cout << "Wrong answer, please choose again" << endl;
		userChoice();
	}

	return 0;
}