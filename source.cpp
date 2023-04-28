#include"header.h"

fstream datafile1;

Product::Product()
{
    Stock_no=5;
    quantity=0;
}

int Product::checkstock()
{
    if(Stock_no==0)
        return 0;
    else
        return 1;
}

float Product::get_price()
{
    return price;
}

void Product::set_price(float price)
{
    this->price=price;
}

int Product::get_quantity()
{
    return quantity;
}

void Product::set_quantity(int quantity)
{
    this->quantity=quantity;
}

int Product::get_stock()
{
    return Stock_no;
}

void Product::set_stock(int no)
{
    Stock_no=no;
}

void Product::purchase()
{
    quantity++;
    Stock_no=Stock_no-1;
}

string Product::get_name()
{
    return name;
}

void Product::set_name(string name)
{
    this->name=name;
}



int Transaction::checkCard(char no[17],char pin[4])
{
    int i;
    datafile1.open("Card.txt",ios::in);
    while(!datafile1.eof())
    {
        if(datafile1.eof())
            break;
        else
        {
            datafile1>>card_no;
            datafile1>>cvv;
            cout<<"CARD NO -"<<card_no<<endl;
            cout<<"CVV NO -"<<cvv<<endl;
            if(no==card_no)
            {
                if(pin==cvv)
                {
                    return 1;
                }
                else
                {
                    return 2;
                }
            }
        }
    }
    datafile1.close();
    return 0;
}

int Cash_dispencer::checkBalance(char user_amount[13],Bill b)
{
    int i;
    int amount=0;
    string data;
    int amount_vending;
    for(i=0;i<strlen(user_amount);i++)
    {
        amount=amount*10+int(user_amount[i])-48;
    }
    datafile1.open("Balance.txt",ios::in);
    datafile1>>data;
    datafile1.close();
    stringstream(data)>>amount_vending;
    balance=amount-b.get_totalamount();
    if(balance>amount_vending)
    {
        return 0;
    }
    else if(balance<amount_vending)
    {
        datafile1.open("Balance.txt",ios::out);
        datafile1<<amount_vending-balance;
        datafile1.close();
        return 1;
    }
}

int Cash_dispencer::get_balance()
{
    return balance;
}

float Bill::get_totalamount()
{
    return totalamount;
}

void Bill::Calculate(Drinks dr[10],Chocolates ch[10],Chips cp[10])
{
    int i;
    totalamount=0;
    for(i=0;i<10;i++)
    {
        totalamount=totalamount+dr[i].get_quantity()*dr[i].get_price()+ch[i].get_quantity()*ch[i].get_price()+cp[i].get_quantity()*cp[i].get_price();
    }
}

int check_quantity(Product &p)
{
    if(p.get_quantity()!=0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Bill::display_bill(Drinks dr[10],Chocolates ch[10],Chips cp[10],float balance)
{
    int i;
    cout<<"------------------------------------------------------\n";
    cout<<"                VENDING MACHINE                         \n";
    cout<<"------------------------------------------------------\n";
    cout<<"   PRODUCT  "<<"  |  "<<"QUANTITY"<<"  |  "<<"  PRICE  "<<endl;
    cout<<"------------------------------------------------------\n";
    for(i=0;i<10;i++)
    {
        if(check_quantity(dr[i]))
        {
            cout<<endl;
            cout<<" "<<dr[i].get_name()<<"        "<<dr[i].get_quantity()<<"           "<<dr[i].get_quantity()*dr[i].get_price()<<endl<<endl;
        }
        if(check_quantity(ch[i]))
        {
            cout<<endl;
            cout<<" "<<ch[i].get_name()<<"        "<<ch[i].get_quantity()<<"           "<<ch[i].get_quantity()*ch[i].get_price()<<endl<<endl;
        }
        if(check_quantity(cp[i]))
        {
            cout<<endl;
            cout<<" "<<cp[i].get_name()<<"        "<<cp[i].get_quantity()<<"           "<<cp[i].get_quantity()*cp[i].get_price()<<endl<<endl;
        }
    }
    cout<<"------------------------------------------------------\n";
    cout<<"TOTAL AMOUNT - "<<totalamount<<endl;
    cout<<"------------------------------------------------------\n";
}

