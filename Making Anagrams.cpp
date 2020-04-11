#include <bits/stdc++.h>

using namespace std;

// Complete the makingAnagrams function below.
int makingAnagrams(string s1, string s2) {

    int size1,size2;
    int total;
    size1=s1.length();
    size2=s2.length();
    total=size1+size2;

    for(int i=0;i<size1;i++){
        for(int j=0;j<size2;j++){
            if(s1[i]==s2[j]){
                total=total-2;
                s2[j]=' ';
                break;
            }
        }
    }
    return total;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = makingAnagrams(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
