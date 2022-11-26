// : Given an array containing both positive and negative integers, we have to find the length of the longest subarray with the sum of all elements equal to zero.

/*
Input Format: N = 6, array[] = {9, -3, 3, -1, 6, -5}

Result: 5

Explanation: The following subarrays sum to zero:
{-3, 3} , {-1, 6, -5}, {-3, 3, -1, 6, -5}
Since we require the length of the longest subarray, our answer is 5!
*/

//Approach 1 : (Naive Approach)  Time Complexity : O(N), Space Complexity : O(1)
int ans = 0;
for(int i=0; i<arr.size(); i++){
    int sum = 0;
    for(int j = i; j<arr.size(); j++){
        sum += arr[j];
        if(sum == 0){
            ans = max(ans, j-i+1);
        }
    }
}

return ans;

//Approach 2 : (HashSet) Time Complexity : O(N), Space Complexity : O(N)
int maxi = 0;
unordered_map<int, int> map;
int sum = 0;
for(int i=0; i<n; i++){
    sum += arr[i];
    if(sum == 0)
    max = i + 1;
    else{
        if(map.find(sum) != map.end()){
            maxi = max(maxi, i - map[sum]);
        }
        else{
            map[sum] = i;
        }
    }
}

return maxi;