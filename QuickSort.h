class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        leftS = nums1.begin();
        rightS = nums2.begin();
        leftE = leftS + m;
        rightE = rightS + n;
        while(leftS < leftE || rightS < rightE){//把两个有序数组合并起来的过程
			//如果右边已经全部检查完毕那么直接将左边合并起来即可
            if(rightS >= rightE || (leftS < leftE && (*leftS) <= (*rightS))){ 
                temp.push_back(*leftS);
                leftS++;  
            }
            else {
                temp.push_back(*rightS);
                rightS++;
            }
        }
        nums1.assign(temp.begin(), temp.end());
    }
private:
    std::vector<int>::iterator leftS, rightS, leftE, rightE;
    vector<int> temp;
};
