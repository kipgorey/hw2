#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <string>
#include "util.h"



using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{ // complete function

    // parse the words and return a set of keywords

    set<std::string> keywords;
    rawWords = convToLower(rawWords); // in order to make the keywords case insensitive
    
    string current_word = "";
    int last_index = 0;
    int last_length = 1;

    for(unsigned int i = 0; i < rawWords.length(); i++)
    {
        if(ispunct(rawWords[i]) || rawWords[i] == ' '){
            // if the character is a punction, then segment off that string
            current_word = rawWords.substr(last_index, last_length-1);
            // now add that word to keywords if it has a length greater than 2
            if(current_word.length() > 1)
            {
                keywords.insert(current_word);
            }

            last_length = 0;
            last_index = i+1;
        } 
        last_length++;

    }
    // run one more time to check the final keyword
    current_word = rawWords.substr(last_index, last_length);
    if(current_word.length() > 1)
    {
        keywords.insert(current_word);
    }


    return keywords;

}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
