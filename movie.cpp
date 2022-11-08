#include "movie.h" 
#include "util.h"
#include <iostream>
#include <set>

using namespace std;


Movie::Movie(const string genre, const string rating, const string category, const string name, const double price, const int qty) : Product (category, name, price, qty)
{
  genre_ = genre;
  rating_ = rating;
  category_ = category;
  name_ = name;
  price_ = price;
  qty_ = qty;
}

Movie::~Movie()
{
  // destructor function

}

std::set<std::string> Movie::keywords() const
{
  std::set<string> key_set;
  // std::string combined_string = this->rating_ + " " + this->name_;
  key_set = parseStringToWords(this->name_);
  key_set.insert(convToLower(this->genre_));
  key_set.insert(convToLower(this->rating_));

  return key_set;



}

std::string Movie::displayString() const
{
  string display_return = "";
  display_return += this->name_ + "\n" + "Genre: " + this->genre_ + " Rating: " + this->rating_ + "\n" + to_string(this->price_) + " " + to_string(this->qty_) + " left";
  return display_return;
}

void Movie::dump(std::ostream& os) const
{
  os << this->category_ << endl;
  os << this->name_ << endl;
  os << this->price_ << endl;
  os << this->qty_ << endl;
  os << this->genre_ << endl;
  os << this->rating_ << endl;

}


