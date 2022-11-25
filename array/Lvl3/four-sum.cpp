//Given an array of N integers, your task is to find unique quads that add up to give a target value. In short, you need to return an array of all the unique quadruplets [arr[a], arr[b], arr[c], arr[d]] such that their sum is equal to a given target.

/*
Input Format: arr[] = [1,0,-1,0,-2,2], target = 0

Result: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Explanation: We have to find unique quadruplets from 
the array such that the sum of those elements is 
equal to the target sum given that is 0. 

The result obtained is such that the sum of the 
quadruplets yields 0

*/

//Approach 1 (three pointers && binary search):  Time Complexity : O(NLog(N) + (N^3)(Log(N))), Space Complexity : O(N)
set<vector<int>> s;
int n = nums.size();
sort(nums.begin(), nums.end());
for(int i=0; i<n; i++){
    for(int j = i+1; j<n; j++){
        for(int k = j+1; k<n; k++){
            int x = (long long)target - (long long)nums[i] + (long long )nums[j] + (long long)nums[k];
            if(binary_search(nums.size() + k + 1, nums.end(), x)){
                vector<int> v;
                v.push_back(nums[i]);
                v.push_back(nums[j]);
                v.push_back(nums[k]);
                v.push_back(x);
                sort(v.begin(), v.end());
                s.insert(v);
            } 
        }
    }

}

vector<vector<int> > res(sort(s.begin(), s.end()));
return res;


//Approach 2 : Time Complexity : O(N^3), Space Complexity : O(1)
vector<vector<int>> res;
if(nums.size() == 0)
return res;

sort(nums.begin(), nums.end());

for(int i=0; i<n; i++){
    int target_3 = target - nums[i];
    for(int j = i+1; j<n; j++){
        int target_2 = target - nums[j]; //use long long in case if there is big value
        int left = j + 1;
        int right = n -1;
        while(left < right){
            int tar = nums[left] + nums[right];
            if(tar < target_2){
                left++;
            }
            else if(tar > target_2){
                right--;
            }
            else{
                vector<int> arr(4, 0);
                arr[0] = nums[i];
                arr[1] = nums[j];
                arr[2] = nums[left];
                arr[3] = nums[right];

                res.push_back(arr);
                while(left < right && arr[2] == nums[left]){left++;}
                while(left < right && arr[3] == nums[right]){right--;}
            }
        }
        while(j+1 < n && nums[j + 1] == nums[j]){ j++; }
    }

    while(i + 1 < n && nums[i + 1] == nums[i]){ i++ };
}

return res;