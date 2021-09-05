#include <iostream>
#include <math.h>

using namespace std;
bool validate_bin(string inp){
	string allowed = "01";
	for(int i = 0 ; i < inp.size() ; i++){
		if( allowed.find(inp[i]) == -1){
            cout<<"\nError! Not a valid binary number!";
			return false;
            }
	}
	return true;
}


bool validate_oct(string inp){
	string allowed = "01234567";
	for(int i = 0 ; i < inp.size() ; i++){
		if( allowed.find(inp[i]) == -1){
            cout<<"\nError! Not a valid base 8 number!";
			return false;
        }
	}
	return true;
}

bool validate_dec(string inp){
	string allowed = "0123456789";
	for(int i = 0 ; i < inp.size() ; i++){
		if( allowed.find(inp[i]) == -1){
            cout<<"\nError! Not a valid base 10 number!";
			return false;
        }
	}
	return true;
}


bool validate_hex(string inp){
	string allowed = "0123456789ABCDEFabcdef";
	for(int i = 0 ; i < inp.size() ; i++){
		if( allowed.find(inp[i]) == -1){
            cout<<"\nError! Not a valid hexadecimal number!";
			return false;
        }
	}
	return true;
}


bool validate_addition(string a , string b ,string base){
	string bases = "281016";
	if(bases.find(base) == -1){
		cout<<"\nYou did not enter a valid base number!\n";
		return false;
	}

	if(base == "2"){
		if(!validate_bin(a) || !validate_bin(b)){
			cout<<"\n One of you numbers is not in base 2\n";
			return false;
		}
	}
	if(base == "8"){
		if(!validate_oct(a) || !validate_oct(b)){
			cout<<"\n One of you numbers is not in base 8\n";
			return false;
		}
	}
	if(base == "10"){
		if(!validate_dec(a) || !validate_dec(b)){
			cout<<"\n One of you numbers is not in base 10\n";
			return false;
		}
	}
	if(base == "16"){
		if(!validate_hex(a) || !validate_hex(b)){
			cout<<"\n One of you numbers is not in base 16\n";
			return false;
		}
	}
	return true;
}


int char_int(char character){
	if(character == 'A' || character == 'a') return 10;
	if(character == 'B' || character == 'b') return 11;
	if(character == 'C' || character == 'c') return 12;
	if(character == 'D' || character == 'd') return 13;
	if(character == 'E' || character == 'e') return 14;
	if(character == 'F' || character == 'f') return 15;
	return 1;
} 


string int_hex(int to_hex){
	if(to_hex == 0) return "0" ;
	if(to_hex == 1) return "1" ;
	if(to_hex == 2) return "2" ;
	if(to_hex == 3) return "3" ;
	if(to_hex == 4) return "4" ;
	if(to_hex == 5) return "5" ;
	if(to_hex == 6) return "6" ;
	if(to_hex == 7) return "7" ;
	if(to_hex == 8) return "8" ;
	if(to_hex == 9) return "9" ;
	if(to_hex == 10) return "A" ;
	if(to_hex == 11) return "B" ;
	if(to_hex == 12) return "C" ;
	if(to_hex == 13) return "D" ;
	if(to_hex == 14) return "E" ;
	if(to_hex == 15) return "F" ;
	return "A";
}

int bin_dec(string bin){
	// long long dec = 0;
	int dec = 0;
	for(int i = 0 ; i < bin.size() ; i++){
		if(bin[i] == '1'){
			dec += pow(2 , (bin.size() - 1 - i));
		}
	}
	return dec;
}

string oct_bin(string oct){
	int current = 0;
	string reverse = "";
	string bin = "";
	for(int i = 0 ; i < oct.size();i++){
		current = oct[i] - 48;
		for(int c = 0 ; c < 3 ; c++){
			reverse +=  to_string(current%2);
			current /= 2;
		}
		for(int i = reverse.size()-1 ; i >= 0 ; i--){
			bin += reverse[i];
		}
		reverse = "";
	}
	return bin;
}

