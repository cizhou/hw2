#include <sstream>
#include <iomanip>
#include "book.h"
#include "util.h"


using namespace std;

Book::Book(const string isbn, const string author, const string category, const string name, const double price, const int qty) : Product (category, name, price, qty)
{
  ISBN_ = isbn;
  author_ = author;
  category_ = category;
  name_ = name;
  price_ = price;
  qty_ = qty;
}

Book::~Book()
{

}


std::set<std::string> Book::keywords() const
{
    std::set<std::string> keywords; 

    std::string rawWords = this->name_ + " " + this->author_;
    keywords = parseStringToWords(rawWords);
    keywords.insert(convToLower(this->ISBN_));
  
    return keywords;
}

bool Book::isMatch(std::vector<std::string>& searchTerms) const
{
    return true; 
}

std::string Book::displayString() const
{
    string display_return = "";
    display_return += this->name_ + "\n" + "Author: " + this->author_ + " ISBN: " + this->ISBN_ + "\n" + to_string(this->price_) + " " + to_string(this->qty_) + " left";
    return display_return;
}

void Book::dump(std::ostream& os) const
{
    os << this->category_ << endl;
    os << this->name_ << endl;
    os << this->price_ << endl;
    os << this->qty_ << endl;
    os << this->ISBN_ << endl;
    os << this->author_ << endl;
}
