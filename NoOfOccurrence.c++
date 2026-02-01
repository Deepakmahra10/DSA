#include <iostream>
#include <vector>
using namespace std;


int firstOccurrence(vector<int> &arr, int n, int target)
{
    int low = 0, high = n - 1;
    int first = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target){
            first = mid;
            high = mid - 1;
        }   
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return first;
}

int lastOccurrence(vector<int> &arr, int n, int target)
{
    int low = 0, high = n - 1;
    int last = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target){
            last = mid;
            low = mid + 1;
        }   
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return last;
}

pair<int, int> firstAndLastOccurrence(vector<int> &arr, int n, int target)
{
    int first = firstOccurrence(arr, n, target);
    if (first == -1)
        return {-1, -1};
    int last = lastOccurrence(arr, n, target);
    return {first, last};
}

int countOccurrences(vector<int> &arr, int target)
{
    int n = arr.size();
    pair<int, int> ans = firstAndLastOccurrence(arr, n, target);
    if (ans.first == -1)
        return 0;
    return (ans.second - ans.first + 1);
}


int main(){
    vector<int> arr = {1, 2, 2, 2, 3, 4, 5};
    int target = 2;
    int count = countOccurrences(arr, target);
    cout << "Number of occurrences of " << target << " is: " << count << endl;
    return 0;
}