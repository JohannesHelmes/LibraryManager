class Cql_query
{
public:
    Cql_query() {}
    ~Cql_query() {}

    void pushConstParam( std::string name, std::string value );
    void pushVolatileParam(  std::string name, std::string value );
    void clearVolatilePars();
    std::string getQuery() { return totalQuery_; } const;
private:

    std::string constQuery_, volatileQuery_, totalQuery_;
};
