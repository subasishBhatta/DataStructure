//
// Created by CHINTOO on 12-06-2021.
//

#include "iostream"
#define SIZE 100
using namespace std;

struct Arr {
    int capacity{};
    int * arr = new int[SIZE];

};

void insert(struct Arr &myarr){
    int pos, val;
    if (myarr.capacity >= SIZE)
    {
        cout << "The array is full, we can't insert anything to it." << endl;
        return;
    }
    if (myarr.capacity == 0)
        cout << "The array is empty." << endl;
    cout << "Enter the pos where you want to insert: " << endl;
    cin >> pos;
    if (myarr.capacity==0 && pos != 1){
        cout << "The array is empty, so you must enter the value in the first position." << endl;
        return;
    }
    cout << "Enter the value you want to insert: " << endl;
    cin >> val;

    int index = pos-1;
    for (int i = myarr.capacity; i > index ; --i) {
        myarr.arr[i] = myarr.arr[i-1];
    }
    myarr.arr[index] = val;
    myarr.capacity += 1;

}

void del(struct Arr &myarr)
{
    int pos;
    if (myarr.capacity == 0)
    {
        cout << "The array is empty, nothing to delete." << endl;
        return;
    }
    cout << "Enter the pos where you want to delete: " << endl;
    cin >> pos;
    int index = pos-1;
    for (int i = index; i < myarr.capacity-1; ++i) {
        myarr.arr[i] = myarr.arr[i+1];
    }
    myarr.capacity -= 1;


}

void display(struct Arr &myarr)
{
    if (myarr.capacity == 0)
    {
        cout << "The array is empty, so there is nothing to display. " << endl;
        return;
    }
    for (int i = 0; i < myarr.capacity; ++i) {
        cout << myarr.arr[i] << " ";
    }
    cout << endl;
}

void menu()
{
    cout << "******************This is the menu for ARRAY OPERATIONS**************" << endl;
    cout << "1. To insert in the array" << endl;
    cout << "2. To delete from the array" << endl;
    cout << "3. To display the content of the array" << endl;
    cout << "4. Exit the menu" << endl;
}

int main()
{
    int cap{};
//    cout << "Enter the capacity of the array: " << endl;
//    cin >> cap;

//    myarr.capacity = cap;
//    cout << "Enter the value into the array: " << endl;
//    for (int i = 0; i < cap; ++i) {
//        cin >> myarr.arr[i];
//    }
//
//    for (int i = 0; i < cap; ++i) {
//        cout << myarr.arr[i] << " ";
//    }


    Arr myarr;

    while (true)
    {
        menu();
        int ch;
        cout << "Enter your choice: " << endl;
        cin >> ch;
        switch (ch) {
            case 1:
                insert(myarr);
                break;
            case 2:
                del(myarr);
                break;
            case 3:
                display(myarr);
                break;
            case 4:
                exit(0);
            default:
                cout << "Choose a valid choice" << endl;
                break;
        }
    }


//    insert(myarr);
//    display(myarr);
//    insert(myarr);
//    display(myarr);
//    insert(myarr);
//    display(myarr);
//    insert(myarr);
//    display(myarr);
//    insert(myarr);
//    display(myarr);
//    del(myarr);
//    display(myarr);
//    del(myarr);
//    display(myarr);

    return 0;
}

