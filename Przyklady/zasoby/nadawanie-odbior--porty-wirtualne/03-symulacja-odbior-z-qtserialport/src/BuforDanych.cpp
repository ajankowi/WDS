#include "BuforDanych.hh"

using namespace std;


#define  MAX_ROZM_LISTY   10


void BuforDanych::DodajNapis(const std::string &rNapis)
{
  std::lock_guard<std::mutex>  Stroz(_Dostep);

  _ListaNapisow.push_back(rNapis);
  while (_ListaNapisow.size() > MAX_ROZM_LISTY) {
    _ListaNapisow.pop_front();
  }
}



bool BuforDanych::PobierzNapis(std::string &rNapis)
{
  std::lock_guard<std::mutex>  Stroz(_Dostep);

  if (_ListaNapisow.empty()) return false;
  rNapis = _ListaNapisow.front();
  _ListaNapisow.pop_front();
  return true;
}



bool BuforDanych::JestNapis() const
{
  std::lock_guard<std::mutex>  Stroz(_Dostep);
  return !_ListaNapisow.empty();
}
