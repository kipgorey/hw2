#include "movie.h" 
#include "util.h"
#include <iostream>
#include <set>

using namespace std;


Movie::Movie(const string genre, const string rating, const string category_, const string name_, const double price_, const int qty_) : Product (category_, name_, price_, qty_)
{
  genre = genre;
  rating = rating;
  category_ = category_;
  name_ = name_;
  price_ = price_;
  qty_ = qty_;
}

Movie::~Movie()
{
  // destructor function

}

std::set<std::string> Movie::keywords() const
{
  set<string> key_set;
  key_set = parseStringToWords(rating);
  key_set.insert(genre);

  return key_set;



}

std::string Movie::displayString() const
{
  string display_return = "";
  display_return += this->name_ + "\n" + "Genre: " + this->genre + " Rating: " + this->rating + "\n" + to_string(this->price_) + " " + to_string(this->qty_) + "left";
  return display_return;
}

void Movie::dump(std::ostream& os) const
{
  os << this->category_ << endl;
  os << this->name_ << endl;
  os << this->price_ << endl;
  os << this->qty_ << endl;
  os << this->genre << endl;
  os << this->rating << endl;

}


