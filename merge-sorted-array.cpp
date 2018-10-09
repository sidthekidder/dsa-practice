// https://leetcode.com/problems/merge-sorted-array
// time complexity = O(N)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int cur = m + n - 1;
        
        // both i,j pointing at end of nums1, nums2 and cur pointing at empty spaces
        // now compare i,j and swap the bigger number with cur
        // decrement both i/j and cur

        while (cur > 0)
        {
            if (j < 0)
            {
                cur--;
            }
            else if (nums1[i] > nums2[j])
            {
                // swap cur and nums1[i]
                int temp = nums1[cur];
                nums1[cur] = nums1[i];
                nums1[i] = temp;
                i--;
            }
            else
            {
                // swap cur and num2[j]
                nums1[cur] = nums2[j];
                j--;
            }
            cur--;
        }
    }
};