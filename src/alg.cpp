int countPairs1(int* arr, int len, int value)
{
	int k = 0;
	for (int i = 0; i < len - 1; i++) {
		for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                k += 1;
            }
		}
	}
    return k;
}

int countPairs2(int* arr, int len, int value)
{
	int k = 0;
	for (int i = 0; i < len; ++i) {
		for (int j = len - 1; i < j; --j) {
            if (arr[i] + arr[j] == value) {
                k += 1;
            }
		}
	}
    return k;
}

int countPairs3(int* arr, int len, int value)
{
    int k = 0;
    for (int i = 0; i < len - 1; i++) {
        int left = i; 
        int right = len;
        while (right - 1 > left) {
            int mid = (left + right) / 2;
            if (arr[i] + arr[mid] == value) {
                k += 1;
                int nm = mid + 1;
                while (arr[i] + arr[nm] == value && nm < right) {
                    k += 1;
                    nm += 1;
                }
                nm = mid - 1;
                while (arr[i] + arr[nm] == value && nm > left) {
                    k += 1;
                    nm -= 1;
                }
                break;
            }
            if (arr[i] + arr[mid] > value) {
                right = mid;
            }
            else {
                left = mid;
            }
        }
    }
    return k;
}
