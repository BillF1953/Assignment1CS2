/*********************************************************************
** Program Filename: List CPP File
** Author: Tyler Forrester
** Date: 6/22/2016
** Description: Creates a List of Items
** Input: Items
** Output: Modify List, Display Lists, Delete Items
** Citations:
********************************************************************/



#include "List.hpp"

/*********************************************************************
** Function: List
** Description: constructor
** Parameters: none
** Pre-Conditions: itemList initialized to a dynamice array of size 4. 
** Post-Conditions: All program operations
** Citation: 
*********************************************************************/


List::List()
{
	 arrayEnd = 0; 
	 size = 4; 
	itemList = new Item[size];
	
}
/*********************************************************************
** Function: Deconstructor List
** Description: Destroys itemList array
** Parameters: none
** Pre-Conditions:  On Exit
** Post-Conditions:  Exited
** Citation: none
*********************************************************************/


List::~List()
{
	delete[] itemList; 
}

int List::getArrayEnd()
{
	return arrayEnd;
}

/*********************************************************************
** Function: List
** Description: add new created Item to the list
** Parameters: Item newItem
** Pre-Conditions: menu selection of addItem. Item created.
** Post-Conditions:  main menu options
** Citation:
*********************************************************************/

void List::addItem(Item newItem)
{
	checkList();
	itemList[arrayEnd] = newItem;
	arrayEnd++;

	
}

/*********************************************************************
** Function: checkList
** Description: checks if 
** Parameters: none
** Pre-Conditions: addItem is selected from menu
** Post-Conditions: doubleLists, return to main menu. 
** Citation:
*********************************************************************/
void List::checkList()
{
	 
	
	if (arrayEnd == size) {
		
		doubleList();
	
	}

		
	

}

/*********************************************************************
** Function: doubleList
** Description: doubles size of array 
** Parameters: none
** Pre-Conditions: itemList must no longer contain null values
** Post-Conditions: addItem
** Citation: Modified from http://www.cplusplus.com/forum/beginner/7418/ psault Feb 2, 2009 at 9:11 am
*********************************************************************/
 void List::doubleList()
 {
	 int oldSize = size; 
	 size = size + size;
	Item * array2 = new Item[size];
	
	for (int i = 0; i < oldSize; i++) {
	
		array2[i] = itemList[i];
	
	}
	
	delete[] itemList; 
	itemList = array2; 

	
	
}
 /*********************************************************************
 ** Function: displayList
 ** Description: Displays Shopping List and Total Cost of Items
 ** Parameters: Void
 ** Pre-Conditions: User must select either delete item or view shopping cart list. 
 ** Post-Conditions: Return to Main Menu. All menu items. 
 ** Citation: 
 *********************************************************************/


void List::displayList()
{
	std::cout.precision(2);
	int i = 0; 
	std::cout << "\nWelcome to your Grocery List.\n\n";
	for (int i = 0; i < arrayEnd; i++) {
		
		
		std::cout << "Item " << i + 1 << ": " << itemList[i].getItemName() << "; Amount " << itemList[i].getNumberToBuy();
		std::cout << " " << itemList[i].getUnit() << "; Price Per Unit $" << std::fixed << itemList[i].getPrice() << ".\n";
		
		
	}
	std::cout << "\nThe Total Price of your Shopping Cart is $" << std::fixed << totalCost() << ".\n\n";

	

}
/*********************************************************************
** Function: totalCost
** Description: Sums Total Cost of Items
** Parameters: Void
** Pre-Conditions: DisplayList is called. 
** Post-Conditions: Return to Main Menu. All menu items. 
** Citation:
*********************************************************************/

double List::totalCost()
{
	double total = 0;
	for (int i = 0; i < arrayEnd; i++) {
	
		total += itemList[i].getPrice() * itemList[i].getNumberToBuy();

	}
	return total;

}
/*********************************************************************
** Function: deleteItem
** Description: deletes Array Item
** Parameters: position
** Pre-Conditions: User Selects Delete Item from Menu.
** Post-Conditions: Return to Main Menu. All menu items.
** Citation:
*********************************************************************/


bool List::deleteItem(int position)
{
	
	if (position < arrayEnd && position > -1) {
		
	for (int i = 0; i < (arrayEnd - position); i++) {
		    
			itemList[position + i] = itemList[position + i + 1];

		} 
		 
		arrayEnd--; 
		displayList();
	    std::cout << "The Item in position " << position + 1 << " has been deleted.\n";
	  
	
		return true; 
	}
	else {
		
		return false; 
	
	}

	
}



