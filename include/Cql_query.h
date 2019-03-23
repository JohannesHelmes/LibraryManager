#include<string>

// inspired by https://ideone.com/ssgW1h
std::string encode_char( char chr );

std::string url_encode( std::string const& str );

class Cql_query
{
public:
    Cql_query() {}
    ~Cql_query() {}

    void pushConstParam( std::string name, std::string value );
    void pushVolatileParam(  std::string name, std::string value );
    void clearVolatilePars();
    std::string getQuery() const { return totalQuery_; }
private:

    std::string constQuery_, volatileQuery_, totalQuery_;
};
