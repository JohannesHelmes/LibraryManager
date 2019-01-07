#include "Url_Interface.h"

#include<iostream>

using namespace std;


/////////////////////   Url_Interface   /////////////////////////

void Url_Interface::generateRequest()
{
}

void Url_Interface::processRequest()
{
}

/////////////////////   Dnb_Interface   /////////////////////////


Dnb_Interface::Dnb_Interface() : Url_Interface()
{
    rootUrl_ = "https://services.dnb.de/sru/dnb?";
    cql_.pushConstPar( "version", "1.1" );
    cql_.pushConstPar( "operation", "searchRetrieve" );
}

void Dnb_Interface::setToken( string token )
{
    cql_.pushConstPar( "accessToken", token );
}


ResultList Dnb_Interface::search( std::string anyfields )
{

}

ResultList Dnb_Interface::search( BookDataset bds )
{
}

ResultList Dnb_Interface::searchIsbns( std::string isbn )
{
    cql_.clearVolatilePars();
    cql_.pushVolatilePar( "query", "isbn=" + isbn );
    request_ = rootUrl_ + cql_.request();
    std::cout << request_ <<std::endl;
}

void Dnb_Interface::parseRdfXml()
{
}
