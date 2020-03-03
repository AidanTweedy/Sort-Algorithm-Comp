#include <iostream>
#include <stdio.h> 
#include <stdlib.h>
#include <time.h> 
#include <algorithm>
#include <chrono> 
#include <thread>

using namespace std;
using namespace std::chrono;
using namespace std::this_thread;

static int ARR_SIZE = 256;

void print_array(int arr[]){
    cout << "\n";
    for(int i = 0; i < ARR_SIZE-1; i++){
        cout << arr[i] << ", ";
    }
    cout << "\n";
}

int main(){
    char print;
    static int arr[256];
    srand(time(0));
    for(int i = 0; i < ARR_SIZE-1; i++){
        arr[i] = rand();
    }
#ifndef BUBBLE_SORT
    {
        cerr << "\nBUBBLE SORT\n "<< endl;
        cout << "Press Enter to begin sort...";
        cin.ignore();
        int arrCOPY[256];
        copy(begin(arr), end(arr), begin(arrCOPY));
        int done = 1;
        int count = 0;
        auto start = high_resolution_clock::now();
        while(done == 1){
            count = 0;
            for(int i = 0; i < ARR_SIZE-1; i++){
                if(arrCOPY[i] > arrCOPY[i+1]){
                    swap(arrCOPY[i], arrCOPY[i+1]);
                    count++;
                }
            }
            if(count == 0){
                done = 0;
            }
        }
        auto stop = high_resolution_clock::now();
        cout << "Sort Done...\nPrint Array?(y/n): \n";
        cin >> print;
        if(print == 'y'){
            print_array(arrCOPY);
        }
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "\nTIME TO SORT: " << duration.count() << " μs == " << (double(duration.count()))/10000000 << " sec\n" <<  endl;
        cerr << "\n\t========================BUBBLE SORT COMPLETE========================\n" << endl;
        cout << "Proceeding to next sorting method...\n";
        sleep_until(system_clock::now() + seconds(1));
    }
#endif
#ifndef SELECTION_SORT
    {
        cerr << "\nSELECTION SORT\n "<< endl;
        sleep_until(system_clock::now() + seconds(1));
        int arrCOPY[256];
        copy(begin(arr), end(arr), begin(arrCOPY));
        int done = 1;
        auto start = high_resolution_clock::now();
        while(done == 1){
            for(int i = 0; i < ARR_SIZE-1; i++){
                int iMin = i;
                for(int k = i + 1; k < ARR_SIZE; k++){
                    if(arrCOPY[k] < arrCOPY[iMin]){
                        iMin = k;
                    }
                    swap(arrCOPY[i], arrCOPY[iMin]);
                }
            }
            done = 0;
        }
        auto stop = high_resolution_clock::now();
        cout << "Sort Done...\nPrint Array?(y/n): \n";
        cin >> print;
        if(print == 'y'){
            print_array(arrCOPY);
        }
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "\nTIME TO SORT: " << duration.count() << " μs == " << (double(duration.count()))/10000000 << " sec\n" <<  endl;
        cerr << "\n\t========================SELECTION SORT COMPLETE========================\n" << endl;
        cout << "Proceeding to next sorting method...\n";
        sleep_until(system_clock::now() + seconds(1));
    }
#endif
#ifndef GNOME_SORT
    {
        cerr << "\nGNOME SORT\n "<< endl;
        sleep_until(system_clock::now() + seconds(1));
        int arrCOPY[256];
        copy(begin(arr), end(arr), begin(arrCOPY));
        int index = 0;
        auto start = high_resolution_clock::now();
        while(index < ARR_SIZE){
            if(index == 0){
                index++;
            }
            if(arrCOPY[index] >= arrCOPY[index-1]){
                index++;
            }else{
                swap(arrCOPY[index], arrCOPY[index-1]);
                index--;
            }
        }
        auto stop = high_resolution_clock::now();
        cout << "Sort Done...\nPrint Array?(y/n): \n";
        cin >> print;
        if(print == 'y'){
            print_array(arrCOPY);
        }
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "\nTIME TO SORT: " << duration.count() << " μs == " << (double(duration.count()))/10000000 << " sec\n" <<  endl;
        cerr << "\n\t========================GNOME SORT COMPLETE========================\n" << endl;
        cout << "Proceeding to next sorting method...\n";
        sleep_until(system_clock::now() + seconds(1));
    }
#endif
}