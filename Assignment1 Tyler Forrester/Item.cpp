/*********************************************************************
** Program Filename: Item CPP File
** Author: Tyler Forrester
** Date: 6/22/2016
** Description: Initializes Items Stores Basic Information like Name, Price, Quantity, Unit.
** Input:  User Input
** Output: Items with basic information.
** Citations:
********************************************************************/


#include "Item.hpp"


Item::Item(string name, string unit, int amount, double price)
{
	setItemName(name);
	setUnit(unit);
	setNumberToBuy(amount);
	setPrice(price);

}

Item::Item()
{
}

void Item::setItemName(string name)
{
	itemName = name; 
}

void Item::setUnit(string unit1)
{
	unit = unit1; 
}

void Item::setNumberToBuy(int num)
{
	numberToBuy = num; 
}

void Item::setPrice(double p)
{
	price = p; 
}

string Item::getItemName()
{
	return itemName;
}

string Item::getUnit()
{
	return unit; 
}

int Item::getNumberToBuy()
{
	return numberToBuy;
}

double Item::getPrice()
{
	return price;
}

