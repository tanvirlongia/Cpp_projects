#include <iostream>
using namespace std;

//declaring the constant size
const int SIZE = 10;

//declaring all the functions
void doPush(int &top, double stack[]);
void doPop(int &top, double stack[]);
void getTop(int &top, double stack[]);
void doPurge(int &top, double stack[]);
void display(int &top, double stack[]);

//starting the main
int main()
{
    //declaring the array to store the stack
    double stack[SIZE];

    int top = -1;
    int menu;
    do
    {
        cout << "Enter 1 for Push\n"
                "Enter 2 for Pop\n" 
                "Enter 3 for Top\n"  
                "Enter 4 for Purge\n"  
                "Enter 5 to Display Stack\n"
                "Enter 0 TO EXIT\n";     
        cin >> menu;
        switch (menu)
        {
        case 1:
            doPush(top, stack);
            display(top, stack);
            break;
        case 2:
            doPop(top, stack);
            display(top, stack);
            break;
        case 3:
            getTop(top, stack);
            display(top, stack);
            break;
        case 4:
            doPurge(top, stack);
            display(top, stack);
            break;
        case 5:
            display(top, stack);
            break;
        case 0:
            break;
        default:
            cout << "Invalid\n"; 
        }
    } while (menu!=0);
}


void doPush(int &top, double stack[])
{
    //checking for overflow
    if (top >= SIZE)
        cout << "Stack full.\n";
    else 
    {
        //incrementing the top
        top += 1;
        //checking for the entry limits
        do 
        {
            cout << "Enter number between 0 and 99 to push on stack: ";
            cin >> stack[top];
        }while (stack[top] < 0 || stack[top] > 99);
    }
}


void doPop(int &top, double stack[])
{
    //checking for the underflow
    if (top <= (SIZE-(SIZE+1)))
        cout << endl;
    else 
    {
        cout << "Poped element is: " << stack [top] << endl;
        //decrementing the top
        top -= 1;
    }
}


void getTop (int &top, double stack[]) 
{
    cout << "Top is: " << top << endl;
    //checking for underflow
    if (top <= -1)
        cout << endl;
    else 
        cout << "Top element is: " << stack[top] << endl;
}


void doPurge (int &top, double stack[]) 
{
    //setting the top to its original value
    top = -1;
    cout << "Top is: " << top << endl;
}


void display (int &top, double stack[]) 
{
    if (top <= (SIZE-(SIZE+1)))
        cout << "Stack empty.\n";
    else 
    {
    cout << "Stack is: " << endl;
    for (int j = top; j >= 0; j--)
        cout  << stack[j] << " " << endl;
    }
}