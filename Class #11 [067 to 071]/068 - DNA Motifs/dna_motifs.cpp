#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

//compute the maximum frequency of a motif of size K 
//and how many different motifs have that frequency

//Tips:
//- Go trough the DNA string and generate all possible 
//  K-strings using for instance the substr function
//- unordered_map<string, int> to keep the frequencies:
//  for each motif just increment the respective frequency
//- At the end check what is the maximum frequency 
//  and how many motifs have that frequency 
//  (you can traverse the map)
void maxFreq_count(string s, int k)
{
    int max_freq = 0;
    int count = 0;
    
    unordered_map<string, int> freq;
    for (int i = 0; i < (int)s.size() - k + 1; i++)
    {
        string motif = s.substr(i, k);
        freq[motif]++;
    }
    
    for (auto e : freq)
    {
        if (e.second > max_freq)
        {
            max_freq = e.second;
            count = 1;
        }
        else if (e.second == max_freq)
        {
            count++;
        }
    }

    cout << max_freq << endl;
    if (count == 1)
    {
        for (auto e : freq) {
            if (e.second == max_freq) {
                cout << e.first << endl;
                break;
            }
        }
    }
    else cout << count << endl;
}


int main()
{
    int k; // length of the motif
    cin >> k;

    string s;   // DNA string
    cin >> s;

    maxFreq_count(s, k);

    return 0;
}