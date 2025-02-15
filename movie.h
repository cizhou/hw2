#ifndef MOVIE_H
#define Movie_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"

class Movie : public Product {
    private: 
        std::string genre_; 
        std::string rating_;
    public: 
        Movie(const std::string ISBN, const std::string author, const std::string category_, const std::string name_, const double price_, const int qty_);
        ~Movie();
        virtual std::set<std::string> keywords() const;
        virtual bool isMatch(std::vector<std::string>& searchTerms) const;
        virtual std::string displayString() const;
        virtual void dump(std::ostream& os) const; 
};

#endif