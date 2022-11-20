#include<bits/stdc++.h>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;

    heap()
    {
        arr[0]=-1;
        size=0;
    }

    int parent(int i)
    {
        return i/2;
    }
    int left(int i)
    {
        return 2*i;
    }
    int right(int i)
    {
        return 2*i + 1;
    }

    // TC=O(logN)
    void insert(int val)
    {
        size++;
        int index=size;
        arr[index]=val;

        while(index>1 and arr[parent(index)]<arr[index])
        {
            swap(arr[parent(index)], arr[index]);
            index=parent(index);
        }
    }

    // TC=O(logN)
    void deletefromheap()
    {
        if(size==0)
        {
            cout<<"Heap is empty"<<endl;
            return;
        }

        arr[1]=arr[size];
        size--;

        int index=1;
        while(index<size)
        {
            if(left(index)<size and arr[left(index)] > arr[index])
            {
                swap(arr[left(index)], arr[index]);
                index=left(index);
            }
            else if(right(index)<size and arr[right(index)] > arr[index])
            {
                swap(arr[right(index)], arr[index]);
                index=right(index);
            }
            else
                return;
        }
    }

    void print()
    {
        for(int i=1;i<=size;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
};


//TC=O(N) but it should be O(NlogN) interesting
// https://youtu.be/rBRItn-P6n4 PROOF
void heapify(int arr[], int n, int i)
{
    int largest=i;
    int leftnode=2*i;
    int rightnode=2*i+1;

    if(leftnode<=n and arr[largest]<arr[leftnode])
    {
        largest=leftnode;
    }
    if(rightnode<=n and arr[largest]<arr[rightnode])
    {
        largest=rightnode;
    }

    if(largest!=i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

// TC=O(NlogN)
// heapsort(asc) -> build the max heap -> heapsort
void heapsort(int arr[], int n)
{
    int size=n;
    while(size>1)
    {
        swap(arr[size], arr[1]);
        size--;
        heapify(arr, size, 1);
    }
}

int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    h.deletefromheap();
    h.print();

    int arr[]={-1, 54, 53, 55, 52, 50};
    int n=5;
    for(int i=n/2;i>0;i--)
    {
        heapify(arr, n, i);
    }
    cout<<"After heapify"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    heapsort(arr, n);
    cout<<"After heap sort"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
}