#pragma once

///Class for exeptions
class Exeption
{
public:
    Exeption(const char *str);
    const char* getExeption() const;

private:
    const char* const message;
};

