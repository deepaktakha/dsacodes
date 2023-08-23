vector < int > sortedArray(vector < int > a, vector < int > b) {
    // Write your code here
   
   int  n1 = a.size();
   int n2 = b.size();
   int i=0;
   int j = 0;
   vector<int> res;
while(i<n1 && j<n2){
     if(a[i]<=b[j])
     { if(res.size()==0 || res.back() != a[i])
     {
        res.push_back(a[i]);
     } i++;
     }else {
         if(res.size()==0 || res.back() != b[j])
         { res.push_back(b[j]);}
         j++;
           }
    }

    while(i<n1){
     if(res.back()==0 || res.back() != a[i]){
         res.push_back(a[i]);}
    i++;
    }
     while(j<n2){
      if(res.back()==0 || res.back() != b[j]){
         res.push_back(b[j]);}
    j++;   
   }
    
    return res;
}
