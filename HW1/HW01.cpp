#include <iostream>
#include <string>
#include "card.cpp"

using namespace std;

class CardList{

public:
	Card *head;
    int index;
    CardList(){
        head =NULL;
        index = 0;
    }

	void pop_back(){
	    Card*ptr = head;
	    if(head == NULL){
            index = 0;
            return;
        }
	    if(head->next == NULL){
            delete head;
            head = NULL;
            index-=1;
	    }
	    else{
            while(ptr->next->next!= NULL){
                ptr = ptr->next;
            }
            ptr->next = NULL;
            index -=1;
	    }
	}


    void insert_back(string newItem){
        Card* newPtr = new Card;
        newPtr ->name = newItem;
        newPtr ->next = NULL;
        index += 1;
        if(head == NULL){
            head = newPtr;
        }else{
            Card* ptr = head;
            while(ptr->next!=NULL){
                ptr = ptr->next;
            }
            ptr->next = newPtr;
        }
    }
    void printCardList(){
        cout<<"[ ";
        Card* ptr = head;
        while(ptr!=NULL){
            cout<< ptr->name<<" ";
            ptr = ptr->next;
        }
        cout<<"]\n";
    }
    void shuffle(int pos){
        if(pos<=0 || pos > index ||head == NULL||head->next ==NULL){
            return;
        }
        Card* curr = head;
        while(curr->next!=NULL){
            curr = curr->next;
        }
        Card* prev = head;
        for(int i = 1;i<pos;i++){
            prev = prev->next;
            if(prev->next == NULL){
                return;
            }
        }
        Card* first = prev->next;
        curr -> next = head;
        head = first;
        prev->next = NULL;
    }
};
