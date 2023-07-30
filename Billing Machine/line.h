//{
void print_line()
{
std::cout<<std::endl;
for(int i=0;i<(168);i++)
        {
           std::cout<<"-";
        }
}
//}
void print_short()//for space and lining
{
    for(int i=0;i<(168/2)-49;i++)
    {
        std::cout<<" ";
    }
    for(int i=1;i<=49;i++)
    {
        std::cout<<"-";
    }
}
namespace bar
{
void space()//for spacing only
{
    std::cout<<std::endl;
    for(int i=0;i<(168/2)-49;i++)
    {
        std::cout<<" ";
    }
}
}
void align(std::string items)
{
    int length=items.length();
    std::cout<<items;
    int i=length;
    while(i<=19)
    {
        if(i==19)
        {
            std::cout<<"|";
        }
        else
        {
            std::cout<<" ";
        }
        i++;
    }
}
void space_align(long int num)
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
        if(i==10) std::cout<<"|";
        else std::cout<<" ";
        i++;
    }
}
