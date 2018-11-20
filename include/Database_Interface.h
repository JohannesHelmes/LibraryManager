#include "BookDataset.h"

class Database_Interface
{
public:
    Database_Interface();
    ~Database_Interface();

    void load( std::string filename );
    void add( BookDataset book );
    std::list< BookDataset > search( std::string key );

private:
    std::set< BookDataset > database_;
};
