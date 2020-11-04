#include "Books.h"
#include "biblioExceptions.h"

#include <stdlib.h>
#include <utility>
#include <sstream>
#include <stdexcept>

using namespace std;

Books_column::Books_column(vector<vector<string>> csv_file) {
	for (size_t i = 0; i < csv_file[0].size(); i++) {
		titles.push_back(csv_file[0][i]);
	}
}

void Books_column::show(ostream& os) {
	for (size_t i = 0; i < titles.size(); i++) {
		os << titles[i] << endl;
	}
}

Books_data::Books_data(vector<vector<string>> csv_file) : csv(csv_file) {
	for (size_t i = 0; i < csv_file[0].size(); i++) {
		if (csv_file[0][i] == "Author") authorIdx = i;
		if (csv_file[0][i] == "Title") titleIdx = i;
		if (csv_file[0][i] == "Collection") collectionIdx = i;
		if (csv_file[0][i] == "Type") typeIdx = i;
		if (csv_file[0][i] == "KeyWords") keywordsIdx = i;
	}
}

vector<vector<string>> Books_data::getCSV() {
	return csv;
}

void Books_data::sortByAuthor() {
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

void Books_data::sortByTitle() {
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

void Books_data::sortByCollection() {
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

void Books_data::sortByType() {
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

pair<int,int> Books_data::searchAccu(const string& s) const {
	pair<int, int> res(-10, -10);
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

vector<vector<string>> Books_data::searchAuthors(const string& s) const {
	vector<vector<string>> res;

	for (size_t j = 0; j < csv.size(); j++) {
		if (s == csv[j][authorIdx]) {
			res.push_back(csv[j]);
		}
	}

	return res;
}

vector<vector<string>> Books_data::searchBooks(const string& s) const {
	vector<vector<string>> res;

	for (size_t j = 0; j < csv.size(); j++) {
		if (s == csv[j][titleIdx]) {
			res.push_back(csv[j]);
		}
	}

	return res;
}

vector<vector<string>> Books_data::searchCollection(const string& s) const {
	vector<vector<string>> res;

	for (size_t j = 0; j < csv.size(); j++) {
		if (s == csv[j][collectionIdx]) {
			res.push_back(csv[j]);
		}
	}

	return res;
}

void Books_data::show(ostream& os) {
	for (size_t i = 0; i < csv.size(); i++) {
		for (size_t k = 0; k < csv[i].size(); k++) {
			os << " | " << csv[i][k];
		}
		os << " |" << endl;
	}
}
