#include <bits/stdc++.h>
using namespace std;

// count frequency of each character in a string
char *frequency(char *input1)
{
    int n = strlen(input1);
    int count[26] = {0};
    for (int i = 0; i < n; i++)
    {
        count[input1[i] - 'a']++;
    }
    int m = 0;
    for (int i = 0; i < 26; i++)
    {
        if (count[i] > 0)
            m++;
    }
    char *output = (char *)malloc(2 * m * sizeof(char));
    int j = 0;
    for (int i = 0; i < 26; i++)
    {
        if (count[i] > 0)
        {
            output[j++] = i + 'a';
            output[j++] = count[i] + '0';
        }
    }
    // output[j] = '\0';
    // if (strlen(output) == 0)
    //     return ;
    return output;
}

int main()
{
    char input1[100] = "phqgh";
    char input2[100] = "babdc";
    char input3[100] = "a";
    char input4[100] = "aabbcc";
    // corner case
    char input5[100] = "aaabbbccc";
    char input6[100] = "vivek";
    char input7[100] = "";

    cout << frequency(input1) << endl;
    cout << frequency(input2) << endl;
    cout << frequency(input3) << endl;
    cout << frequency(input4) << endl;
    cout << frequency(input5) << endl;
    cout << frequency(input6) << endl;
    cout << frequency(input7) << endl;
}

// // count frequency of each character in a string
// char* frequency(char* input1)
// {
//     int i, j, k, l, m, n, count;
//     char* output1 = (char*)malloc(100*sizeof(char));
//     for (i = 0; input1[i] != '\0'; i++)
//     {
//         count = 1;
//         for (j = i + 1; input1[j] != '\0'; j++)
//         {
//             if (input1[i] == input1[j])
//             {
//                 count++;
//                 for (k = j; input1[k] != '\0'; k++)
//                 {
//                     input1[k] = input1[k + 1];
//                 }
//                 j--;
//             }
//         }
//         output1[i] = input1[i];
//         output1[i + 1] = count + '0';
//         i++;
//     }
//     output1[i] = '\0';
//     return output1;
// }

// int main()
// {
//     char input1[100] = "aababbbccdd";
//     cout<<frequency(input1);
// }