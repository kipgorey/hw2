#ifndef MOVIE_H
#define MOVIE_H

#include "product.h"
#include <iostream>
#include <string>

class Movie : public Product {

  public:
  // public variables
    std::string genre_;
    std::string rating_;
  // public functions

  Movie(const std::string genre, const std::string rating, const std::string category, const std::string name, const double price, const int qty);
  ~Movie();
  virtual std::set<std::string> keywords() const;
  virtual std::string displayString() const;
  virtual void dump(std::ostream& os) const;

  


  



};

#endif





