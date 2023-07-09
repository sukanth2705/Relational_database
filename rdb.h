#include<bits/stdc++.h>
using namespace std;
class attr;
class record;
class relation;
typedef struct dnf{
    list<list<tuple<string,char,attr*>>> ops;
}dnf;
relation* unione(relation*,relation*);
relation*difference(relation*,relation*);
relation*cartesian(relation*,relation*);
relation*projection(relation*,list<string>);
relation*unione(relation*,dnf*);
relation*difference(relation*,string ,string);
relation*naturaljoin(relation*,relation*,list<string>);
list<string> common(relation*,relation*);
