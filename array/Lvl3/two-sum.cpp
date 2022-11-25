// Given an array of integers nums[] and an integer target, return indices of the two numbers such that their sum is equal to the target.
/*
Input: nums = [2,7,11,15], target = 9

Output: [0,1]

Explanation: Because nums[0] + nums[1] == 9, 
which is the required target, we return 
indexes [0,1]. (0-based indexing)
*/

//Approach 1 (brute Force):  Time Complexity : O(N^2) Space Complexity : O(1)
vector<int> res;
for(int i = 0; i<arr.size(); i++){
    for(int j = i+1; j<arr.size(); j++){
        if(arr[i] + arr[j] == target){
            res.emplace_back(i);
            res.emplace_back(j);
            break;
        }
    }

    if(res.size() == 2)
    break;
} 

return res;

//Approach 2 (Two pointer optimization):  Time Complexity : O(NLog(N)), Space Complexity : O(N)
vector<int> res, solve;
solve = nums;
sort(solve.begin(), solve.end());
int l = 0, r = nums.size() - 1;
int n1, n2;
while( l < r){
    if(solve[l] + solve[r] == target){
        n1 = solve[l];
        n2 = solve[r];

        break;
    }

    else if( solve[l] + solve[r] > target)
    r--;

    else
    l++;
}

for(int i = 0; i<nums.size(); i++){
    if(nums[i] == n1)
    res.emplace_back(i);

    if(nums[i] == n2)
    res.emplace_back(i);
}

return res;

//Approach 3 (Hashing Most optimization): Time Complexity : O(N), Space Complexity : O(N)
unordered_map<int, int> mp;
vector<int> res;

for(int i=0; i<nums.size(); i++){
    if(mp.find(target - nums[i]) != mp.end()){
        res.emplace_back(i);
        res.emplace_back(mp[target - nums[i]]);

        return res;
    }

    mp[nums[i]] = i;
}

return res;