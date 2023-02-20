#include "MyArray.h"

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

    cout << "\nArr1: Append(Arr2):";
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
}
