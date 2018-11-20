#include "Isbn.h"

Isbn::Isbn()
{
    number_.clear();
    typ_ = 'U';
}

void Isbn::pushDigit( uint8_t digit )
{
    number_.push_back( digit );
}

void Isbn::reset( std::string number )
{
}

int64_t Isbn::getNumber() const
{
    int64_t number_int = 0;
    int64_t power_ten = 1;
    for ( auto itrDigit = number_.rbegin(), itrDigit != number_.rend(); ++itrDigit )
    {
        number_int += power_ten * *itrDigit;
        power_ten *= 10;
    }
    return number_int;
}

bool Isbn::check() const
{
}

uint8_t Isbn::calcChecksum() const
{
}
