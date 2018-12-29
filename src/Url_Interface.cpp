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
    searchParams_.push_back( make_pair( "version", "1.1" ) );
    searchParams_.push_back( make_pair( "operation", "searchRetrieve" ) );
}

void Dnb_Interface::setToken( string token )
{
    searchParams_.push_back( make_pair( "accessToken", token ) );
}


ResultList Dnb_Interface::search( std::string anyfields )
{

}

ResultList Dnb_Interface::search( BookDataset bds )
{
}

ResultList Dnb_Interface::searchIsbns( std::string isbn )
{
    request_ = rootUrl_ + "&query=isbn" + urlCode( "=" ) + isbn + "&accessToken=" + token_;
    std::cout << request_ <<std::endl;
}

void Dnb_Interface::parseRdfXml()
{
}
