#include "clothing.h"
#include "util.h"
#include <iostream>


using namespace std;


Clothing::Clothing(const string size, const string brand, const string category_, const string name_, const double price_, const int qty_) : Product (category_, name_, price_, qty_)
{
  size = size;
  brand = brand;
  category_ = category_;
  name_ = name_;
  price_ = price_;
  qty_ = qty_;

}

Clothing::~Clothing()
{
  
}

std::set<std::string> Clothing::keywords() const
{
  set<string> key_set;
  string combined_string = size + " " + brand;
  key_set = parseStringToWords(combined_string);

  return key_set;
}

std::string Clothing::displayString() const
{
  string display_return = "";
  display_return += this->name_ + "\n" + "Size: " + this->size + " Brand: " + this->brand + "\n" + to_string(this->price_) + " " + to_string(this->qty_) + "left";
  return display_return;

}

void Clothing::dump(std::ostream& os) const
{
  os << this->category_ << endl;
  os << this->name_ << endl;
  os << this->price_ << endl;
  os << this->qty_ << endl;
  os << this->size << endl;
  os << this->brand << endl;

}


