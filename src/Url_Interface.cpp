#include "Url_Interface.h"

#include<iostream>

void Url_Interface::processRequest()
{
}

/////////////////////   Dnb_Interface   /////////////////////////


Dnb_Interface::Dnb_Interface() : Url_Interface()
{
    rootUrl_ = "https://services.dnb.de/sru/dnb?version=1.1&operation=searchRetrieve";
}


void Dnb_Interface::genRequest( std::string anyfields )
{
}

void Dnb_Interface::genRequest( BookDataset bds )
{
}

void Dnb_Interface::genRequestIsbn( std::string isbn )
{
    request_ = rootUrl_ + "&query=isbn" + urlCode( "=" ) + isbn + "&accessToken=" + token_;
    std::cout << request_ <<std::endl;
}

void Dnb_Interface::parseRdfXml()
{
}
