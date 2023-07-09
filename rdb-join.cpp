#include"rdb-basics.cpp"
#include"rdb-join.cpp"
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