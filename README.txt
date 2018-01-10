Program Description: Prompt a user for their name, or at least their save name. This is in order to load their previous state. The next step is to ask whether they want to check their items (list of previously saved items), add an item (and therefore location), check item locations (by name), or delete items. Additionally, all (menu) input is to be kept in lower case, for ease of use and design purposes.

1. Prompt the user for their user name.
— main menu —
2. Ask if the user wants to see a (list) of their items, to (add) an item to the list, to (delete) an item from the list, or to (view) an item (location). (quit) option present as well.
	i)if list, show a list of items, then go back to main menu
	ii)if add, prompt user for name of item, suggest to use lower case, add item as token with location
	iii)if delete, remove the item from the token vector	
	iv)if view location, prompt the user for an item name, then display location, and return to main menu.


UPDATE:
Changes as of 2/13/2017:
	dependency on textbook header removed
	restructured program to be more compliant with OOP conventions (added getters, setters, etc.)
	updated class 
	created save/load variables
	restructured program to be more compliant with C++ standards (width, comments, etc)	