string hex_bin(string hex){
	string nums = "1234567890";
	int current = 0;
	string reverse = "";
	string bin = "";
	for(int i = 0 ; i < hex.size();i++){
		if(nums.find(hex[i]) == -1){
			current = char_int(hex[i]);
		} else {
			current = hex[i] - 48;
		}		
		for(int c = 0 ; c < 4 ; c++){
			reverse +=  to_string(current%2);
			current /= 2;
		}

		for(int i = reverse.size()-1 ; i >= 0 ; i--){
			bin += reverse[i];
		}
		reverse = "";
	}
	return bin;
}

string dec_bin(string dec){
	int number = stoi(dec);
	string reverse = "";
	string bin = "";
	while(number/2 !=0){
		reverse += to_string(number % 2);
		number /= 2;
	}
	reverse += to_string(number % 2);
	for(int i = reverse.size() - 1 ; i >= 0 ; i --){
		bin += reverse[i];
	}
	return bin;
}

string bin_oct(string bin){
	int start = 3 - (bin.size()%3);
	string starting_zeros = "";
	string oct = "";
	int value = 0;
	for(int i = 0 ; i < start ; i++){
		starting_zeros += "0";
	}
	bin = starting_zeros + bin;
	for(int i = 0 ; i < bin.size() ; i++){
		value = 0;
		if(bin[i] == '1'){
			value += 4;
		}
		i++;
		if(bin[i] == '1'){
			value += 2;
		}
		i++;
		if(bin[i] == '1'){
			value += 1;
		}
		oct += to_string(value);
	}
	return oct;
}

string bin_hex(string bin){
	int start = 4 - (bin.size()%4);
	string starting_zeros = "";
	string hex = "";
	int value = 0;
	for(int i = 0 ; i < start ; i++){
		starting_zeros += "0";
	}
	bin = starting_zeros + bin;
	for(int i = 0 ; i < bin.size() ; i++){
		value = 0;
		if(bin[i] == '1'){
			value += 8;
		}
		i++;
		if(bin[i] == '1'){
			value += 4;
		}
		i++;
		if(bin[i] == '1'){
			value += 2;
		}
		i++;
		if(bin[i] == '1'){
			value += 1;
		}
		hex += int_hex(value);
	}
	return hex;
}

string addition(string a , string b , string base){
	string result = "";
	if(base == "2"){
		result = to_string(bin_dec(a) + bin_dec(b));
		result =  dec_bin(result);
	}
	if(base == "8"){
		a = oct_bin(a);
		b = oct_bin(b);
		result = to_string(bin_dec(a) + bin_dec(b));
		result = dec_bin(result);
		result =  bin_oct(result);
		
	}
	if(base == "10"){
		result = to_string(stoi(a) + stoi(b));
		result =  result;
	}
	if (base == "16"){
		a = hex_bin(a);
		b = hex_bin(b);
		result = to_string(bin_dec(a) + bin_dec(b));
		result = dec_bin(result);
		result =  bin_hex(result);
	}
	return result;
}


int main(){
    string inp = "";
	string a = "";
	string b = "";
	string base = "";
	string result = "";
	//number one
    cout<<"Please enter a 16 bit binary integer.\n";
    cin>>inp;
    if(validate_bin(inp)){
        cout<<"\n Base 10 = "<<bin_dec(inp);
    }


	//number two
    cout<<"\nPlease enter an 8 digit hex value.\n";
    cout<<"Warning: Any hex value above 7fffffff will result in overflow of a 32bit int\n";
    cin>>inp;
    if(validate_hex(inp)){
        cout<<"\n Base 10 = "<<bin_dec(hex_bin(inp));
    }



	//number three
    cout<<"\nPlease enter a base 10 number!\n";
    cin>>inp;
    if(validate_dec(inp)){
        cout<<"\nBinary = "<<dec_bin(inp);
    }


	//number four
    cout<<"\nPlease enter a base 10 number!\n";
    cin>>inp;
    if(validate_dec(inp)){
        cout<<"\nHexadecimal = "<<bin_hex(dec_bin(inp));
    }



	//number five
	cout<<"\n Please enter number A(very large numbers may lead to overflow!):\n";
	cin>>a;
	cout<<"\n Please enter number B(very large numbers may lead to overflow!):\n";
	cin>>b;
	cout<<"\nPlease enter the number base(2,8,10,16):\n";
	cin>>base;
	if(validate_addition(a,b,base)){
		result = addition(a,b,base);
		cout << "\n"<<a<<" + "<<b<<" = "<<result;
	}

    return 0;
}