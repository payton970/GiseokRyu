#include "CustomHeap.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>
#include <map>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

//implement a min-priority queue based on an “extended heap” data structure
//Your extended heap should be able to find a contestant with id k in O(1) time.
//Once a contestant node is found, its score can be changed in O(lg n) time.
//To support find() in O(1) time, add a handle array---an additional array that tracks the location of all the items in the extended heap
//A contestant whose id is k resides in heap location handle[k]
//extended_heap & handle_array free 해야된다


CustomHeap::CustomHeap(string input, string output){
    string line;
	ifstream streaming(input);
	while(getline(streaming, line)){
		commands.push_back(line);
	}
    output_title = output;
}


void CustomHeap::spliting(string s, std::vector<string> &v){
	string temp = "";
	for(int i=0;i<s.length();++i){
		if(s[i]==' '){
			v.push_back(temp);
			temp = "";
		}
		else{
			temp.push_back(s[i]);
		}
	}
	v.push_back(temp);
}

void CustomHeap::swapBoth(int index1, int index2){
    iter_swap(extended_heap.begin() + index1, extended_heap.begin() + index2);
    int temp;
    temp = handle_array[extended_heap[index1].first];
    handle_array[extended_heap[index1].first] = handle_array[extended_heap[index2].first];
    handle_array[extended_heap[index2].first] = temp;
}

void CustomHeap::heapExtractMax(int n){
    if(n < 1) return;
    swapBoth(1,extended_heap.size()-1);
    handle_array[extended_heap[extended_heap.size()-1].first] = -1;
    extended_heap.pop_back();
    heapify(extended_heap.size(), 1);
}

void CustomHeap::heapInsert(pair <int,int> key, int n){
    extended_heap.push_back(key);
    //handle_array[extended_heap.size()-1] = key.first;
    handle_array[key.first] = extended_heap.size()-1;
    extended_heap[n].second = INT_MAX;
    heapIncreaseKey(n, key);
}

void CustomHeap::heapIncreaseKey(int i, pair <int,int> key){
    if(key.second > extended_heap[i].second) return;
    extended_heap[i].second = key.second;
    while(i > 1 && extended_heap[i/2].second > extended_heap[i].second){
        swapBoth(i, i/2);
        i = i/2;
    }
}

void CustomHeap::heapUpdateIncreaseKey(int i, pair <int,int> key){
    heapify(extended_heap.size(), i);
}

void CustomHeap::heapUpdateDecreaseKey(int i, pair <int,int> key){
    while(i > 1 && extended_heap[i/2].second > extended_heap[i].second){
        swapBoth(i, i/2);
        i = i/2;
    }
}

void CustomHeap::heapify(int n, int i)
{
    if(i >= extended_heap.size()) return;
    int smallest = i;
    int l = 2 * i;
    int r = 2 * i + 1;
    if (l < n && extended_heap[l].second < extended_heap[smallest].second){
        smallest = l;
    }

    if (r < n && extended_heap[r].second < extended_heap[smallest].second){
        smallest = r;
    }

    if (smallest != i) {
        swapBoth(i, smallest);
        heapify(n, smallest);
    }
}

void CustomHeap::crownHeapify(int n, int i)
{
    int largest = i;
    int l = 2 * i;
    int r = 2 * i + 1;

    if (l < n && extended_heap[l].second > extended_heap[largest].second){
        largest = l;
    }

    if (r < n && extended_heap[r].second > extended_heap[largest].second){
        largest = r;
    }

    if (largest != i) {
        swapBoth(i, largest);
        heapify(n, largest);
    }
}

void CustomHeap::heapSort(int n)
{
    // Build Max Heap
    for (int i = n / 2; i >= 1; i--)
        crownHeapify(n, i);

    for (int i = n - 1; i >= 2; i--) {
        swapBoth(1, i);
        crownHeapify(i-1, 1);
    }
}

void CustomHeap::printArray(std::vector<pair <int,int> > heap, int n)
{
    for (int i = 0; i < n; ++i)
        cout << heap[i].first << " " << heap[i].second << "\n";
    cout << "\n";
}

void CustomHeap::startGame(){

    ofstream file;
    file.open(output_title);
    std::vector<string> split_str;
    extended_heap.push_back(make_pair(-1,-1)); //Since index 0 is not used, put garbage value

    //Loop each line in input text file
    for(int i = 0; i < commands.size(); i++){
        string command = commands.at(i);
        if(i == 0){
            int size = stoi(command) + 1;
            handle_array = (int *) malloc (size * sizeof (int));
            for(int i = 0; i < size; i++){
                handle_array[i] = -1;
            }
            max_size = size;
            continue;
        }
        command.erase(std::remove(command.begin(), command.end(), '<'), command.end()); //remove < from string
        command.erase(std::remove(command.begin(), command.end(), '>'), command.end()); //remove > from string

        if(split_str.size() > 0)split_str.clear();
        spliting(command, split_str);

        //Go to the right function
        if(split_str.at(0).find("find") != string::npos){
            findContestant(stoi(split_str.at(1)), file);
        }else if(split_str.at(0).find("insert") != string::npos){
            insertContestant(stoi(split_str.at(1)), stoi(split_str.at(2)), file);
        }else if(split_str.at(0).find("eliminate") != string::npos){
            eliminateWeakest(file);
        }else if(split_str.at(0).find("earn") != string::npos){
            earnPoints(stoi(split_str.at(1)), stoi(split_str.at(2)), file);
        }else if(split_str.at(0).find("lose") != string::npos){
            losePoints(stoi(split_str.at(1)), stoi(split_str.at(2)), file);
        }else if(split_str.at(0).find("showC") != string::npos){
            showContestants(file);
        }else if(split_str.at(0).find("showH") != string::npos){
            showHandles(file);
        }else if(split_str.at(0).find("showL") != string::npos){
            showLocation(stoi(split_str.at(1)), file);
        }else if(split_str.at(0).find("crown") != string::npos){
            crownWinner(file);
        }else{
            cout << "Invalid" << endl;
        }
    }

    file.close();
    free(handle_array);
}
void CustomHeap::findContestant(int k, std::ofstream& file){
    file << "findContestant <" << k << ">" << endl;
    if(handle_array[k] < 0 || k >= extended_heap.size()){
        file << "Contestant <" << k << "> is not in the extended heap." << endl;
    }else{
        file << "Contestant <" << k << "> is in the extended heap with score <" << extended_heap[handle_array[k]].second << ">." << endl;
    }
}
void CustomHeap::insertContestant(int k, int s, std::ofstream& file){
    file << "insertContestant <" << k  << "> <" << s << ">" << endl;
    if(extended_heap.size() >= max_size){
        file << "Contestant <" << k << "> could not be inserted because the extended heap is full." << endl;
        return;
    }else if(handle_array[k] > 0){
        file << "Contestant <" << k << "> is already in the extended heap: cannot insert." << endl;
        return;
    }else{
        heapInsert(make_pair(k,s), extended_heap.size());
        file << "Contestant <" << k << "> inserted with initial score <" << s  << ">." << endl;
        return;
    }
}

