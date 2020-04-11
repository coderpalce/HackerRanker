#include <bits/stdc++.h>

using namespace std;

// Complete the anagram function below.
int anagram(string s) {

    int split=0;
    int count=0;
    if(s.length()%2==0){
        split=s.length()/2;
        }
    else{
        return -1;
    }
    count=split;
    for(int i=split;i<s.length();i++){
        for(int j=0;j<split;j++){
            if(s[i]==s[j]){
                count--;
                s[j]=' ';
                break;   
            }
        }
    }
    return count;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = anagram(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
