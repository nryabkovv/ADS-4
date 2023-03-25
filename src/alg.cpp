int countPairs1(int* arr, int len, int value)
{
	int k = 0;
	for (int i = 0; i < len-1; i++) {
		for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                k += 1;
            }
		}
	}
}
int countPairs2(int* arr, int len, int value)
{
	int k = 0;
	for (int i = 0; i < len - 1; i++) {
		for (int j = len - 1; i < j; j--) {
            if (arr[i] + arr[j] == value) {
                k += 1;
            }
		}
	}
}
int countPairs3(int* arr, int len, int value)
{
    int k = 0;
    for (int i = 0; i < len-1; i++) {
        int left = i; 
        int right = len;
        while (right - 1 > left) {
            int mid = (left + right) / 2;
            if (arr[i] + arr[mid] == value) {
                k++;
                int nm = mid + 1;
                while (arr[i] + arr[nm] == value && nm < right) {
                    k++;
                    nm++;
                }
                nm = mid - 1;
                while (arr[i] + arr[nm] == value && nm > left) {
                    k++;
                    nm--;
                }
                break;
            }
            if (arr[i] + arr[mid] > value) 
                right = mid;       
            else 
                left = mid;            
        }
    }
    return k;
}
