#include <ctime>

#include "Isbn.h"

struct BookDataset
{
    BookDataset();
    std::string title_, author_, publisher_;
    int32_t year_, pages_;
    time_t entrydate_;
    Isbn isbn_;
};
