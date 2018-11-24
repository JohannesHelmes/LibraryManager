#include<string>
#include<list>
#include<set>
#include<vector>

class Isbn
{
public:
    Isbn();
    virtual ~Isbn();

    void pushDigit( char digit );
    void update( std::string numStr );
    std::string getNumber() const;

    bool checkValid() const;
    std::list< std::string > autoComplete() const;
private:
    void updateTyp();
    int8_t calcChecksum() const;


    std::vector<int8_t> num_;
    char typ_; // 'U' - unknown, 'X' - Isbn10, 'E' - EAN ( Isbn13 ), 'W' - wrong
    static const int32_t _maxAutoComplete = 100;
    const std::set<char> _allowedDigits {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'X' };
};

