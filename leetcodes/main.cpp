#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
    for(int i=0;i<nums.size();i++)      //loop through the vector
    {
        for(int j=i+1;j<nums.size();j++)
        {
            if(nums[j]==target-nums[i])     //if the sum of both numbers equals the target number
                return {i,j};
        }
    }

    return {};      //return empty vector if not found
}

bool isPalindrome(int x)
{
    if(x<0)         //negative numbers are not palindromes
        return false;
    else
    {
        unsigned int y=0,t=x;
        while(x)
        {
            y=y*10+x%10;        //"append" the last digit of the number
            x/=10;              //remove the last digit
        }

        return (t==y);
    }
}

int romanToInt(string s)
{
    int result=0;
    for(int i=0;i<s.length();i++)       //loop through the characters of the string
    {
        switch(int(s[i]))
        {
        case 67:    //C
            result+=(s[i+1]=='D'||s[i+1]=='M')?-100:100;
            break;
        case 68:    //D
            result+=500;
            break;
        case 73:    //I
            result+=(s[i+1]=='X'||s[i+1]=='V')?-1:1;
            break;
        case 76:    //L
            result+=50;
            break;
        case 77:    //M
            result+=1000;
            break;
        case 86:    //V
            result+=5;
            break;
        case 88:    //X
            result+=(s[i+1]=='C'||s[i+1]=='L')?-10:10;
            break;
        }
    }

    return result;
}

string longestCommonPrefix(vector<string>& strs)
{
    string com="";      //empty common prefix
    short int cont=0;       //letter counter
    char x=strs[0][0];   //first letter of first word

    while(x)        //loop through the characters of the first word
    {
        for(const auto &w:strs)     //loop through the strings
        {
            if(w[cont]!=x)      //if the letter at this position is not the same in all words
                return com;     //return common prefix
        }
        com+=x;         //for loop finished, so the letter is in all words, so save the letter
        cont++;
        x=strs[0][cont];    //next letter. It doesn't matter which word we take it from,
                            //since they must all be the same

    }

    return com;
}

bool isValid(string s)
{
    vector<char> v={};
    for(const auto &c:s)
    {
        if (c == '(' || c == '{' || c == '[')
            v.emplace_back(c);         // push to the vector
        else
        {
            // if the character is a closing bracket and last character is not the corresponding one
            if (v.empty() || (c == ')' && v.back() != '(') || (c == '}' && v.back() != '{') ||
                (c == ']' && v.back() != '['))
            {
                return false;           // the string is not valid, so return false
            }
            v.pop_back();              // otherwise, remove the opening bracket from the vector
        }

    }

    return v.empty();       //if vector is empty, all brackets were correct
}

int removeElement(vector<int>& nums, int val)
{
    short int k=0;

    for(auto i=nums.begin();i!=nums.end();)
    {
        if(*i==val)         //remove value
        {
            nums.erase(i);
            continue;       //because of how "erase" works, next value will be in the same position
        }
        k++;
        i++;        //only increase position if no element was erased
    }

    return k;
}



int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
