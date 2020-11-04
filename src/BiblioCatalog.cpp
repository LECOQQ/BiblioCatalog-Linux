//Author : Quentin LECOQ
//09/01/2020

#include "Functions.h"
#include "biblioExceptions.h"

int main(){
	try {
		userChoice();
	}
	catch (biblioExceptions& e) {
		e.printExce(cout);
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
	//userChoice();
	//return 0;
}
