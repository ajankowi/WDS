#include <iostream>
#include <cstring>
#include <string>
#include <cassert>
#include <iomanip>
#include <bitset>
using namespace std;


//------------------------------------------------------------------
//  Przykład implementacji obliczania sumy kontrolnej CRC8
//  oraz tworzenia ramki danych.
//




typedef unsigned char byte;
typedef unsigned short int  word;



#define CRC_INIT       0xffff 
#define CRC_POLYNOMIAL 0x1021
  
unsigned short int ComputeCRC16_CCITT_FALSE(const char* pData, int Length)
{
    short int i;
    unsigned short int wCrc = CRC_INIT;
    
    while (Length--) {
        wCrc ^= *(unsigned const char *)pData++ << 8;
        for (i=0; i < 8; i++)
            wCrc = wCrc & 0x8000 ? (wCrc << 1) ^ CRC_POLYNOMIAL : wCrc << 1;
    }
    return wCrc;
}




word ParseDataFrame( const char *pDataFrame, int &AccX, int &AccY )
{
  std::istringstream IStrm(pDataFrame);
  char  FHeader;
  unsigned int CRC16;

  IStrm >> FHeader >> AccX >> AccY >> hex >> CRC16;
  if (IStrm.fail() || FHeader != 'X' ) return false;
  return static_cast<word>(CRC16) == ComputeCRC16_CCITT_FALSE(pDataFrame,strlen(pDataFrame)-4);
}




inline
bool ParseDataFrame( const std::string &rDataFrame, int &AccX, int &AccY )
{
  return ParseDataFrame(rDataFrame.c_str(),AccX,AccY);
}



std::string CreateDataFrame( int AccX, int AccY )
{
  std::ostringstream  OStrm;

  OStrm << "X " << AccX << " " << AccY << " ";
  word CRC16 = ComputeCRC16_CCITT_FALSE(OStrm.str().c_str(),OStrm.str().length());
  OStrm << hex << uppercase << setw(4) << static_cast<int>(CRC16);
  return OStrm.str();
}



int main()
{
  int   Num1, Num2;

  //------------------------------------------------------------------------
  //   Przykład tworzenia ramki danych
  //
  std::string  DataFrame = CreateDataFrame(147,45281);
  cout << endl << "   Utworzona ramka danych: " << DataFrame << endl << endl;


  
  //------------------------------------------------------------------------
  //   Przykład parsowania ramki danych
  //
  cout << "--- Parsowanie ramki danych --------------" << endl;
  if (ParseDataFrame(DataFrame,Num1,Num2)) {
    cout << endl
	 << ":)  Ramka jest poprawna. Wczytane dane:" << endl
	 << "       Num1: " << Num1 << endl
	 << "       Num2: " << Num2 << endl
	 << endl;
  } else {
    cout << endl << ":(  Ramka jest niepoprawna." << endl << endl;
  }
}
