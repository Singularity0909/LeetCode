
// @Title: 矩形重叠 (Rectangle Overlap)
// @Author: Singularity0909
// @Date: 2020-04-12 01:22:00
// @Runtime: 0 ms
// @Memory: 7.5 MB

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return !(rec1[2] <= rec2[0] || rec1[3] <= rec2[1] || rec1[0] >= rec2[2] || rec1[1] >= rec2[3]);
    }
};
