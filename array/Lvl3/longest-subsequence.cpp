// You are given an array of ‘N’ integers. You need to find the length of the longest sequence which contains the consecutive elements.

/*
Example 1:

Input: [100, 200, 1, 3, 2, 4]

Output: 4

Explanation: The longest consecutive subsequence is 1, 2, 3, and 4

*/

//Approch 1 : Time Complexity : O(Nlog(N)), Space Complexity : O(1)
sort(arr.begin(), ans.end());
int ans = 1;
int prev = arr[0];
int curr = 1;
for(int i=1; i<arr.size(); i++){
    if(arr[i] == prev+1){
        curr++;
    }
    else if(arr[i] != prev){
        curr = 1;
    }
    prev = arr[i];
    ans = max(ans, curr);
}

return ans;


//Approach 2 : (HashSet) 
set<int> HashSet;
for(auto num : nums){
    HashSet.insert(num); //Storing elements in hashSet
}

int ans = 1;
for(auto num : nums){
    if(!HashSet.count(num - 1)){ //Checking if it's the starting element in the sequenece
        int currNum = num;
        int currentStreak = 1;

        while(HashSet.count(nums+1)){ //If yes then how long 
            currNum +=1;
            currentStreak += 1; 
        }
    }

    ans = max(ans, currentStreak);
}
return ans;