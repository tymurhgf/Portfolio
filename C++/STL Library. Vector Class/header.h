#pragma once
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

class Car {
protected:
    string brand;
    string model;
    int year;
    double engVol;
    double price;
public:
    Car() : brand(""), model(""), year(0), engVol(0.), price(0.) {}
    Car(string b) : brand(b), model(""), year(0), engVol(0.), price(0.) {}
    Car(string b, string m) : brand(b), model(m), year(0), engVol(0.), price(0.) {}
    Car(string b, string m, int y) : brand(b), model(m), year(y), engVol(0.), price(0.) {}
    Car(string b, string m, int y, double ev) : brand(b), model(m), year(y), engVol(ev), price(0.) {}
    Car(string b, string m, int y, double ev, double p) : brand(b), model(m), year(y), engVol(ev), price(p) {}

    string getBrand() const { return brand; }
    string getModel() const { return model; }
    int getYear() const { return year; }
    double getEngVol() const { return engVol; }
    double getPrice() const { return price; }

    void setBrand(const string& b) { brand = b; }
    void setModel(const string& m) { model = m; }
    void setYear(int y) { year = y; }
    void setEngVol(double ev) { engVol = ev; }
    void setPrice(double p) { price = p; }

    void show() const {
        cout << "Brand: " << brand
            << "\nModel: " << model
            << "\nYear: " << year
            << "\nEngine Volume: " << engVol << " l"
            << "\nPrice: " << price << " $" << endl;
    }
};

class CarManage {
private:
    vector<Car> cars;
public:

    void addCar() {
        string b, m;
        int y;
        double eV, p;

        cout << "Enter brand: "; cin >> b;
        cout << "Enter model: "; cin >> m;
        cout << "Enter year: "; cin >> y;
        cout << "Enter engine volume: "; cin >> eV;
        cout << "Enter price: "; cin >> p;
        cars.push_back(Car(b, m, y, eV, p));
    }

    void showAll() const {
        if (cars.empty()) {
            cout << "Empty.\n";
            return;
        }
        for (int i = 0; i < cars.size(); ++i) {
            cout << "\n";
            cars[i].show();
        }
    }
    void sortCars() {
        if (cars.empty()) {
            cout << "Empty.\n";
            return;
        }
        cout << "\nChoose a sorting criterion:\n"
            << "1.By brand\n"
            << "2.By model\n"
            << "3.By year\n"
            << "4.By engine volume\n"
            << "5.By price\n"
            << "Your choice: ";
        int choice;
        cin >> choice;
        if (choice < 1 || choice > 5) {
            cout << "Incorrect choice.\n";
            return;
        }
        int n = cars.size();
        int min;
        bool find;

        for (int i = 0; i < n - 1; ++i) {
            min = i;
            for (int j = i + 1; j < n; ++j) {
                find = false;
                switch (choice) {
                case 1: find = (cars[j].getBrand() < cars[min].getBrand()); break;
                case 2: find = (cars[j].getModel() < cars[min].getModel()); break;
                case 3: find = (cars[j].getYear() < cars[min].getYear()); break;
                case 4: find = (cars[j].getEngVol() < cars[min].getEngVol()); break;
                case 5: find = (cars[j].getPrice() < cars[min].getPrice()); break;
                }
                if (find) {
                    min = j;
                }
            }
            if (min != i) {
                swap(cars[i], cars[min]);
            }
        }
    }
    void searchCars() const {
        if (cars.empty()) {
            cout << "Empty.\n";
            return;
        }
        cout << "\nChoose a search criterion:\n"
            << "1.By brand\n"
            << "2.By model\n"
            << "3.By year\n"
            << "4.By engine volume\n"
            << "5.By price\n"
            << "Your choice: ";
        int choice;
        cin >> choice;
        bool found = false;

        switch (choice) {
        case 1: {
            string tBrand;
            cout << "Enter brand: "; cin >> tBrand;
            cout << "\n";
            for (int i = 0; i < cars.size(); ++i) {
                if (cars[i].getBrand() == tBrand) {
                    cars[i].show();
                    found = true;
                }
            }
            break;
        }
        case 2: {
            string tModel;
            cout << "Enter model: "; cin >> tModel;
            cout << "\n";
            for (int i = 0; i < cars.size(); ++i) {
                if (cars[i].getModel() == tModel) {
                    cars[i].show();
                    found = true;
                }
            }
            break;
        }
        case 3: {
            int tYear;
            cout << "Enter year: "; cin >> tYear;
            cout << "\n";
            for (int i = 0; i < cars.size(); ++i) {
                if (cars[i].getYear() == tYear) {
                    cars[i].show();
                    found = true;
                }
            }
            break;
        }
        case 4: {
            double tEngVol;
            cout << "Enter engine volume: "; cin >> tEngVol;
            cout << "\n";
            for (int i = 0; i < cars.size(); ++i) {
                if (cars[i].getEngVol() == tEngVol) {
                    cars[i].show();
                    found = true;
                }
            }
            break;
        }
        case 5: {
            double tPrice;
            cout << "Enter maximum price ($): "; cin >> tPrice;
            cout << "\n";
            for (int i = 0; i < cars.size(); ++i) {
                if (cars[i].getPrice() <= tPrice) {
                    cars[i].show();
                    found = true;
                }
            }
            break;
        }
        default:
            cout << "Incorrect choice.\n";
            return;
        }

        if (!found) {
            cout << "No cars found for your query.\n";
        }
    }
};