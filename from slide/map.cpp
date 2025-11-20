 #include<iostream>
 #include<map>

 using namespace std;

void print(map<string,int>&r)
{
    for(auto mal:r)
    {
        cout<<mal.first<<"->"<<mal.second<<endl;
    }
}
void makepair(map<string,int>&r,string &name,int &age){
    r.insert(make_pair(name,age));
   

    print(r);

}


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

    //map pass by referance

    map<string,int>r;
    cout<<"how many pair you want to add in this map:"<<endl;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string name;
        cout<<"enter name:"<<endl;
        cin>>name;

        int age;
        cout<<"enter the age:"<<endl;
        cin>>age;
        makepair(r,name,age);
    }

    auto it=fruit.find("apple");
    if(it!=fruit.end())
    {
        fruit["apple"]=fruit["apple"]+4;    
    }

     for(auto val: fruit)
    {
        cout<<val.first<<"->"<<val.second<<endl;
    }
    return 0;
  }