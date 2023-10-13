#include <chrono>
#include <thread>

bool is_pair_anagrammatic(const string& A, size_t p, size_t q, size_t k)
{
    #ifdef MY_DEBUG
    cout << "check pair " << p << ":" << q << endl;
    #endif
    vector<int> psignature(30,0);
    vector<int> qsignature(30,0);
    
    for (size_t i=0; i<k; ++i) {
        psignature[A[p+i]-'a']++;
        qsignature[A[q+i]-'a']++;
    }
    
    return (psignature == qsignature);
}

void find_pairs_of_size(const string& A, unordered_set<string>& pairs, size_t k) 
{
    #ifdef MY_DEBUG
    cout << "find pairs of size " << k << endl;
    #endif
    for (size_t i=0; i<A.size()-k; ++i) {
        for (size_t j=i+1; j<A.size()-k+1; ++j) {
            //this_thread::sleep_for(chrono::milliseconds(1000));
            if (is_pair_anagrammatic(A, i, j, k)) {
                #ifdef MY_DEBUG
                cout << "YES" << endl;
                #endif
                pairs.insert(anagram_pair_to_string(i,i+k-1,j,j+k-1));
            }
        }
    }
}

// Find number of unordered anagrammatic pairs for the given string
int find_anagrammatic_pairs_slow(const string& A)
{
    #ifdef MY_DEBUG
    cout << "=== " << A << " ===" << endl;
    #endif
    unordered_set<string> pairs;
  
    for (size_t k=1; k<A.size(); k++) {
        find_pairs_of_size(A, pairs, k);
    }

    return pairs.size(); 
}

