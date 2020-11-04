#ifndef _BIBLIO_EXCEPTIONS_H
#define _BIBLIO_EXCEPTIONS_H

#include <string>
#include <cstring>
#include <iostream>

using namespace std;

class biblioExceptions : public exception {
	private:
		string msg;
		int num;
	public:
		biblioExceptions(int _num);
		int getNum() const;
		void printExce(ostream& os) const;
};


#endif