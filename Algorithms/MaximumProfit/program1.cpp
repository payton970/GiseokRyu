#include <fstream>
#include <sstream>
#include <iostream>
#include <ctime>
#include <unistd.h>
#include <vector>
#include <map>
#include <algorithm>
 
using namespace std;

void checkingMap(map<string, int> &mPMap){
	map<string, int>::iterator itr;
    cout << "\tKEY\tELEMENT\n";
    for (itr = mPMap.begin(); itr != mPMap.end(); ++itr) {
        cout << '\t' << itr->first << '\t' << itr->second
             << '\n';
    }
    cout << endl;
}

void spliting(string s, vector<string> &v){
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

void updateVector(string str, vector<string> &vec){
	string line;
	ifstream streaming(str);
	while(getline(streaming, line)){
		vec.push_back(line);
	}
}

bool containsOnlyNumbers(std::string const &str) {
    return str.find_first_not_of("0123456789") == std::string::npos;
}

int totalProfits(vector<string> subset){
	int total = 0;
	for(int i = 0; i < subset.size(); i++){
		string temp = subset.at(i);
		vector<string> temp_vec;
		spliting(temp, temp_vec);
		total += stoi(temp_vec[1]);
	}
	return total;
}

void subsetsHelper(vector<string>& A, vector<vector<string> >& res, vector<string>& subset, int index, int max_profits){
	if(max_profits < totalProfits(subset)) return;
    res.push_back(subset);
    for (int i = index; i < A.size(); i++) {
        subset.push_back(A[i]);
        subsetsHelper(A, res, subset, i + 1, max_profits);
        subset.pop_back();
    }
    return;
}
 
vector<vector<string>> subsets(vector<string>& A, int max_profits){
    vector<string> subset;
    vector<vector<string>> res;
    int index = 0;
    subsetsHelper(A, res, subset, index, max_profits);
    return res;
}

int main(int argc, char* argv[]){
	
	/* Getting Input File */
    const char *optstring = "m:p:";
	string market_price, price_list;
	int o ;

	while((o = getopt(argc, argv, optstring)) != -1){
		switch (o)
		{
			case 'm':
				market_price = argv[2];
				break;
			
			case 'p':
				price_list = argv[4];
				break;

			case '?':
				cout << "This is wrong" << endl;
		}
	}
	vector<string> m_vec;
	vector<string> p_vec;
	updateVector(market_price, m_vec);
	updateVector(price_list, p_vec);
	/* Getting Input File */


	/* Put Market Price to Map */
	map<string, int> mp_map;

	//i=0 is total number of cards, so don't need it
	for(int i = 1; i < m_vec.size(); i++){
		string temp = m_vec.at(i);
		vector<string> temp_vec;
		spliting(temp, temp_vec);
		mp_map[temp_vec.at(0)] = stoi(temp_vec.at(1)); 
	}

	/* Put Market Price to Map */


	/* Dividing Price List to each single problem */
	vector<vector<string>> list_of_problems;
	vector<string> single_problem_vec;
	for(int i = 0; i < p_vec.size(); i++){
		string temp = p_vec.at(i);
		vector<string> temp_vec;
		spliting(temp, temp_vec);
		if(containsOnlyNumbers(temp_vec.at(0))){
			list_of_problems.push_back(single_problem_vec);
			single_problem_vec.clear();
			single_problem_vec.push_back(temp);
			
		}else{
			single_problem_vec.push_back(temp);
		}		
	}
	if(!single_problem_vec.empty()) list_of_problems.push_back(single_problem_vec);
	/* Dividing Price List to each single problem */

	clock_t t = clock();
	ofstream file;
	file.open ("output.txt");
	
	for(int i = 0; i < list_of_problems.size(); i++){
		//Initial Setting
		vector<string> single_problem = list_of_problems.at(i);
		if(single_problem.empty()) continue; //list_of_problems's first map is empty so need condition
		clock_t t = clock();
		int max_profits = 0; //W
		int num_cards = 0;
		vector<string> temp_vec;
		spliting(single_problem.at(0), temp_vec);
		int input_size = stoi(temp_vec[0]);
		int max_cost = stoi(temp_vec[1]);
		single_problem.erase(single_problem.begin()); //Since we stored max_cost, don't need it anymore

		//Make all the possible sets
		vector<vector<string>> all_subset = subsets(single_problem, max_cost);

		//Looping all the possible sets & Update max_profit
		for(int j = 0; j < all_subset.size(); j++){
			if(all_subset.at(j).size() == 0){
				//cout << "" << endl;
				continue;
			}

			int cur_profits = 0;
			vector<string> cur_vec = all_subset.at(j);
			for(int i = 0; i < cur_vec.size(); i++){
				string temp = cur_vec.at(i);
				vector<string> temp_vec_inside;
				spliting(temp, temp_vec_inside);
				
				cur_profits += mp_map.at(temp_vec_inside[0]) - stoi(temp_vec_inside[1]);
			}

			if(cur_profits > max_profits){				
				max_profits = cur_profits;
				num_cards = cur_vec.size();
			}
		}
		// Stop the clock
		t = clock() - t;
		file << input_size << " " << max_profits << " " << num_cards << " " << static_cast<float>(t)/CLOCKS_PER_SEC << "sec\n";
	}
	file.close();
	/* Making output file and run all problem */

    return 0;
}

