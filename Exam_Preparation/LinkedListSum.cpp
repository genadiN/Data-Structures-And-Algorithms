#include <bits/stdc++.h>
using namespace std;


struct Node {
    Node *next;
    int data;
};


class LinkedList{
    public:
    LinkedList(){
        head = nullptr;
        tail = nullptr;
    }
    ~LinkedList(){
        Node* temp;
        while(head != nullptr){
            temp = head;
            head = head->next;
            delete temp;
        }
    }
    void add(int value){
        Node* temp = new Node;
        temp->data = value;
        temp->next = nullptr;

        if (head == nullptr and tail == nullptr){
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }
    void print(){
        Node* curr = head;
        while(curr != nullptr){
            cout << curr->data << " ";
            curr = curr->next;
        }
    }

    int getSize(){
        int size = 0;
        Node* curr = head;
        while(curr != nullptr){
            size++;
            curr = curr->next;
        }
        return size;
    }

private:
    Node *head, *tail;
};


void solve(LinkedList& num1, LinkedList& num2)
{
    std::vector<int> number1(size, 0), number2(size, 0);
    int num1sz = 0, num2sz = 0;

    Node* temp = num1.get_head();
    std::stack<int> s;

    long long int i = 0;
    while (temp)
    {
        number1[i] = temp->data;
        temp = temp->next;
        i++;
    }
    num1sz = i - 1;

    i = 0;
    temp = num2.get_head();

    while (temp)
    {
        number2[i] = temp->data;
        temp = temp->next;
        i++;
    }
    num2sz = i - 1;

    std::stack<int> answer;

    for (int i = 0; i < size; i++)
    {
        if (number1[i] == 0 && number2[i] == 0 && i > num1sz && i > num2sz)
            break;

        if (number1[i] + number2[i] > 9)
        {
            answer.push((number1[i] + number2[i]) % 10);
            number1[i + 1]++;
        }
        else
            answer.push(number1[i] + number2[i]);
    }

    while (!answer.empty())
    {
        std::cout << answer.top();
        answer.pop();
    }
}

int main(){
    LinkedList num1, num2;

    int size1, size2;
    cin >> size1;
    for(int i = 0 ; i < size1 ; i++){
        int digit;
        cin >> digit;
        num1.add(digit);
    }

    cin >> size2;
    for(int i = 0 ; i < size2 ; i++){
        int digit;
        cin >> digit;
        num2.add(digit);
    }

    solve(num1, num2);
}
