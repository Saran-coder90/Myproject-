void print_shortbill(std::fstream &bil)//for space and lining
{
    for(int i=0;i<(168/2)-49;i++)
    {
       bil<<" ";
    }
    for(int i=1;i<=49;i++)
    {
       bil<<"-";
    }
}
void space_bill(std::fstream &bil)//for spacing only
{
    bil<<"\n";
    for(int i=0;i<(168/2)-49;i++)
    {
        bil<<" ";
    }
}
void space_align_billing(long int num,std::fstream &bil)
{
    int digit=1;
    while(num>=10)
    {
        num=num/10;
        digit++;
    }
    int i=digit+4;
    while(i<=10)
    {
        if(i==10) bil<<"|";
        else bil<<" ";
        i++;
    }
}
void align_billing(std::string items,std::fstream &bil)
{
    int length=items.length();
    bil<<items;
    int i=length;
    while(i<=19)
    {
        if(i==19)
        {
            bil<<"|";
        }
        else
        {
            bil<<" ";
        }
        i++;
    }
}
