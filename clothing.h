#ifndef USER_H
#define USER_H

#include "product.h"
#include <iostream>
#include <string>

class Clothing : public Product {

  public:
  // public variables
    std::string size_;
    std::string brand_;
  // public functions
    Clothing(const std::string size, const std::string brand, const std::string category, const std::string name, const double price, const int qty);
    ~Clothing();
    std::set<std::string> keywords() const;
    std::string displayString() const;
    void dump(std::ostream& os) const;



  
};

#endif


