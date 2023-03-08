#include "MyArray.h"
#include "Point.h"

string Beautify(string str, bool saveBeginTab);

int main()
{
    srand(time(0));

    /*
    Print() - вывод на экран массива, без показа скрытой 
    дополнительной памяти.
    PrintDev() - вывод на экран элементов массива, затем знака `
    и затем колличество дополнительных слотов для элементов.
    */

    MyArray<int> arrInt(5);
    arrInt.Input();
    cout << "Arr1: ";
    arrInt.PrintDev();

    MyArray<int> arrInt2(3);
    arrInt2.Input();
    cout << "Arr2: ";
    arrInt2.PrintDev();

    cout << "\n" << boolalpha 
        << "Arr1 is empty? " << arrInt.IsEmpty()
        << "\nArr2 is empty? " << arrInt2.IsEmpty()<< "\n\n";
    
    arrInt.SetSize(3);
    cout << "Arr1 SetSize(3): ";
    arrInt.PrintDev();
    
    arrInt2.SetSize(4);
    cout << "Arr2 SetSize(4): ";
    arrInt2.PrintDev();

    cout << "\nArr1: GetAt(2): " << arrInt.GetAt(2)
        << "\nArr2: GetAt(2): " << arrInt2.GetAt(2) << "\n";

    cout << "\nArr1: SetAt(12,2): ";
    arrInt.SetAt(12, 2);
    arrInt.PrintDev();

    cout << "Arr2: SetAt(60,2): ";
    arrInt2.SetAt(60, 2);
    arrInt2.PrintDev();
    
    cout << "\nArr1: Add(100): ";
    arrInt.Add(100);
    arrInt.PrintDev();

    cout << "Arr2: Add(200): ";
    arrInt2.Add(200);
    arrInt2.PrintDev();

    arrInt.SetSize(3, 4);
    cout << "Arr1 SetSize(3,4) -> grow = 4: ";
    arrInt.PrintDev();

    arrInt2.SetSize(4, 2);
    cout << "Arr2 SetSize(4,2) -> grow = 2: ";
    arrInt2.PrintDev();

    cout << "\nArr1: Add(15): ";
    arrInt.Add(15);
    arrInt.PrintDev();

    cout << "Arr2: Add(80): ";
    arrInt2.Add(80);
    arrInt2.PrintDev();

    cout << "\nArr1: Sum(): " << arrInt.Sum();

    cout << "\nArr2: Sum(): " << arrInt2.Sum();

    cout << "\n\nArr1: Append(Arr2):";
    arrInt.Append(arrInt2);
    arrInt.PrintDev();

    cout << "\nArr1: InsertAt(150,3):\n";
    arrInt.InsertAt(150, 3);
    arrInt.PrintDev();
    
    const int SIZE = 3;
    int* ar = new int[SIZE];
    for (int i = 0; i < SIZE; i++)
        ar[i] = (i + 1) * 11;

    cout << "\nArr1: InsertAt({11, 22, 33},2):\n";
    arrInt.InsertAt(ar, SIZE, 2);
    arrInt.PrintDev();

    cout << "\nArr1: RemoveAt(2):\n";
    arrInt.RemoveAt(2);
    arrInt.PrintDev();

    cout << "\nArr1: RemoveAt(2,5):\n";
    arrInt.RemoveAt(2, 5);
    arrInt.PrintDev();

    cout << "\nArr1: FreeExtra():\n";
    arrInt.FreeExtra();
    arrInt.PrintDev();

    cout << "\nArr1: RemoveAll():\n";
    arrInt.RemoveAll();
    arrInt.PrintDev();

    delete[] ar;

    cout << "\n---------------------------\n\n";

    MyArray<double> arrDouble(4);
    MyArray<char> arrChar(6);
    MyArray<Point<int>> arrPointInt(3);
    MyArray<Point<double>> arrPointDouble(5);
    MyArray<Point<char>> arrPointChar(4);
    MyArray<Point<Point<int>>> arrPointPointInt(2);

    arrDouble.Input();
    cout << "Arr Double: ";
    arrDouble.Add(2.3);
    arrDouble.PrintDev();

    arrChar.Input();
    cout << "Arr Char: ";
    arrChar.PrintDev();

    arrPointInt.Input();
    cout << "Arr Point<int>: ";
    arrPointInt.PrintDev();

    arrPointDouble.Input();
    cout << "Arr Point<double>: ";
    arrPointDouble.PrintDev();
    
    arrPointChar.Input();
    cout << "Arr Point<char>: ";
    arrPointChar.PrintDev();

    for (int i = 0; i < arrPointPointInt.GetSize(); i++)
    {
        arrPointPointInt[i] = Point<Point<int>>(
            Point<int>(
                rand() % 100,
                rand() % 100,
                rand() % 100),
            Point<int>(
                rand() % 100,
                rand() % 100,
                rand() % 100),
            Point<int>(
                rand() % 100,
                rand() % 100,
                rand() % 100));
    }
    cout << "Arr Point<Point<int>>: ";
    arrPointPointInt.PrintDev();

    cout << "\nArr Double: Sum(): " << arrDouble.Sum();
    cout << "\nArr Char: Sum(): " << arrChar.Sum() << " (" << (int)arrChar.Sum() << ")";
    cout << "\nArr Point<int>: Sum(): " << arrPointInt.Sum();
    cout << "\nArr Point<double>: Sum(): " << arrPointDouble.Sum();
    cout << "\nArr Point<char>: Sum(): " << arrPointChar.Sum();
    cout << "\nArr Point<Point<int>>: Sum(): " << arrPointPointInt.Sum() << "\n";

    cout << "\n---------------------------\n\n";

    cout << "MyArray<int> arr{ 1, 10, 12, 30, -56, 32, 90 };\n";

    MyArray<int> arr{ 1, 10, 12, 30, -56, 32, 90 };
    arr.PrintDev();
    
    cout << "MyArray<Point<int>> arr2{ {1, 6, 8}, {3, 9, 12} };\n";

    MyArray<Point<int>> arr2{ {1, 6, 8}, {3, 9, 12} };
    arr2.PrintDev();

    cout << "\n";

    string helloAlex = "     Hello   Alex!  How  are     you    doing?          ";

    cout << helloAlex << "\n";

    cout << "\n" << Beautify(helloAlex, true) << "\n\n";

    cout << "begin->(" << helloAlex << ")<-end of string\n";

    cout << "\nbegin->(" << Beautify(helloAlex, true) << ")<-end of string\n";
}

string Beautify(string str, bool saveBeginTab = false)
{
    const int SIZE = str.size();

    int beg = 0;
    while (str[beg] == ' ')
        beg++;

    if (beg == SIZE)
        return str;

    int end = SIZE - 1;
    while (str[end] == ' ')
        end--;

    string tmp(SIZE, ' ');

    int k = 0;
    for (int i = beg; i <= end; )
    {
        while (str[i] != ' ')
        {
            tmp[k] = str[i];
            k++;
            i++;
        }
        if (str[i] == ' ')
        {
            tmp[k] = str[i];
            k++;
            i++;
        }
        while (str[i] == ' ')
        {
            i++;
        }
    }

    if (!saveBeginTab)
    {
        string tmp2(k - 1, ' ');

        for (int i = 0; i < k; i++)
            tmp2[i] = tmp[i];
        return tmp2;
    }
    else
    {
        string tmp2(beg + k - 1, ' ');

        for (int i = 0; i < beg; i++)
        {
            tmp2[i] = ' ';
        }
        for (int i = beg, j = 0; i < k + beg - 1; i++, j++)
            tmp2[i] = tmp[j];
        return tmp2;
    }
}
