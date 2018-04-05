vector<int> plusOne(vector<int>& digits) {
    int mod = 1;
    for(int i=digits.size()-1;i>=0 && mod !=0 ;i--){
        digits[i] += 1;
        digits[i] %= 10;
        mod = digits[i]!=0 ? 0:1;
    }
    std::vector<int>::iterator vec_it = digits.begin();
    //vector insert syntax iterator,position,value
    //position should start from 1
    if(mod == 1)
        digits.insert(vec_it,1,1);
    return digits;
}