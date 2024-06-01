#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100


int max(int a, int b) 
{
    return (a > b) ? a : b;
}


void findLCS(char *str1, char *str2, int len1, int len2, int choice) 
{
    int lcs[len1 + 1][len2 + 1];
    int i, j;

    
    for (i = 0; i <= len1; i++) 
    {
      for (j = 0; j <= len2; j++)
      {
        if (i == 0 || j == 0)
            lcs[i][j] = 0;
        else if (str1[i - 1] == str2[j - 1])
            lcs[i][j] = lcs[i - 1][j - 1] + 1;
        else
            lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
      } 
    }

    int index = lcs[len1][len2];
    char lcs_sequence[index + 1];
    lcs_sequence[index] = '\0';
    i = len1;
    j = len2;

    while (i > 0 && j > 0) 
    {
      if (str1[i - 1] == str2[j - 1]) 
      {
        lcs_sequence[index - 1] = str1[i - 1];
        i--;
        j--;
        index--;
      } 
      else if (choice == 1) 
      { 
        if (lcs[i - 1][j] >= lcs[i][j - 1])
            i--;
        else
            j--;
      } 
      else 
      { 
        if (lcs[i][j - 1] > lcs[i - 1][j])
            j--;
        else
            i--;
      }
    }

    printf("%d\n", lcs[len1][len2]);
    printf("%s\n", lcs_sequence);
}

int main() 
{
    int len1, len2, choice;
    char str1[MAX_LENGTH], str2[MAX_LENGTH];
    scanf("%d", &len1);
    scanf("%s", str1);
    scanf("%d", &len2);
    scanf("%s", str2);
    scanf("%d", &choice);
    findLCS(str1, str2, len1, len2, choice);
    return 0;
}
