// Ogrenci_Bilgi_Sistemi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include "Ogrenci.h"

using namespace std;

void menuGoster() {
    cout << "- - - - Ogrenci Bilgi Sistemi - - - -" << endl;
    cout << "* * * * * * * * * * * * * * * * * * *" << endl;
    cout << "*                                   *" << endl;
    cout << "*                MENU               *" << endl;
    cout << "*                                   *" << endl;
    cout << "* * * * * * * * * * * * * * * * * * *" << endl;
    cout << "- - - - 1.Yeni Kayit Ekle - - - - - -" << endl;
    cout << "- - - - 2.Tum Listeyi Goster- - - - -" << endl;
    cout << "- - - - 3.Ogrenci Kayit Sil - - - - -" << endl;
    cout << "- - - - 4.Ogrenci Ara - - - - - - - -" << endl;
    cout << "- - - - 5.Cikis Yap - - - - - - - - -" << endl;
}
bool KontrolString(const string& str) {
    for (char ch : str) {  // butun karakterlerin kontrolu icin dongu tanimlamasi
        if (!isdigit(ch))  // integer olmama durumu 
            return false;  // false
    }
    return !str.empty();  // string bos degilse true
}
void OgrenciEkle(list<Ogrenci>& lOgrenci) {
    int OgrenciID, sinavNot;
    string adSoyad;
    try {
        cout << "Ogrenci ID : ";
        cin >> OgrenciID;
        if (cin.fail()) {
            cin.clear();  // hata bayragini sifirla
            cin.ignore(1000, '\n');  // tampondaki geçersiz girdiyi temizle
            throw 100;  // OgrenciID string olamaz hata firlat
        }
        cin.ignore();
        cout << "Ogrenci Adi Soyadi: ";
        getline(cin, adSoyad);
        if (KontrolString(adSoyad)) {
            throw 101; // Ogrenci adi sayi olamaz
        }
        cout << "Sinav Not : ";
        cin >> sinavNot;
        if (cin.fail()) {
            cin.clear();  // hata bayragini sifirla
            cin.ignore(1000, '\n');  // tampondaki geçersiz girdiyi temizle
            throw 102;  // sinavNot string olamaz hata firlat
        }
        cout << "Yeni Ogrenci Kaydi Ekleniyor ..." << endl;
        lOgrenci.push_back(Ogrenci(OgrenciID, adSoyad, sinavNot));
    }
    catch (int hataKodu) {
        cout << "Bir exception olustu , hata kodu : " << hataKodu << endl;
        if (hataKodu == 100)
            cout << "Ogrenci ID string deger olamaz !" << endl;
        else if (hataKodu == 101)
            cout << "Ogrenci Adi Soyadi integer deger olamaz !" << endl;
        else if (hataKodu == 102)
            cout << "Sinav Not integer deger olamaz !" << endl;
    }
}
void TumListeGoruntule(list<Ogrenci>& lOgrenci) {
    list<Ogrenci>::iterator itr;  // iterator olustur
    cout << "- - - - Tum Ogrenci Listesi - - - - -" << endl;
    for (itr = lOgrenci.begin(); itr != lOgrenci.end(); itr++) {
        itr->bilgileriYaz();
    }
}
void OgrenciSil(list<Ogrenci>& lOgrenci) {
    list<Ogrenci>::iterator itr;  // iterator olustur
    int OgrenciID;
    cout << "Silinecek Ogrenci ID : ";
    cin >> OgrenciID;
    for (itr = lOgrenci.begin(); itr != lOgrenci.end(); itr++) {
        if (itr->getID() == OgrenciID)
            break;
    }
    if (itr == lOgrenci.end())
        cout << "Silinecek Ogrenci Bulunamadi !" << endl;
    else {
        lOgrenci.erase(itr);
        cout << "Ogrenci Silindi !" << endl;
    }
}
void OgrenciAra(list<Ogrenci>& lOgrenci) {
    list<Ogrenci>::iterator itr;  // iterator olustur
    int OgrenciID;
    cout << "Aranacak Ogrenci ID : ";
    cin >> OgrenciID;
    for (itr = lOgrenci.begin(); itr != lOgrenci.end(); itr++) {
        if (itr->getID() == OgrenciID)
            break;
    }
    if(itr == lOgrenci.end())
        cout << "Aranan Ogrenci Bulunamadi !" << endl;
    else {
        cout << "- - Aranan Ogrenci Bilgileri -" << endl;
        itr->bilgileriYaz();
    }
}
int main()
{
    menuGoster();
    list<Ogrenci> lOgrenci;
    int input;
    do {
        cout << "Seciminizi Yapiniz : ";
        cin >> input;
        switch (input) {
        case 1:
            OgrenciEkle(lOgrenci);
            break;
        case 2:
            TumListeGoruntule(lOgrenci);
            break;
        case 3:
            OgrenciSil(lOgrenci);
            break;
        case 4:
            OgrenciAra(lOgrenci);
            break;
        case 5:
            cout << "Cikis Yapiliyor ..." << endl;
            break;
        default:
            cout << "! Yanlis Deger Girdiniz !" << endl;
        }
    } while (input != 5);
    return 0;
}

