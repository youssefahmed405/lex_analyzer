#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <regex>

using std::find;
using std::ifstream;
using std::string;
using std::cout;
using std::cin;
using std::vector;
using std::noskipws; 
#define endl "\n"
#define space ' '

#define ENUM2TXT(x) #x 
/*
_check_for_id_
_catch_a_data_type_
_catch_a_res_word_
_catch_a_operator_
*/

vector<string> data_types = {"int","float","double","signed","unsigned","const","bool","void","long","short","char","byte"};

vector<string> reserved_libs{"cout","stdlib"};///................................

vector<string> reserved_words = {"int","float","double","signed","unsigned","const","bool","void","long","short","char","byte",
                                "if","while","else","for","return","auto","break","continue","true","false","new","this","case",
                                "switch","struct","goto","sizeof","delete","enum","extern"};

vector<string> operators = {"==" , ">" , "<" , "<=" , ">=" , "!=" , "+" , "-" , "*" , "/" , "%" , "++" , "--", "&&" , "||" , "!" , "<<" , ">>" };

vector<char> ops = {'(', ')' , ':' , ';' ,'=' , '[' , ']' , '{' , '}' , '>' , '<' , '!' , '+' , '-' , '*' , '/' , '%' , '&' , '|' , ','};

bool _check_for_id_(string id)
{
    if (!((id[0] >= 65 && id[0] <= 90) || (id[0] >= 97 && id[0] <= 122) || id[0] == '_')) return false;
    for (int i = 1; i < id.length(); i++) {
        if (!((id[i] >= 65 && id[i] <= 90) || (id[i] >= 97 && id[i] <= 122) || (id[i] >= 48 && id[i] <= 57) || id[i] == '_')) return false;
    }
    return true;
}

bool _catch_a_data_type_(string ip)
{
    if (std::find(data_types.begin(), data_types.end(), ip) != data_types.end() )
    {
        return true;
    }
    return false;
}

bool _catch_a_res_word_(string ip)
{
    if (std::find(reserved_words.begin(), reserved_words.end(), ip) != reserved_words.end() )
    {
        return true;
    }
    return false;
}


bool _catch_a_res_lib_(string ip)
{
    if (std::find(reserved_libs.begin(), reserved_libs.end(), ip) != reserved_libs.end() )
    {
        return true;
    }
    return false;
}

bool _catch_a_operator_(string ip)
{
    if (std::find(operators.begin(), operators.end(), ip) != operators.end() )
    {
        return true;
    }
    return false;
}
bool _catch_op_(char ip)
{
    for(auto it = ops.begin(); it != ops.end() ; it++)
    {
        if(ip == *it) return true;
    }
    return false;
}

bool is_float(string s) 
{ 
std::size_t pos(0); 
pos = s.find_first_not_of(' '); 
if (pos == s.size()) return false; 
if (s[pos] == '+' || s[pos] == '-')  ++pos;
int n_nm, n_pt; 
for (n_nm = 0, n_pt = 0;  std::isdigit(s[pos]) || s[pos] == '.';  ++pos) 
{ 
	s[pos] == '.' ? ++n_pt : ++n_nm; 
} 
if (n_pt>1 || n_nm<1) return false; 
if(n_pt == 0) return false;
return pos == s.size(); // must reach the ending 0 of the string 
} 


bool is_integer(const std::string & s){
    return std::regex_match(s, std::regex("[(-|+)|][0-9]+"));
}