#include <fstream>
#include <string>
#include <bitset>


std::string bin_str16(unsigned short n) 
{
    std::bitset<16> bs(n);
    return bs.to_string();
}

unsigned short bigToLittle(unsigned short value) 
{
    unsigned short tempValue;
    tempValue = value >> 8;
    value = value << 8;
    return tempValue ^ value;
}

unsigned char createChar(unsigned short value) 
{
    return value >> 4;
}

void OutStream(unsigned short num, unsigned char c)
{
    std::ofstream outfile;
    outfile.open("LittleEndian.txt", std::ios::app);
    outfile << bin_str16(bigToLittle(num)) << " ";
    outfile.close();

    outfile.open("UnsignedChar.txt", std::ios::app);
    outfile << static_cast<unsigned>(c) << " ";
    outfile.close();
}

void InStream()
{
    std::ifstream infile;
    unsigned short num;
    infile.open("UnsignedShort.txt");

    while (infile >> num)
    {
        OutStream(num, createChar(bigToLittle(num)));
    }
    infile.close();
}

void GenerateInputFile() 
{
    std::ofstream outfile;
    outfile.open("UnsignedShort.txt");
    unsigned short num;
    for (short i = 0; i <= 99; i++)
    {
        num = rand();
        outfile << num << " ";
    }
    outfile.close();
}

int main()
{
    GenerateInputFile();
    InStream();
}