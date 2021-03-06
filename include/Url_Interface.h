#pragma once 

#include "BookDataset.h"
#include "Isbn.h"
#include "Cql_query.h"

typedef std::list<BookDataset> ResultList ;

class Url_Interface
{
public:
    Url_Interface() {};
    virtual ~Url_Interface() {};

    virtual ResultList search( std::string anyfields ) = 0; 
    virtual ResultList search( BookDataset bds ); 
    virtual ResultList searchIsbns( std::string isbn ); 

protected:
    std::list<BookDataset> data_;
    std::pair< std::string, std::string > searchParams_;

    std::string request_;
private:
    void generateRequest();
    void processRequest();
    
};

class Dnb_Interface : public Url_Interface
{
public:
    Dnb_Interface();
    virtual ~Dnb_Interface() {};

    ResultList search( std::string anyfields );
    ResultList search( BookDataset bds ); 
    ResultList searchIsbns( std::string isbn ); 

    void setToken( std::string token );
    void setDefaultParams();

    std::string const& getResponseText() const { return response_; };
private:
    void parseRdfXml();
    std::string token_, rootUrl_, response_;
    Cql_query cql_;

};
