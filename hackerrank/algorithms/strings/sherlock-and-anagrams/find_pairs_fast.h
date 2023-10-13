void count_between_pairs(const string& A, size_t first_pos, size_t second_pos, unordered_set<string>& pairs)
{
    vector<int> lsignature(30, 0);
    vector<int> rsignature(30, 0);

    size_t t = second_pos-first_pos-2;
    for (size_t j=1; j<=t; ++j) {
        lsignature[A[first_pos+j]-'a']++;
        rsignature[A[second_pos-j]-'a']++;
        if (lsignature == rsignature) {
            pairs.insert(anagram_pair_to_string(first_pos,first_pos+j,second_pos-j,second_pos));
            #ifdef MY_DEBUG
            cout << 
                pairs.size() << 
                "$5> " << 
                first_pos << 
                "," << 
                first_pos+j << 
                " = " << 
                second_pos-j << 
                "," << 
                second_pos << 
                " " << 
                A.substr(first_pos, j+1) << 
                endl;
            #endif
        }
    }
}

void count_forward_pairs(const string& A, size_t first_pos, size_t second_pos, unordered_set<string>& pairs)
{
    vector<int> lsignature(30, 0);
    vector<int> rsignature(30, 0);

    size_t t = A.size()-second_pos-1;
    for (size_t j=1; j<=t; ++j) {
        lsignature[A[first_pos+j]-'a']++;
        rsignature[A[second_pos+j]-'a']++;
        if (lsignature == rsignature) {
            pairs.insert(anagram_pair_to_string(first_pos,first_pos+j,second_pos,second_pos+j));
            #ifdef MY_DEBUG
            cout << 
                pairs.size() << 
                "$3> " << 
                first_pos << 
                "," << 
                first_pos+j << 
                " = " << 
                second_pos << 
                "," << 
                second_pos+j << 
                " " << 
                A.substr(first_pos, j+1) << 
                " " << 
                A.substr(second_pos, j+1) << 
                endl;
            #endif
        }
    }
}

void count_backward_pairs(const string& A, size_t first_pos, size_t second_pos, unordered_set<string>& pairs)
{
    vector<int> lsignature(30, 0);
    vector<int> rsignature(30, 0);

    for (size_t j=1; j<=first_pos; ++j) {
        lsignature[A[first_pos-j]-'a']++;
        rsignature[A[second_pos-j]-'a']++;
        if (lsignature == rsignature) {
            pairs.insert(anagram_pair_to_string(first_pos-j,first_pos,second_pos-j,second_pos));
            #ifdef MY_DEBUG
            cout << 
                pairs.size() << 
                "$4> " << 
                first_pos-j << 
                "," << 
                first_pos << 
                " = " << 
                second_pos-j << 
                "," << 
                second_pos << 
                " " << 
                A.substr(first_pos-j, j) << 
                " " << 
                A.substr(second_pos-j, j) << 
                endl;
            #endif
        }
    }
}

// Find number of unordered anagrammatic pairs for the given string
int find_anagrammatic_pairs(const string& A)
{
    #ifdef MY_DEBUG
    cout << "=== " << A << " ===" << endl;
    #endif
    unordered_set<string> pairs;
  
    for (size_t i=0; i<A.size()-1; ++i) {
        size_t pos = i;
        
        while (pos < A.size()) {
            pos = A.find(A[i], pos+1);
        
            if (pos != string::npos) {
                // count one char substrings (i,i) and (pos,pos)
                pairs.insert(anagram_pair_to_string(i,i,pos,pos));
                #ifdef MY_DEBUG
                cout << pairs.size() << "$1> " << i << "," << i << " = " << pos << "," << pos << " " << A[i] << endl;
                #endif
                
                if (pos-i > 1) {
                    // count substrings (i,pos-1) and (i+1, pos), they are anagrammatic for sure
                    pairs.insert(anagram_pair_to_string(i,pos-1,i+1,pos));
                    #ifdef MY_DEBUG
                    cout << pairs.size() << "$2> " << i << "," << pos-1 << " = " << i+1 << "," << pos << " " << A.substr(i, pos-i+1) << endl;
                    #endif
                    
                    count_forward_pairs(A, i, pos, pairs);
                    count_backward_pairs(A, i, pos, pairs);
                }
                
                if (pos-i > 2) {
                    count_between_pairs(A, i, pos, pairs);
                }
            }
        } // while
    } // for
     
    return pairs.size(); 
}

