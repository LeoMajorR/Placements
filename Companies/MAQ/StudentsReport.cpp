#include <bits/stdc++.h>
using namespace std;

struct Result
{
    Result() : output1(){};
    int output1[100];
};

Result SortsStudentMarks(int input1, int input2, int **input3)
{
    Result result;
    vector<int> marks;
    for (int i = 0; i < input2; i++)
    {
        int temp=0;
        for(int j = 0; j < input1; j++)
        {
            temp+=input3[j][i];
        }
        marks.push_back(temp);
    }
    
}
int main()
{
    // input 3[][] = {{75,76,65,87,87},{78,76,68,56,89},{67,87,78,77,65}}
    int input1 = 3;
    int input2 = 5;
    int **input3 = new int *[input1];
    for (int i = 0; i < input1; i++)
    {
        input3[i] = new int[input2];
    }
    input3[0][0] = 75;
    input3[0][1] = 76;
    input3[0][2] = 65;
    input3[0][3] = 87;
    input3[0][4] = 87;
    input3[1][0] = 78;
    input3[1][1] = 76;
    input3[1][2] = 68;
    input3[1][3] = 56;
    input3[1][4] = 89;
    input3[2][0] = 67;
    input3[2][1] = 87;
    input3[2][2] = 78;
    input3[2][3] = 77;
    input3[2][4] = 65;
    Result result = SortsStudentMarks(input1, input2, input3);
    for (int i = 0; i < input1; i++)
    {
        cout << result.output1[i] << " ";
    }
}