void CustomHeap::eliminateWeakest(std::ofstream& file){
    file << "eliminateWeakest" << endl;
    if(extended_heap.size() <= 1){
        file << "No contestant can be eliminated since the extended heap is empty" << endl;
    }else{
        pair<int, int> temp = extended_heap.at(1);
        int id = temp.first;
        int value = temp.second;
        heapExtractMax(extended_heap.size());
        file << "Contestant <" << id << "> with current lowest score <" << value << "> eliminated." << endl;
    }
}

void CustomHeap::earnPoints(int k, int p, std::ofstream& file){
    file << "earnPoints <" << k  << "> <" << p << ">" << endl;
    if(handle_array[k] == -1){
        file << "Contestant <" << k << "> is not in the extended heap." << endl;
    }else{
        pair <int, int> temp_pair = extended_heap.at(handle_array[k]);
        extended_heap.at(handle_array[k]).second += p;
        heapUpdateIncreaseKey(handle_array[k], temp_pair);
        file << "Contestant <" << k << ">'s score increased by <" << p << "> points to <" << extended_heap[handle_array[k]].second << ">." << endl;
    }
}

void CustomHeap::losePoints(int k, int p, std::ofstream& file){
    file << "losePoints <" << k  << "> <" << p << ">" << endl;
    if(handle_array[k] == -1){
        file << "Contestant <" << k << "> is not in the extended heap." << endl;
    }else{
        pair <int, int> temp_pair = extended_heap.at(handle_array[k]);
        extended_heap.at(handle_array[k]).second -= p;
        heapUpdateDecreaseKey(handle_array[k], temp_pair);
        file << "Contestant <" << k << ">'s score decreased by <" << p << "> points to <" << extended_heap[handle_array[k]].second << ">." << endl;
    //             cout << "This is k " << k << endl;
    //     cout << "This is handle_array[k] " << handle_array[k] << endl;
    //     cout << "size of extended: " << extended_heap.size() << endl;
    //         printArray(extended_heap, extended_heap.size());
    // cout << "handle Array" << endl;
    // for(int i = 0; i < max_size; i++){
    //     cout << handle_array[i] << endl;
    // }
    // cout << "" << endl;
    }
}
void CustomHeap::showContestants(std::ofstream& file){
    file << "showContestants" << endl;
    for(int i = 1; i < extended_heap.size(); i++){
        file << "Contestant <" << extended_heap[i].first << "> in extended heap location <" << i << "> with score <" << extended_heap[i].second << ">." << endl;
    }
}

void CustomHeap::showHandles(std::ofstream& file){
    file << "showHandles" << endl;
    for(int i = 1; i < max_size; i++){
        if(handle_array[i] == -1){
            file << "There is no Contestant <" << i << "> in the extended heap: handle[<" << i << ">] = -1." << endl;
        }else{
            file << "Contestant <" << i << "> stored in extended heap location <" << handle_array[i] << ">." << endl;
        }
    }
}
void CustomHeap::showLocation(int k, std::ofstream& file){
    file << "showLocation <" << k << ">" << endl;
    if(k >= extended_heap.size() || handle_array[k] == -1){
        file << "There is no Contestant <" << k << "> in the extended heap: handle[<" << k << ">] = -1." << endl;
    }else{
        file << "Contestant <" << k << "> stored in extended heap location <" << handle_array[k] << ">." << endl;
    }
}
void CustomHeap::crownWinner(std::ofstream& file){
    file << "crownWinner" << endl;
    heapSort(extended_heap.size());
    // printArray(extended_heap, extended_heap.size());
    // cout << "handle Array" << endl;
    // for(int i = 0; i < max_size; i++){
    //     cout << handle_array[i] << endl;
    // }
    pair <int,int> temp = extended_heap.at(extended_heap.size()-1);
    for(int i = 0; i < max_size; i++){
        handle_array[i] = -1;
    }
    extended_heap.resize(2);
    extended_heap[1] = temp;
    handle_array[extended_heap[1].first] = 1;
    file << "Contestant <" << temp.first << "> wins with score <" << temp.second << ">!" << endl;
}