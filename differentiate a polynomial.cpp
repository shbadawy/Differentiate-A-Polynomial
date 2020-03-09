#include <iostream>

using namespace std;

class poly{
    
public:
    //getters 
    int get_co(){return co;}
    int get_power(){return power;}
    poly *get_next(){return next;}
    poly *get_pre(){return pre;}
    void printList();
    poly ini(int arr[],int size);
    //setters
    void set_co(int i){co=i;}
    void set_power(int i){power=i;}
    void set_next(poly *i){next=i;}
    void set_pre(poly  *i) {pre=i;}
    void insert (int i);
    int  count (poly * first);
    poly *get_multiplication (poly *fFir,poly *sFir,poly *&nF,poly *&nL);
    int sub (int i);
    
private:
    int  co;
    int power;
    poly *next=nullptr , *pre=nullptr,*first =nullptr,*last=nullptr;
    };
    
poly *first1=nullptr;
poly *first2=nullptr;
poly *first3=nullptr;

poly *last1=nullptr;
poly *last2=nullptr;
poly *last3=nullptr;

poly poly :: ini(int arr[],int size){
    
    int i=0;
    int tempS=size;
    
    poly first;
    poly last;
            first.set_co(arr[i]) ;
            first.set_power(size-1);
            last=first;
            size--;
            i++;
    while (i<tempS){
            poly *newItem = new poly();
            last.set_next(newItem);
            last.set_co(arr[i]);
            last.set_power(size-1);
            last.set_next(last.get_next());
            size--;
            i++; 
       
        }
        return first;
    }
    
int poly :: count (poly * first){
    
    poly *ptr=first;
    int i=0;
    while (ptr != nullptr){
        
        i++;
        ptr=ptr->get_next();
        
        }
    return i;
    }
    
void poly:: printList(){
    while ( this != nullptr){
        cout << this->get_co() << " " << this->get_power() <<endl;
        this->set_next(this->get_next());
    }
   
        }

poly* poly :: get_multiplication (poly *fFir,poly *sFir,poly *&nF,poly *&nL){
    
    int newS= fFir->get_power()+sFir->get_power();
    int p,c,pos;
    int arr[newS+1]={0};
    poly *i=fFir;
    poly *j=sFir;
    while (i != nullptr){
        
        j=sFir;
        while(j != nullptr){
            
            p=j->get_power()+i->get_power();
            c=j->get_co()*i->get_co();
            pos=newS-p;
            arr[pos]+=c;
            j=j->get_next();
            
            }
        i=i->get_next();
        }
      ini(arr,newS+1);
      return nF;
    
    }
int main (){//begin main 
    
int arr1 [4]={4,2,0,-1};
int arr2 [4]={2,0,0,2};

poly poly1 ,poly2,*poly3;
poly1.ini(arr1,4);
//poly2.ini(arr2,4,first2,last2);
//poly3->get_multiplication(first1,first2,first3,last3);
//poly3->printList(first3);

poly1.printList();
//poly2.printList(first2);


}//end main 


