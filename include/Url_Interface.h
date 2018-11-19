#include "BookDataset.h"

class Url_Interface
{
public:
    Url_Interface() {};
    virtual ~Url_Interface() {};

    virtual void sendRequest( std::string search );
    virtual std::list<BookDataset> getData() const;

private:
    std::list<BookDataset> data_;

};

class Dnb_Interface : public Url_Interface
{
};
