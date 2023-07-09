#include"rdb.h"
#include"rdb-attr.cpp"
#include"rdb-basics.cpp"
#include"rdb-join.cpp"
list<string> common(relation*r1,relation*r2){
    list<string> l;
    for(int i=0;i<r1->nattr;i++){
        for(int j=0;j<r2->nattr;j++){
            if(r1->attrnames[i]==r2->attrnames[j]){
                l.push_back(r1->attrnames[i]);
                break;
            }
        }
    }
    return l;
}
void options(){
    cout<<endl;
    cout<<endl;
    cout<<"Enter option 1 to create a empty relation."<<endl;
    cout<<"Enter option 2 to enter attribute to a relation."<<endl;
    cout<<"Enter option 3 to enter a record to a relation."<<endl;
    cout<<"Enter option 4 to print relation."<<endl;
    cout<<"Enter option 5 to delete a relation."<<endl;
    cout<<"Enter option 6 to create new relation based on relational algebra."<<endl;
    cout<<"Enter option 7 to selecting a set of based on boolean expression."<<endl;
    cout<<"Enter option 8 to exit the program."<<endl;
    cout<<endl;
    cout<<endl;
}
void sub_options(){
    cout<<endl;
    cout<<endl;
    cout<<"Enter option 1 to create union of two relations."<<endl;
    cout<<"Enter option 2 to create difference of two relations."<<endl;
    cout<<"Enter option 3 to make cartesian product of two relations."<<endl;
    cout<<"Enter option 4 to rename attribute in a relation."<<endl;
    cout<<"Enter option 5 to make projection of a relation."<<endl;
    cout<<"Enter option 6 to make natural join of two relations."<<endl;
    cout<<endl;
    cout<<endl;
}
int index_input(int len){
    int temp;
    while(1){
        cout<<"Enter index :";
        cin>>temp;
        if(temp<1||temp>len){
            cout<<"Invalid index."<<endl;
        }
        else{
            return temp;  
        }
    }
}
int main(){
    cout<<"Program started."<<endl;
    vector<relation*> database;
    int val;
    while(1){
        options();
        cout<<"Enter option:";
        cin>>val;
        if(val==1){
            relation* r=new relation();
            database.push_back(r);
            cout<<"Empty relation created."<<endl;
        }
        else if(val==2){
            if(int(database.size())==0){
                cout<<"Database is empty."<<endl;
            }
            else{
                int index=index_input(int(database.size()));
                database[index-1]->add_attribute();
                cout<<"Attribute successfully added."<<endl;
            }
        }
        else if(val==3){
            if(int(database.size())==0){
                cout<<"Database is empty."<<endl;
            }
            else{
                int index=index_input(int(database.size()));
                database[index-1]->add_record();
            }
        }
        else if(val==4){
            if(int(database.size())==0){
                cout<<"Database is empty."<<endl;
            }
            else{
                int index=index_input(int(database.size()));
                database[index-1]->print_relation();
            }
        }
        else if(val==5){
            if(int(database.size())==0){
                cout<<"Databse is empty."<<endl;
            }
            else{
                int index=index_input(int(database.size()));
                relation* temp=database[index-1];
                database[index-1]=database[database.size()-1];
                database[database.size()-1]=temp;
                database.pop_back();
                delete temp;
                cout<<"Successfully deleted."<<endl;
            }
        }
        else if(val==6){
            int temp;
            while(1){
                sub_options();
                cout<<"Enter option:";
                cin>>temp;
                if(temp<1||temp>6){
                    cout<<"Invalid option."<<endl;
                }
                else{
                    break;
                }
            }
            if(temp==1){
                if(int(database.size())<2){
                    cout<<"Database size is not enough."<<endl;
                }
                else{
                    int index1=index_input(int(database.size()));
                    int index2=index_input(int(database.size()));
                    database.push_back(unione(database[index1-1],database[index2-1]));
                }
            }
            else if(temp==2){
                if(int(database.size())<2){
                    cout<<"Database size is not enough."<<endl;
                }
                else{
                    int index1=index_input(int(database.size()));
                    int index2=index_input(int(database.size()));
                    database.push_back(difference(database[index1-1],database[index2-1]));
                }
            }
            else if(temp==3){
                if(int(database.size())<2){
                    cout<<"Database size is not enough."<<endl;
                }
                else{
                    int index1=index_input(int(database.size()));
                    int index2=index_input(int(database.size()));
                    database.push_back(cartesian(database[index1-1],database[index2-1]));
                }
            }
            else if(temp==4){
                if(int(database.size())==0){
                    cout<<"Database is empty."<<endl;
                }
                else{
                    int index=index_input(int(database.size()));
                    string s1,s2;
                    cout<<"Enter Attribute name to rename:";
                    cin>>s1;
                    cout<<"Enter new name of attribute:";
                    cin>>s2;
                    database.push_back(difference(database[index-1],s1,s2));
                }
            }
            else if(temp==5){
                if(int(database.size())==0){
                    cout<<"Database is empty."<<endl;
                }
                else{
                    int index=index_input(int(database.size()));
                    int n;
                    cout<<"Enter number of attributes in projection:";
                    cin>>n;
                    list<string> l;
                    for(int i=0;i<n;i++){
                        string s;
                        cout<<"Enter Attribute "<<i+1<<":";
                        cin>>s;
                        l.push_back(s);
                    }
                    database.push_back(projection(database[index-1],l));
                }
            }
            else if(temp==6){
                if(int(database.size())<2){
                    cout<<"Database size is not enough."<<endl;
                }
                else{
                    int index1=index_input(int(database.size()));
                    int index2=index_input(int(database.size()));
                    list<string> l=common(database[index1-1],database[index2-1]);
                    if(int(l.size())==0){
                        cout<<"Can't perfom natural join."<<endl;
                    }
                    else{
                        database.push_back(naturaljoin(database[index1-1],database[index2-1],l));
                        cout<<"Natural join performed successfully."<<endl;
                    }
                }
            }
        }
        else if(val==7){
            if(int(database.size())==0){
                cout<<"Database is empty."<<endl;
            }
            else{
                dnf *f=new dnf;
                int index=index_input(int(database.size()));
                int n;
                cout<<"Enter number of constarints you want to apply:";
                cin>>n;
                for(int i=0;i<n;i++){
                    list<tuple<string,char,attr*>> l;
                    cout<<"Enter number of comparators in constarint "<<i+1<<":";
                    int num;
                    cin>>num;
                    for(int j=0;j<num;j++){
                        string name;
                        while(1){
                            cout<<"Enter Attribute name:";
                            cin>>name;
                            if(!database[index-1]->is_attr(name)){
                                cout<<"Invalid attribute name."<<endl;
                            }
                            else{
                                break;
                            }
                        }
                        char op;
                        cout<<"Enter comparator:";
                        cin>>op;
                        int id=database[index-1]->id(name);
                        cout<<"Enter value for attribute:";
                        attr* a;
                        if(id==0){
                            a=new intattr();
                        }
                        else if(id==1){
                            a=new doubleattr();
                        }
                        else if(id==2){
                            a=new floatattr();
                        }
                        else{
                            a=new stringattr();
                        }
                        l.push_back({name,op,a});
                    }
                    f->ops.push_back(l);
                }
                database.push_back(unione(database[index-1],f));
                cout<<"Selction performed successfully."<<endl;
            }
        }
        else if(val==8){
            cout<<"Program exited."<<endl;
            break;
        }
        else{
            cout<<"Invalid option."<<endl;
            cout<<"Enter valid option."<<endl;
        }
    }
    return 0;
}
