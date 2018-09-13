#include <string>
#include "GroceryItem.h"
#include "GroceryInventory.h"
using namespace std;

template <typename T>
bool testAnswer(const string&, const T&, const T&);

template <typename T>
bool testAnswerEpsilon(const string&, const T&, const T&);

///////////////////////////////////////////////////////////////
// DO NOT EDIT THIS FILE (except for your own testing)       //
// CODE WILL BE GRADED USING A MAIN FUNCTION SIMILAR TO THIS //
///////////////////////////////////////////////////////////////

int main() {
    // test only the GroceryItem class
    GroceryItem item("Apples", 1000, 1.29, true);
    testAnswer("GroceryItem.getName() test", item.getName(), string("Apples"));
    testAnswer("GroceryItem.getQuantity() test", item.getQuantity(), 1000);
    testAnswerEpsilon("GroceryItem.getPrice test", item.getUnitPrice(), 1.29f);
    testAnswer("GroceryItem.isTaxable test", item.isTaxable(), true);

    // test only the GroceryInventory class
    GroceryInventory inventory;
    inventory.addEntry("Apples", 1000, 1.99, false);
    inventory.addEntry("Bananas", 2000, 0.99, false);
    testAnswerEpsilon("GroceryInventory.getEntry() 1", inventory.getEntry("Apples").getUnitPrice(), 1.99f);
    testAnswerEpsilon("GroceryInventory.getEntry() 2", inventory.getEntry("Bananas").getUnitPrice(), 0.99f);

    //// test copy constructor
    //GroceryInventory inventory2 = inventory;
    //testAnswer("GroceryInventory copy constructor 1", inventory2.getEntry("Apples").getUnitPrice(), 1.99f);
    //inventory.addEntry("Milk", 3000, 3.49, false);
    //inventory2.addEntry("Eggs", 4000, 4.99, false);
    // Expect the following to fail
    string nameOfTest = "GroceryInventory copy constructor 2";
    try {
        testAnswerEpsilon(nameOfTest, inventory.getEntry("Eggs").getUnitPrice(), 3.49f);
        cout << "FAILED " << nameOfTest << ": expected to recieve an error but didn't" << endl;
    } catch (const exception& e) {
        cout << "PASSED " << nameOfTest << ": expected and received error " << e.what() << endl;
    }


    // test assignment operator
    GroceryInventory inventory3;
    inventory3 = inventory;
    testAnswerEpsilon("GroceryInventory assignment operator 1", inventory3.getEntry("Apples").getUnitPrice(), 1.99f);
    inventory.addEntry("Orange Juice", 4500, 6.49, false);
    inventory3.addEntry("Diapers", 5000, 19.99, false);
    // Expect the following to fail
    nameOfTest = "GroceryInventory assignment operator 2";
    try {
        testAnswerEpsilon(nameOfTest, inventory.getEntry("Diapers").getUnitPrice(), 19.99f);
        cout << "FAILED " << nameOfTest << ": expected to recieve an error but didn't" << endl;
    } catch (const exception& e) {
        cout << "PASSED " << nameOfTest << ": expected and received error " << e.what() << endl;
    }

    // test the GroceryInventory class
    GroceryInventory inventory4;
    inventory4.createListFromFile("shipment.txt");
    inventory4.setTaxRate(7.75);
    testAnswer("GroceryInventory initialization", inventory4.getEntry("Lettuce_iceberg").getQuantity(), 9541);
    testAnswerEpsilon("GroceryInventory.calculateUnitRevenue()", inventory4.calculateUnitRevenue(), 1835852.375f);
    testAnswerEpsilon("GroceryInventory.calculateTaxRevenue()", inventory4.calculateTaxRevenue(), 11549.519531f);
    testAnswerEpsilon("GroceryInventory.calculateTotalRevenue()", inventory4.calculateTotalRevenue(), 1847401.875f);

    return 0;
}

template <typename T>
bool testAnswer(const string& nameOfTest, const T& received, const T& expected) {
    if (received == expected) {
        cout << "PASSED " << nameOfTest << ": expected and received " << received << endl;
        return true;
    }
    cout << "FAILED " << nameOfTest << ": expected " << expected << " but received " << received << endl;
    return false;
}

template <typename T>
bool testAnswerEpsilon(const string& nameOfTest, const T& received, const T& expected) {
    const double epsilon = 0.0001;
    if ((received - expected < epsilon) && (expected - received < epsilon)) {
        cout << fixed << "PASSED " << nameOfTest << ": expected and received " << received << endl;
        return true;
    }
    cout << "FAILED " << nameOfTest << ": expected " << expected << " but received " << received << endl;
    return false;
}
