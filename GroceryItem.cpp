#include "GroceryItem.h"

//Constructors 
GroceryItem::GroceryItem() {
	
}

GroceryItem::GroceryItem(const string& name, const int& quantity, const float& price, const bool& taxable){
	this->_name = name;
	this->_quantity = quantity;
	this->_unitPrice = price;
	this->_taxable = taxable;
}

GroceryItem& GroceryItem::operator=(GroceryItem& other) {
	if (this != &other) {
		this->_name = other._name;
		this->_quantity = other._quantity;
		this->_unitPrice = other._unitPrice;
		this->_taxable = other._taxable;
		return *this;
	}
	return *this;	
}

//Getters
string GroceryItem::getName() const {
	return this->_name;
}

int GroceryItem::getQuantity() const {
	return this->_quantity;
}

float GroceryItem::getUnitPrice() const {
	return this->_unitPrice;
}

//Setters

void GroceryItem::setName(const string& name) {
	this->_name = name;
}


void GroceryItem::setQuantity(const int& quanity) {
	this->_quantity = quanity;
}


void GroceryItem::setUnitPrice(const float& price) {
	this->_unitPrice = price;
}

void GroceryItem::setTaxable(const bool& isTaxable) {
	this->_taxable = isTaxable;
}

//
bool GroceryItem::isTaxable() const {
	return this->_taxable;
}

