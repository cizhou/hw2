#ifndef MYDATASTORE_H
#define MYDATASTORE_H

#include <string>
#include <set>
#include <vector>
#include <map>

#include "datastore.h"
#include "user.h"
#include "product.h"

class MyDataStore : public DataStore{

    private:

        // PRIVATE VARIABLES

        /* a set that holds all products that the store has, inventory */
        std::set<Product*> products_; 

        /* a map that takes in a key of a user and maps it to a vector products
         * a map that maps users to all items they have in their cart */
        std::map<User*, std::vector<Product*>> users_;
        
        /* a map that takes in a key of a string and maps taht to a set of products
         * a map that takes in a a name of a product (as a string) and maps it to a list of 
         * products that has the same keywords */
        std::map<std::string, std::set<Product*>> keywords_;




        // HELPER FUNCTIONS

        /* a function that returns the reference of a product in products_ given p
         * used to check if a product is real */
        Product* stringToProduct(std::string p);

        /* a function that returns the reference of a user in users_ given u
         * used to check if a user is real
         * if function returns nullptr, show an error messagem*/
        User* stringToUser(std::string u);

        /* a function that takes in a user reference and returns
         * a cart reference */
        std::vector<Product*>& userToCart(User* u);

    public: 

        /* METHODS MUST BE ABLE TO
         * code form amazon.cpp
         * cout << "=====================================" << endl;
         * cout << "  AND term term ...                  " << endl;     ds.search(terms, 0);
         * cout << "  OR term term ...                   " << endl;     ds.search(terms, 1);
         * cout << "  ADD username search_hit_number     " << endl;     *** Need to implement ***
         * cout << "  VIEWCART username                  " << endl;     *** Need to implement ***
         * cout << "  BUYCART username                   " << endl;     *** Need to implement ***
         * cout << "  QUIT new_db_filename               " << endl;     ofstream ofile(filename.c_str());       ds.dump(ofile);     ofile.close();
         * cout << "=====================================" << endl; */




        // DERIVED FROM DATASTORE

        /* deallocates the memory taken up */
        ~MyDataStore(); 

        /* input: a product reference
         * output: nothing, internally adds this product to products_ */
        void addProduct(Product* p); 

        /* input: a user reference
         * output: nothing, internally adds this user to users_, the key being u which maps to an empty array */
        void addUser(User* u); 

        /* input: a vector of terms and the type of search that will be performed
         * output: a vector of product references that match the search criteria*/
        std::vector<Product*> search(std::vector<std::string>& terms, int type);

        /* input: a ostream object reference
         * outputs everything to the ostream */
        void dump(std::ostream& ofile);







        // MY METHODS
        
        /* input: string username and a product reference
         * output: nothing, internally adds a product to the user's cart
         * finds the user in users_ and adds product p to the set it is mapped to */
        void addToCart(std::string username, Product* p);

        /* input: string username
         * output: prints out all items that the user has in their cart */
        void viewCart(std::string username); 

        /* input: string username
         * outputs: nothing
         * internally: checks if item is in stock, changes quantitiy in stock, updates user's balance */
        void buyCart(std::string username);







}; 

#endif