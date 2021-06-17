#include<bits/stdc++.h>
using namespace std;
//分割点被置于数组的末尾
    int partition(vector<int>& nums,int begin,int end)
    {
        int pivot = nums[end];
        int left = begin;
        for(int i = begin;i < end;i++)
        {
            if(nums[i] < pivot)
            {
                swap(nums[i],nums[left]);
                left++;
            }
        }
        swap(nums[left],nums[end]);
        return left;//返回分割点最后所处位置
    }
    //随机选择分割点
    int rand_index(vector<int> &nums,int begin,int end)
    {
        int index = rand() % (end - begin + 1) + begin;
        swap(nums[index],nums[end]);
        return partition(nums,begin,end);
    }
    //快速排序
    void quicksort(vector<int> &nums,int begin,int end)
    {
        if(begin < end)
        {
            int pos = rand_index(nums,begin,end);
            quicksort(nums,begin,pos - 1);
            quicksort(nums,pos + 1,end);
        }
    }
int main()
{
    ifstream in("data_in.txt");//待排序的数据，第一行为数据的个数
    int num;
    in >> num;
    //待排序的数组
    vector<int> nums(num);
    for(int i = 0;i < num;i++)
    {
        in >> nums[i];
    }
    quicksort(nums,0,num - 1);
    ofstream out("data_out.txt");//输出已经排序的数据
    out << num << endl;
    for(int i = 0;i < num;i++)
    {
        out << nums[i] << " ";
    }
    return 0;
}