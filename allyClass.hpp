/*   allyClass.hpp
*   
*    NOTES: [PLEASE WRITE ANYTHIGN OF NOTING WHETHER YOU ARE APOL OR NOT, LIST YOUR NAME THOUGH]
*
* 	 
*
*/


#ifndef ALLYCLASS_H
#define ALLYCLASS_H
#include "node.hpp"
#include <string>
#include <vector>
#include <unordered_map>

class Ally {
private:
    // the name of the ally
    std::string allyName;

public:

    // constructor with no name, default ally name is Ally #
    Ally();

    // constructor with ally name
    Ally(std::string name);

    // gets the ally name
    std::string getAllyName();

    // set the ally name
    void setAllyName(std::string name);
};


#endif