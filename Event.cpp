#include <iostream>
using namespace std;

// Class name should typically be capitalized to follow C++ naming conventions.
class Car {
public:
    string brand;   
    int year;

    // Constructor using an initializer list
    Car(string b, int y) : brand(b), year(y) {}

    // Function to display car information
    void display() {
        cout << "Brand: " << brand << endl;
        cout << "Year: " << year << endl;
    }

    // Function to update the brand
    void updateBrand(string b) {
        brand = b;
    }
};

int main() {
    Car car1("Toyota", 2021); // Create an object of Car
    car1.display(); // Display car information
    
    car1.updateBrand("Honda"); // Update the brand
    car1.display(); // Display updated car information
    
    return 0;
}
