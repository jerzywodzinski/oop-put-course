#include <iostream>
#include <vector>

class Product {
private:
    std::string name;
    double price;
    int productId;

public:
    Product(const std::string& name, double price, int productId)
        : name(name), price(price), productId(productId) {}

    double showPrice() const { return price; }
};

class Customer {
private:
    std::string name;
    std::string email;
    int customerId;

public:
    Customer(const std::string& name, const std::string& email, int customerId)
        : name(name), email(email), customerId(customerId) {}


};

class Order {
private:
    int orderId;
    Customer customer;
    std::vector<Product> products;

public:
    Order(int orderId, const Customer& customer)
        : orderId(orderId), customer(customer) {}

    void addProduct(const Product& product) {
        products.push_back(product);
    }

    double calculateTotalCost() const {
        double totalCost = 0.0;
        for (const Product& product : products) {
            totalCost += product.showPrice();
        }
        return totalCost;
    }
};

int main() {
    Product product1("Product 1", 10.0, 1);
    Product product2("Product 2", 20.0, 2);
    Product product3("Product 3", 29.99, 3);

    Customer customer("Jan Nowak", "jannowak@gmail.com", 1);

    Order order(1, customer);
    order.addProduct(product1);
    order.addProduct(product2);
    order.addProduct(product3);

    double totalCost = order.calculateTotalCost();
    std::cout << "Total cost of the order: " << totalCost << std::endl;

    return 0;
}
