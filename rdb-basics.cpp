#include"rdb-attr.cpp"
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