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
** Post-Conditions: none
** Citation: none
*********************************************************************/


List::~List()
{
	delete[] itemList; 
}
/*********************************************************************
** Function: input
** Description: Checks for duplication of Item name, if no duplication proceeds to prompt user 
** for price and quantity. Otherwise function duplicate prompts user to update the quantity
** Parameters:  InputValid object
** Pre-Conditions: Menu selection "Add Item" 
** Post-Conditions:  List::duplicate() and continueOn() upon exit 
** Citation: 
*********************************************************************/


void List::input(InputValid valid)
{
	Item item = Item();
	
	std::cout.precision(2);
	cout << "Please enter the Item's name to add to your list" << endl;
	item.setItemName(valid.validateString());
	cout << "Your item's name is " << item.getItemName() << ".\n";
	
	if (duplicate(item, valid) == false) 	
   {


		cout << "Please enter the amount of the item you will be buying. Whole Numbers only." << endl;
		item.setNumberToBuy(valid.validateInt());
		cout << "Please enter the unit of the amount you will be buying." << endl;
		item.setUnit(valid.validateString());
		cout << "Please enter the Price per unit of the item you will be buying." << endl;
		item.setPrice(valid.validatePrice());
		cout << "The of amount of " << item.getItemName() << " that you will buy is " << item.getNumberToBuy();
		cout << " " << item.getUnit() << " at $" << std::fixed << item.getPrice() << " per unit.\n";
		addItem(item);
		cout << "Your item has been succesfully added to the list.\n";


	}
	


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
** Function: checkDel
** Description: Check for existance of items on the list. If no items, exits to main menu;
** Parameters:  InputValid object
** Pre-Conditions: Menu selection "Delete Item"
** Post-Conditions:  List::exists() to List::deleteItem() or continueOn() 
** Citation:
*********************************************************************/

void List::checkDel(InputValid valid)
{
	if (arrayEnd > 0) {
		displayList();
		cout << "Please Select Number of Item to Delete.\n";
		while (deleteItem(valid.validateInt() - 1) == false) {

			std::cout << "The Item number was not found on the list. Please enter a new number.\n";

		}

	}
	else {

		cout << "There are no items to delete.\n";

	}


}
/*********************************************************************
** Function: totalCost
** Description: Sums Total Cost of Items
** Parameters: Void
** Pre-Conditions: checkDel(), DisplayList called from main
** Post-Conditions: main or deleteItem() depends on use case. 
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
** Pre-Conditions: Selects delete checkDel()
** Post-Conditions: if true main, if false checkDel()
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
/*********************************************************************
** Function: duplicate
** Description: Checks if items name is already on the list
** Parameters:  Item newItem InputValid object
** Pre-Conditions: Menu selection "Add Item" to List::input()
** Post-Conditions: uses Item::operator==() exits to main() or input()
** Citation:
*********************************************************************/

bool List::duplicate(Item newItem, InputValid valid )
{
	for (int i = 0; i < arrayEnd; i++) {

		if (itemList[i] == newItem) {
			
			cout << "Your item is already on the list.\n";
			cout << "Please update the amount of the item you would like to buy.\n Whole numbers only.\n";
			itemList[i].setNumberToBuy(valid.validateInt());
			cout << "Your amount has been updated to " << itemList[i].getNumberToBuy() << ".\n";
			return true; 

		}

	}
	return false;
}












