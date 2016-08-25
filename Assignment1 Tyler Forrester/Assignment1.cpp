/*********************************************************************
** Program Filename: Assignment1 
** Author: Tyler Forrester
** Date: 6/22/2016
** Description: A program that allows user to create, read and delete entries to a list.
** Input: User
** Output: List of Items
** Citations: Program 6-14 Gaddis P. 352
********************************************************************/



#include "InputValid.hpp"
#include "Item.hpp"
#include "List.hpp"
int main() {
	
	// Citation: Program 6-14 Gaddis P. 352 


	void displayMenu();
	int getChoice(InputValid);
	void continueOn(InputValid);
	int choice;
	List list = List();
	InputValid valid = InputValid();
/** Item test = Item("Banana", "lbs", 3, 2.10);  //  Testing Items
	Item test1 = Item("Banana Hammocks", "ozs", 4, 3.10);
	Item test2 = Item("Banana Pancakes", "lbs", 5, 4.10);
	Item test3 = Item("Banana Bread", "lbs", 6, 5.10);          
	Item test4 = Item("Banana Pudding", "lbs", 7, 6.10);
	list.addItem(test);
	list.addItem(test1);
	list.addItem(test2);
	list.addItem(test3);
	list.addItem(test4); **/
	do {


		displayMenu();
		choice = getChoice(valid);

		if (choice != 4) {

			
			switch (choice)
			{
				case 1:
						{ Item addItem = Item();
						std::cout.precision(2);
						cout << "Please enter the Item's name to add to your list" << endl;
						addItem.setItemName(valid.validateString());
						cout << "Your item's name is " << addItem.getItemName() << ".\n";
						cout << "Please enter the amount of the item you will be buying. Whole Numbers only." << endl;
						addItem.setNumberToBuy(valid.validateInt());
						cout << "Please enter the unit of the amount you will be buying." << endl;
						addItem.setUnit(valid.validateString());
						cout << "Please enter the Price per unit of the item you will be buying." << endl;
						addItem.setPrice(valid.validatePrice());
						cout << "The of amount of " << addItem.getItemName() << " that you will buy is " << addItem.getNumberToBuy();
						cout << " " << addItem.getUnit() << " at $" << std::fixed << addItem.getPrice() << " per unit.\n";
						list.addItem(addItem);
						cout << "Your item has been succesfully added to the list.\n";
						continueOn(valid);
						break;
				}

				case 2: list.displayList();
						continueOn(valid);
						break;
				case 3: 
						if (list.getArrayEnd() > 0) {
							list.displayList();
							cout << "Please Select Number of Item to Delete.\n";
							while (list.deleteItem(valid.validateInt() - 1) == false) {

								std::cout << "The Item number was not found on the list. Please enter a new number.\n";

							}
						
						}
						else {

						cout << "There are no items to delete.\n";
						
						}
						continueOn(valid);
						break;


			}





		}



	} while (choice != 4);

	return 0;

}

/*********************************************************************
** Function: displayMenu
** Description: Displays Menu of Options for Sum Game
** Parameters: void
** Pre-Conditions: Start of Program
** Post-Conditions: getChoice()
** Citation: Starting Out C++: Early Objects (8th Edition) Program 6-14 Gaddis P. 352
*********************************************************************/


void displayMenu() {


	cout << "\nWelcome to Assignment1\nPlease Select a Number\n\n";
	cout << "1. Add an Item to Your List.\n";
	cout << "2. Display your Shopping List.\n";
	cout << "3. Delete an Item from you List.\n";
	cout << "4. Quit the Program.\n\n";


}
/*********************************************************************
** Function:  getChoice
** Description: gets number of Choice
** Parameters:  InputValid
** Pre-Conditions: DisplayMenu()
** Post-Conditions: Switch and Array Entry
** Citation: Starting Out C++: Early Objects (8th Edition) Program 6-14 Gaddis P. 352
*********************************************************************/


int getChoice(InputValid valid) {

	int choice;
	choice = valid.validateInt();
	while (choice < 1 || choice > 4) {

		cout << "The only valid choices are 1-4. Please re-enter.\n";
		choice = valid.validateInt();

	}

	return choice;




}

/*********************************************************************
** Function:  continueOn
** Description: Pauses program after tasks
** Parameters: InputValid
** Pre-Conditions: switch case 1, case 2 and case 3
** Post-Conditions: displaymenu()
** Citation: 
*********************************************************************/

void continueOn(InputValid valid) {
	char entry = '0';
	do {
		
		
		cout << "Please enter 'c' to continue.\n";
		entry = valid.validateChar(); 


	
	} while (entry != 'c');

}

