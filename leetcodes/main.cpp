#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    for(int i=0;i<nums.size();i++)
    {
        for(int j=i+1;j<nums.size();j++)
        {
            if(nums[j]==target-nums[i])
                return {i,j};

        }
    }
    return {};
}

bool isPalindrome(int x) {
    if(x<0)
        return false;
    else
    {
        unsigned int y=0,t=x;
        while(x)
        {
            y=y*10+x%10;
            x/=10;
        }
        return (t==y);

    }
}

int romanToInt(string s) {
    int result=0;
    for(int i=0;i<s.length();i++)
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

string longestCommonPrefix(vector<string>& strs) {
    string com="";
    short int cont=0;
    char x=strs[0][cont];
    while(x)
    {
        for(const auto &w:strs)
        {
            if(w[cont]!=x)
                return com;
        }
        com+=x;
        cont++;
        x=strs[0][cont];

    }

    return com;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
