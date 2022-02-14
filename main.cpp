#include "getip.hpp"
#include <iostream>
using namespace std;

std::list<std::string> ipv4;
std::list<std::string> ipv6;


int main(int argc, char** argv)
{

    int ret_val = get_ipv4_linux(ipv4);
    if (0 != ret_val)
    {
        cout << "error, ipv4, id = " << ret_val << endl;
    }
    else
    {
        int index = 0;
        for (auto item: ipv4)
        {
            cout << "index = " << ++index;
            cout << ", ipv4 = " << item.c_str() << endl;
        }
    }


    ret_val = get_ipv6_linux(ipv6);
    if (0 != ret_val)
    {
        cout << "error, ipv6, id = " << ret_val << endl;
    }
    else
    {
        int index = 0;
        for (auto item: ipv6)
        {
            cout << "index = " << ++index;
            cout << ", ipv6 = " << item.c_str() << endl;
        }
    }


    return 0;
}



