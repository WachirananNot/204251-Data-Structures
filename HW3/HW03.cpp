#include <iostream>
#include "term.cpp"
using namespace std;
class Polynomial{
public:
    Poly_node* head;
    Polynomial(){
        head = NULL;
    }
    void addTerm(int coef, int exponent){
        Poly_node* newPtr = new Poly_node;
        newPtr->coef = coef;
        newPtr->exponent = exponent;
        newPtr->next = NULL;
        if(head == NULL){
            head = newPtr;
        }
        else if (exponent>head->exponent){
        newPtr->next = head;
        head = newPtr;
        }
            
        else if (exponent == head ->exponent){
        head ->coef = head->coef + coef;
        } 
        else{
            Poly_node* cur = head;
            while (cur->next != NULL && cur ->next->exponent>exponent){
                cur = cur->next;
            }
            if(cur -> next == NULL){
                cur->next = newPtr;
            }else{
                if(cur->next->exponent == exponent){
                    cur->next->coef = cur->next->coef+coef;
                }else{
                    newPtr->next = cur->next;
                    cur->next = newPtr;
                }
            }   
        }
    }
    void printPolynomial(){
        cout<<"[ ";
        Poly_node* ptr = head;
        while(ptr!=NULL){
            if(ptr->coef==0){

            }else{
                cout<< ptr->coef<<"X^{"<<ptr->exponent<<"} ";
            }
            ptr = ptr->next;
        }
        cout<<"]\n";
    }

    void plus(Polynomial f2){
        Poly_node* b = f2.head;
        while(b != NULL){
            addTerm(b->coef,b->exponent);
            b = b->next;
            
        }
    }
    void minus(Polynomial f2){
        Poly_node* b = f2.head;
        while(b != NULL){
            b->coef = (b->coef)*(-1);
            addTerm(b->coef,b->exponent);
            b = b->next;
        }
    }
};
