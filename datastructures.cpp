#include <bits/stdc++.h>
#define REP(i, a, n) for(int i = a; i < n; i++)
#define DESC(i, n, a) for(int i = n-1; i >= a; i--)
#define pb push_back
#define mp make_pair
#define mset(v, val) memset(v, val, sizeof(v))
#define printv(v) {cout << "["; for(int i = 0; i < v.size(); i++){cout << v[i] << " ";} cout << "]" << endl;}
#define printarr(v, n) {cout << "["; for(int i = 0; i < n; i++){cout << v[i] << " ";} cout << endl;}
#define EMPTY 2147483640 // pretty unlikely to appear in stack, queue, or deque

using namespace std;

struct Node{
	Node *next;
	Node *prev;
	int value;
	Node(int v = 0, Node *nxt = 0, Node *prv = 0) : prev(nxt), next(prv), value(v) {}
};

struct Queue{
	Node *top;
	Node *bot;
	int size;
	Queue() : top(NULL), bot(NULL), size(0) {}
};

struct Stack{
	Node *top;
	int size;
	Stack() : top(NULL), size(0) {}
};

struct Deque{
	Node *top;
	Node *bot;
	int size;
	Deque() : top(NULL), bot(NULL), size(0) {}
};

// functions for Queue
// adds element to bottom of the queue
// complexity: O(1)
void push(Queue *q, int val){
	Node *temp = new Node(val, q->bot, NULL);
	q->bot->prev = temp;
	q->bot = temp;
	q->size++;
}

// removes and returns element from the top of the queue
// complexity: O(1)
int pop(Queue *q){
	if(q->size > 0){
		q->size--;
		Node *temp = q->top;
		q->top = q->top->prev;
		
		int v = temp->value;

		delete temp;
		return v;
	}
	return EMPTY;
}

// functions for Stack
// pushes element onto the top of Stack
// complexity: O(1)
void push(Stack *s, int val){
	Node *temp;
	temp = new Node(val, NULL, s->top);
	s->top = temp;
	s->size++;
}

int pop(Stack *s){
	if(s->size > 0){
		s->size--;
		Node *temp = s->top;
		s->top = s->top->prev;
		s->top->next = NULL;
		int val = temp->value;
		delete temp;
		return val;
	}
	return EMPTY;
}

// functions for Deque
// pushes element on both sides
// complexity: O(1)
void push_front(Deque *d, int val){
    Node *temp = new Node(val, d->top, NULL);
    d->top = temp;
    d->size++;
}

int pop_front(Deque *d){
    if(d->size > 0){
        d->size--;
        Node *temp = d->top;
        d->top = d->top->prev;
        d->top->next = NULL;
        
        int val = temp->value;
        delete temp;
        return val;
    }
    
    return EMPTY;
}

void push_back(Deque *d, int val){
    Node *temp = new Node(val, NULL, d->bot);
    d->bot->prev = temp;
	d->bot = temp;
    d->size++;
}

int pop_back(Deque *d){
    if(d->size > 0){
        d->size--;
        Node *temp = d->top;
		d->top = d->top->prev;
		
		int v = temp->value;

		delete temp;
		return v;
    }
    
    return EMPTY;
}

int main(){
	Stack *s = new Stack();
	
	push(s, 4);
	push(s, 2);
	push(s, 6);
	push(s, 1);
	push(s, 7);
	push(s, 3);
	push(s, 8);
	
	while(s->size > 0){
		cout << pop(s) << endl;
	} 
	
	Deque *d = new Deque();
	
	push_front(d, 1);
	push_front(d, 2);
	push_back(d, 3);
	push_back(d, 4);
	
	while(d->size > 0){
	    if(d->size & 1)
	        cout << pop_front(d) << endl;
	    else cout << pop_back(d) << endl;
	   
	}
	
	
	return 0;
}
