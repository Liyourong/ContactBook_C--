#include <iostream>
#include <string>
#include "leeselection.h"
#define maxx 1000

using namespace std;

struct contact
{
    string name;
    int age;
};

struct contactbook
{
    contact book[maxx];
    int msize;
};

bool checkisfull(contactbook *thisbook)
{
    return thisbook->msize == maxx;
}

bool checkisempty(contactbook *thisbook)
{
    return thisbook->msize == 0;
}

void add(contactbook *thisbook)
{
    // printl(thisbook->msize);
    if (checkisfull(thisbook))
    {
        printl("unable to add, the conatct book is already full");
    }
    else
    {
        // string newname = ins ("Please enter the name");
        thisbook->book[thisbook->msize].name = ins("Please enter the name");
        thisbook->book[thisbook->msize].age = in("Please enter the age");
        thisbook->msize++;
        printl("This contact person is successfullly added");
        // print(thisbook->msize);
        //  in("Please enter the age");
    }
}
int find(contactbook *thisbook)
{
    if (checkisempty(thisbook))
    {
        printl("error, the conatct book is empty");
        return -1;
    }
    else
    {
        string targetname = ins("Please enter the name u wanna search");
        for (int i = 0; i < thisbook->msize; i++)
        {
            if (thisbook->book[i].name == targetname)
            {
                printl("find the target");
                printt(thisbook->book[i].name);
                printt("        ");
                printlt(thisbook->book[i].age);
                return i;
            }
        }
        print("the name is not find");
        return -1;
    }
}

void show(contactbook *thisbook)
{
    if (checkisempty(thisbook))
    {
        printl("error, the conatct book is empty");
    }
    else
    {
        printl("persons in the contactbook are: ");
        for (int i = 0; i < thisbook->msize; i++)
        {
            printt(thisbook->book[i].name);
            printt("        ");
            printlt(thisbook->book[i].age);
        }
        print("thatsit");
    }
}

void del(contactbook *thisbook)
{
    if (checkisempty(thisbook))
    {
        printl("error, the conatct book is empty");
    }
    else
    {
        int indicator = find(thisbook);
        if (indicator != -1)
        {
            for (int i = indicator; i < thisbook->msize - 1; i++)
            {
                thisbook->book[i].age = thisbook->book[i + 1].age;
                thisbook->book[i].name = thisbook->book[i + 1].name;
            }
            thisbook->msize--;
        }
    }
}

void edit(contactbook *thisbook)
{
    if (checkisempty(thisbook))
    {
        printl("error, the conatct book is empty");
    }
    else
    {
        int indicator = find(thisbook);
        if (indicator != -1)
        {
            
            thisbook->book[indicator].name = ins("Please the edited name");
            thisbook->book[indicator].age = in("Please the edited age");
            
        }
    }
}
void clear(contactbook *thisbook)
{
    if (checkisempty(thisbook))
    {
        printl("error, the conatct book is empty");
    }
    else
    {
        for (int i = 0; i < thisbook->msize; i++)
        {
            thisbook->book[i].name = "";
            thisbook->book[i].age = 0;
        }
        thisbook->msize=0;
    }
    printl("the contact book is already empty");
}

void showmenu()
{
    printl("Hello, Please direct to the function u want");
    printl("1. Add");
    printl("2. Show");
    printl("3. Delete");
    printl("4. Find");
    printl("5. Edit");
    printl("6. Clear");
    printl("0. End");
}

void selection(int *pflag, contactbook *thisbook)
{
    int selection = in("");

    if (selection == 1)
    {
        // printl("inselecito 1;");
        add(thisbook);
    }
    else if (selection == 2)
    {
        show(thisbook);
    }
    else if (selection == 3)
    {
        del(thisbook);
    }
    else if (selection == 4)
    {
        find(thisbook);
    }
    else if (selection == 5)
    {
        edit(thisbook);
    }
    else if (selection == 6)
    {
        clear(thisbook);
    }
    else
    {
        *pflag = 1;
        print("Thanks for using this function, have a good one!");
    }
}

void changeflag(int *p)
{

    *p = 345678;
}

int main()
{
    int flag = 0;
    int *pflag = &flag;
    contactbook mybook;
    mybook.msize = 0;

    // if (checkisfull(&mybook)){
    //     print("full");

    // }

    while (flag == 0)
    {
        showmenu();
        selection(pflag, &mybook);
        // printl(mybook.book[0].name);
        // printl(mybook.book[0].name);
        // printl(mybook.book[0].name);
        // printl(mybook.book[0].name);
        // printl(mybook.book[0].name);
    }

    system("Pause");
    return 0;
}

// pop选择菜单

//接受用户输入

//创建联系人

//添加联系人

//查找联系人
