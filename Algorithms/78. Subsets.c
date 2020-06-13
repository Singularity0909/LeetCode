int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 1 << numsSize;
    int** res = (int**)malloc(sizeof(int*) * *returnSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * *returnSize);
    for (int i = 0; i < *returnSize; i++) {
        int cnt = 0;
        res[i] = (int*)malloc(sizeof(int) * numsSize);
        for (int j = i, dig = 0; j; j >>= 1, dig++)
            if (j & 1)
                res[i][cnt++] = nums[dig];
        (*returnColumnSizes)[i] = cnt;
    }
    return res;
}
