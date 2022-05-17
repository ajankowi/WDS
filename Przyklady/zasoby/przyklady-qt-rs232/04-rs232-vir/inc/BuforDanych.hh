#ifndef BUFORDANYCH_HH
#define BUFORDANYCH_HH

#include <string>
#include <list>
#include <thread>
#include <mutex>



class BuforDanych {
   std::list<std::string>     _ListaNapisow;
   mutable std::mutex         _Dostep;
  
  public:

   void DodajNapis(const std::string &rNapis);
   bool PobierzNapis(std::string &rNapis);
   bool JestNapis() const;
};

#endif
