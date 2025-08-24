#include <iostream>
#include <list>
#include <string>
#include "Ogrenci.h"

// Constructor
Ogrenci::Ogrenci(int _ID = 777, string _adSoyad = "X", int _sinavNot = 77) : ID(_ID) , adSoyad(_adSoyad) , sinavNot(_sinavNot){}
// setID
void Ogrenci::setID(int _ID) { ID = _ID; }
// setAdSoyad
void Ogrenci::setAdSoyad(string _adSoyad) { adSoyad = _adSoyad; }
// setSinavNot
void Ogrenci::setSinavNot(int _sinavNot) { sinavNot = _sinavNot; }
// getID
int Ogrenci::getID() { return ID; }
// getAdSoyad
string Ogrenci::getAdSoyad() { return adSoyad; }
// getSinavNot
int Ogrenci::getSinavNot() { return sinavNot; }
// bilgileriYaz
void Ogrenci::bilgileriYaz() {
	cout << "Ogrenci ID : " << Ogrenci::ID << " | Ogrenci Ad Soyad : " << Ogrenci::adSoyad << " | Ogrenci Sinav Not : " << Ogrenci::sinavNot << endl;
}