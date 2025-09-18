#include <iostream>
#include "typedefs.h"
#include "model/ClientType.h"
#include "model/Client.h"
#include "model/Address.h"
#include "model/Drug.h"
#include "model/Supplement.h"
#include "model/Order.h"
#include "managers/ClientManager.h"
#include "managers/OrderManager.h"
#include "repositories/OrderRepository.h"
#include <boost/date_time/posix_time/posix_time.hpp>

namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

using namespace std;

int main() {

    string name;
    string nazwisko;
    unsigned int pesel;
    unsigned int numerTelefonu;
    char emerytura;
    ClientTypePtr emeryt = std::make_shared<RetiredClient>();
    ClientTypePtr normalny = std::make_shared<DefaultClient>();
    ClientManager klientManager;
    OrderManager orderManager;
    string miasto;
    string ulica;
    unsigned int nrdomu;
    AddressPtr address;
    ClientTypePtr zmienna;
    ClientPtr klient;
    ProductPtr produkt;
    ProductPtr lek = make_shared<Drug>(20.5, "Lek", 1, true);;
    ProductPtr suplement = make_shared<Supplement>(10.7, "Suplement", 2, 5);;;;;


    cout << "Witam w naszej APTECE" << endl << "Prosimy o zarejestrowanie sie w naszej APTECE" << endl;
    do {
        cout << "Podaj kolejno swoje imie:" << endl;
        cin >> name;
        cout << "nazwisko:" << endl;
        cin >> nazwisko;
        cout << "pesel:" << endl;
        cin >> pesel;
        cout << "numerTelefonu:" << endl;
        cin >> numerTelefonu;
        cout << "Prosze podac swoj adres zamieszkania    miasto:" << endl;
        cin >> miasto;
        cout << "ulica:" << endl;
        cin >> ulica;
        cout << "numer domu:" << endl;
        cin >> nrdomu;
        address = std::make_shared<Address>(miasto, ulica, nrdomu);
        cout << "Czy jest Pan/Pani na emeryturze? Jesli TAK to prosze wpisac - T/t, jesli nie to prosze wpisac - N/n:"
             << endl;
        cin >> emerytura;
        cout << " ";
        switch (emerytura) {
            case 'T':
            case 't':
                zmienna = emeryt;
                break;
            case 'N':
            case 'n':
                zmienna = normalny;
                break;
            default:
                cout << "Podano bledna opcje." << endl;
        }
    } while(zmienna != emeryt && zmienna != normalny);

    klient = klientManager.registerClient(name, nazwisko, pesel, numerTelefonu, zmienna, address);
    cout << "Utworzono klienta." << endl;
    cout << "Informacje o kliencie: " << klient->getInfo() << endl;

    char wybor;
    do {
        cout << "Chcesz zamowic lek czy suplement? Jesli LEK to prosze wpisac - L/l, jesli SUPLEMENT to prosze wpisac - S/s:" << endl;
        cin >> wybor;
        switch (wybor) {
            case 'L':
            case 'l':
                produkt = lek;
                cout << "Utworzono produkt." << endl;
                cout << "Informacje o produkcie: " << lek->getInfo() << endl;
                break;
            case 'S':
            case 's':
                produkt = suplement;
                break;
            default:
                cout << "Podano bledna opcje." << endl;
                cout << "Utworzono produkt." <<

                endl;
                cout << "Informacje o produkcie: " << lek->getInfo() << endl;
        }
    } while(produkt != lek && produkt != suplement);

    OrderPtr order = orderManager.registerOrder(1234, pt::not_a_date_time, produkt, klient);
    cout << "Utworzono zamowienie." << endl;
    cout << "Informacje o zamowieniu: " << order->getInfo() << endl;

return 0;
}
