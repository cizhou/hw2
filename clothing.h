#ifndef CLOTHING_H
#define CLOTHING_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"

class Clothing : public Product {
    private: 
        std::string size_; 
        std::string brand_;
    public: 
        Clothing(const std::string ISBN, const std::string author, const std::string category_, const std::string name_, const double price_, const int qty_);
        ~Clothing();
        virtual std::set<std::string> keywords() const;
        virtual bool isMatch(std::vector<std::string>& searchTerms) const;
        virtual std::string displayString() const;
        virtual void dump(std::ostream& os) const; 
};

#endif