#include <bits/stdc++.h>

using namespace std;

// Complete the staircase function below.
void staircase(int n) {
    /*for(int i=n ; i<=n; i--)
    {
        cout<<" ";
    }*/
    int k=1;
    int x;
    int count;
    while(k<=n)
    {
        x = n-k;
        count=n;
       for(int i= x ; i > 0; i--)
       {
           cout<<" ";
           count--;
       }
       for(int j=1; j <= count; j++)
       {
            cout<<"#";
       }
       count=n;
       k++;
       cout<<endl;
       
    }
    

}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    staircase(n);

    return 0;
}

