#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>


using namespace std;

struct Stock
{
    int stockno;
    double price;
};

void readquote1 (Stock stock[]);
void readquote2 (Stock stock[]);
void readquote3 (Stock stock[]);
void readquote4 (Stock stock[]);
bool check (Stock stockone[], Stock stocktwo[], Stock stockthree[], Stock stockfour[], int stockcheckno);

int main()
{
    Stock stock1[9999];
    Stock stock2[9999];
    Stock stock3[9999];
    Stock stock4[9999];

    int stockno = 0;
    double price = 0;
    double position = 0;

    readquote1 (stock1);
    readquote2 (stock2);
    readquote3 (stock3);
    readquote4 (stock4);

    cout << "Welcome to Elite Bank IT System!" << endl << endl;
    cout << "Please Enter the Inquiry Data" << endl << endl;
    cout << "Instrument symbol" << endl;
    cin >> stockno;
    cout << "Price" << endl;
    cin >> price;
    cout << "Position" << endl;
    cin >> position;

    if (check (stock1, stock2, stock3, stock4, (stockno - 1)))
    {
        if (price == stock1[stockno - 1].price)
        {
            cout << "Consistent Data!" << endl;
            cout << "P & L = " << price * position << endl;
        }

        else
        {
            cout << "Wrong Input!" << endl;
            cout << "Discrepancy with External Databases!" << endl;
            cout << "Please enter the price again." << endl;
            cin >> price;
            if (price == stock1[stockno - 1].price)
            {
                cout << "Consistent Data!" << endl;
                cout << "P & L = " << price * position << endl;
            }
            else
            {
                cout << "Auto-correction, Change It to " << stock1[stockno - 1].price << "?";
            }
        }
    }

    else
    {
        cout << "There is a Problem with the Sata from the External Databases. Contact IT Department?" << endl;
    }
}

void readquote1 (Stock stock[])
{
    int no = 0;
    char dummy;
    ifstream fin ("list 1.txt");

	if(fin.fail())
    {
        exit(1);
    }

    while (fin.good())
    {
        fin >> stock[no].stockno >> dummy >> stock[no].price;
        no++;
    }
    fin.close();
}

void readquote2 (Stock stock[])
{
    int no = 0;
    char dummy;
    ifstream fin ("list 2.txt");

	if(fin.fail())
    {
        exit(1);
    }

    while (fin.good())
    {
        fin >> stock[no].stockno >> dummy >> stock[no].price;
        no++;
    }
    fin.close();
}

void readquote3 (Stock stock[])
{
    int no = 0;
    char dummy;
    ifstream fin ("list 3.txt");

	if(fin.fail())
    {
        exit(1);
    }

    while (fin.good())
    {
        fin >> stock[no].stockno >> dummy >> stock[no].price;
        no++;
    }
    fin.close();
}

void readquote4 (Stock stock[])
{
    int no = 0;
    char dummy;
    ifstream fin ("list 4.txt");

	if(fin.fail())
    {
        exit(1);
    }

    while (fin.good())
    {
        fin >> stock[no].stockno >> dummy >> stock[no].price;
        no++;
    }
    fin.close();
}

bool check (Stock stockone[], Stock stocktwo[], Stock stockthree[], Stock stockfour[], int stockcheckno)
{
    if (stockone[stockcheckno].price == stocktwo[stockcheckno].price && stocktwo[stockcheckno].price == stockthree[stockcheckno].price
        && stockthree[stockcheckno].price == stockfour[stockcheckno].price)
    {
        return true;
    }
    return false;
}
