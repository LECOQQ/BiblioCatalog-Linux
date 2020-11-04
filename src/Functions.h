#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Books.h"
#include <string>
#include <cstring>
#include <vector>

void checkCSVFile(const string& filename);
void Reset(const string& filename);
bool sure();
void write_books_csv(const string& filename, vector<string> book);
vector<vector<string>> read_books_csv(const string& filename);
void addBook();
void listBooks();
void rewrite_books_csv(const string& filename, Books_data csv);
void sort(Books_data& csv);
void search(Books_data csv);
unsigned char userChoice();

#endif
