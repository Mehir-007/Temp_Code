/*
Approach: We will first push all are elements in the HashSet. 
Then we will run a for loop and check for any number(x) if it is the starting number of the consecutive sequence by checking if the HashSet contains (x-1) or not. 
If ‘x’ is the starting number of the consecutive sequence we will keep searching for the numbers y = x+1, x+2, x+3, ….. 
And stop at the first ‘y’ which is not present in the HashSet. Using this we can calculate the length of the longest consecutive subsequence. 
*/

#include<bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        
        unordered_map<int,int> um;
        
        for(int i=0;i<nums.size();i++)
        um[nums[i]]++;
        int ans=1;
        
        for(int i=0;i<nums.size();i++)
        {
            if(um[nums[i]-1]) continue;
            else
            {
                int x=1;
                int curr=nums[i]+1;
                while(um[curr])
                {
                    x++;
                    curr++;
                }
                ans=max(ans,x);
            }
        
        }
        return ans;
}
int main()
{
	vector<int> v={100,4,200,1,3,2};
	cout<<longestConsecutive(v);
}
