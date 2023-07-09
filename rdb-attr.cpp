#include"rdb.h"
class attr{
    public:
    virtual bool operator==(const attr& r) = 0;
    virtual bool operator!=(const attr& r) = 0;
    virtual bool operator<=(const attr& r) = 0;
    virtual bool operator>=(const attr& r) = 0;
    virtual bool operator<(const attr& r) = 0;
    virtual bool operator>(const attr& r) = 0;
    virtual void print_attr(){
        cout<<"default";
    }
};
class intattr:public attr{
    private:
    int val;
    public:
    intattr(){
        cin>>val;
    }
    intattr(int v){
        val=v;
    }
    bool operator==(const attr& r){
        if(val==((const intattr&)r).val){
            return true;
        }
        return false;
    }
    bool operator!=(const attr& r){
        if(val!=((const intattr&)r).val){
            return true;
        }
        return false;
    }
    bool operator<=(const attr& r){
        if(val<=((const intattr&)r).val){
            return true;
        }
        return false;
    }
    bool operator>=(const attr& r){
        if(val>=((const intattr&)r).val){
            return true;
        }
        return false;
    }
    bool operator<(const attr& r){
        if(val<((const intattr&)r).val){
            return true;
        }
        return false;
    }
    bool operator>(const attr& r){
        if(val>((const intattr&)r).val){
            return true;
        }
        return false;
    }
    int get(){
        return this->val;
    }
    void print_attr(){
        cout<<val;
    }
};
class floatattr:public attr{
    private:
    float val;
    public:
    floatattr(){
        cin>>val;
    }
    floatattr(float v){
        val=v;
    }
    bool operator==(const attr& r){
        if(val==((const floatattr&)r).val){
            return true;
        }
        return false;
    }
    bool operator!=(const attr& r){
        if(val!=((const floatattr&)r).val){
            return true;
        }
        return false;
    }
    bool operator<=(const attr& r){
        if(val<=((const floatattr&)r).val){
            return true;
        }
        return false;
    }
    bool operator>=(const attr& r){
        if(val>=((const floatattr&)r).val){
            return true;
        }
        return false;
    }
    bool operator<(const attr& r){
        if(val<((const floatattr&)r).val){
            return true;
        }
        return false;
    }
    bool operator>(const attr& r){
        if(val>((const floatattr&)r).val){
            return true;
        }
        return false;
    }
    float get(){
        return this->val;
    }
    void print_attr(){
        cout<<val;
    }
};
class doubleattr:public attr{
    private:
    double val;
    public:
    doubleattr(){
        cin>>val;
    }
    doubleattr(double v){
        val=v;
    }
    bool operator==(const attr& r){
        if(val==((const doubleattr&)r).val){
            return true;
        }
        return false;
    }
    bool operator!=(const attr& r){
        if(val!=((const doubleattr&)r).val){
            return true;
        }
        return false;
    }
    bool operator<=(const attr& r){
        if(val<=((const doubleattr&)r).val){
            return true;
        }
        return false;
    }
    bool operator>=(const attr& r){
        if(val>=((const doubleattr&)r).val){
            return true;
        }
        return false;
    }
    bool operator<(const attr& r){
        if(val<((const doubleattr&)r).val){
            return true;
        }
        return false;
    }
    bool operator>(const attr& r){
        if(val>((const doubleattr&)r).val){
            return true;
        }
        return false;
    }
    double get(){
        return this->val;
    }
    void print_attr(){
        cout<<val;
    }
};
class stringattr:public attr{
    private:
    string val;
    public:
    stringattr(){
        cin>>val;
    }
    stringattr(string v){
        val=v;
    }
    bool operator==(const attr& r){
        if(val==((const stringattr&)r).val){
            return true;
        }
        return false;
    }
    bool operator!=(const attr& r){
        if(val!=((const stringattr&)r).val){
            return true;
        }
        return false;
    }
    bool operator<=(const attr& r){
        if(val<=((const stringattr&)r).val){
            return true;
        }
        return false;
    }
    bool operator>=(const attr& r){
        if(val>=((const stringattr&)r).val){
            return true;
        }
        return false;
    }
    bool operator<(const attr& r){
        if(val<((const stringattr&)r).val){
            return true;
        }
        return false;
    }
    bool operator>(const attr& r){
        if(val>((const stringattr&)r).val){
            return true;
        }
        return false;
    }
    string get(){
        return this->val;
    }
    void print_attr(){
        cout<<val;
    }
};
class record{
    vector<attr*> attrptr;
    public:
    record(){}
    record(int nattr,const vector<int>& attrids){
        attrptr.resize(nattr);
        for(int i=0;i<nattr;i++){
            cout<<"Enter value for attribute "<<i+1<<":";
            if(attrids[i]==0){
                attrptr[i]=new intattr;
            }
            else if(attrids[i]==1){
                attrptr[i]=new doubleattr;
            }
            else if(attrids[i]==2){
                attrptr[i]=new floatattr;
            }
            else{
                attrptr[i]=new stringattr;
            }
        }
    }
    record(const record& r,const vector<int>& attrids){
        int nattr=attrids.size();
        attrptr.resize(nattr);
        for(int i=0;i<nattr;i++){
            if(attrids[i]==0){
                intattr*ptr=dynamic_cast<intattr*>(r.attrptr[i]);
                attrptr[i]=new intattr(ptr->get());
            }
            else if(attrids[i]==1){
                doubleattr*ptr=dynamic_cast<doubleattr*>(r.attrptr[i]);
                attrptr[i]=new doubleattr(ptr->get());
            }
            else if(attrids[i]==2){
                floatattr*ptr=dynamic_cast<floatattr*>(r.attrptr[i]);
                attrptr[i]=new floatattr(ptr->get());
            }
            else{
                stringattr*ptr=dynamic_cast<stringattr*>(r.attrptr[i]);
                attrptr[i]=new stringattr(ptr->get());
            }
        }
    }
    ~record(){
        for(int i=0;i<attrptr.size();i++){
            delete attrptr[i];
        }
    }
    void add_attribute(int v){
        cout<<"Enter value:";
        if(v==0){
            attrptr.push_back(new intattr());
        }
        else if(v==1){
            attrptr.push_back(new doubleattr());
        }
        else if(v==2){
            attrptr.push_back(new floatattr());
        }
        else{
            attrptr.push_back(new stringattr());
        }
    }
    void print_record(int nattr){
        for(int i=0;i<nattr;i++){
            attrptr[i]->print_attr();
            cout<<"   ";
        }
    }
    bool operator==(const record& r){
        for(int i=0;i<r.attrptr.size();i++){
            if(!(*(r.attrptr[i])==*(this->attrptr[i]))){
                return false;
            }
        }
        return true;
    }
    friend relation*projection(relation*,list<string>);
    friend relation*cartesian(relation*,relation*);
    friend relation*unione(relation*,relation*);
    friend relation*difference(relation*,relation*);
    friend relation*unione(relation*,dnf*);
    friend relation*naturaljoin(relation*,relation*,list<string>);
};
class relation{
    int nrecs,nattr;
    vector<string> attrnames;
    vector<int> attrids;
    list<record*> records;
    public:
    relation(){
        nrecs=0;
        nattr=0;
    }
    relation(const relation& r){
        nrecs=r.nrecs;
        nattr=r.nattr;
        attrnames=r.attrnames;
        attrids=r.attrids;
        records.resize(nrecs);
        list<record*>::iterator it1=records.begin();
        for(auto it=r.records.begin();it!=r.records.end();++it){
            *it1=new record(**it,attrids);
            ++it1;
        }
    }
    ~relation(){
        for(auto it=records.begin();it!=records.end();it++){
            delete *it;
        }
    }
    void add_attribute(){
        cout<<"Enter Attribute name:";
        string s;
        cin>>s;
        int v;
        attrnames.push_back(s);
        nattr++;
        cout<<"Enter 0 if int 1 if double 2 if float 3 if string."<<endl;
        while(1){
            cout<<"Enter value:";
            cin>>v;
            if(v<0||v>3){
                cout<<"Invalid value."<<endl;
            }
            else{
                attrids.push_back(v);
                break;
            }
        }
        if(nrecs==0){
            cout<<"No records are present."<<endl;
            return ;
        }
        int i=0;
        for(auto it=records.begin();it!=records.end();++it){
            cout<<"Enter value of new attribute for record "<<i+1<<endl;
            (*it)->add_attribute(v);
            i++;
        }
    }
    void add_record(){
        if(nattr==0){
            cout<<"Add attributes first."<<endl;
            return;
        }
        nrecs++;
        records.push_back(new record(nattr,attrids));
        cout<<"Record successfully added."<<endl;
    }
    bool is_attr(string s){
        for(int i=0;i<nattr;i++){
            if(attrnames[i]==s){
                return true;
            }
        }
        return false;
    }
    int id(string s){
        for(int i=0;i<nattr;i++){
            if(attrnames[i]==s){
                return attrids[i];
            }
        }
    }
    void print_relation(){
        if(nrecs==0){
            cout<<"Empty relation."<<endl;
            return ;
        }
        for(int i=0;i<nattr;i++){
            cout<<attrnames[i]<<"   ";
        }
        cout<<endl;
        for(auto it=records.begin();it!=records.end();++it){
            (*it)->print_record(this->nattr);
            cout<<endl;
        }
    }
    friend relation*difference(relation*,string ,string);
    friend relation*projection(relation*,list<string>);
    friend relation*cartesian(relation*,relation*);
    friend relation*unione(relation*,relation*);
    friend relation*difference(relation*,relation*);
    friend relation*unione(relation*,dnf*);
    friend relation*naturaljoin(relation*,relation*,list<string>);
    friend list<string> common(relation*,relation*);
};