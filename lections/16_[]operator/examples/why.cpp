class User {
    int id;
public:
    User(int id) : id(id) {}
    
    bool operator==(const User& other) const {
        return id == other.id;
    }
};

class Product {
    int id;
public:
    Product(int id) : id(id) {}
    
    bool isEqual(const Product& other) const {
        return id == other.id;
    }
};