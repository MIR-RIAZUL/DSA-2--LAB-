 #include<iostream>
 #include<map>

 using namespace std;
  int main()
  {
    map<string, int>fruit;
    fruit.insert(make_pair("apple",3));
    fruit.insert(make_pair("orange",6));
    fruit.insert(pair<string,int>("banana",10));
    fruit["guauaba"]=12;

    for(auto val: fruit)
    {
        cout<<val.first<<"->"<<val.second<<endl;
    }
    return 0;
  }