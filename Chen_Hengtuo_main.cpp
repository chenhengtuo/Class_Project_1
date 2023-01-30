// Chen_Hengtuo_main.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>
#include<string>
using namespace std;
class listNode {

public:
    string data;
    listNode* next;
    listNode(string s) {
        data = s;
        next =NULL;
    }
    // a string printNode method for rerurn the string,will use in outfile
    string printNode() {
        string first = "";
        string second = "";
        if (this != NULL && this->next != NULL) {
            first = "( " + this->data + "," ;
            second = (this->next)->data + " )->";
        }
        else {
            first = "( " + this->data + ",";
            second = "null )" ;
       }
        return first + second;
    }

};

class LLStack {
private:
    listNode* top;
public:

    LLStack() {
        listNode *dummy = new listNode("dummy");
        top = dummy;
    }

    // a push method add the node to the top(i.e.after dummy node
    void push(listNode &newNode) {
        listNode* curr = top;
        if (isEmpty()) {
            top->next = &newNode;
        }
        else {
            listNode* temp = &newNode;
            curr = top->next;
            top->next = temp;
            temp->next = curr;
        }
    }
    //check if the top is NULL, i.e.after the dummy node
    bool isEmpty() {
        if (top->next == NULL)
            return true;
        else
            return false;
    }
    
    //if stack is not empty, deletes and returns the top of the stack, i.e., the node after dummy
    listNode* pop(ofstream& out) {
        listNode* curr = top;
        listNode* temp = top;
        if (isEmpty()) {
            out << "-----Stack is empty" << endl;
        }
        else
        {
            temp = top->next;
            curr = temp->next;
            top->next = curr;
            temp->next = NULL;
        }
        return temp;
    }

    //the method for build a stack from input file and print into a outfile1
    void buildStack(LLStack& theStack, ifstream& input, ofstream& out ) {

            string op;
            string name;
            if (!input.is_open()) {
                cout << "file can not open" << endl;
                exit(1);
            }
            while (input >> op >> name) {
                if (op == "+") {
                    listNode* node = new listNode(name);
                    theStack.push(*node);
                    theStack.printStack(out);
                }
                else if (op == "-")
                {
                    theStack.pop(out);
                    theStack.printStack(out);
                }
            }

    }
    //print the node in the satck
    void printStack(ofstream& out) {
        listNode* curr = top;
        out << "TOP->";
            while (curr != NULL) {
                out << curr->printNode();
                curr = curr->next;
            }
            out << "-> null" << endl;
    }
};

//LLQuene class
class LLQueue {
private:
    listNode* head;
    listNode* tail;
public:
    LLQueue() {
        listNode* dummy = new listNode("dummy");
        head = dummy;
        tail = dummy;
    }
    //insetr the newNode into the Queue,which is after the tail
    void insertQ(listNode& node){
        tail->next = &node;
        tail = tail->next;
    }

    //delete the first node in the queue i.e.is the node after the head(dummy node.next)
    listNode* deleteQ(){
        listNode* temp = head->next;
        if (!this->isEmpty()) {
            head->next = temp->next;
            temp->next== NULL;
            return temp;

        }
        else {
            return head;
        }
    }
    //check if the queue is empty
    bool isEmpty() {
        if (head->next == NULL)
            return true;
        else
            return false;
    };
    // build a queue by read data from inFile and print out in outFile.txt
    void buildQueue(LLQueue& theQueue, ifstream& input, ofstream& out) {
        string op;
        string name;
        if (!input.is_open()) {
            cout << "file can not open" << endl;
            exit(1);
        }
        while (input >> op >> name) {
            if (op == "+") {
                listNode* node = new listNode(name);
                theQueue.insertQ(*node);
                theQueue.printQueue(out);
            }
            else if (op == "-")
            {
                theQueue.deleteQ();
                theQueue.printQueue(out);
            }
        }
    }
    // the method use for print node in the Queue
    void printQueue(ofstream& out) {
        listNode* curr = head;
        out << "Head->";
        if (head->next == NULL)
        {
            out << head->printNode() << " ---The Queue is empty" << endl;
        }
        else
        {
            while (curr != NULL) {
                out <<curr->printNode();
                curr = curr->next;
            }
            out << "-> null" << endl;
            out << " Tail-> " << tail->printNode() << endl;
        }
    }
};

//the main function for reading data from inFile to build stack,queueand print
int main(int argc, const char* argv[])
{
    ifstream* myFile = new ifstream(argv[1]); //get input file name form CMD
    ofstream copy(argv[2]); //for outfile 1
    ofstream copy2(argv[3]); //for outfile 2
    copy << "============The operator for Stack part==================" << endl;
    LLStack test;
    test.buildStack(test, *myFile, copy);
   
    myFile->close(); //close the file 


    myFile->open(argv[1]);//open the file again
    LLQueue theQ;
    copy2 << "============The operator for Queue part==================" << endl;
    theQ.buildQueue(theQ, *myFile, copy2);
    myFile->close();

    return 0;
}