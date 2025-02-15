#include <sstream>
#include <iomanip>
#include "movie.h"
#include "util.h"

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

}


std::set<std::string> Movie::keywords() const
{
    std::set<std::string> keywords; 

    std::string rawWords = this->name_ + " " + this->genre_ + " " + this->rating_;
    keywords = parseStringToWords(rawWords);
  
    return keywords;
}

bool Movie::isMatch(std::vector<std::string>& searchTerms) const
{
    return true; 
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
