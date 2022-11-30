#include <iostream>
#include <string>
#include "station.cpp"
using namespace std;

class Trip {

public:

    Station* header;
    Station* trailer;
    Trip()
    {
        header = new Station;
        trailer = new Station;
        header->next  = trailer;
        trailer->prev  = header;
    }
    void printList(){
        cout << "[ ";
        Station* ptr = header->next;
        while (ptr != trailer) {
            cout << ptr->name << " ";
            ptr = ptr->next;
        }
        cout << "]\n";
    }
    void insert_front(string newItem){
        Station* ptr = new Station;
        ptr -> name = newItem;
        ptr -> next = NULL;
        ptr -> prev = NULL;
        if(header ->next == trailer){
            ptr->prev = header;
            ptr->next = trailer;
            header ->next = ptr;
            trailer ->prev = ptr;
        }else{
            ptr->prev = header;
            ptr ->next = header->next;
            header->next->prev = ptr;
            header->next = ptr;
        }
    }
    void insert_back(string newItem){
        Station* ptr = new Station;
        ptr -> name = newItem;
        ptr -> next = NULL;
        ptr -> prev = NULL;
        if(header->next == trailer){
            ptr->prev = header;
            ptr->next = trailer;
            header ->next = ptr;
            trailer ->prev = ptr;
        }else{
            ptr ->next = trailer;
            ptr ->prev = trailer ->prev;
            (trailer->prev)->next = ptr;
            trailer->prev = ptr;
        }
    }
    void remove_front(){
        if(header->next == trailer){
            return;
        }
        header->next->next->prev = header;
        header->next = header->next->next;
    }
    void remove_back(){
        if(header->next == trailer){
            return;
        }
        trailer->prev->prev->next = trailer;
        trailer->prev = trailer->prev->prev;
    }

    Station* visit(int nStep, string stepText){
        Station* cur = header->next;
        for(int i = 0;i<nStep;i++){
            if(stepText[i]=='r'||stepText[i]=='R'){
                if(cur->next == trailer){
                    continue;
                }
                cur = cur->next;
            }
            else if(stepText[i]=='l'||stepText[i]=='L'){
                if(cur->prev == header){
                    continue;
                }
                cur = cur->prev;
            }
        }
        return cur;

    }
};
