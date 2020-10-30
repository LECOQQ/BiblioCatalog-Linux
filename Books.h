#ifndef BOOKS_H
#define BOOKS_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <stdlib.h>
#include <utility>
#include <sstream>
#include <stdexcept>

using namespace std;

//Author/Title/Collection/Type/KeyWords
class Books_column {
	private:
		vector<string> titles;
	public:
		Books_column(const vector<vector<string>>& csv_file) {
			for (size_t i = 0; i < csv_file[0].size(); i++) {
				titles.push_back(csv_file[0][i]);
			}
		}
		void show(ostream& os) {
			for (size_t i = 0; i < titles.size(); i++) {
				os << titles[i] << endl;
			}
		}
};

//datas WITH TITLE
class Books_data {
	private:
		vector<vector<string>> csv;
		int authorIdx, titleIdx, collectionIdx, typeIdx, keywordsIdx;
	public:
		Books_data(const vector<vector<string>>& csv_file) : csv(csv_file) {
			for (size_t i = 0; i < csv_file[0].size(); i++) {
				if (csv_file[0][i] == "Author") authorIdx = i;
				if (csv_file[0][i] == "Title") titleIdx = i;
				if (csv_file[0][i] == "Collection") collectionIdx = i;
				if (csv_file[0][i] == "Type") typeIdx = i;
				if (csv_file[0][i] == "KeyWords") keywordsIdx = i;
			}
		}

		vector<vector<string>> getCSV() const{
			return csv;
		}

		void sortByAuthor() {
			vector<string> tmp;
			for (size_t i = 1; i < csv.size(); i++) {
				for (size_t j = i + 1; j < csv.size(); j++) {
					if (csv[i][authorIdx] > csv[j][authorIdx]) {
						tmp = csv[j];
						csv[j] = csv[i];
						csv[i] = tmp;
					}
				}
			}
		}

		void sortByTitle() {
			vector<string> tmp;
			for (size_t i = 1; i < csv.size(); i++) {
				for (size_t j = i + 1; j < csv.size(); j++) {
					if (csv[i][titleIdx] > csv[j][titleIdx]) {
						tmp = csv[j];
						csv[j] = csv[i];
						csv[i] = tmp;
					}
				}
			}
		}

		void sortByCollection() {
			vector<string> tmp;
			for (size_t i = 1; i < csv.size(); i++) {
				for (size_t j = i + 1; j < csv.size(); j++) {
					if (csv[i][collectionIdx] > csv[j][collectionIdx]) {
						tmp = csv[j];
						csv[j] = csv[i];
						csv[i] = tmp;
					}
				}
			}
		}

		void sortByType() {
			vector<string> tmp;
			for (size_t i = 1; i < csv.size(); i++) {
				for (size_t j = i + 1; j < csv.size(); j++) {
					if (csv[i][typeIdx] > csv[j][typeIdx]) {
						tmp = csv[j];
						csv[j] = csv[i];
						csv[i] = tmp;
					}
				}
			}
		}

		//take a string, parse the csv file to get index of where it occurs;
		pair<int, int> searchAccu(const string& s) const{
			pair<int, int> res(-10,-10);
			for (size_t i = 1; i < csv.size(); i++) {
				for (size_t j = 0; j < csv[0].size(); j++) {
					if (s == csv[i][j]) {
						res.first = i;
						res.second = j;
						return res;
					}
				}
			}
			return res;
		}

		//return all the lines with the string in
		vector<vector<string>> searchAuthors(const string& s) const {
			vector<vector<string>> res;

			for (size_t j = 0; j < csv.size(); j++) {
				if (s == csv[j][authorIdx]) {
					res.push_back(csv[j]);
				}
			}

			return res;
		}

		vector<vector<string>> searchBooks(const string& s) const {
			vector<vector<string>> res;

			for (size_t j = 0; j < csv.size(); j++) {
				if (s == csv[j][titleIdx]) {
					res.push_back(csv[j]);
				}
			}

			return res;
		}

		vector<vector<string>> searchCollection(const string& s) const {
			vector<vector<string>> res;

			for (size_t j = 0; j < csv.size(); j++) {
				if (s == csv[j][collectionIdx]) {
					res.push_back(csv[j]);
				}
			}

			return res;
		}

		void show(ostream& os) {
			for (size_t i = 0; i < csv.size(); i++) {
				for (size_t k = 0; k < csv[i].size(); k++) {
					os << " | " << csv[i][k];
				}
				os << " |" << endl;
			}
		}
};

ostream& operator<<(ostream& os, const vector<vector<string>>& v) {
	for (size_t i = 0; i < v.size(); i++) {
		for (size_t k = 0; k < v[i].size(); k++) {
			os << " | " << v[i][k];
		}
		os << " |" << endl;
	}
	return os;
}

ostream& operator<<(ostream& os, Books_data v) {
	v.show(os);
	return os;
}

#endif
