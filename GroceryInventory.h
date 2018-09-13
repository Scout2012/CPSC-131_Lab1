#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "GroceryItem.h"
using namespace std;

class GroceryInventory {
private:
    vector<GroceryItem> _inventory;
	GroceryItem item;
    float _taxRate;
public:
    GroceryInventory();

    GroceryItem& getEntry(const string&);
    void addEntry(const string&, const int&, const float&, const bool&);
    float getTaxRate() const;
    void setTaxRate(const float&);

    void createListFromFile(const string&);
    float calculateUnitRevenue() const;
    float calculateTaxRevenue() const;
    float calculateTotalRevenue() const;

    GroceryItem& operator[](const int&);
};

