#include <iostream>
#include "BlogEntry.h"
#include "Text.h"
#include "Date.h"
using namespace std;

/*Constructor
 Pre: none
 Post: creates an entry with unnamed author and empty contents.*/
BlogEntry::BlogEntry()
{
    // complier calls default constructor for Text and Date
}


/*Constructor
 Pre: none
 Post: creates an entry initialized to the specified author and contents.*/
BlogEntry::BlogEntry(const Text& initAuthor, const Text& initContents)
    :author(initAuthor), contents(initContents)
{
    //author = initAuthor;
    //contents = initContents;
}


/*Constructor
 Pre: none
 Post: returns value of author object.*/
Text BlogEntry::getAuthor() const
{
    return author;
}


/*Constructor
 Pre: none
 Post: returns value of contents object.*/
Text BlogEntry::getContents() const
{
    return contents;
}


/*Constructor
 Pre: none
 Post: returns value of created object.*/
Date BlogEntry::getCreateDate() const
{
    return created;
}

/*Constructor
 Pre: none
 Post: returns value of modified object.*/
Date BlogEntry::getModifyDate() const
{
    return modified;
}


/*Constructor
 Pre: none
 Post: sets value of author object.*/
void BlogEntry::setAuthor(const Text& newAuthor)
{
    author = newAuthor;
}


/*Constructor
 Pre: none
 Post: sets value of contents object.*/
void BlogEntry::setContents(const Text& newContents)
{
    contents = newContents;
}


/*Constructor
 Pre: none
 Post: outputs the contents of the BlogEntry.*/
void BlogEntry::showStructure() const
{
    cout << "Author: " << author << endl;
    cout << "Created: " << created << endl;
    cout << "Modified: " << modified << endl;
    cout << "Content: " << contents << endl;
}
//Program Exercise 1

/*Constructor
 Pre: none
 Post: sends output to the stream out in the format specified below.*/
void BlogEntry::printHTML( ostream& out ) const
{
    out << "<html>" << endl;
    out << "<body>" << endl;
    out<< "<hl>" << author << "</hl>" << endl;
    out << "<p>" << endl;
    out << contents << endl;
    out << "</p>" << endl;
    out << "<p>" << endl;
    out << "Created: " << created << endl;
    out << "</p>" << endl;
    out << "<p>" << endl;
    out << "Last modified: " << modified << endl;
    out << "</p>" << endl;
    out << "</body>" << endl;
    out << "<html>" << endl;
}








