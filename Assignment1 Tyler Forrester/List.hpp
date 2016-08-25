/*********************************************************************
** Program Filename: List Head File
** Author: Tyler Forrester
** Date: 6/22/2016
** Description: Creates a List of Items
** Input: Items
** Output: Modify List, Display Lists, Delete Items
** Citations:
********************************************************************/

#ifndef LIST_HPP
#define LIST_HPP
#include "Item.hpp"
#include  <iostream>
class List {

private:
	int size; 
	int arrayEnd;
	Item *itemList;
	

public:
	List();
	~List();
	int getArrayEnd();
    void addItem(Item);
	void checkList();
	void doubleList();
	void displayList(); 
	double totalCost(); 
	bool deleteItem(int);
};
#endif // !LIST_HPP
