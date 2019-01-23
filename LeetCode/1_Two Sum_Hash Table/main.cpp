#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> twosum(vector<int>& nums,int target)
{
    vector<int> results;
    int key;
    map<int,int> hashmap;
    for(unsigned int i=0;i<nums.size();i++){
        key = nums[i];
        if(hashmap.find(target - key) != hashmap.end()){
            int temp = hashmap[target - key];
            results.push_back(temp);
            results.push_back(i);
        }
        hashmap[key] = i;
    }
    return results;
}

int main()
{
    vector<int> nums;
    vector<int> results;
    int num;
    int target;

    cout << "请输入数组中的元素，以换行符结束：" << endl;
    while((cin.get()) != '\n'){
        cin.unget();
        cin >> num;
        nums.push_back(num);
    }

    cout << "请输入目标值:" << endl;
    cin >> target;

    results = twosum(nums,target);

    for(unsigned i=0;i<results.size();i++){
        cout << results[i] << " ";
    }
    return 0;
}
