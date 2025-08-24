#pragma once
#include <iostream>
#include <list>
#include <string>

using namespace std;

class Ogrenci {
public:
	//Constructor
	Ogrenci(int _ID, string _adSoyad, int _sinavNot);
	void setID(int _ID);
	void setAdSoyad(string _adSoyad);
	void setSinavNot(int _sinavNot);
	int getID();
	string getAdSoyad();
	int getSinavNot();
	void bilgileriYaz();
private:
	int ID;
	string adSoyad;
	int sinavNot;
};