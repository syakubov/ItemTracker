#include "item_tracker_facilities.h"

/*----------Makes save/load function simpler-----------*/
string username;
/*-----------------------------------------------------*/

/*----------------------------------------------------------------------*/
//main function

int main()
try {
	
	cout << "Hello! What is your name?" << endl << prompt;
	getline(cin, username);

	cout << username << ", welcome to the item tracker." << endl << endl;

	cout << "-- Main Menu --" << endl;
	cout << "If you would like to add an item, type 'a'." << endl;
	cout << "If you would like to remove an item from your list, type 'd'" << endl;
	cout << "If you would like to view an item's location, type 'l'" << endl;
	cout << "If you would like to change an item's location, type 'c'" << endl;
	cout << "If you would like to view all your items, type 'v'" << endl;
	cout << "If you would like to view the menu options again, type 'm'" << endl;
	cout << "If you would like some information about the program and author, type 'i'" << endl;
	cout << "To quit, type 'q'" << endl;
	cout << "* Note: All inputs are case sensitive, and all input after first character will be ignored. *" << endl;

	while(ItemTracker(items))
	{}
	return 0;
}
catch(exception& e) {
		cerr << "exception: " << e.what() << endl;
}
catch(...)
{
	cerr << "exception." << endl;
}
/*----------------------------------------------------------------------*/
