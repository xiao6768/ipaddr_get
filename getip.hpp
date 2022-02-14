#pragma once
#ifndef __GET_IP_MY_HPP__
#define __GET_IP_MY_HPP__


#include <string>
#include <list>

int get_ip_linux(int ipv4_6, std::list<std::string>& out_list_ip);
int get_ipv4_linux(std::list<std::string>& out_list_ip4);
int get_ipv6_linux(std::list<std::string>& out_list_ip6);

#endif // __GET_IP_MY_HPP__




