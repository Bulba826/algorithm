#include <iostream>
#include <vector>
using namespace std;

class QuickSort{
    public:
        int partition(const vector<int>& array, int left, int right, int pivot){
            while(left<=right){
                while(array[left]<pivot) left++; 
                while(array[right]>pivot) right--;
                if(left<=right){
                    swap(left, right);
                    left++;
                    right--;
                }
            }
        }
        void quickSort(const vector<int>& array){
            quickSort(array, 0, array.size() - 1);
        }
        void quickSort(const vector<int>& array, int left, int right){
            if(left>=right) return;
            int pivot = array[(left + right) / 2];
            int index = partition(array, left, right, pivot);
            quickSort(array, left, index - 1);
            quickSort(array, index + 1,right);
        }
    private:
}
