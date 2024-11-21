start = 0;
    int end = size - 1;

    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }