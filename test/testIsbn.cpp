#include "catch.hpp"
#include "Isbn.h"

TEST_CASE( "Testing class Isbn", "[Isbn]" )
{
    Isbn isbnVal10, isbnWrong10, isbnVal13, isbnWrong13, isbnIncomplete10;
    isbnVal10.update ( "3426111233" );
    isbnVal13.update ( "9783411040155" );
    std::string isbnQueneau = "2070253104";

    CHECK( isbnVal10.getTyp() == 'X' );
    CHECK( isbnVal10.checkValid() );
    CHECK( isbnVal10.getNumber() == "3426111233" );

    CHECK( isbnVal13.getTyp() == 'E' );
    CHECK( isbnVal13.checkValid() );

    isbnIncomplete10.update( "3765485" );
    CHECK( isbnIncomplete10.getTyp() == 'X' );
    std::string autoComp = "";
    auto list = isbnIncomplete10.autoComplete( 10 );
    list = isbnIncomplete10.autoComplete( 8 );
    for ( auto listItr = list.cbegin(); listItr != list.cend(); ++listItr )
        autoComp +=  *listItr + "\n";
    WARN( autoComp );
}
