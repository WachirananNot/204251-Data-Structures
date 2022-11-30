#include <iostream>
using namespace std;
class Ranking{
private:
    int data[1000];
    int temp[1000];
    int size;
public:
    Ranking(int n){
        size = n;
    }
    void inputData(){
        for(int i=0;i<size;i++){
            cin>>data[i];
        }
    }
    int binarySearch(int key){
        int low = 0;
        int hi = size-1;
        int mid;
        while(low<=hi){
            mid = (low+hi)/2;
            if(key == data[mid]){
                return mid+1;
            }else{
                if(key<data[mid]){
                    low = mid+1;
                }else{
                    hi = mid-1;
                }
            }
        }
        return NULL;
    }
    void merge(int left, int mid, int right){
        int i,left_end,num_elements,tmp_pos;
        left_end = mid-1;
        tmp_pos = left;
        num_elements = right-left+1;
        while((left<=left_end)&&(mid<=right)){
            if (data[left] >= data[mid]){
                temp[tmp_pos] = data[left];
                tmp_pos += 1;
                left += 1;
            }else{
                temp[tmp_pos] = data[mid];
                tmp_pos += 1;
                mid += 1;
            }
        }
        while(left <= left_end){
            temp[tmp_pos] = data[left];
            tmp_pos += 1;
            left += 1;
        }
        while (mid <= right)
        {
            temp[tmp_pos] = data[mid];
            tmp_pos += 1;
            mid += 1;
        }

        for(i=0;i<num_elements;i++){
            data[right] = temp[right];
            right -= 1;
        }
        
    }
    void mergeSort(int left, int right){
        int mid;
        if(right>left){
            mid = (right+left)/2;
            mergeSort(left,mid);
            mergeSort(mid+1,right);
            merge(left,mid+1,right);
        }
	}
    int show(int index){
        return data[index-1];
    }
};

