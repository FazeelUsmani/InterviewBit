/*
Matrix Median
Given a N cross M matrix in which each row is sorted, find the overall median of the matrix. Assume N*M is odd. For example,
Matrix=
[1, 3, 5]
[2, 6, 9]
[3, 6, 9]

A = [1, 2, 3, 3, 5, 6, 6, 9, 9]

Median is 5. So, we return 5.
Note: No extra memory is allowed.
*/

// Median of any sorted array must have (rows * column +1 )/2 values less then it, so as matrix is row sorted find min and max for the range, then use BS to find median

int Solution::findMedian(vector<vector<int> > &A) {
    
    int min = A[0][0], max = A[0][0];
    int n = A.size(), m = A[0].size();
    for (int i = 0; i < n; ++i) {
        if (A[i][0] < min) min = A[i][0];
        if (A[i][m-1] > max) max = A[i][m-1];
    }

    int element = (n * m + 1) / 2;
    while (min < max) {
        int mid = min + (max - min) / 2;
        int cnt = 0;
        for (int i = 0; i < n; ++i)
            cnt += upper_bound(&A[i][0], &A[i][m], mid) - &A[i][0]; // No of elm that are less then mid in given range
        if (cnt < element) // if count is less then desired move mid towards right i.e min is incremented
            min = mid + 1;
        else
            max = mid;
    }
    return min;
}
