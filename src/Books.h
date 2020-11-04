#ifndef BOOKS_H
#define BOOKS_H

#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

//Order -> Author/Title/Collection/Type/KeyWords
class Books_column {
	private:
		vector<string> titles;
	public:
		Books_column(vector<vector<string>> csv_file);
		void show(ostream& os);
};

//datas WITH TITLE
class Books_data {
	private:
		vector<vector<string>> csv;
		int authorIdx, titleIdx, collectionIdx, typeIdx, keywordsIdx;
	public:
		Books_data(vector<vector<string>> csv_file);
		vector<vector<string>> getCSV();

		void sortByAuthor();
		void sortByTitle();
		void sortByCollection();
		void sortByType();

		//take a string, parse the csv file to get index of where it occurs;
		pair<int, int> searchAccu(const string& s) const;

		//return all the lines with the string in
		vector<vector<string>> searchAuthors(const string& s) const;
		vector<vector<string>> searchBooks(const string& s) const;
		vector<vector<string>> searchCollection(const string& s) const;

		void show(ostream& os);
};

inline ostream& operator<<(ostream& os, vector<vector<string>> v) {
	for (size_t i = 0; i < v.size(); i++) {
		for (size_t k = 0; k < v[i].size(); k++) {
			os << " | " << v[i][k];
		}
		os << " |" << endl;
	}
	return os;
}

inline ostream& operator<<(ostream& os, Books_data v) {
	v.show(os);
	return os;
}

#endif
