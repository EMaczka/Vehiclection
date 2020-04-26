#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h> //for Sleep();

#define CLS system("cls"); //dla niektórych kompilatorów: System("cls"). Zwykle tylko windows.

using namespace std;

unsigned short last_edited_type;

void show_menu(bool last_edited=false);

class Pojazd
{
private:
	string brand;
	unsigned prod_year;
	string color;
	unsigned short type;

public:
	void show_data();
	void save_data();
	void nowy(unsigned short typ);
}samolot, samochod, statek;



int main()
{
	show_menu();

	return 0;
}



void show_menu(bool last_edited)
{
	CLS;
	int opcja, opcja2;
	if(last_edited==true)
	{
		cout<<"Ostatnio edytowany pojazd: \n"<<endl;
		switch(last_edited_type)
		{
			case 1: cout<<"\t\tSamolot \n"; samolot.show_data(); break;	
			case 2: cout<<"\t\tSamochod \n"; samochod.show_data(); break;	
			case 3: cout<<"\t\tStatek \n"; statek.show_data(); break;	
		}
		cout<<endl;
	}

	cout<<"Menu: "
		<<"\t1. nowe dane dla pojazdu\n";
		if(last_edited==true)
			cout<<"\t2. zapisz pojazd\n";
		cout<<"\t3. wyjdz z programu\n"
		<<endl;
	cout<<"opcja: ";

		cin>>opcja;
	cout<<endl;

	switch(opcja)
	{
		case 1:
				wybor_typu:
				cout<<"Wybierz pojazd: 1. samolot, 2. samochod, 3. statek"
					<<"\nopcja: ";
				cin>>opcja;
				cout<<endl;
				switch(opcja)
				{
					case 1: samolot.nowy(1); break;
					case 2: samochod.nowy(2); break;
					case 3: statek.nowy(3); break;
					default: cout<<"\nnie ma takiej opcji, wybierz ponownie\n"<<endl; goto wybor_typu;
				}
				break;

		case 2:
				if(last_edited!=true)
					break;
				switch(last_edited_type)
				{
					case 1: samolot.save_data(); break;
					case 2: samochod.save_data(); break;
					case 3: statek.save_data(); break;
					default: cout<<"\nnie ma takiej opcji, wybierz ponownie\n"<<endl; goto wybor_typu;
				}
				break;

		case 3: cout<<"Dziekujemy za uzycie programu. Zostanie on wylaczony w ciagu 5 sekund"; Sleep(5000); exit(0); break;
		default: cout<<"nie ma takiej opcji! powrot do menu za 3 sekundy."; Sleep(3000); show_menu();
	}

}


void Pojazd::show_data()
{
	cout<< "Marka: " << this->brand 
		<< "\nRok produkcji: " << this->prod_year
		<< "\nKolor: " << this->color
		<<endl;
}
void Pojazd::save_data()
{
	string name;
	if (this->type==1)
		name="Samolot";
	else if(this->type==2)
		name="Samochod";
	else
		name="Statek";

	fstream file(name+".txt", ios_base::app);
	if(file.bad())
	{
		cout<<"blad otwarcia/utworzenia pliku"<<endl;
		Sleep(3000);
		show_menu(true);
	}
	else
	{
		file<<"Typ: " << name
			<< "\nMarka: " << this->brand 
			<< "\nRok produkcji: " << this->prod_year
			<< "\nKolor: " << this->color
			<<"\n\n";
		file.close();
		cout<<"Pojazd zapisany! :) \n"
			<<"Nacisnij enter aby przejsc do menu";
		cin.get();
		cin.get();
		show_menu(true);
	}
}

void Pojazd::nowy(unsigned short typ)
{
	last_edited_type=typ;
	this->type=typ;
	poczatek_uzupelniania:
	cout<<"wprowadz marke: ";
	cin>>this->brand;
	cout<<endl;
	
	cout<<"wprowadz rok produkcji: ";
	cin>>this->prod_year;
	cout<<endl;
	
	cout<<"wprowadz kolor: ";
	cin>>this->color;
	cout<<endl;

	CLS;
	this->show_data();
	string opcja3;
	cout<<"\nczy dane wprowadzone sa prawidlowe?"
		<<"[t/n]: ";
	cin>>opcja3;

	if(opcja3 == "n")
	{
		CLS;
		goto poczatek_uzupelniania;
	}
	
	show_menu(true);
}

