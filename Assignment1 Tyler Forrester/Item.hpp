/*********************************************************************
** Program Filename: Item Header File
** Author: Tyler Forrester
** Date: 6/22/2016
** Description: Initializes Items Stores Basic Information like Name, Price, Quantity, Unit. 
** Input:  User Input
** Output: Items with basic information. 
** Citations:
********************************************************************/
#ifndef ITEM_HPP
#define ITEM_HPP
#include <string>
#include <iomanip>
using std::string; 

class Item{

private: 
	string itemName; 
	string unit; 
	int numberToBuy;
	double price; 
public:
	Item(string, string, int, double);
	Item(); 
	void setItemName(string);
	void setUnit(string);
	void setNumberToBuy(int);
	void setPrice(double);
	string getItemName();
	string getUnit();
	int getNumberToBuy();
	double getPrice(); 

};
#endif // !ITEM_HPP

