#ifndef MOVIE_H
#define MOVIE_H

#include "product.h"
#include <iostream>
#include <string>

class Movie : public Product {

  public:
  // public variables
    std::string genre;
    std::string rating;
  // public functions

  Movie(const std::string genre, const std::string rating, const std::string category_, const std::string name_, const double price_, const int qty_);
  ~Movie();
  std::set<std::string> keywords() const;
  std::string displayString() const;
  void dump(std::ostream& os) const;

  


  



};

#endif





