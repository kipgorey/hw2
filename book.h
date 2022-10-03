#ifndef BOOK_H
#define BOOK_H
#include "product.h" 
#include <iostream>
#include <string>

class Book : public Product {

  public:
  // public variables
    std::string ISBN;
    std::string author;
  // public functions
    Book(const std::string ISBN, const std::string author, const std::string category_, const std::string name_, const double price_, const int qty_);
    ~Book();
    std::set<std::string> keywords() const;
    std::string displayString() const;
    void dump(std::ostream& os) const;

};
#endif
