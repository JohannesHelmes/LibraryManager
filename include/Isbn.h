class Isbn
{
public:
    Isbn();
    ~virtual isbn();

    bool check() const;
    uint8_t calcChecksum() const;
    void pushDigit( uint8_t digit );
    int64_t getNumber() const;

protected:
    std::vector<uint8_t> number_;

};

class Isbn10 : public Isbn
{
};

class Isbn13 : public Isbn
{
};
