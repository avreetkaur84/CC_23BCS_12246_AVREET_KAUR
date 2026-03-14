#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int> &nums)
{
    int result = 0;

    for (int i = 0; i < 32; i++)
    {
        int sum = 0;

        for (int num : nums)
        {
            if ((num >> i) & 1)
            {
                sum++;
            }
        }

        if (sum % 3)
        {
            result |= (1 << i);
        }
    }

    return result;
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int ans = singleNumber(nums);

    cout << "Single number is: " << ans << endl;

    return 0;
}