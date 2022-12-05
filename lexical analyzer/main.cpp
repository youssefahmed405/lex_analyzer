#include "tokens.h"

int main(int argc,char* argv[])
{
    vector<token> tokens;

    vector<string> code;
    ifstream input ("code.txt"); 

    string element;
    string operand;
    string operatorq;
    string literal;

    char buffer;
    char nextbuffer;
    int ophandler = 0;
    while ( input >> noskipws >> buffer) 
    {
        
        //comment handler
        if(buffer == '/')
        {
            if(element != " " && element != "\t" && element != "\n" && element != "")
            {
                code.push_back(element);
                element = "";
            }


            input.get(nextbuffer);

            if(nextbuffer == '/')
            {
                input.ignore(1000,'\n');
                nextbuffer == ' ';
                continue;
            }
            if(nextbuffer == '*')
            {
                while ( input >> noskipws >> buffer)
                {
                    if(buffer == '*')
                        nextbuffer = buffer;
                    if(buffer == '/' && nextbuffer == '*')
                    {
                        nextbuffer = ' ';
                        break;
                    }
                }
                continue;
            }
            operand += buffer;
            code.push_back(operand);
            operand = "";
            buffer = nextbuffer;

        }
        //literal 
        if(buffer == '\"')
        {
            literal += '\"';
            while ( input >> noskipws >> buffer) 
            {
                if(buffer == '\"')
                {
                    literal += '\"';
                    code.push_back(literal);
                    literal = "";
                    break;
                }
                literal += buffer;
            }
            continue;
        }
        //operatores
        if(ophandler && _catch_op_(buffer))
        {
            operatorq += buffer;
            if(_catch_a_operator_(operatorq)){
                code.pop_back();
                code.push_back(operatorq);
            }
            else {
                operatorq = "";
                operatorq += buffer;
                code.push_back(operatorq);}
            operand = "";
            operatorq = "";
            ophandler = 0;
            continue;
        }
        else {operatorq = ""; ophandler = 0;}
        if(_catch_op_(buffer))
        {
            if(element != " " && element != "\t" && element != "\n" && element != "")
            {
                code.push_back(element);
                element = "";
            }

            if(operand != " " && operand != "\t" && operand != "\n")
            {
                operatorq += buffer;
                operand += buffer;
                code.push_back(operand);
                operand = "";
                ophandler = 1;
                continue;
            }
            continue;
        }
        
        if(buffer == space || buffer == '\n' || buffer == '\t')
        {
            if(element != " " && element != "\t" && element != "\n" && element != ""){
            code.push_back(element);
            element = "";}
        }
        else
            element += buffer;
    }

//____________________________________________________________________________________________________________________________________________________________

    if(element != " " && element != "\t" && element != "\n" && element != "")
            code.push_back(element);



    int i = 0;
    for(auto it = code.begin(); it != code.end() ; it++)
    {
        token temp;  
        temp.lexeme = *it;
        temp.type = t_type(*it);
        tokens.push_back(temp);
        cout << tokens[i].lexeme << "  " << return_value(tokens[i].type) << endl;
        i++;
    }
}