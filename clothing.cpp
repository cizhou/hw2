#include <sstream>
#include <iomanip>
#include "clothing.h"
#include "util.h"

using namespace std;

Clothing::Clothing(const string size, const string brand, const string category, const string name, const double price, const int qty) : Product (category, name, price, qty)
{
  size_ = size;
  brand_ = brand;
  category_ = category;
  name_ = name;
  price_ = price;
  qty_ = qty;
}

Clothing::~Clothing()
{

}


std::set<std::string> Clothing::keywords() const
{
    std::set<std::string> keywords; 

    std::string rawWords = this->name_ + " " + this->brand_ + " " + this->size_;
    keywords = parseStringToWords(rawWords);
  
    return keywords;
}

bool Clothing::isMatch(std::vector<std::string>& searchTerms) const
{
    return true; 
}

std::string Clothing::displayString() const
{
    string display_return = "";
    display_return += this->name_ + "\n" + "Size: " + this->size_ + " Brand: " + this->brand_ + "\n" + to_string(this->price_) + " " + to_string(this->qty_) + " left";
    return display_return;
}

void Clothing::dump(std::ostream& os) const
{
    os << this->category_ << endl;
    os << this->name_ << endl;
    os << this->price_ << endl;
    os << this->qty_ << endl;
    os << this->size_ << endl;
    os << this->brand_ << endl;
}
