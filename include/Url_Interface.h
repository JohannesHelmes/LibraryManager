#pragma once 

#include "BookDataset.h"
#include "Isbn.h"

class Url_Interface
{
public:
    Url_Interface() {};
    virtual ~Url_Interface() {};

    void processRequest();
    virtual void genRequest( std::string anyfields ) = 0; 
    virtual void genRequest( BookDataset bds ); 
    virtual void genRequestIsbn( std::string isbn ); 
    std::list<BookDataset> getData() const {return data_;};

protected:
    std::list<BookDataset> data_;
    std::string request_;
};

class Dnb_Interface : public Url_Interface
{
public:
    Dnb_Interface();
    virtual ~Dnb_Interface() {};

    void genRequest( std::string anyfields ); 
    void genRequest( BookDataset bds ); 
    void genRequestIsbn( std::string isbn ); 

    void setToken( std::string token ) { token_ = token; }

    std::string const& getResponseText() const { return response_; };
private:
    void parseRdfXml();
    std::string token_, rootUrl_, response_;

};
