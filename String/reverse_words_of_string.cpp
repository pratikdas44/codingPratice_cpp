//program to print output for i/p like ab.cde to cde.ab. Here strtok is used to find delimiter '.' First need to convert string to char as strtok can be used for char type only.
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t--){
	    string ip;
	    cin >> ip;
	    char s[ip.length()];
	    int i;
	    for(i=0;i<ip.length();i++)
	        s[i] = ip[i];
	    s[i]='\0';
	    char *c;
	    vector<string> a;
	    c = strtok(s,".");
	    while(c!=NULL){
	        a.push_back(c);
	        c = strtok(NULL,".");
	    }
	    for(int i=a.size()-1;i>=0;i--){
            cout << a[i];
            if(i!=0)
                cout << ".";
	    }
	    cout << endl;
	}
	return 0;
}

//program to insert '.' before each consonant and to delete all vowels
#include<bits/stdc++.h>
using namespace std;

// Returns true if p_char is a vowel
bool is_vowel(const char p_char)
{

    constexpr char vowels[] = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
    return std::find(std::begin(vowels), std::end(vowels), p_char) != std::end(vowels);
}

std::string remove_vowel(std::string st)
{
    // Moves all the characters for which `is_vowel` is true to the back
    //  and returns an iterator to the first such character
    auto to_erase = std::remove_if(st.begin(), st.end(), is_vowel);

    // Actually remove the unwanted characters from the string
    st.erase(to_erase, st.end());int n = st.length();transform(st.begin(), st.end(), st.begin(), ::tolower);
    for(int i=n-1;i>=0;i--)
    {st.insert(i,1,'.');}
    return st;
}

int main()
{
    std::cout <<  remove_vowel("odn");

}
