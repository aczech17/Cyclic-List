#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "cyclist.h"
#ifdef WIN32
#define CLEAR system("cls");
#else
#define CLEAR system("clear");
#endif // system
using std::cin;
using std::cout;
using std::endl;
void notANumber()
{
    cout<<"Podana wartość nie jest liczbą";
    cin.clear();
    cin.ignore(1000,'\n');
    getchar();
    CLEAR;
}
int main()
{
    CycList c;
    int option;
    do
    {
        cout<<"Zawartość listy"<<endl;
        CycList::iterator it;
        for(it=c.begin(); it!=c.end(); ++it)
            cout<<*it<<endl;
        cout<<"Liczba elementów listy: "<<c.quantity()<<endl<<endl;
        cout<<"1. Dodaj liczbę na początek listy"<<endl;
        cout<<"2. Dodaj element na koniec listy"<<endl;
        cout<<"3. Dodaj element po elemencie o określonym indeksie"<<endl;
        cout<<"4. Dodaj element przed elementem o określonym indeksie"<<endl;
        cout<<"5. Zapisz liczbę do elementu o określonym indeksie"<<endl;
        cout<<"6. Usuń element o określonym indeksie"<<endl;
        cout<<"7. Usuń elementy o określonej wartości"<<endl;
        cout<<"8. Usuń elementy o wartościach z podanego przedziału"<<endl;
        cout<<"9. Usuń pierwszy element"<<endl;
        cout<<"10. Usuń ostatni element"<<endl;
        cout<<"11. Usuń powtarzające się wartości"<<endl;
        cout<<"12. Wyjście"<<endl;
        cout<<"Wybierz opcję: ";
        cin>>option;
        switch(option)
        {
        case 1:
        {
            int v;
            cout<<"Podaj liczbę: ";
            cin>>v;
            if(!cin.good()) notANumber();
            else c.pushFirst(v);
            break;
        }//dodawanie na początek
        case 2:
        {
            int v;
            cout<<"Podaj liczbę: ";
            cin>>v;
            if(!cin.good()) notANumber();
            else
                c.pushLast(v);
            break;
        }//dodawanie na koniec
        case 3:
        {
            int id,v;
            cout<<"Jaką liczbę chcesz dodać?: ";
            cin>>v;
            if(!cin.good())
            {
                notANumber();
                continue;
            }
            cout<<"Po którym elemencie chcesz ją dodać?: ";
            cin>>id;
            if(!cin.good())
            {
                notANumber();
                continue;
            }
            c.pushAfter(id,v);
            break;
        }//dodawanie po indeksie
        case 4:
        {
            int id,v;
            cout<<"Jaką liczbę chcesz dodać?: ";
            cin>>v;
            if(!cin.good())
            {
                notANumber();
                continue;
            }
            cout<<"Przed którym elementem chcesz ją dodać?: ";
            cin>>id;
            if(!cin.good())
            {
                notANumber();
                continue;
            }
            c.pushBefore(id,v);
            break;
        }//dodawanie przed indeksem
        case 5:
        {
            int id,v;
            cout<<"Jaką liczbę chcesz dodać?: ";
            cin>>v;
            if(!cin.good())
            {
                notANumber();
                continue;
            }
            cout<<"Do którego elementu chcesz ją dodać?: ";
            cin>>id;
            if(!cin.good())
            {
                notANumber();
                continue;
            }
            c.pushIndex(id,v);
            break;
        }//zapisz w indeksie
        case 6:
        {
            int id;
            cout<<"Który element chcesz usunąć?: ";
            cin>>id;
            if(!cin.good()) notANumber();
            else c.deleteIndex(id);
            break;
        }//usuń indeks
        case 7:
        {
            int v;
            cout<<"Którą wartość chcesz usunąć?: ";
            cin>>v;
            if(!cin.good()) notANumber();
            else c.deleteValue(v);
            break;
        }//usun wartość
        case 8:
        {
            int a,b;
            cout<<"Z jakiego przedziału chcesz usunąć liczby?: ";
            cin>>a;
            if(!cin.good())
            {
                notANumber();
                continue;
            }
            cin>>b;
            if(!cin.good())
            {
                notANumber();
                continue;
            }
            c.deleteBetween(a,b);
            break;
        }//usun liczby z przedzialu
        case 9:
        {
            c.deleteFirst();
            break;
        }
        case 10:
        {
            c.deleteLast();
            break;
        }
        case 11:
        {
            c.deleteRepeats();
            break;
        }
        case 12:
            break;
        default:
        {
            cout<<"Wpisz liczbe od 1 do 10";
            cin.clear();
            cin.ignore(1000,'\n');
            getchar();
            CLEAR;
        }
        }//switch
        CLEAR;
    }
    while(option!=12);
    return 0;
}
