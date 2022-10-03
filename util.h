#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>

using namespace std;


/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */
template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{
  int size_before = s1.size();
  typename set<T>::iterator itr;

  set<T> intersection_return;

  for(itr = s2.begin(); itr != s2.end(); itr++)
  {
    s1.insert(*itr);
    if(s1.size() == size_before)
    {
      intersection_return.insert(*itr);
    } else {
      size_before = s1.size(); // set equal to
    }
  }

  return intersection_return;
  

}
template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{

  // run in O(nlog(n)) time

  set<T> intersection_return;
  
  intersection_return.insert(s1.begin(), s1.end());
  intersection_return.insert(s2.begin(), s2.end());

  return intersection_return;


}

/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
std::string &ltrim(std::string &s) ;

// Removes any trailing whitespace
std::string &rtrim(std::string &s) ;

// Removes leading and trailing whitespace
std::string &trim(std::string &s) ;
#endif
