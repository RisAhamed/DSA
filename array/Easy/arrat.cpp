#include <bits/stdc++.h>
using namespace std;

void second_largest(int arr[], int n) {
    if (n < 2) {
        cout << "Array must contain at least two elements." << endl;
        return;
    }

    int largest = INT_MIN;
    int second_largest = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            second_largest = largest; // Update second largest
            largest = arr[i]; // Update largest
        } else if (arr[i] > second_largest && arr[i] != largest) {
            second_largest = arr[i]; // Update second largest if it's not equal to largest
        }
    }

    if (second_largest == INT_MIN) {
        cout << "There is no second largest element." << endl;
    } else {
        cout << largest << " is the largest element." << endl;
        cout << second_largest << " is the second largest element." << endl;
    }
}

void check_sorted(int arr[],int len){
    bool value = true;
    int i;
    for(i=0;i<len-1;i++){
        if (arr[i]> arr[i+1]){
            printf("The Value %d && %d is not sorted",arr[i],arr[i+1]);
            value = false;
            break;
        }
    }
    if (value){
        printf("The array is sorted \n ");

    }
    else{
        printf("The array is not sorted \n");

    }

}

void rotate_array(int arr[],int n){
    int temp = arr[0];
    for (int i=1;i<n;i++){
        arr[i-1] = arr[i];
    }
    arr[n] = temp;
    for (int i=0;i<n;i++){
    cout<< "\n left rotated_Array \n"<<arr[i];}
}

void left_rotate_array_by_k(int arr[],int d,int n){
    d = d%n;

    int temp[d];
    for (int i=0;i<d;i++){
        temp[i] = arr[i];
    }//shifting 
    for (int i =d;i<n;i++ ){
        arr[i-d]  =arr[i]; 
    }
    //replacing
    for (int j= n-d;j<n;j++){
        arr[j]= temp[j-(n-d)];
    }
    cout << "shifted elements" ;
    for(int i=0;i<n;i++){
        printf("%d -->",arr[i]);
    }
    
    }

void move_zeros_to_last_brute(int arr[],int n){
    // int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> temp;
    for (int i=0;i<n;i++){
        if (arr[i]!=0){
            temp.push_back(arr[i]);
        }
    }
    for (int i= 0;i< temp.size();i++){
        arr[i] = temp[i];
    }
    for(int i = temp.size();i<n;i++){
        arr[i] = 0;
    }

    cout << "shifted elements" ;
    for(int i=0;i<n;i++){
        printf("%d -->",arr[i]);
    }
}


vector <int > move_zeros_optimal(vector<int>arr){
    int j =-1;

    int n = arr.size();
    for(int i=0;i<n;i++)
    {
        if (arr[i]==0)
        {
            j=i;
            break;
    }
    }
    if(j==-1) return arr;
    for(int i =j+1;i<n;i++){
        if (arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ->",arr[i]);
    }
    return arr;
}
vector<int>union_of_sorted_array(vector<int> a1,vector<int> b1){
    int a = a1.size();
    int b = b1.size();

    set<int>st;
    for(int i=0;i<a;i++){
        st.insert(a1[i]);

    }
    for (int i=0;i<b;i++){
        st.insert(b1[i]);
    }
    vector<int> temp;
    for(auto it :st){
        temp.push_back(it);
    }
    for(int i=0;i<temp.size();i++){
        cout <<temp[i]<<"-->";
    }
    return temp;
}

vector <int> intersection_of_two_sorted_Array(vector<int> A,int n,vector<int>B ,int m){
    vector<int>ans ;
    int visit[m] = {0};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (A[i] ==B[j] && visit[j]==0){
                ans.push_back(A[i]);
                visit[j] =1;
                break;

            }
            if(B[j]>A[i]) break;
        }
    }
    for(int i=0;i<ans.size();i++){
        cout <<ans[i]<<"-->";
    }
  
    return ans;

}

vector <int> intersection_of_two_sorted_Array_optimal(vector<int> A,int n,vector<int>B ,int m){
    vector<int> ans;
    int i=0;
    int j =0;
    while(i<n && j<m){
        if (A[i]==B[j]){
            ans.push_back(A[i]);
            i++;
            j++;
            }
        else if  (A[i]<B[j]){
            i++;
            }
        else{
            j++;
        }
        

    }
    
    return ans;
}


