#include "Isbn.h"

Isbn::Isbn()
{
    number_.clear();
    typ_ = 'U';
}

void Isbn::pushDigit( uint8_t digit )
{
    number_.push_back( digit );
    if ( number_.size() == 1 && number_[0] != '9' )
        typ_ = 'X';
    else if ( number_.size() == 2 && number_[1] != '7' )
        typ_ = 'X';
    else if ( number_.size() == 3 )
    { 
        if ( number_[2] == '8' || number_[2] == '9' ) && typ_ == 'U' )
            typ_ = 'E';
        else 
            typ_ = 'X';
    }
    else if ( typ_ == 'X' )
    {
        if ( number_.size() > 10 )
            typ_ = 'W';
        if ( number_.size() == 10 && !check() )
            typ_ = 'W';
    }
    else if ( typ_ == 'E' && number_.size() == 13 && !check() )
        typ_ = 'W';
    else if ( number_.size() > 13 )
        typ_ = 'W';
}

void Isbn::reset( std::string number )
{
}

int64_t Isbn::getNumber() const
{
    if ( typ_ == 'W' )
        return 0;
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
    chkIdx == typ_
}

uint8_t Isbn::calcChecksum() const
{
}
