class Solution {
public:
	void replaceSpace(char *str,int length) {
		if (str != NULL && length > 0) {
            int tail = strlen(str);
            int len = strlen(str);
            char* p = str;
            while (*p != '\0') {
                if (*p == ' ') {
                    len += 2;
                }
                p++;
            }
            while (tail >= 0 && len > tail) {
                if (str[tail] == ' ') {
                    str[len--] = '0';
                    str[len--] = '2';
                    str[len--] = '%';
                } else {
                    str[len--] = str[tail];
                }
                tail--;
            }
        }
	}
};
