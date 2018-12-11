#include "BookDataset.h"
#include "Isbn.h"

class Url_Interface
{
public:
    Url_Interface() {};
    virtual ~Url_Interface() {};

    virtual void processRequest() = 0;
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
    Dnb_Interface() : Url_Interface {};
    ~Dnb_Interface();

    void processRequest( );
    void genRequest( std::string anyfields ); 
    void genRequest( BookDataset bds ); 
    void genRequestIsbn( std::string isbn ); 

private:
    void parseRdfXml();

};
