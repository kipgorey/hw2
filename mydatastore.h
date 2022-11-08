#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include "datastore.h"
#include "util.h"

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>



class MyDataStore : public DataStore
{

  public:

  // from datastore class
    void delete_prods_users();
    void addProduct(Product* p);
    void addUser(User* u);
    std::vector<Product*> search(std::vector<std::string>& terms, int type);
  // from part 1
    void add(std::string usrn_, Product *p);
    void buy(std::string usrn_);
    void view(std::string usrn_);
    void dump(std::ostream& ofile);
    
  // variables


    std::string usrn_;
    std::vector<Product*> search_hits;
    std::map<std::string, std::vector<Product*>> cart; // username to product vector
    std::map<std::set<std::string>, Product*> keyword_map; // keywords set to product
    std::map<std::string, User*> user_to_id; // username to user
    std::set<Product*> all_products;
    std::set<User*> all_users;




};

#endif










