#pragma once

#include <string>
using namespace std;

class GroceryItem {
private:
    string _name;
    int _quantity;
    float _unitPrice;
    bool _taxable;

public:
    GroceryItem();
    GroceryItem(const string&, const int&, const float&, const bool&);
	GroceryItem& operator=(GroceryItem& other);

    string getName() const;
    void setName(const string&);
    int getQuantity() const;
    void setQuantity(const int&);
    float getUnitPrice() const;
    void setUnitPrice(const float&);
    bool isTaxable() const;
    void setTaxable(const bool&);
};
