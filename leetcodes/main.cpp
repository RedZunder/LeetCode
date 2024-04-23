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


int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
