class Solution {
public:
    vector<int> majorityElement(vector<int>& v) {
//optimal solution : Extended Moores Voting Algorithm
int n = v.size(); //size of the array

    int cnt1 = 0, cnt2 = 0; // counts
    int el1 = INT_MIN; // element 1
    int el2 = INT_MIN; // element 2

    // applying the Extended Boyer Moore's Voting Algorithm:
    for (int i = 0; i < n; i++) {
        if (cnt1 == 0 && el2 != v[i]) {
            cnt1 = 1;
            el1 = v[i];
        }
        else if (cnt2 == 0 && el1 != v[i]) {
            cnt2 = 1;
            el2 = v[i];
        }
        else if (v[i] == el1) cnt1++;
        else if (v[i] == el2) cnt2++;
        else {
            cnt1--, cnt2--;
        }
    }

    vector<int> ls; // list of answers

    // Manually check if the stored elements in
    // el1 and el2 are the majority elements:
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == el1) cnt1++;
        if (v[i] == el2) cnt2++;
    }

    int mini = int(n / 3) + 1;
    if (cnt1 >= mini) ls.push_back(el1);
    if (cnt2 >= mini) ls.push_back(el2);

    // Uncomment the following line
    // if it is told to sort the answer array:
    // sort(ls.begin(), ls.end()); //TC --> O(2*log2) ~ O(1);

    return ls;
}


        
    
};



//brute force approach
// vector<int> ans;
//         for(int i =0;i<n;i++)
//         {
//             if (ans.size() == 0 || ans[0] != nums[i]) {
//                 int count =0;
//                 for(int j=0;j<n;j++)
//                 {
//                     if(nums[j] == nums[i])
//                     {
//                         count++;
//                     }
//                 }
//                 if (count > (n / 3))
//                 ans.push_back(nums[i]);
//             }
//             if (ans.size() == 2) break;
//         }
//         return ans;




// better approach
//         vector<int> ans;
//         map<int,int>mpp;
//         int mini = int(n / 3) + 1;

//         for(int i =0;i<n;i++)
//         {
//             mpp[nums[i]]++;

//             if(mpp[nums[i]] ==mini)
//             {
//                 ans.push_back(nums[i]);
//             }

//             if(ans.size() == 2)break;

//         }
//         return ans;