#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the activityNotifications function below.
int activityNotifications(vector<int> expenditure, int d) {
vector<int> exp(201,0);
int removePos;
int removeValue;
int addPos;
int addValue;
int count=0;
float median;
int pos;
long int size;
size=d;
for(int i=0;i<size;i++){
    pos=expenditure[i];
    exp[pos]++;
}

for(int i=d;i<expenditure.size();i++){
        int sum=0;
         if(size%2!=0){
            median=(size/2)+1;
            for(int j=0;j<201;j++){
                if(exp[j]!=0){
                    sum=sum+exp[j];
                    
                    if(sum>=median){
                        int point;
                        point=2*j;
                        if(expenditure[i]>=point){
                            count++;
                            
                            break;
                        }
                    }
                }
            }
        }
       else if(size%2==0){
            int mid1=0,mid2=0,pos1=0,pos2=0;
            int sum1=0;
            
            mid1=size/2;
            mid2=(size/2)+1;
            for(int r=0;r<201;r++){
                sum1=sum1+exp[r];
                if(sum1==mid1){
                    pos1=r;
                    pos2=r+1;
                    break;
                }
                else if(sum1>mid1){
                    pos1=r;
                    pos2=r;
                    break;
                }
            }
           
            float point;
            float point1;
            point=(float)(pos1+pos2)/2;
            point1=2*point;
            if(expenditure[i]>=point1){
                count++;
            
            }
           
        }
        
        removePos=i-size;
        removeValue=expenditure[removePos];
        exp[removeValue]--;
        addValue=expenditure[i];
        exp[addValue]++;
                
}
return count;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split_string(expenditure_temp_temp);

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
