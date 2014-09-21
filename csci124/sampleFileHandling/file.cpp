#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream in;
    ofstream out;
    int value, sum=0;
    char filename[100];
    char label[50];

    cout << "Enter filename: ";
    cin >> filename;

    out.open (filename, ios::out);

    for(int i=1; i<=5; i++)
    {
        cout << "Label: ";
        cin >> label;
        cout << "Enter number " << i << " : ";
        cin >> value;  //read from user

        out << label << "   ";
        out << value << "\n";   //write to file
    }
    out.close();

    in.open(filename, ios::in);

    if (!in)
    {
        cout << "File not found!!" << endl;
        return 0;
    }

    while(in.good())
    {
            in >> label;
            in >> value;

            if (!in.eof())
            {
                cout << label << " - ";
                sum += value;
                cout << value << endl;
            }

    }
    cout << endl << sum << endl;
    in.close();

    return 0;

}
