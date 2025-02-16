#include "mydatastore.h"
#include "util.h"

using namespace std; 

// DERIVED FUNCTIONS

MyDataStore::~MyDataStore()
{
    for (Product *p: products_) 
    {
        delete p;
    }

    for (map<User*, vector<Product*>>::iterator it = users_.begin(); it != users_.end(); ++it)
    {
        delete it->first;

        // for (Product* p : it->second)
        // {
        //     delete p; 
        // }
    }

    products_.clear();
    users_.clear();
    keywords_.clear();
}

// changing string into product is taken care of by the given code
void MyDataStore::addProduct(Product* p)
{
    products_.insert(p);

    // add reference to product p under each of it's keyword in keywords_
    std::set<std::string> keywords = p->keywords();
    for (string k: keywords)
    {
        if (keywords_.find(k) == keywords_.end())
        {
            keywords_[k] = std::set<Product *>();
        }
        keywords_[k].insert(p);
    }
}

void MyDataStore::addUser(User* u)
{
    // user starts off with an empty cart
    std::vector<Product*> userCart;
    users_.insert({u, userCart});
}

std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type)
{
    std::vector<Product*> searchResults;
    
    /* setIntersection and setUnion only works with sets
     * std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
     * enter in two sets of Products */
    std::set<Product*> searchResultsSet; 

    if (terms.empty() || (type != 0 && type != 1))
    {
        std::cout << "Invalid request" << std::endl;
        return searchResults;
    }

    bool first = true;
    for (std::string& t : terms)
    {
        if (first)                              // initialize searchResultSet
        {
            searchResultsSet = keywords_[t];
            first = false;
        }
        else if (type == 0)                     // AND search
        {
            searchResultsSet = setIntersection(searchResultsSet, keywords_[t]);
        }
        else                                    // OR search
        {
            searchResultsSet = setUnion(searchResultsSet, keywords_[t]);
        }
    }

    for (Product* product : searchResultsSet) 
    {
        searchResults.push_back(product);
    }

    return searchResults;
}

void MyDataStore::dump(std::ostream& ofile)
{
    ofile << "<products>" << std::endl; 
    for (Product *p: products_)
    {
        p->dump(ofile);
    }
    ofile << "</products>" << std::endl;

    ofile << "<users>" << std::endl;
    for (map<User*, vector<Product*>>::iterator it = users_.begin(); it != users_.end(); ++it)
    {
        (it->first)->dump(ofile);
    }
    ofile << "</users>" << std::endl;

}








// MY FUNCTIONS

void MyDataStore::addToCart(std::string username, Product* p)
{
    User* temp = stringToUser(username);
    if(temp == nullptr)
    {
        cout << "Invalid request" << endl;
        return;
    }

    userToCart(temp).push_back(p);
}

void MyDataStore::viewCart(std::string username)
{
    User* temp = stringToUser(username);
    if(temp == nullptr)
    {
        cout << "Invalid username" << endl;
        return;
    }

    std::vector<Product*> cart = userToCart(temp);

    for(unsigned int i = 0; i < cart.size(); i++)
    {
        std::cout << "Item " << i + 1 << ":" << std::endl;
        std::cout << cart[i]->displayString() << std::endl;        
    }
}

void MyDataStore::buyCart(std::string username)
{
    User* temp = stringToUser(username);
    if(temp == nullptr)
    {
        std::cout << "Invalid username" << std::endl;
        return;
    }

    std::vector<Product*>& cart = userToCart(temp);
        std::vector<Product*> unBoughtItems;

        for (Product* p : cart)
        {
            if (p->getQty() > 0 && p->getPrice() <= temp->getBalance())
            {
                temp->deductAmount(p->getPrice());
                p->subtractQty(1);
            }
            else
            {
                unBoughtItems.push_back(p);
            }
        }

        cart = unBoughtItems;
}








// PRIVATE HELPER FUNCTIONS
Product* MyDataStore::stringToProduct(std::string productName) 
{
    for (Product* p : products_) 
    {
        if (p->getName() == productName) {
            return p;
        }
    }
    return nullptr;
}

User* MyDataStore::stringToUser(std::string username)
{
    User* user = nullptr;
    for(map<User*, vector<Product*>>::iterator it = users_.begin(); it != users_.end(); ++it)
    {
      if((it->first)->getName() == username)
      {
        user = it->first;
        break;
      }
    }
    return user;
}

std::vector<Product*>& MyDataStore::userToCart(User* u)
{
    std::map<User*, std::vector<Product*>>::iterator it = users_.find(u);
    return it->second;
}