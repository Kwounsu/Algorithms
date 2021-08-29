int BtoD(){
    int ret = 0;
    for (int i=strlen(bit)-1, base=1; i>=0; i--, base*=2)
        ret += base * (bit[i]-'0');
    return ret;
}
