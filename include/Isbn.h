class Isbn
{
public:
    Isbn();
    ~virtual isbn();

    void pushDigit( char digit );
    void update( std::string number );
    std::string getNumber() const;

    void updateTyp();
    bool checkValid() const;
    int8_t calcChecksum() const;

    std::list< std::string > autoComplete() const;
private:
    std::vector<uint8_t> num_;
    char typ_; // 'U' - unknown, 'X' - Isbn10, 'E' - EAN ( Isbn13 ), 'W' - wrong
    static int32_t _maxAutoComplete = 100;
};

