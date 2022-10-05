#include "mydatastore.h"
#include "util.h"
#include "book.h"
#include "movie.h"
#include "clothing.h"
#include "product_parser.h"
#include "datastore.h"
#include "user.h"
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <set>
#include <map>
#include <vector>

using namespace std;



void MyDataStore::addProduct(Product *p)
{
  keyword_map.insert({p->keywords(), p});
  all_products.insert(p); // for dump output later only

}

void MyDataStore::addUser(User *u)
{
  all_users.insert(u); // for dump output later only
  user_to_id.insert({u->getName(), u});
  
}

std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type)
{
  std::vector<Product*> item_list;
  
  if(type == 0) // run and -- work on this
  {
    std::set<std::string> combined;
    std::set<std::string> temp(terms.begin(), terms.end());
    
    

    std::map<std::set<std::string>, Product*>::iterator it; // keywords set to product
    for(it = keyword_map.begin(); it != keyword_map.end(); it++)
    {
      std::set<std::string> keyword_two = it->first;

      combined = setIntersection(keyword_two, temp);
      
      if(combined.size() == temp.size())
      {
        std::cout << "test for and" << endl;
        item_list.push_back(it->second);
      }
    }
  }
  if(type == 1) // run or -- good
  {
    std::set<std::string> combined;
    std::set<std::string> temp(terms.begin(), terms.end());

    std::map<std::set<std::string>, Product*>:: iterator it; // keywords set to product
    for(it = keyword_map.begin(); it != keyword_map.end(); it++)
    {
      std::set<std::string> keyword_two = it->first;
      combined = setIntersection(keyword_two, temp);
      if(combined.size() > 0)
      {
        item_list.push_back(it->second);
      }
    }

  }

  this->search_hits = item_list;
  return item_list;

}

void MyDataStore::add(std::string usrn_, Product *p)
{
  cart[usrn_].push_back(p);

}

void MyDataStore::buy(std::string usrn_)
{


  // make an iterator to go through cart
  //
  if(user_to_id.find(usrn_) != user_to_id.end())
  {
    double amount;
    for(int unsigned i = 0; i < cart[usrn_].size(); i++) 
    {
      amount = 0;
      amount += cart[usrn_][i]->getPrice(); // charge the user
      if(user_to_id[usrn_]->getBalance() >= amount && cart[usrn_][i]->getQty() > 0)
      {
        cart[usrn_][i]->subtractQty(1); // reduce the quantity by 1
        user_to_id[usrn_]->deductAmount(amount);
        cart[usrn_].erase(cart[usrn_].begin()+i);
      }
      
    }
  } else {
    std::cout << "Invalid username" << endl;

  }


}


void MyDataStore::view(std::string usrn_)
{
  if(user_to_id.find(usrn_) != user_to_id.end())
  {
    std::vector<Product*>::iterator itr;
    for(itr = cart[usrn_].begin(); itr != cart[usrn_].end(); itr++)
    {
      cout << (*itr)->displayString() << endl; // displays the string
    }
  } else {
    std::cout << "Invalid username" << endl;
  }
}

void MyDataStore::dump(std::ostream& ofile)
{
  std::set<Product*>::iterator itr;
  for(itr = all_products.begin(); itr != all_products.end(); itr++)
  {
    (*itr)->dump(ofile); // runs the product dump functions for each product in the cart
  }

  std::set<User*>::iterator it;
  for(it = all_users.begin(); it != all_users.end(); it++)
  {
    (*it)->dump(ofile);

  }

}




