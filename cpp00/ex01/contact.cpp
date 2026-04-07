#include "contact.hpp"

std::string Contact::get_fi_name(){
    return (f_name);}

std::string Contact::get_la_name(){
    return (l_name);}

std::string Contact::get_nkname(){
    return (nickname);}

void Contact::get_f_name(){
    std::cout << f_name ;}

void Contact::get_l_name(){
    std::cout << l_name ;}

void Contact::get_nickname(){
    std::cout << nickname ;}

void Contact::get_p_num(){
    std::cout << p_num ;}

void Contact::get_d_s(){
    std::cout << d_s ;}

void Contact::set_f_name(std::string name){
    f_name  = name;}

void Contact::set_l_name(std::string ln){
    l_name  = ln;}

void Contact::set_nickname(std::string nn){
    nickname  = nn;}

void Contact::set_p_num(std::string pn){
    p_num  = pn;}

void Contact::set_d_s(std::string ds){
    d_s  = ds;}
