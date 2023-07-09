#include<bits/stdc++.h>
using namespace std;
class attr;
class record;
class relation;
typedef struct dnf{
    list<list<tuple<string,char,attr*>>> ops;
}dnf;
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
relation* unione(relation*r1,relation*r2){
    int s=0;
    vector<int> pos(r1->nattr,-1);
    for(int i=0;i<r1->nattr;i++){
        for(int j=0;j<r2->nattr;j++){
            if(r1->attrnames[i]==r2->attrnames[j]&&r1->attrids[i]==r2->attrids[j]){
                pos[i]=j;
                s++;
                break;
            }
        }
    }
    if(r1->attrnames.size()!=r2->attrnames.size()){
        s=0;
    }
    if(s!=r1->attrnames.size()){
        cout<<"Attributes don't match can't perform union."<<endl;
        return r1;
    }
    relation* u=new relation();
    relation* copy=new relation(*r2);
    u->nattr=r1->nattr;
    u->attrnames=r1->attrnames;
    u->attrids=r1->attrids;
    vector<pair<int,string>> temp;
    for(int i=0;i<copy->nattr;i++){
        temp.push_back({pos[i],copy->attrnames[i]});
    }
    sort(temp.begin(),temp.end());
    for(int i=0;i<copy->nattr;i++){
        copy->attrnames[i]=temp[i].second;
    }
    for(auto it=copy->records.begin();it!=copy->records.end();++it){
        vector<pair<int,attr*>> t;
        for(int i=0;i<copy->nattr;i++){
            t.push_back({pos[i],(*it)->attrptr[i]});
        }
        sort(t.begin(),t.end());
        for(int i=0;i<copy->nattr;i++){
            (*it)->attrptr[i]=t[i].second;
        }
    }
    for(auto it=r1->records.begin();it!=r1->records.end();++it){
        int s=0;
        for(auto it1=u->records.begin();it1!=u->records.end();++it1){
            if(*(*it)==*(*it1)){
                s=1;
                break;
            }
        }
        if(!s){
            u->records.push_back(new record(**it,u->attrids));
            u->nrecs+=1;
        }
    }
    for(auto it=copy->records.begin();it!=copy->records.end();++it){
        int sw=0;
        for(auto it1=u->records.begin();it1!=u->records.end();++it1){
            if(*(*it)==*(*it1)){
                sw=1;
                break;
            }
        }
        if(!sw){
            u->records.push_back(new record(**it,u->attrids));
            u->nrecs+=1;
        }
    }
    cout<<"Union created successfully."<<endl;
    return u;
}
relation* difference(relation* r1,relation* r2){
    int s=0;
    vector<int> pos(r1->nattr,-1);
    for(int i=0;i<r1->nattr;i++){
        for(int j=0;j<r2->nattr;j++){
            if(r1->attrnames[i]==r2->attrnames[j]&&r1->attrids[i]==r2->attrids[j]){
                pos[i]=j;
                s++;
                break;
            }
        }
    }
    if(r1->attrnames.size()!=r2->attrnames.size()){
        s=0;
    }
    if(s!=r1->attrnames.size()){
        cout<<"Attributes don't match can't perform difference."<<endl;
        return r1;
    }
    relation* d=new relation();
    relation* copy=new relation(*r2);
    d->attrids=r1->attrids;
    d->attrnames=r1->attrnames;
    d->nattr=r1->nattr;
    vector<pair<int,string>> temp;
    for(int i=0;i<copy->nattr;i++){
        temp.push_back({pos[i],copy->attrnames[i]});
    }
    sort(temp.begin(),temp.end());
    for(int i=0;i<copy->nattr;i++){
        copy->attrnames[i]=temp[i].second;
    }
    for(auto it=copy->records.begin();it!=copy->records.end();++it){
        vector<pair<int,attr*>> t;
        for(int i=0;i<copy->nattr;i++){
            t.push_back({pos[i],(*it)->attrptr[i]});
        }
        sort(t.begin(),t.end());
        for(int i=0;i<copy->nattr;i++){
            (*it)->attrptr[i]=t[i].second;
        }
    }
    for(auto it=r1->records.begin();it!=r1->records.end();++it){
        int sw=1;
        for(auto it1=copy->records.begin();it1!=copy->records.end();++it1){
            if(*(*it)==*(*it1)){
                sw=0;
                break;
            }
        }
        if(sw){
            for(auto it1=d->records.begin();it1!=d->records.end();++it1){
                if(*(*it)==*(*it1)){
                    sw=0;
                    break;
                }
            }
            if(sw){
                d->records.push_back(new record(**it,d->attrids));
                d->nrecs++;
            }
        }
    }
    cout<<"Difference created successfully."<<endl;
    return d;
}
relation* cartesian(relation* r1,relation* r2){
    int s=0;
    for(int i=0;i<r1->nattr;i++){
        for(int j=0;j<r2->nattr;j++){
            if((r1->attrnames[i]==r2->attrnames[j])&&(r1->attrids[i]==r2->attrids[j])){
                s++;
                break;
            }
        }
    }
    if(s){
        cout<<"Common attributes are present so cartesian product can't be taken."<<endl;
        return r1;
    }
    relation* p=new relation();
    p->nrecs=r1->nrecs*r2->nrecs;
    p->nattr=r1->nattr+r2->nattr;
    for(int j=0;j<r1->nattr;j++){
        p->attrnames.push_back(r1->attrnames[j]);
        p->attrids.push_back(r1->attrids[j]);
    }
    for(int j=0;j<r2->nattr;j++){
        p->attrnames.push_back(r2->attrnames[j]);
        p->attrids.push_back(r2->attrids[j]);
    }
    for(auto it=r1->records.begin();it!=r1->records.end();++it){
        record* temp;
        record*temp1;
        for(auto j=r2->records.begin();j!=r2->records.end();j++){
            temp=new record(**it,r1->attrids);
            temp1=new record(**j,r2->attrids);
            for(int k=0;k<temp1->attrptr.size();k++){
                temp->attrptr.push_back(temp1->attrptr[k]);
            }
            p->records.push_back(temp);
        }
    }
    cout<<"Cartesian product created successfully."<<endl;
    return p;
}
relation* projection(relation* r,list<string> projectattrs){
    if(projectattrs.size()>r->nattr){
        cout<<"Size of projection is greater than the relation."<<endl;
        return r;
    }
    relation* sub=new relation();
    sub->nattr=projectattrs.size();
    sub->nrecs=r->nrecs;
    sub->attrnames.resize(sub->nattr);
    sub->attrids.resize(sub->nattr);
    vector<int> pos;
    int id=0;
    for(auto it=projectattrs.begin();it!=projectattrs.end();++it){
        int s=1;
        for(int j=0;j<r->nattr;j++){
            if(r->attrnames[j]==*it){
                s=0;
                sub->attrnames[id]=r->attrnames[j];
                sub->attrids[id]=r->attrids[j];
                pos.push_back(j);
                ++id;
                break;
            }
        }
        if(s){
            cout<<"Some attributes are not in relation so cannot be projected."<<endl;
            return r;
        }
    }
    sub->records.resize(sub->nrecs);
    list<record*>::iterator it1=r->records.begin();
    for(auto it=sub->records.begin();it!=sub->records.end();++it){
        (*it)=new record();
        for(int i=0;i<pos.size();i++){
            attr* p;
            if(sub->attrids[i]==0){
                intattr* ptr=dynamic_cast<intattr*>((*it1)->attrptr[pos[i]]);
                p=new intattr(ptr->get());
                (*it)->attrptr.push_back(p);
            }
            else if(sub->attrids[i]==1){
                doubleattr* ptr=dynamic_cast<doubleattr*>((*it1)->attrptr[pos[i]]);
                p=new doubleattr(ptr->get());
                (*it)->attrptr.push_back(p);
            }
            else if(sub->attrids[i]==2){
                floatattr* ptr=dynamic_cast<floatattr*>((*it1)->attrptr[pos[i]]);
                p=new floatattr(ptr->get());
                (*it)->attrptr.push_back(p);
            }
            else{
                stringattr* ptr=dynamic_cast<stringattr*>((*it1)->attrptr[pos[i]]);
                p=new stringattr(ptr->get());
                (*it)->attrptr.push_back(p);
            }
        }
        ++it1;
    }
    cout<<"Successfully projected."<<endl;
    return sub;
}
relation* unione(relation* r,dnf* f){
    relation* n=new relation();
    n->attrnames=r->attrnames;
    n->attrids=r->attrids;
    n->nattr=r->nattr;
    for(auto it=r->records.begin();it!=r->records.end();++it){
        for(auto out=f->ops.begin();out!=f->ops.end();++out){
            bool final=true;
            for(auto inner=(*out).begin();inner!=(*out).end();++inner){
                bool temp=false;
                for(int i=0;i<n->nattr;i++){
                    if(n->attrnames[i]==get<0>(*inner)){
                        if(get<1>(*inner)=='<'){
                            temp=*((*it)->attrptr[i])<*(get<2>(*inner));
                        }
                        else if(get<1>(*inner)=='='){
                            temp=*((*it)->attrptr[i])==*(get<2>(*inner));
                        }
                        else if(get<1>(*inner)=='>'){
                            temp=*((*it)->attrptr[i])<*(get<2>(*inner));
                        }
                        break;
                    }
                }
                final=final&&temp;
            }
            if(final){
                n->records.push_back(new record(**it,n->attrids));
                n->nrecs++;
                break;
            }
        }
    }
    return n;
}
relation* difference(relation* r,string s1,string s2){
    relation* copy=new relation(*r);
    int s=0;
    for(int i=0;i<r->nattr;i++){
        if(copy->attrnames[i]==s1){
            copy->attrnames[i]=s2;
            s++;
        }
    }
    if(s){
        cout<<"Attribute name successfully renamed."<<endl;
        return copy;
    }
    cout<<"Attribute name not found."<<endl;
    return copy;
}
relation* naturaljoin(relation*r1,relation*r2,list<string> joinattr){
    relation* copy1=new relation(*r1);
    relation* copy2=new relation(*r2);
    for(auto it=joinattr.begin();it!=joinattr.end();++it){
        string temp=*it;
        reverse(temp.begin(),temp.end());
        copy2=difference(copy2,*it,temp);
    }
    relation* prod=cartesian(copy1,copy2);
    dnf* f=new dnf;
    for(auto it=r2->records.begin();it!=r2->records.end();++it){
        list<tuple<string,char,attr*>> l;
        for(auto it1=joinattr.begin();it1!=joinattr.end();++it1){
            int index;
            for(int j=0;j<copy2->nattr;j++){
                if(r2->attrnames[j]==(*it1)){
                    index=j;
                    break;
                }
            }
            string temp=*it1;
            reverse(temp.begin(),temp.end());
            l.push_back({*it1,'=',(*it)->attrptr[index]});
            l.push_back({temp,'=',(*it)->attrptr[index]});
        }
        f->ops.push_back(l);
    }
    relation* sel=unione(prod,f);
    list<string> p=joinattr;
    for(int i=0;i<r1->nattr;i++){
        int s=1;
        for(auto it=joinattr.begin();it!=joinattr.end();++it){
            if(r1->attrnames[i]==(*it)){
                s=0;
                break;
            }
        }
        if(s){
            p.push_back(r1->attrnames[i]);
        }
    }
    for(int i=0;i<r2->nattr;i++){
        int s=1;
        for(auto it=joinattr.begin();it!=joinattr.end();++it){
            if(r2->attrnames[i]==(*it)){
                s=0;
                break;
            }
        }
        if(s){
            p.push_back(r2->attrnames[i]);
        }
    }
    delete f;
    relation* final=projection(sel,p);
    return final;
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