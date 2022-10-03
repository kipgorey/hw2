#ifndef USER_H
#define USER_H

#include "product.h"
#include <iostream>
#include <string>

class Clothing : public Product {

  public:
  // public variables
    std::string size;
    std::string brand;
  // public functions
    Clothing(const std::string size, const std::string brand, const std::string category_, const std::string name_, const double price_, const int qty_);
    ~Clothing();
    std::set<std::string> keywords() const;
    std::string displayString() const;
    void dump(std::ostream& os) const;



  
};

#endif


