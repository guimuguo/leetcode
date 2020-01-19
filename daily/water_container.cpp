#include<iostream>
#include<vector>
using namespace std;
class water_container{
public:
    int wc_cal(vector<int>& height){
    	int i = 0;
		int j = height.size() - 1;
		int max_size = (j-i)*min(height[i],height[j]);
		int cur_size = 0;
		bool flag = 0; //0 means left and 1 means right
		if(height[i] > height[j])
			flag = 1;
		while(i < j){
			if(flag == 0){
				i++;
				if(i < j && height[i] > height[i-1]){
					if(height[i] > height[j])
						flag = 1;
					cur_size = (j-i)*min(height[i],height[j]);
					if(cur_size > max_size)
						max_size = cur_size;
				}
			}else{
				j--;
				if(i < j && height[j] > height[j+1]){
					if(height[i] < height[j])
					flag = 0;
					cur_size = (j-i)*min(height[i],height[j]);
					if(cur_size > max_size)
						max_size = cur_size;
				}
			}
		}
		return max_size;
    }
};
int main(int argc, char* argv[]){
	vector<int> height = {1,2,4,3};
	water_container wc;
	cout<<wc.wc_cal(height);
    return 0;
}
