#include "Cql_query.h"

using namespace std;

string const _knownChars = "0123456789";

string encode_char( char chr )
{
    if ( _knownChars.find( chr ) == std::string::npos )
        // do conversion
        int dbg = 0;
    else
        return string(1, chr);
}

std::string url_encode( std::string const& str )
{
}

void Cql_query::pushConstParam( std::string name, std::string value )
{
}

void Cql_query::pushVolatileParam(  std::string name, std::string value )
{
}

void Cql_query::clearVolatilePars()
{
}
