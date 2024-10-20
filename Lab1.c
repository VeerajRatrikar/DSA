#include<stdio.h>

char str[100], pat[50], rep[50], ans[100];
int i, j, c, m, k, flag = 0;

void find_match();

void main() {
    printf("Enter a main string \n");
    gets(str);
    printf("Enter a pattern string \n");
    gets(pat);
    printf("Enter a replace string \n");
    gets(rep);
    
    find_match();
    
    if (flag == 1) {
        printf("The resultant string is\n %s", ans);
    } else {
        printf("Pattern string NOT found\n");
    }
}

void find_match() {
    i = m = c = j = 0;
    while (str[c] != '\0') {
        if (str[m] == pat[i]) {
            i++;
            m++;
            if (pat[i] == '\0') {  // Pattern fully matched
                flag = 1;
                for (k = 0; rep[k] != '\0'; k++, j++) {
                    ans[j] = rep[k];  // Copy replacement string
                }
                i = 0;
                c = m;  // Move forward in the main string
            }
        } else {
            ans[j] = str[c];  // Copy the current character of main string to result
            j++;
            c++;
            m = c;  // Move on to the next character
        }
    }
    ans[j] = '\0';  // End the result string with a null character
    return flag;
}
