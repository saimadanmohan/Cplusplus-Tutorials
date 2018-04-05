#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the contacts function below.
 */

struct Trie{
    char c;
    struct Trie *next[26];
    int cnt;
    Trie(char c){
        this->c = c;
        for(int i = 0;i<26;i++)
            next[i] = NULL;
    }
}*TrieNodes[26];

Trie* add_to_trie(string& s,int index,struct Trie* trieNode){
    if(trieNode == NULL){
        trieNode = new Trie(s[index]-'a');
        //cout<<"hello "<<s[index]<<endl;
        trieNode->cnt = 1;
    }else{
        //cout<<"hola "<<s[index]<<endl;
        trieNode->cnt += 1;
    }
    if(index + 1 < s.size())
        trieNode->next[s[index+1]-'a'] = add_to_trie(s,index+1,trieNode->next[s[index+1]-'a']);
    return trieNode;
}

int find(string& s,int index,struct Trie* trieNode){
    if(trieNode == nullptr){
        return 0;
    }
    if(index ==  s.size() - 1)
        return trieNode->cnt;
    else
        return find(s,index+1,trieNode->next[s[index+1]-'a']);
}


vector<int> contacts(vector<vector<string>>& queries) {
    vector<int> ans;
    for(int i = 0;i<queries.size();i++){
        if(queries[i][0] == "add")
            TrieNodes[queries[i][1][0]-'a'] = add_to_trie(queries[i][1],0,TrieNodes[queries[i][1][0]-'a']);
        else
            ans.push_back(find(queries[i][1],0,TrieNodes[queries[i][1][0]-'a']));
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int queries_rows;
    cin >> queries_rows;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<string>> queries(queries_rows);
    for (int queries_row_itr = 0; queries_row_itr < queries_rows; queries_row_itr++) {
        queries[queries_row_itr].resize(2);

        for (int queries_column_itr = 0; queries_column_itr < 2; queries_column_itr++) {
            cin >> queries[queries_row_itr][queries_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> result = contacts(queries);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout << result[result_itr];

        if (result_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
