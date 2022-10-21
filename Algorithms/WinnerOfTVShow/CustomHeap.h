#ifndef CUSTOMHEAP_H
#define CUSTOMHEAP_H
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>
#include <map>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

class CustomHeap{

    private:
        std::vector<pair <int,int> > extended_heap; //ID, Score
        int *handle_array; //Index = ID, Value = extended_heap index
        vector<string> commands; //Each line from inpute file     
        string output_title; //Name of the output text file
        int max_size; //Max size of vector & array
    public:
        CustomHeap(std::string input, std::string output); //Receive input & output to start the program
        void spliting(string s, vector<string> &v); //Split string into word, returning vector
        void swapBoth(int index1, int index2); //Swap extended_heap & handle_array value
        void heapExtractMax(int n); //Extract the root from the extended_hap and do heapify to maintain min-heap property
        void heapInsert(pair <int,int> key, int n); //Insert new Contestant into extended_heap & heap
        void heapIncreaseKey(int i, pair <int,int> key); //Helper function of heapInsert
        void heapUpdateIncreaseKey(int i, pair <int,int> key); //Apply when one of the value earn points
        void heapUpdateDecreaseKey(int i, pair <int,int> key); //Apply when one of the value take off points
        void heapify(int n, int i); //heapify function
        void crownHeapify(int n, int i); //Sort the extended_hep in increasing order to find the winner and keep only winner in extended_heap
        void heapSort(int n); //Sort the extended_hep in increasing order to find the winner and keep only winner in extended_heap
        void printArray(vector<pair <int,int> > heap, int n); //Check function to make sure the list is ordered properly
        void startGame(); //This function is the main function which loop all the command line in input text file, and execute the right function for each command line.
        void findContestant(int k,std::ofstream& file); //Find Contestant in O(1) time
        void insertContestant(int k, int s,std::ofstream& file); //Insert Contestant
        void eliminateWeakest(std::ofstream& file); //Eliminate the weakest contestant
        void earnPoints(int k, int p, std::ofstream& file); //Update the Contestant who earned points
        void losePoints(int k, int p, std::ofstream& file); //Update the Contestant who lost points
        void showContestants(std::ofstream& file); //Show all the contestants with scores
        void showHandles(std::ofstream& file); //Show all the contestants with heap location
        void showLocation(int k, std::ofstream& file); //Show certain the contestants with heap location
        void crownWinner(std::ofstream& file); //Show the winner of the game
};

#endif