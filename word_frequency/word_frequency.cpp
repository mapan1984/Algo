int main()
{
    map <string, int> M;
    map <string, int>::iterator j;
    string t;
    while(cin >> t){
        M[t]++;
    }
    for(j = M.begin(); j != M.end(); ++j){
        cout << j->first << ": " << j->second << "\n";
    }
    return 0;
}
