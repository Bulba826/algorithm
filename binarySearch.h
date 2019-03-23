#include <iostream>
#include <vector>
using namespace std;
class BinarySearch{
public:    
    int binarySearch(const vector<int>& a, int target){
        return binarySearchRecursive(a, 0, a.size()-1, target);
    }
private:    
    int binarySearchRecursive(const vector<int>& a, int start, int end, int target){
        if(start > end) return -1;//终止条件：头比尾大
        int mid = start + (end - start) / 2; // preventing overflow
        if(a.at(mid) == target) return mid;
        else if(a.at(mid) < target) return binarySearchRecursive(a, mid + 1, end, target);
        else return binarySearchRecursive(a, start, mid - 1, target);
    }
    int binarySearchIterative(const vector<int>& a, int target){
        front = 0;
        rear = a.size() - 1;
        while(front<=rear){
            mid = front + (rear - front) / 2;
            if(a.at(mid) == target) return mid;
            else if(a.at(mid) < target) front = mid + 1;
            else rear = mid - 1;
        }
        return -1;
    }
    int front, rear, mid;
};
