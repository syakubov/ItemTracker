Program Description: Prompt a user for their name, or at least their save name. This is in order to load their previous state. The next step is to ask whether they want to check their items (list of previously saved items), add an item (and therefore location), check item locations (by name), or delete items. Additionally, all (menu) input is to be kept in lower case, for ease of use and design purposes.

**Note: uses a header from a textbook: Programming: Principles and Practice Using C++ (2nd edition)**

1. Prompt the user for their user name.
— main menu —
2. Ask if the user wants to see a (list) of their items, to (add) an item to the list, to (delete) an item from the list, or to (view) an item (location). (quit) option present as well.
	i)if list, show a list of items, then go back to main menu
	ii)if add, prompt user for name of item, suggest to use lower case, add item as token with 	location
	iii)if delete, remove the item from the token vector	
	iv)if view location, prompt the user for an item name, then display location, and return to main 	menu.
Stage 1 should continue as long as q is not pressed. 

As of 1/29/2017, the save/load functionality has not been implemented.