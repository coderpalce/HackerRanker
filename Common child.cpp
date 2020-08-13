#include <bits/stdc++.h>

using namespace std;

// Complete the commonChild function below.
int a[5001][5001]={0};
int commonChild(string s1, string s2) {
 //int a[5001][5001]={0};
 int size=s1.size();

for(int i=1;i<=size;i++){
    for(int j=1;j<=size;j++){
        if(s1[i-1]==s2[j-1]){
            a[i][j]=a[i-1][j-1]+1;
        }
        else{
            a[i][j]=max(a[i-1][j],a[i][j-1]);
        }
    }
}
int result;
int l=size;
result=a[l][l];
return result;


}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
