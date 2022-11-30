class StackItem{
    public:
    char ch;
};

class CharStack {

public:
    StackItem* S;
    int index = -1;
    int Max_Stack = 100;
    CharStack() { // constructor
        S = new StackItem[Max_Stack];
        
    }

    void push(char new_item) {
        if(index+1 < Max_Stack){
            index++;
            S[index].ch = new_item;
        }
    }

    char pop() {
        if(!isEmpty()){
            index--;
            return S[index+1].ch;
        }
    }

    char top() {
        if(!isEmpty()){
            return S[index].ch;
        }

    }

    bool isEmpty() {
        return(index==-1);
    }
};