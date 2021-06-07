vl hashedTargets1,hashedTargets2;
vl hashedString1,hashedString2;
unordered_map <ll,ll> primePower1;
unordered_map <ll,ll> primePower2;
ll p1 = 999999937;
ll p2 = 999999929;
ll A = 999999893;
void preprocess(unordered_map <ll,ll> &primePower, ll multiplier = 999999893, ll m = 999999937){
    primePower[0] = 1;
    for(int i = 1;i<=5000;i++){
        primePower[i] = (primePower[i-1]*multiplier)%m;
    }
}
ll getHashedStringWhole(string &s, ll mod = p1,ll multiplier = 999999893){
    ll hashh = s[0];
  //  DEBUG(s);
  //  DEBUG(hashh);

    for(int i = 1;i<s.size();i++){
        hashh = ((hashh*multiplier)%mod + s[i])%mod;
      //  DEBUG(hashh);
    }

    return hashh;
}

vl getHashVector(string &s, ll m = p1, ll multiplier = 999999893){
    vector <ll> hashVector(s.size());

    hashVector[0] = s[0];
    // DEBUG(s[0]);
    // DEBUG( hashVector[0]);
     for(int i = 1;i<s.size();i++){
        hashVector[i] = (hashVector[i-1]*multiplier + s[i])%m;
        //   DEBUG(s[i]);
        // DEBUG( hashVector[i]);
    }

    return hashVector;
}

ll substringHash(vl &hashVector, ll a, ll b, ll m ,unordered_map<ll,ll> &primePower){
    if(a == 0){
        return hashVector[b];
    }
    return ((hashVector[b] - (hashVector[a-1]*primePower[b-a+1])%m)%m+m)%m;
}
