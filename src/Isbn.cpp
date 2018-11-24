#include "Isbn.h"

Isbn::Isbn()
{
    number_.clear();
    typ_ = 'U';
}

void Isbn::pushDigit( char digit )
{
    num_.push_back( uint8_t(digit - '0') );
    updateTyp();
}

void Isbn::update( std::string numStr )
{
    const char* numChar = numStr.c_str(); 
    int32_t newSize = numStr.size();
    for ( int i = 0; i <= newSize; ++i )
        num_[i] = (uint8_t)(numChar[i] - '0' );
    updateTyp();
}


std::string Isbn::getNumber() const
{
    if ( typ_ == 'W' )
        return "";
    std::string numStr = "";
    for ( auto itrDig = number_.rbegin(), itrDig != number_.rend(); ++itrDig )
        numStr.push_back( *itrDig == 10 ? 'X' : char(uint8_t('0') + *itrDig ));
    return numStr;
}

void Isbn::updateTyp()
{
    typ_ = 'U';
    if ( newSize >= 3 )
    {
        if ( num_[0] == 9 && num_[1] == 7 && ( num_[2] == 8 || num_[2] == 9 ) )
            typ_ = ( newSize <= 13 ) ? 'E' : 'W' ;
        else
            typ_ = ( newSize <= 10 ) ? 'X' : 'W' ;
    }
}

bool Isbn::checkValid() const
{
    else if ( typ_ == 'X' && num_.size() == 10 )
        return calcChecksum() == num_[9];
    else if ( typ_ == 'E' && num_.size() == 13 )
        return calcChecksum() == num_[12];
    return false;
}

int8_t Isbn::calcChecksum() const
{
    if ( typ_ == 'X' && num_.size() >= 9 )
    {
        int8_t sum = 0;
        for ( int i = 0; i <= 8; ++i )
            sum += num_[i] * ( i + 1 ) % 11;
        return sum;
    }
    if ( typ_ == 'E' && num_.size() >= 12 )
    {
        int8_t sum = 0;
        for ( int i = 0; i <= 11; i+=2 )
            sum += ( num_[i] + 3 * num_[i+1] ) % 10;
        sum = ( 10 - sum ) % 10 ;
        return sum;
    }
    return -1; // error code
}

std::list< std::string > autoComplete() const
{
}
