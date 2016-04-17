/*************************************************************************
	> File Name: b1012.cpp
	> Author: Shadow Hu 
	> Mail: shadow_hu1441@163.com
	> Created Time: 2016年04月17日 星期日 21时10分11秒
 ************************************************************************/

#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
  
int main()
{
    int num;
    cin >> num;
    int *arr = new int[num];
    int i;
    for (i = 0; i<num; i++)
        cin >> arr[i];
    int A1 = 0;
    int A2 = 0;
    int A3 = 0;
    double A4;
    int A5 = 0;
    int count = 1;
    int number = 0;
    float sum = 0;
    for (i = 0; i<num; i++)
    {
        switch (arr[i] % 5)
        {
        case 0:
            if (arr[i] % 2 == 0)
                A1 += arr[i];
            break;
        case 1:
            count++;
            A2 += arr[i] * pow(-1, count);
            break;
        case 2:
            A3++; break;
        case 3:
            number++;
            sum += arr[i]; break;
        case 4:
            if (A5<arr[i])
                A5 = arr[i]; break;
        default:
            cout << "error!";
  
        }
    }
    if (A1 == 0)
        cout << 'N' << ' ';
    else
        cout << A1 << ' ';
    if (A2 == 0)
        cout << 'N' << ' ';
    else
        cout << A2 << ' ';
    if (A3 == 0)
        cout << 'N' << ' ';
    else
        cout << A3 << ' ';
    if (number == 0)
        cout << 'N' << ' ';
    else
    {
        A4 = sum / number;
        cout << fixed << showpoint << setprecision(1) << A4 << ' ';
        /*必须用setprecision（1）控制输出一位小数，用fixed进一步控制输出格式，还有用showpoint显示小数点后的0 
         */
    }
    if (A5 == 0)
        cout << 'N' << endl;
    else
        cout << A5 << endl;
    return 0;
}
