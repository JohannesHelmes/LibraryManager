class Isbn
{
public:
    Isbn();
    ~virtual isbn();

    void pushDigit( uint8_t digit );
    void reset( std::string number );
    int64_t getNumber() const;

    bool check() const;
    uint8_t calcChecksum() const;
private:
    std::vector<uint8_t> number_;
    char typ_; // 'U' - unknown, 'X' - Isbn10, 'E' - EAN ( Isbn13 ), 'W' - wrong
};