int getSingleElement(vector<int> &arr){
	// Write your code here.
	
	int n =arr.size();
	int maximum = arr[0];
	for(int i=0;i<n;i++){
		maximum = max(maximum,arr[i]);
	}
	int hash[maximum+1] = {0};
	for (int i=0;i<n;i++){
		hash[arr[i]]++;
	}
	for(int i=0;i<n;i++){
		if (hash[arr[i]]==1){
            cout<<"\n  the single element "<<arr[i];
			// return arr[i];
		}

	}
    
	return  -1;
}

vector<int> two_sum(int target,vector<int>arr){
    vector<int> ans;
    int value = INT_MIN;
    bool flag = true;
    int n = arr.size();
    for(int i=0;i<n;i++){
        
        for (int j=i+1;i<n;i++){
            if (arr[i]+arr[j]==target){
                ans.push_back(arr[i]);
                ans.push_back(arr[j]);
                printf("%d %d\n",arr[i],arr[j]);
                printf("index values %d %d\n",i,j);
                flag = false;
                break;
            }
            

        }
    
    }
    if (flag==true){
        cout<<"No";
        return {-1,-1};
    }
    cout<<"YES";
    return ans;
}

vector<int> two_sum_usingHashing(int target,vector<int>arr){
    int n = arr.size();
    unordered_map<int,int> bucket;
    for (int i=0;i<n;i++){
        int num =arr[i];
        int value = target-num;
        if (bucket.find(value) !=bucket.end()){
            printf("found --->");
            printf("%d ",bucket[value],"%d ",i);

            return {bucket[value],i};
        }
        bucket[num]=i;
        printf( " \n bucket value updated  for num %d  ",num,"i %d \n ",bucket[num]);
    }
    return {-1,-1};

}

int find_element_n(vector<int> arr){
    
    unordered_map<int,int> bucket;
    float  n =arr.size()/2.0;
    for (int i=0;i<arr.size();i++){
        bucket[arr[i]]++;
    }
    for (auto it :bucket){
        printf("%d ,%d \n",it.first,it.second);
        cout<<endl ;
    }

    for (auto it : bucket) {
        if (it.second > n) {
            cout << it.first << " is the element that occurs > n/2" << endl; // Consistent output
            return it.first;
        }
    }
    return -1;
}

vector<int> RearrangebySign(vector<int>arr){
        int n = arr.size();
        vector<int> pos;
        vector<int>neg;
        for(int i=0;i<n;i++){
            if (arr[i]>0) pos.push_back(arr[i]);
            else neg.push_back(arr[i]);
        }
        for(int i=0;i<n/2;i++){
            arr[ 2*i] = pos[i];
            arr[2*i +1] =neg[i];
        }
        cout<<"changed sequence-->";
        for(int i=0;i<n;i++){
            printf("%d ",arr[i]);
           
        }
        return arr;

}
int main() {
    // int arr[5] = {2, 1, 9, 10, 7};
    // int len = sizeof(arr) / sizeof(arr[0]);

    // second_largest(arr, len);
    // int arr1[] = {1,4,2,3,4,5};
    // check_sorted(arr1,len);

    // rotate_array(arr1,len);
    // left_rotate_array_by_k(arr,3,len);
    // int zeros[9] = {0,0,0,1,3,90,0,0,2};
    // int len1 = sizeof(zeros) / sizeof(zeros[0]);
    // move_zeros_to_last_brute(zeros,len1);

    // vector<int > a = {0,1,3,0,4,2,9,2,0};
    
    // move_zeros_optimal(a);
    // cout<<"\n\n";
    // vector<int> a1 = {1,2,4,6,7};
    // vector<int > b = {2,5,6,9,34};
    // union_of_sorted_array(a1,b);
    // cout<<"\n intersection of two sorted array \n";
    // intersection_of_two_sorted_Array(a1,5,b,5);
    // vector<int> ans  = intersection_of_two_sorted_Array_optimal(a1,5,b,5);
    // for (int i=0;i<ans.size();i++){
    //     cout<< ans[i]<<"-->";
    // }
    // vector<int> elements  ={11,3,3,11,9,9,4,1};
    // getSingleElement(elements);
    // vector<int>two_sum_array = {3,2,4};
    // two_sum(6,two_sum_array);
    // vector<int> two_sum_usingHashing_array = {3,8,9,1,2,4};
    // two_sum_usingHashing(10,two_sum_usingHashing_array);
    vector<int> arr={1,1,3,4,5,5,1,3,3,3};
    find_element_n(arr);
    vector<int> sequence = {3,1,-2,-5,2,-4};
    RearrangebySign(sequence);


    return 0;
}