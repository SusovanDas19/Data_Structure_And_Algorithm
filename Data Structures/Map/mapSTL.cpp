#include<iostream>
#include<unordered_map> // for unordered map
#include<map>           // for ordered map

using namespace std;


unordered_map<char,int> count(string &s){
    
  unordered_map<char,int> ans;

  for(auto ch: s){
    if(ans.find(ch) != ans.end()){
      ans[ch]++;
    }else{
      ans[ch] = 1;
    }
  }
  return ans;

}

int main()
{
    //Creation of ordered map
    map<string, int> m;

    //Creation of unordered map
    unordered_map<string, int> mp;
  
    //insertion
      //way 1
    mp.insert({"Susovan",21});

     //way 2
    mp["Piku"] = 10;

      //way 3
    pair<string, int> a("Ramesh", 12);
    mp.insert(a);

      //way 4
    pair<string, int> b = make_pair("Rahul", 41);
    mp.insert(b);

      //way 5
    pair<string,int> c;
    c.first = "Jadu";
    c.second = 22;
    mp.insert(c);


    //Size
    cout<<"Size of the map: "<<mp.size()<<endl;


    //Access
    cout<<"Using AT: "<<mp.at("Jadu")<<endl;   //if error => 'std::out_of_range' then the key does not exist in map
    cout<<"Using []: "<<mp["Ramesh"]<<endl;    // when we try to access element using [] then if the keyValue pair exist then the value will be printed but if the key is not present then one entry of that key will be inserted and 0 will be printed

    //Searching
     // using count => if 1 -> present, if 0-> not present
    if(mp.count("Susovan")) cout<<"Susovan Present"<<endl;
    else cout<<"Not present"<<endl;

     //using find
    if(mp.find("Jadu") != mp.end()){
        cout<<"Found"<<endl;
    }else cout<<"Not found"<<endl; 

  
  //Count freq of each letter in a word
  
  string word = "susovan";
  unordered_map<char,int> ans = count(word);
  cout<<"Count of each letter in "<<word<<endl;
  for(auto i: ans){
    cout<< i.first << " --> "<<i.second<<endl;
  }

    
    return 0;
}