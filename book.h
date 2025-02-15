#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"

class Book : public Product {
    private: 
        std::string ISBN_; 
        std::string author_;
    public: 
        Book(const std::string ISBN, const std::string author, const std::string category_, const std::string name_, const double price_, const int qty_);
        ~Book();
        virtual std::set<std::string> keywords() const;
        virtual bool isMatch(std::vector<std::string>& searchTerms) const;
        virtual std::string displayString() const;
        virtual void dump(std::ostream& os) const; 
};

#endif