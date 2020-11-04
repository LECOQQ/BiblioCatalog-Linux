#include "biblioExceptions.h"

biblioExceptions::biblioExceptions(int _num) : num(_num) {
	if (num == 0) {
		msg = "File opening";
	}
	else if (num == 1) {
		msg = "File closing";
	}
	else if (num == 2) {
		msg = "Stream not good";
	}
}

int biblioExceptions::getNum() const {
	return num;
}

void biblioExceptions::printExce(ostream& os) const {
	os << "Exception " << num << endl;
	os << msg << endl;
}