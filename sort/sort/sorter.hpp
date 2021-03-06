//
//  sorter.hpp
//  sort
//
//  Created by Jorge Becker on 8/31/20.
//  Copyright © 2020 Jorge Becker. All rights reserved.
//

//#ifndef sorter_hpp
#define sorter_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace::std;


template <typename T>// clase papa para intercambiar resultados
class Sorter
{
    public:
    Sorter() {};
    ~Sorter() {};

    void swap(int i, int j, std::vector<T> &arr)
    {
        T aux = arr[i];
        arr[i] = arr[j];
        arr[j] = aux;
    };

    virtual void sort(std::vector<T> &arr) {};
};


template <typename T>
class SelectionSort : public Sorter<T>//clase para la implementacion de selection sort
{
    public:
    SelectionSort() {};
    ~SelectionSort() {};

    void sort(std::vector<T> &arr)
    {
        for (size_t i = 0; i < arr.size() - 1; i++)
        {
            size_t min = i;
            for (size_t j = i+1; j < arr.size(); j++)
            {
                if (arr[j] < arr[min])
                    min = j;
            }
            Sorter<T>::swap(i, min, arr);
        }
    };
};

template <typename T>
class BubbleSort : public Sorter<T>// clase para la implementacion de bubble sort
{
    public:
    BubbleSort() {};
    ~BubbleSort() {};
    bool no_swap;
    void sort(std::vector<T> &arr)
    {
        for (size_t i = 0; i < arr.size(); i++)
        {
            no_swap = true;
            for (size_t j = 0; j < arr.size() - i-1; j++)
            {
                if (arr[j] > arr[j+1]) {
                    Sorter<T>::swap(j, j+1, arr);
                    no_swap = false;
                }
            }
            if (no_swap)
                break;
        }
    };
};


    
    template<typename T>
    class InsertionSort : public Sorter<T> //clase para la implementacion de insertion sort
    {
        public:
        InsertionSort(){};
        ~InsertionSort(){};
        
        void sort(std::vector<T> &arr)
        {
            T key;
            for (size_t i = 1; i < arr.size(); i++)
            {
                key = arr[i];
                int j = i-1;
                while (j >=0 && arr[j]>key)
                {
                    arr[j+1] = arr[j];
                    j--;
                }
                arr[j+1];
            }
        };
    };



template <typename T>
class MergeSort : public Sorter<T>
{
    public:
    MergeSort() {};
    ~MergeSort() {};

    void sort(std::vector<T> &arr)
    {
        mergesort(arr, 0, arr.size()-1);
    };

    // 1 3 5 2 7 4 6 2 0
    // 0 1 2 3 4 5 6 7 8
    void mergesort(std::vector<T> &arr, int l, int r)
    {
        if (l < r) {
            // Same as (l+r)/2, but avoids overflow for
            // large l and h
            int m = l + (r-l) / 2;
            
            // Sort first and second halves
            mergesort(arr, l, m);
            mergesort(arr, m+1, r);

            merge(arr, l, m, r);
        }
    }

    // 1 3 5 1 2 4 0 5 6 7 4 6 2 0
    // - - - l - m - - r - - - - -
    // L = [1 2 4], R = [0 5 6]
    void merge(std::vector<T> &arr, int l, int m, int r)
    {
        size_t i, j, k;
        size_t n1 = m - l + 1;
        size_t n2 = r - m;
      
        /* create temp arrays */
        T L[n1], R[n2];
      
        /* Copy data to temp arrays L[] and R[] */
        for (i = 0; i < n1; i++)
            L[i] = arr[l + i];
        for (j = 0; j < n2; j++)
            R[j] = arr[m + 1 + j];
      
        /* Merge the temp arrays back into arr[l..r]*/
        i = 0; // Initial index of first subarray
        j = 0; // Initial index of second subarray
        k = l; // Initial index of merged subarray
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
      
        /* Copy the remaining elements of L[], if there
           are any */
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }
      
        /* Copy the remaining elements of R[], if there
           are any */
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    };
};

template<typename T>
class QuickSort : public Sorter<T> //clase para la implementacion de Quick Sort
{
    public:
    QuickSort(){};
    ~QuickSort(){};
    
    void sort(std::vector<T> &arr)
    {
        quicksort(arr, 0, arr.size()-1);
        
    };
    void quicksort(std::vector<T> &arr, int low, int high)
    {
        if(low < high)
        {
            int piv = partition(arr,low,high);
            
            quicksort(arr, low, piv-1);
            quicksort(arr,piv+1,high);
        }
    };
    int partition(vector<T> &arr, int low, int high)
    {
        T pivot =arr[high];
        int i = low - 1;
        for (int j = low ; j < high; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                Sorter<T>::swap(i,j,arr);
            }
            
        }
        Sorter<T>::swap(i+1, high, arr);
        return (i+1);
        
    };
};
