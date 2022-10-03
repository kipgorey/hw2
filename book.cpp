#include "book.h" 
#include "util.h"
#include <iostream>
#include <set>


using namespace std;


Book::Book(const string ISBN, const string author, const string category_, const string name_, const double price_, const int qty_) : Product (category_, name_, price_, qty_)
{
  ISBN = ISBN;
  author = author;
  category_ = category_;
  name_ = name_;
  price_ = price_;
  qty_ = qty_;
}

Book::~Book()
{

}

std::set<std::string> Book::keywords() const
{
  set<string> key_set;
  key_set = parseStringToWords(this->author);
  key_set.insert(this->ISBN);

  return key_set;
}

std::string Book::displayString() const
{
  string display_return = "";
  display_return += this->name_ + "\n" + "ISBN: " + this->ISBN + " Author: " + this->author + "\n" + to_string(this->price_) + " " + to_string(this->qty_) + "left";
  return display_return;

}

void Book::dump(std::ostream& os) const
{

  os << this->category_ << endl;
  os << this->name_ << endl;
  os << this->price_ << endl;
  os << this->qty_ << endl;
  os << this->ISBN << endl;
  os << this->author << endl;

}






