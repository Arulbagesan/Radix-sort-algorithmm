#include<iostream> 
#include<cstdlib>
#include<ctime>
using namespace std; 

int getMax(int arr[], int n) 
{ 
    int mx = arr[0]; 
    for (int i = 1; i < n; i++) 
        if (arr[i] > mx) 
            mx = arr[i]; 
    return mx; 
} 

void countSort(int arr[], int n, int exp) 
{ 
    int output[n];
    int i, count[10] = {0}; 
   
    for (i = 0; i < n; i++) 
        count[ (arr[i]/exp)%10 ]++; 
  
    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 

    for (i = n - 1; i >= 0; i--) 
    { 
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
        count[ (arr[i]/exp)%10 ]--; 
    } 
  
    for (i = 0; i < n; i++) 
        arr[i] = output[i]; 
} 

void print(int arr[], int n) 
{ 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
} 

void radixsort(int arr[], int n) 
{ 

    int m = getMax(arr, n); 
    //cout<<"Max element : "<<m<<endl<<endl;
    for (int exp = 1; m/exp > 0; exp *= 10)
    {
        cout<<"Before count sort on "<<exp<<" digit"<<endl;
        print(arr,n);
        cout<<endl;
        countSort(arr, n, exp);
        cout<<"After count sort on "<<exp<<" digit"<<endl;
        print(arr,n);
        cout<<endl<<endl;
    } 
} 


int main(int argc, char *argv[]) 
{ 
    int arr[10000]; //Change this value too if need more array size
    srand(time(0));
    int n = 100;
    cout<<"For n="<<n<<"\n\n";
    for(int i = 0;i<n;i++)
    {
        arr[i] = (rand()%1000); //for 3 digit random number
    }
    radixsort(arr, n);
    return 0; 
}
