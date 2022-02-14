#include <sys/types.h>
#include <ifaddrs.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include <list>





int get_ip_linux(int ipv4_6, std::list<std::string>& out_list_ip)
{
    int ret_val = 0;

    struct ifaddrs * ifAddrStruct 	= NULL;
    void * tmpAddrPtr 				= NULL;

    // 1.
    ret_val 						= getifaddrs(&ifAddrStruct);
    if (0 != ret_val)
    {
        ret_val = errno;

        return ret_val;
    }

    // 2.
    std::string str_ipvX;

    int padress_buf_len = 0;
    char addressBuffer[INET6_ADDRSTRLEN] = {0};

    if (AF_INET6 == ipv4_6)
            padress_buf_len = INET6_ADDRSTRLEN;
    else
        padress_buf_len = INET_ADDRSTRLEN;
    
    
    while (NULL != ifAddrStruct ) 
    {
        if (ipv4_6 == ifAddrStruct->ifa_addr->sa_family ) 
        { 
            // is a valid IP4 Address
            tmpAddrPtr = &((struct sockaddr_in *)ifAddrStruct->ifa_addr)->sin_addr;
            
            inet_ntop(ipv4_6, tmpAddrPtr, addressBuffer, padress_buf_len);
            str_ipvX = std::string(addressBuffer);

            out_list_ip.push_back(str_ipvX);

            memset(addressBuffer, 0, padress_buf_len);
        } 

        ifAddrStruct=ifAddrStruct->ifa_next;
    }

    return ret_val;
}


int get_ipv4_linux(std::list<std::string>& out_list_ip4)
{
    return get_ip_linux(AF_INET, out_list_ip4); 
}

int get_ipv6_linux(std::list<std::string>& out_list_ip6)
{
    return get_ip_linux(AF_INET6, out_list_ip6); 
}




