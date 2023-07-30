#include<iostream>
#include<windows.h>
#include<fstream>
#include"password.h"
#include"load.h"
#include"line.h"
#include"billing.h"
using namespace std;
fstream bil;
class product
{
    protected:
    string product[100];
    long int rate[100];
    int quantity[100];
    long int totalrate[100];
    long int total;
public:
    void store(string item,long int paisa,int things,int key)
    {
        product[key]=item;
        rate[key]=paisa;
        quantity[key]=things;
        totalrate[key]=quantity[key]*paisa;
    }
    void total_bill(int item)
    {
        total=0;
        for(int i=0;i<item;i++)
        {
            total=total+totalrate[i];
        }
    }
    void display(int item)
    {
        char hold;
        bar::space();
        cout<<"|S.No ";
        cout<<"|    Items          |";
        cout<<" Quantity |";
        cout<<"Total Rate|";
        cout<<endl;
        print_short();
        for(int i=0;i<item;i++)
        {
            bar::space();
            if((i+1)>9)cout<<"| "<<i+1<<"  |";
            if((i+1)<=9)cout<<"| "<<i+1<<"   |";
            align(product[i]);
            if(quantity[i]<10) cout<<"    "<<quantity[i]<<"     |";
            else cout<<"    "<<quantity[i]<<"    |";
            cout<<"    "<<totalrate[i];
            space_align(totalrate[i]);
        }
        cout<<endl;
        print_short();
        //cout<<endl;
        bar::space();
        cout<<"|   "<<"Total"<<"                            |";
        cout<<"Rs. "<<total;
        space_align(total);
        cout<<endl;
        print_short();
        cout<<"\n"<<"Press any alphabet to save the bill and go home"<<"\n";
        cin>>hold;
    }
    void billing(int item)
    {
        bil.open("bill.txt",ios::out);
        print_shortbill(bil);
        space_bill(bil);
        bil<<"|S.No ";
        bil<<"|    Items          |";
        bil<<" Quantity |";
        bil<<"Total Rate|";
        bil<<"\n";
        print_shortbill(bil);
        for(int i=0;i<item;i++)
        {
            space_bill(bil);
            if((i+1)>9) bil<<"| "<<i+1<<"  |";
            if((i+1)<=9) bil<<"| "<<i+1<<"   |";
            align_billing(product[i],bil);
            if(quantity[i]<10) bil<<"    "<<quantity[i]<<"     |";
            else bil<<"    "<<quantity[i]<<"    |";
            bil<<"    "<<totalrate[i];
            space_align_billing(totalrate[i],bil);
        }
        bil<<"\n";
        print_shortbill(bil);
        //cout<<endl;
        space_bill(bil);
        bil<<"|   "<<"Total"<<"                            |";
        bil<<"Rs. "<<total;
        space_align_billing(total,bil);
        bil<<"\n";
        print_shortbill(bil);
        bil.close();
}
void bill_store(int item)
{
        cout<<endl;
        print_line();
        cout<<endl;
        bil.open("billstore.txt",ios::app);
        print_shortbill(bil);
        space_bill(bil);
        bil<<"|S.No ";
        bil<<"|    Items          |";
        bil<<" Quantity |";
        bil<<"Total Rate|";
        bil<<"\n";
        print_shortbill(bil);
        for(int i=0;i<item;i++)
        {
            space_bill(bil);
            if((i+1)>9) bil<<"| "<<i+1<<"  |";
            if((i+1)<=9) bil<<"| "<<i+1<<"   |";
            align_billing(product[i],bil);
            if(quantity[i]<10) bil<<"    "<<quantity[i]<<"     |";
            else bil<<"    "<<quantity[i]<<"    |";
            bil<<"    "<<totalrate[i];
            space_align_billing(totalrate[i],bil);
        }
        bil<<"\n";
        print_shortbill(bil);
        space_bill(bil);
        bil<<"|   "<<"Total"<<"                            |";
        bil<<"Rs. "<<total;
        space_align_billing(total,bil);
        bil<<"\n";
        print_shortbill(bil);
        bil.close();
}
};
class bill
{
    int items;
    string item;
    long int rupee;
    int quantities;
    product s1;
public:
    bill()
    {
        system("color 72");
        //print_line();
        cout<<"\n Enter no.of items:";
        cin>>items;
        for(int i=0;i<items;i++)
        {
          cout<<"Item No "<<i+1<<":"<<endl;
          cout<<"Enter the item name :";
          cin>>item;
          cout<<"Enter the rate of the "<<item<<":";
          cin>>rupee;
          cout<<"Enter the Quantity:";
          cin>>quantities;
          s1.store(item,rupee,quantities,i);
          system("cls");
        }
        s1.total_bill(items);
        //cout<<endl<<product::total;
        print_short();
        s1.display(items);
        s1.billing(items);
        s1.bill_store(items);
    }
};
int main()
{
    setting_font();
    string username;
    long int password;
    int key;
    system("color 71");
    cout<<"\n Enter the username:";
    cin>>username;
    cout<<" Enter the Password:";
    cin>>password;
    key=password_checking(username,password);
    while(key==0)
    {
        cout<<"\n Wrong Username and Wrong Password!!!"<<endl;
        cout<<"\n Enter the username:";
        cin>>username;
        cout<<" Enter the Password:";
        cin>>password;
        key=password_checking(username,password);
    }
    if(key==1)
    {
        cout<<"\n Username and Password is correct!!!!"<<endl;
        loading();
        loading_success();
        int key=1;
        out:
        system("cls");
        if(key)
        {
         key=disp();
         switch(key)
         {
          case 1:
            {system("cls");bill obj;goto out;}
          case 2:
            {system("billstore.txt");
             goto out;}
          case 3:
            {system("bill.txt");goto out;}
          case 4:
            {
                ofstream del_bill;
                del_bill.open("billstore.txt",ios::trunc);
                del_bill.close();
                goto out;
            }
          case 0:
            {
                goto out;
            }
          default:
            {cout<<"!!!!!ERROR!!!!!";
            goto out;}
        }
    }
 }
    return 0;
}
