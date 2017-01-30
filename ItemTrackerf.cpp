#include "item_tracker_facilities.h"

string prompt = "> ";
vector<Item_tag> items;

void add(vector<Item_tag>& items, Item_tag& s) {

	if (items.size() >= 1) {

		for (int i = 0; i < items.size(); i++) {
			if (items[i].name == s.name) {
				cout << "Item with this name already exists. Try a different name!" << endl << endl;
				return;
			}
			else {
				items.push_back(s);
				cout << s.name << ", located in " << s.location << ", has been added to your list of items!" << endl << endl;
				return;
			}
		}
	}
	else {
		items.push_back(s);
		cout << s.name << ", located in " << s.location << ", has been added to your list of items!" << endl << endl;
		return;
	}

}

void del(vector<Item_tag>& items, string& s) {
	for (int i = 0; i < items.size(); i++) {
		if (items[i].name == s) {	
			items.erase(items.begin() + i);
			cout << s << " has been removed from your list." << endl << endl;
			return;
		}
	}
	cout << "Item not found." << endl << endl;
	return;
}

void location(vector<Item_tag>& items, string& s) {
	for (int i = 0; i < items.size(); i++) {
		if (items[i].name == s) {
			cout << s << " is located in " << items[i].location << endl << endl;
			return;
		}
	}
	cout << "No items found with that name." << endl << endl;
	return;
}

void view(vector<Item_tag>& items)
{
	if (items.size() == 0) cout << "List is empty. No items found." << endl << endl;
	else {
		cout << "Your current tracked items: " << endl;
		for (int i = 0; i < items.size(); i++)
			cout << items[i].name << endl;
		cout << endl;
		return;
	}
	return;
}

void change(vector<Item_tag>& items, string& s)
{
	for (int i = 0; i < items.size(); i++) {
		if (items[i].name == s) {
			cout << "Ok, what is the new location of " << s << "?" << endl << prompt;
			getline(cin, items[i].location);
			if (is_valid(items[i].location)) {
				cout << s << " has been moved to " << items[i].location << ". " << endl << endl;
				return;
			}
			else {
					cout << "Invalid input!" << endl; //handles wrong inputs that aren't whitespaces
					return;
			}
		}
	}
	cout << "No items found with that name." << endl << endl;
	return;
}

void menu_options()
{
	cout << "-- Main Menu --" << endl;
	cout << "If you would like to add an item, type 'a'." << endl;
	cout << "If you would like to remove an item from your list, type 'd'" << endl;
	cout << "If you would like to view an item's location, type 'l'" << endl;
	cout << "If you would like to change an item's location, type 'c'" << endl;
	cout << "If you would like to view all your items, type 'v'" << endl;
	cout << "If you would like some information about the program and author, type 'i'" << endl;
	cout << "To quit, type 'q'" << endl;
	cout << "* Note: All inputs are case sensitive, and no special charaters are allowed. *" << endl;
	return;
}

/*-----------------------------------------------------*/
/* This is the application function. It returns type boolean because that makes it really simple to create a while loop in main that can be exited at will.*/

bool is_valid(string& item) {
	string delimiters = "./!@#$%^&*(){}?/~-_=+][|";
	for (int i = 0; i < item.size(); i++) {
			for (int j = 0; j < delimiters.size(); j++) {
					if (item[i] == delimiters[j])
						return false;
			}
	}	
	return true;
}
bool ItemTracker(vector<Item_tag>& items) {

	string selector;
	string delimiters = "./!@#$%^&*(){}?/~-_=+][|";
	cout << "What would you like to do? (type 'm' to see menu options)" << endl;
	cout << prompt;
	cin >> selector;
	cin.ignore();

	if (selector == "a") {
			Item_tag new_item;
			cout << "What is the item you are trying to add?" << endl << prompt;
			cin.clear();
			getline(cin, new_item.name);
			if (is_valid(new_item.name)) {
				cout << "Where is this item currently located?" << endl << prompt;
				getline(cin, new_item.location);
				if (is_valid(new_item.location)) {
				add(items, new_item);
				return true; //note: anytime a functionality must return to main menu, this function returns "true".
				}
				else {
					cout << "Invalid input!" << endl; //handles wrong inputs that aren't whitespaces
					return true;
				}
			}
			else {
				cout << "Invalid input!" << endl; //handles wrong inputs that aren't whitespaces
				return true;
			}	
	}

	else if (selector == "d") {
			string item_name;
			if (items.size() < 1) {
				cout << "There are no items in your list." << endl << endl;
				return true;
			}
			else {
				cout << "What is the item you are trying to remove?" << endl << prompt;
				getline(cin, item_name);
				del(items, item_name);
				return true;
			}
		}

	else if (selector == "l") {
			string item_name;

			if (items.size() < 1) {
				cout << "There are no items in your list." << endl << endl;
				return true;
			}
			else {
				cout << "What is the item you are trying to find?" << endl << prompt;
				getline(cin, item_name);
				if (is_valid(item_name)) {
					location(items, item_name);
					return true;
				}
				else {
					cout << "Invalid input!" << endl; //handles wrong inputs that aren't whitespaces
					return true;
				}
			}
		}

	else if (selector == "c") {
			string item_name;

			if (items.size() < 1) {
				cout << "There are no items in your list." << endl << endl;
				return true;
			}
			else {
				cout << "What is the item you would like to move?" << endl << prompt;
				getline(cin, item_name);
				change(items, item_name);
				return true;
			}
		}

	else if (selector == "v") {
			if (items.size() < 1) {
				cout << "There are no items in your list." << endl << endl;
				return true;
			}
			else {
				view(items);
				return true;
			}
		}

	else if (selector == "i") {
			cout << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "ItemTracker Utility was created by Solomon Yakubov" << endl;
			cout << "The program is used to track everyday objects (car keys, wallet, MetroCard, etc.)" << endl;
			cout << "and their locations, to prevent the (somewhat) specific problem of forgetting where one put something.\n";
			cout << "v1.3 12/08/2016\n";
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << endl;
			return true;
		}
		
	else if (selector == "m") {
			menu_options();
			return true;
		}
	else if (selector == "q") {
			cout << "Thank you for using the ItemTracker." << endl;
			return false; //quit, returns false, while loop stops running and main returns 0. ez quit.
		}
	else if (selector == " ") {
			cout << "Invalid input!" << endl; //handles wrong inputs that aren't whitespaces
			return true;
		}
		
	else {
			cout << "Invalid input!" << endl; //handles wrong inputs that aren't whitespaces
			return true;
		}

		return true;
}

