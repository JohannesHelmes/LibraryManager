#include "catch.hpp"
#include "Isbn.h"

TEST_CASE( "Testing class Isbn", "[Isbn]" )
{
    Isbn isbnVal10, isbnWrong10, isbnVal13, isbnWrong13, isbnIncomplete13;
    isbnVal10.update ( "3426111233" );
    isbnVal13.update ( "9783411040155" );
    std::string isbnQueneau = "2070253104";

    REQUIRE( isbnVal10.getTyp() == 'X' );
    REQUIRE( isbnVal10.checkValid() );

    REQUIRE( isbnVal13.getTyp() == 'E' );
    REQUIRE( isbnVal13.checkValid() );
}
