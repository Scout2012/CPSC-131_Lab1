#include "GroceryInventory.h"

GroceryInventory::GroceryInventory() {


}

//Getters

GroceryItem& GroceryInventory::getEntry(const string& name) {
	//can use std::vector<GroceryItem>::iterator it, rather than auto it, but it's simpler to use auto.
	//for the sake of simplicity, I will use it throughout the project.

	//need to do something if the item is not there
	for (auto it : _inventory) {
		if (it.getName() == name) {
			//deep copy constructor called
			item = it;

			return item;
		}
	}
}

float GroceryInventory::getTaxRate() const {
	return this->_taxRate;
}

//Setters

void GroceryInventory::setTaxRate(const float& taxrate) {
	this->_taxRate = taxrate;
}


void GroceryInventory::addEntry(const string& name, const int& quantity, const float& price, const bool& isTaxable) {
	//Call constructor for a new GroceryItem
	GroceryItem item(name, quantity, price, isTaxable);
	//Add that item to our class's inventory vector
	_inventory.push_back(item);
}

//Calculations
//side note, all these are const functions which means we cannot alter the member data

//total revenue
float GroceryInventory::calculateUnitRevenue() const {
	float unitRev = 0;
	for (auto it : _inventory) {
		unitRev += it.getUnitPrice();
	}
	return unitRev;
}
//total taxes from all inventory
float GroceryInventory::calculateTaxRevenue() const {
	float taxRev = 0;

	for (auto it : _inventory) {
		if (it.isTaxable()) {
			taxRev += it.getUnitPrice()*this->getTaxRate();
		}
	}

	return taxRev;
}

//net revenue after taxes
float GroceryInventory::calculateTotalRevenue() const {
	return 0;
}


//Operators
GroceryItem& GroceryInventory::operator[](const int&) {
	GroceryItem item;
	return item;
}

//Functions used to generate lists from external file
void GroceryInventory::createListFromFile(const string& filename) {
	ifstream input_file(filename);

	if (input_file.is_open()) {
		cout << "Successfully opened file " << filename << endl;
		string name;
		int quantity;
		float unit_price;
		bool taxable;
		while (input_file >> name >> quantity >> unit_price >> taxable) {
			addEntry(name, quantity, unit_price, taxable);
		}
		input_file.close();
	}
	else {
		throw invalid_argument("Could not open file " + filename);
	}
}
