#pragma once

#include<cinttypes>
#include<string>
#include<list>
#include<set>
#include<vector>

class Isbn
{
public:
    Isbn();
    virtual ~Isbn() {};

    void pushDigit( char digit );
    void update( std::string numStr );
    std::string getNumber() const;
    char getTyp() const { return typ_; };

    bool checkValid() const;
    std::list< std::string > autoComplete( int32_t size );
private:
    void updateTyp();
    int8_t calcChecksum( std::vector<int8_t> const& number ) const;
    std::string num2strg( std::vector<int8_t> const& number ) const;


    std::vector<int8_t> num_, autoComp_;
    char typ_; // 'U' - unknown, 'X' - Isbn10, 'E' - EAN ( Isbn13 ), 'W' - wrong
    int32_t autoCompCount_;
    static const int32_t _maxAutoComp = 100;
    const std::set<char> _allowedDigits {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'X' };
};

