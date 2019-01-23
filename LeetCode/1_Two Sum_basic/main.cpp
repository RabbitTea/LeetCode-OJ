#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> results;

        sort(nums.begin(),nums.end());

        for(unsigned int i=0;i<nums.size();i++){
            for(unsigned int j=i+1;j<nums.size();j++){
                if((nums[i]+nums[j]) > target){
                   break;
                }
                else if((nums[i]+nums[j]) == target){
                    results.push_back(i);
                    results.push_back(j);
                }
                else
                    continue;
            }
        }

        return results;
}

int main()
{
    vector<int> nums;
    vector<int> results;
    int num;
    int target;

    cout << "请输入数组中的元素,以换行符结束：" << endl;
    while((cin.get()) != '\n'){
        cin.unget();
        nums.push_back(num);
        cin >> num;
    }

    cout << "请输入目标值：" << endl;
    cin >> target;

    results = twoSum(nums,target);
    int count = results.size();
    for(int i=0;i<count;i++){
        cout << results[i] << " ";
    }
    return 0;
}
