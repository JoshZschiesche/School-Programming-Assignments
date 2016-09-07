//Josh Zschiesche
//CSCE 221-505
//Due: Feb/2/2016
//Instructor: Leyk

#include <stdexcept>
#include "My_vec_temp.h"

int main(){

My_vec<int> v;
cout<<"My_vec using int!"<<endl;
cout<<"populating, returning size, sorting then printing"<<endl;
v.insert_at_rank(0,1);
v.insert_at_rank(0,2);
v.insert_at_rank(0,3);
v.replace_at_rank(0,5);
v.insert_at_rank(0,2);
cout<<v.get_size()<<endl;
sort_max(v);
cout<<v;
cout<<endl;

My_vec<char> vc;
cout<<"My_vec using char!"<<endl;
cout<<"populating, returning size, sorting then printing"<<endl;
vc.insert_at_rank(0,'1');
vc.insert_at_rank(0,'2');
vc.insert_at_rank(0,'3');
vc.replace_at_rank(0,'5');
vc.insert_at_rank(0,'2');
cout<<vc.get_size()<<endl;
sort_max(vc);
cout<<vc;
cout<<endl;

My_vec<double> vd;
cout<<"My_vec using double!"<<endl;
cout<<"populating, returning size, sorting then printing"<<endl;
vd.insert_at_rank(0,1);
vd.insert_at_rank(0,2);
vd.insert_at_rank(0,3);
vd.replace_at_rank(0,5);
vd.insert_at_rank(0,2);
cout<<vd.get_size()<<endl;
sort_max(vd);
cout<<vd;

}