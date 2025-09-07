int maxWater(vector<int> &arr) {
    int n = arr.size();
    if (n < 2) return 0; // No water can be trapped if there are fewer than 2 bars

    int left = 0, right = n - 1;
    int maxArea = 0;

    while (left < right) {
        // Calculate the area between the current left and right bars
        int height = min(arr[left], arr[right]);
        int width = right - left;
        int area = height * width;

        // Update the maximum area
        maxArea = max(maxArea, area);

        // Move the pointer pointing to the smaller height
        if (arr[left] < arr[right]) {
            left++;
        } else {
            right--;
        }
    }

    return maxArea;
}