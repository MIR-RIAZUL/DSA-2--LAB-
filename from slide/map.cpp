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

    map<string, pair<string,int>>wife_kids;
    wife_kids.insert(make_pair("sunny",make_pair("porimoni",10)));

    wife_kids.insert(make_pair("riazul",make_pair("pori",2)));

    for(auto i:wife_kids)
    {
        cout<<i.first<<"->"<<i.second.first<<","<<"baccha kaccha: "<<i.second.second<<endl;
    }
    return 0;
  }