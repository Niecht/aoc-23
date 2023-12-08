#include <iostream>
#include <string_view>
using std::string_view;
#include <map>
using std::map;
#include <fstream>
using std::ifstream;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <iterator>
using std::istream_iterator;
#include  <algorithm>
using std::copy;
    
int part1(vector<string> lines){
    int sum = 0;
    int line_value = 0;
    
    for(auto i : lines){
    for(char& c : i){
        if (isdigit(c)) {
            line_value += ( c - '0' ) *10;
            break;
        }
    }
    for(int j = i.length()-1; j >=0; j--) {
        if (isdigit(i[j])) {
            line_value += ( i[j] - '0' );
            break; 
        }
    }
    sum += line_value;
    line_value = 0; 
    }

    return sum;

}

int find_number_in_string(string_view input_line) {
    map<string, int> str_int_map;
    str_int_map["one"] = 1;
    str_int_map["two"] = 2;
    str_int_map["three"] = 3;
    str_int_map["four"] = 4;
    str_int_map["five"] = 5;
    str_int_map["six"] = 6;
    str_int_map["seven"] = 7;
    str_int_map["eight"] = 8;
    str_int_map["nine"] = 9;

    for (auto [key, val] : str_int_map) {
        auto found = input_line.find(key);
        if (found != string::npos){
            return val;
        }
    }
    return 0;
}

int part2(vector<string> lines){
    int sum = 0;
    int line_value = 0;

    for(auto i : lines){
    for(int j = 0; j < i.length(); j++ ){
        if (isdigit(i[j])) {
            line_value += ( i[j] - '0' ) *10;
            break;
        } else {
            string_view view = string_view(i).substr(0, j+1);
            int string_number = find_number_in_string(view);
            if ( string_number != 0 ) {
                line_value += string_number *10;
                break;
            }
        }
    }
    for(int j = i.length()-1; j >=0; j--) {
        if (isdigit(i[j])) {
            line_value += ( i[j] - '0' );
            break; 
        } else {
            string_view view = string_view(i).substr(j, i.length()-j);
            int string_number = find_number_in_string(view);
            if ( string_number != 0 ) {
                line_value += string_number;
                break;
            }
        }
    }
    sum += line_value;
    std::cout << line_value << std::endl;
    line_value = 0; 
    }

    return sum;
}


int main(){
    vector<string> lines;

    std::ifstream input("input.txt");

    copy(istream_iterator<string>(input), istream_iterator<string>(),back_inserter(lines));

    int part_1 = part1(lines);

    int part_2 = part2(lines);

    std::cout << "PART 1: " << part_1 << std::endl;
    std::cout << "PART 2: " << part_2 << std::endl;

}