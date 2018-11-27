#include "catch.hpp"
#include "Isbn.h"

TEST_CASE( "Testing class Isbn", "[Isbn]" )
{
    Isbn isbn;
    std::string isbnSchwab = "3A26111233";
    std::string isbnDuden = "9783411040155";
    std::string isbnQueneau = "2070253104";
    isbn.update( isbnSchwab );
    REQUIRE( isbn.getTyp() == 'X' );
    REQUIRE( isbn.checkValid() );
}
