#include "Isbn.h"

#include<iostream>

Isbn::Isbn()
{
    num_.clear();
    typ_ = 'U';
    autoCompCount_ = 0;
}

void Isbn::pushDigit( char digit )
{
    num_.push_back( int8_t(digit - '0') );
    updateTyp();
    autoCompCount_ = 0;
}

void Isbn::update( std::string numStr )
{
    num_.assign( numStr.size(), -1 );
    const char* numChar = numStr.c_str(); 
    int32_t newSize = numStr.size();
    for ( int i = 0; i < newSize; ++i )
    {
        if ( _allowedDigits.count( numChar[i] ) == 0 )
            continue;
        num_[i] = numChar[i] == 'X' ? 10 : (int8_t)(numChar[i] - '0' );
    }
    updateTyp();
    autoCompCount_ = 0;
}


std::string Isbn::getNumber() const
{
    if ( typ_ == 'W' )
        return "";
    return num2strg( num_ );
}

void Isbn::updateTyp()
{
    typ_ = 'U';
    if ( num_.size() >= 3 )
    {
        if ( num_[0] == 9 && num_[1] == 7 && ( num_[2] == 8 || num_[2] == 9 ) )
            typ_ = ( num_.size()<= 13 ) ? 'E' : 'W' ;
        else
            typ_ = ( num_.size()<= 10 ) ? 'X' : 'W' ;
    }
}

bool Isbn::checkValid() const
{
    if ( typ_ == 'X' && num_.size() == 10 )
        return calcChecksum( num_ ) == num_[9];
    if ( typ_ == 'E' && num_.size() == 13 )
        return calcChecksum( num_ ) == num_[12];
    return false;
}

std::string Isbn::num2strg( std::vector<int8_t> const& number ) const
{
    std::string numStr = "";
    for ( auto itrDig = number.cbegin(); itrDig != number.cend(); ++itrDig )
        numStr.push_back( *itrDig == 10 ? 'X' : char(int8_t('0') + *itrDig ));
    return numStr;
}

int8_t Isbn::calcChecksum( std::vector<int8_t> const& number ) const
{
    if ( typ_ == 'X' && number.size() >= 9 )
    {
        int8_t sum = 0;
        for ( int i = 0; i <= 8; ++i )
        {
            sum += number[i] * ( i + 1 );
            sum %= 11;
        }
        return sum;
    }
    if ( typ_ == 'E' && number.size() >= 12 )
    {
        int8_t sum = 0;
        for ( int i = 0; i <= 11; i+=2 )
        {
            sum += ( number[i] + 3 * number[i+1] );
            sum %= 10;
        }
        sum = ( 10 - sum ) % 10 ;
        return sum;
    }
    return -1; // error code
}

std::list< std::string > Isbn::autoComplete( int32_t size )
{
    std::list< std::string > autoCompList;
    if ( checkValid() )
    {
        autoCompList.push_back( num2strg( num_ ) );
        return autoCompList;
    }
    else if ( typ_ == 'W' || typ_ == 'U' )
        return autoCompList;

    size = std::min( size, _maxAutoComp );
    if ( autoCompCount_ == 0 )
        autoComp_ = num_;
    int32_t cnt = 0;
    int8_t crtDgt = num_.size();
    int8_t const chkSumDgt = ( typ_ == 'X' ? 9 : 12 );
    autoComp_.resize( chkSumDgt + 1, 0 );
    while ( cnt < size && crtDgt < chkSumDgt )
    {
        autoComp_[ chkSumDgt ] = calcChecksum( autoComp_ );
        autoCompList.push_back( num2strg( autoComp_ ) );
        crtDgt = num_.size();
        while ( crtDgt < chkSumDgt && ++autoComp_[ crtDgt ] == 10 )
            autoComp_[ crtDgt++ ] = 0;
        ++cnt;
    }

    autoCompCount_ += autoCompList.size();
    return autoCompList;
}
