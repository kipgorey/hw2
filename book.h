#ifndef BOOK_H
#define BOOK_H
#include "product.h" 
#include <iostream>
#include <string>

class Book : public Product {

  public:
  // public variables
    std::string ISBN_;
    std::string author_;
  // public functions
    Book(const std::string ISBN, const std::string author, const std::string category_, const std::string name_, const double price_, const int qty_);
    ~Book();
    virtual std::set<std::string> keywords() const;
    virtual std::string displayString() const;
    virtual void dump(std::ostream& os) const;

};
#endif
